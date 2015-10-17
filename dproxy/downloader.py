#!/usr/bin/python2.7

import pycurl
import os
import sys
import signal
import time

import pycurl
import cStringIO
import re

class downloader:

    def __init__(self, target_address, output_file, proxy=None):

        ######## Set variables of the downloader ########
        self.output_file = output_file  # Downloaded file is stored here
        self.chunk = 1 * 1024 * 1024                # Define the chunk size to be downloaded at once
        self.download_limit = 150 * 1024 * 1024 
        #################################################
        try:
            self.dir_name = self.output_file + "tmp"
            os.mkdir(self.dir_name)
        except OSError:
            pass
        ######### Set the target of the Curl object ######

        self.curl_obj = pycurl.Curl()        # Initializing CURL object
        
        # Setting the target
        self.curl_obj.setopt(self.curl_obj.URL, target_address)
        self.url_addr = target_address

        # allow redirection
        self.curl_obj.setopt(pycurl.FOLLOWLOCATION, True)
        
        if proxy != None:
            # This should be set as
            # "http://<username>[:<password>]@<proxy-host>[:<proxy-port>]"
            self.curl_obj.setopt(pycurl.PROXY, proxy)

        #################################################

        ##### Set the size of the file to be downloaded ######
        # Create a temporary curl object to get the information
        tmp_curl_obj = pycurl.Curl()
        # Setting the target
        tmp_curl_obj.setopt(tmp_curl_obj.URL, target_address)
        tmp_curl_obj.setopt(pycurl.FOLLOWLOCATION, True)
        if proxy != None:
            # This should be set as
            # "http://<username>[:<password>]@<proxy-host>[:<proxy-port>]"
            self.curl_obj.setopt(pycurl.PROXY, proxy)
        # Set NO-body download to true
        tmp_curl_obj.setopt(tmp_curl_obj.NOBODY, True)
        #self.curl_obj.setopt(self.curl_obj.USERAGENT,"Mozilla/5.0 (compatible; pycurl)")
        # Send request
        try:
            with Timeout(7):
                print "Trying to get size of the file"
                print target_address
                tmp_curl_obj.perform()
                # print "Got size"
            # get the size
            # print tmp_curl_obj
            with Timeout(2):
                self.size = tmp_curl_obj.getinfo(
                    tmp_curl_obj.CONTENT_LENGTH_DOWNLOAD)
                print "Size: " + str(self.size)
        except Exception, e:
            print e
            self.delete_temp()
            self.size = 0
            #sys.exit (2)

        ######## Set the progress function #############
        # self.curl_obj.setopt(self.curl_obj.NOPROGRESS,1)
        # self.curl_obj.setopt(self.curl_obj.PROGRESSFUNCTION,self.progress)

    def resume_capable(self):
        """Test if the server supports multi-part file download. Method expects effective (absolute) url."""

        effective_url = self.url_addr

        c = pycurl.Curl()
        header = cStringIO.StringIO()

        # Get http header
        c.setopt(c.URL, effective_url)
        c.setopt(c.NOBODY, 1)
        c.setopt(c.HEADERFUNCTION, header.write)
        c.perform()
        c.close()

        header_text = header.getvalue()
        header.close()

        # verbose_print(header_text)

        # Check if server accepts byte-ranges
        match = re.search('Accept-Ranges:\s+bytes', header_text)
        if match:
            return True
        else:
            # If server explicitly specifies "Accept-Ranges: none" in the
            # header, we do not attempt partial download.
            match = re.search('Accept-Ranges:\s+none', header_text)
            if match:
                return False
            else:
                c = pycurl.Curl()

                # There is still hope, try a simple byte range query
                c.setopt(c.RANGE, '0-0')  # First byte
                c.setopt(c.URL, effective_url)
                c.setopt(c.NOBODY, 1)
                c.perform()

                http_code = c.getinfo(c.HTTP_CODE)
                c.close()

                if http_code == 206:  # Http status code 206 means byte-ranges are accepted
                    return True
                else:
                    return False


    def download(self):

        if (self.size > 0):
            print "Starting download. Total size: " + str(self.size) + " bytes or " + str(self.size / 1024 / 1024) + " MB"
        else:
            print "Starting download"
        # Download straight-away if the size is less than the limit

        # print self.curl_obj.getopt(self.curl_obj.URL)
        print self.url_addr

        if self.size <= self.chunk or self.size < 0 or not self.resume_capable():
            print "No resume Capability !"

            if self.size > self.download_limit:
                print "File size larger than download limit. Aborting."
                sys.exit()    

            # Set the output file
            self.curl_obj.fp = open(self.output_file, "wb")
            self.curl_obj.setopt(pycurl.WRITEDATA, self.curl_obj.fp)
            self.curl_obj.perform()
            self.delete_temp()
            sys.exit()

        # All errors are logged in the logfile
        # Opened in append mode (maintains all logs)
        log = open("/var/log/downloader.log", "a")

        # This variable decides the number of concurrent processes.
        num_proc = 10

        pid = []                    # This stores the list of PIDs of the children (processes)

        # Limits the maximum download time per download-connection to 10
        # minutes (This could be changed for slower connections)
        self.curl_obj.setopt(pycurl.TIMEOUT, 60 * 10)

        lim_l = 0                    # lower limit of the byte-range for download
        lim_u = self.chunk        # upper limit of the byte-range for download
        i = 1
        while lim_l <= self.size:
            f = open('status', 'w')
            s = str(int(100 * i * self.chunk / self.size))
            f.write(s)
            f.close()

            # Create a temporary filename
            temp_output = os.path.join(self.dir_name, "output" + str(i))
            # print temp_output
            # Ensure that it doesn't already exists
            # If it exists and its size is the same as that of the chunk
            # downloaded each time, then go to the next chunk
            if os.path.exists(temp_output) and os.path.getsize(temp_output) == self.chunk:
                # print str(i)+" MB already downloaded"
                i = i + 1
                r = str(lim_l) + "-" + str(lim_u - 1)
                # print r
                lim_l = lim_l + self.chunk
                lim_u = lim_u + self.chunk
                continue

            # Handle to the file to be written to.
            self.curl_obj.fp = open(temp_output, "wb")
            # Sets the pycurl option to write to the file
            self.curl_obj.setopt(pycurl.WRITEDATA, self.curl_obj.fp)

            # Define the range
            # print lim_l
            # print lim_u
            r = str(lim_l) + "-" + str(lim_u - 1)
            # print r
            # Set the range
            self.curl_obj.setopt(pycurl.RANGE, r)

            # Create a child process
            tpid = os.fork()

            if tpid == -1:
                print "error"
            if tpid == 0:
                # Inside the child

                while True:
                    try:
                        # Start downloading
                        self.curl_obj.perform()
                        # print "Downloaded "+str(i)+" MB of
                        # "+str(self.size/(1024*1024)) + " MB"
                        self.curl_obj.fp.close()  # Close the file
                        break
                    except pycurl.error, e:
                        # Catch the error while downloading a file
                        # and restart the download of the particular file

                        # print "Pycurl error caught"
                        log.write("Pycurl error caught " + str(e) + " while downloading at download range " + str(
                            r) + " while storing to file " + str(temp_output) + "\n")

                        # Close the existing file and reopen (otherwise data
                        # would be appended)
                        self.curl_obj.fp.close()
                        self.curl_obj.fp = open(temp_output, "wb")

                        continue  # Continues the loop

                exit()        # Exits the child process

            if tpid > 0:
                # In the parent
                pid.append(tpid)

            if len(pid) > num_proc - 1:

                # This ensures that only the required number (num_proc) of
                # child processes run at once

                (cpid, exitstatus) = os.wait()        # Wait for any child to exit

                # if not exitstatus==0:
                # If exit status is non-zero, implies a file smaller than the required is downloaded,
                # Hence (either the downloaded has ended, or error)
                # Stop any new downloads
                # TODO : Introduce provision to handle network errors
                # pid.remove(cpid)
                # print "breaking"
                # break
                # pid.remove(cpid)                # remove that child from the list

            # Define lower and upper limit of the next range.
            lim_l = lim_l + self.chunk
            lim_u = lim_u + self.chunk
            # self.print_percentage(i)
            i = i + 1

        while len(pid) > 0:
            # wait for all sub-processes to exit
            try:
                (cpid, exitstatus) = os.wait()        # wait for child to exit
                pid.remove(cpid)                # remove that child from the list
            except OSError:
                # Arises when children have already exit.
                break

    def concatenate(self):

        # Concatenate the files to finally create the desired output

        # TODO : Check that the file doesn't already exist

        # Open file in write mode (and close) to over-write any existing file
        # with same name
        fp = open(self.output_file, 'w')
        fp.close()

        i = 1
        while True:
            temp_output = os.path.join(self.dir_name, "output" + str(i))
            # print temp_output
            if os.path.exists(temp_output):

                # Open file to append to
                fp = open(self.output_file, 'a')

                # Open the temporary file to read from
                tp = open(temp_output, "r")

                # Append to the output_file
                fp.write(tp.read())

                # Close files
                tp.close()
                fp.close()

                if os.path.getsize(temp_output) == self.chunk:
                    i = i + 1        # Increase only if the file size is equal to the chunk size
                else:
                    break        # this takes care of redundant files downloaded

        fp.close()

    def delete_temp(self):

        # Remove the temporary files created
        i = 1
        while True:
            temp_output = os.path.join(self.dir_name, "output" + str(i))
            # print temp_output
            if os.path.exists(temp_output):
                os.remove(temp_output)
            else:
                break
            i = i + 1

        try:
            os.rmdir(self.dir_name)
        except Exception, e:
            pass

    def progress(self, download_total, downloaded, uploaded_total, upload):
        '''
        Function to display the progress
        '''
        print "To be downloaded" + str(download_total)
        print "Downloaded : " + str(downloaded)

    
class Timeout():
    """Timeout class using ALARM signal."""
    class Timeout(Exception):
        pass

    def __init__(self, sec):
        self.sec = sec

    def __enter__(self):
        signal.signal(signal.SIGALRM, self.raise_timeout)
        signal.alarm(self.sec)

    def __exit__(self, *args):
        signal.alarm(0)    # disable alarm

    def raise_timeout(self, *args):
        raise Timeout.Timeout()
