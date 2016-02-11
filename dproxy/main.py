#!/usr/bin/python2.7

from downloader import downloader
import sys
import os
import signal
import time

def main(argv):

	# Get the information from the arguments
	try:
		target_address=argv[1]
		output_file=argv[2]
		os.chdir(argv[3])
	except IndexError:
		print "my error handler"
		print "Incorrect number of arguments"
		print "Usage downloader <target_address> <output_file> [-p [proxy]]"
		sys.exit(1)		# Exit status 1 for invalid usage

	# Get the information about the proxy
	if len(argv)>3:
		if argv[3]=="-p":

			try:
				# Check if proxy is passed as an argument
				http_proxy=argv[4]

			except IndexError:
				# If proxy is not passed, use the environment variable
				http_proxy=os.environ['http_proxy']


	# Ensure that http_proxy variable is set
	try:
		http_proxy
	except NameError:
		http_proxy=None


	# Create a downloader object
	handle=downloader(target_address,output_file,http_proxy)

	# Download the files
	handle.download()

	# Concatenate the resulting segments
	handle.concatenate()

	# Delete temporary files
	handle.delete_temp()

def signal_term_handler(signal, frame):
	print 'SIGTERM'
	del handle
	
	sys.exit(0)

if __name__=="__main__":

	signal.signal(signal.SIGTERM, signal_term_handler)
	signal.signal(signal.SIGINT, signal_term_handler)

	main(sys.argv)
