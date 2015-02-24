
#include "allproxy.h"
#include "ui_allproxy.h"

#include <QFileDialog>
#include <QString>
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QTreeView>
#include <QSettings>
#include <QMessageBox>
#include <QDebug>
#include <QToolBox>
#include <QTextEdit>
#include <QtGui>
#include <QVBoxLayout>
#include <QCloseEvent>

AllProxy::AllProxy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllProxy)
{

    ui->setupUi(this);
    this->setFixedSize(this->size());

    this->load_configuration();
    this->start();
}

AllProxy::~AllProxy()
{
    delete ui;
}

void AllProxy::start(){
    qDebug() << "App path : " << qApp->applicationDirPath();
    system("touch config/config.sh");
//    system("sudo bash start.sh");
}

void AllProxy::setToolBoxButtonColor(QToolBox* toolBox, int index, QColor color)
{
    int i = 0;
    foreach (QAbstractButton* button, toolBox->findChildren<QAbstractButton*>())
    {
        // make sure only toolbox button palettes are modified
        if (button->metaObject()->className() == QString("QToolBoxButton"))
        {
            if (i == index)
            {
                // found correct button
                QPalette p = button->palette();
                p.setColor(QPalette::Button, color);
                button->setPalette(p);
                break;
            }
            i++;
        }
    }
}

void AllProxy::load_configuration(){
    QSettings project_settings("project_settings");

    qDebug() << project_settings.fileName();
    qDebug() << "Gateway : " << project_settings.value("nproxy_gateway").toString();
    qDebug() << "Server : " << project_settings.value("nproxy_server").toString();
    qDebug() << "Port : " << project_settings.value("nproxy_port").toString();
    qDebug() << "Username : " << project_settings.value("nproxy_username").toString();
    qDebug() << "Password : " << project_settings.value("nproxy_password").toString();
    qDebug() << "Vproxy Username : " << project_settings.value("vproxy_username").toString();
    qDebug() << "Vproxy password : " << project_settings.value("vproxy_password").toString();


    this->ui->in_text_nproxy_gateway->setText(project_settings.value("nproxy_gateway").toString());
    this->ui->in_text_nproxy_server->setText(project_settings.value("nproxy_server").toString());
    this->ui->in_text_nproxy_port->setText(project_settings.value("nproxy_port").toString());
    this->ui->in_text_nproxy_username->setText(project_settings.value("nproxy_username").toString());
    this->ui->in_text_nproxy_password->setText(project_settings.value("nproxy_password").toString());

    this->ui->in_text_vproxy_username->setText(project_settings.value("vproxy_username").toString());
    this->ui->in_text_vproxy_password->setText(project_settings.value("vproxy_password").toString());
    this->ui->in_text_vproxy_server->setText(project_settings.value("vproxy_server").toString());
    this->ui->in_text_vproxy_port->setText(project_settings.value("vproxy_port").toString());
    this->ui->in_text_vproxy_path->setText(project_settings.value("vproxy_path").toString());
    this->ui->in_text_vproxy_proxy_username->setText(project_settings.value("vproxy_proxy_username").toString());
    this->ui->in_text_vproxy_proxy_password->setText(project_settings.value("vproxy_proxy_password").toString());

    this->ui->in_text_lproxy_local_port->setText(project_settings.value("lproxy_local_port").toString());
    this->ui->in_text_lproxy_server->setText(project_settings.value("lproxy_server").toString());
    this->ui->in_text_lproxy_port->setText(project_settings.value("lproxy_port").toString());

    this->ui->in_text_tproxy_username->setText(project_settings.value("tproxy_username").toString());
    this->ui->in_text_tproxy_password->setText(project_settings.value("tproxy_password").toString());
    this->ui->in_text_tproxy_server->setText(project_settings.value("tproxy_server").toString());
    this->ui->in_text_tproxy_port->setText(project_settings.value("tproxy_port").toString());

    this->ui->in_text_sproxy_username->setText(project_settings.value("sproxy_username").toString());
    this->ui->in_text_sproxy_password->setText(project_settings.value("sproxy_password").toString());
    this->ui->in_text_sproxy_server->setText(project_settings.value("sproxy_server").toString());
    this->ui->in_text_sproxy_local_port->setText(project_settings.value("sproxy_local_port").toString());
    this->ui->in_text_sproxy_port->setText(project_settings.value("sproxy_port").toString());
    this->ui->in_text_sproxy_ssh_server->setText(project_settings.value("sproxy_ssh_server").toString());
    
    QString status_vproxy, status_sproxy, status_lproxy, status_tproxy;
    status_lproxy = project_settings.value("status_lproxy").toString();
    status_sproxy = project_settings.value("status_sproxy").toString();
    status_vproxy = project_settings.value("status_vproxy").toString();
    status_tproxy = project_settings.value("status_tproxy").toString();

    if(status_lproxy=="on"){
        this->ui->push_lproxy_on->setVisible(false);
    }else{
        this->ui->push_lproxy_off->setVisible(false);
    }
    if(status_sproxy=="on"){
        this->ui->push_sproxy_on->setVisible(false);
    }else{
        this->ui->push_sproxy_off->setVisible(false);
    }
    if(status_vproxy=="on"){
        this->ui->push_vproxy_on->setVisible(false);
    }else{
        this->ui->push_vproxy_off->setVisible(false);
    }
    if(status_tproxy=="on"){
        this->ui->push_tproxy_on->setVisible(false);
    }else{
        this->ui->push_tproxy_off->setVisible(false);
    }
    this->setToolBoxButtonColor(this->ui->toolbox_main, 1, Qt::red);
}

void AllProxy::on_in_button_browse_clicked()
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setVisible(true);

    QSettings project_settings("project_settings");
    QFile *selected_file;
    QString file_path,previous_path;

    previous_path=project_settings.value("vproxy_path").toString();

    if(previous_path=="")
        previous_path="/home";

    file_path = QFileDialog::getOpenFileName(this,
        tr("Open Server config file (.ovpn)"), previous_path, tr("Text files (*.ovpn)"));

    if( file_path != NULL ){

        selected_file = new QFile(file_path);
        // project_settings.setValue("vproxy_path",file_path);

        this->ui->in_text_vproxy_path->setText(file_path);
    }
}

void AllProxy::display_error(QString error){
    QMessageBox::critical(this,tr("Error"),error);
}

void AllProxy::update_config(QString key, QString value){

    key.replace(QString("/"), QString("\\/"));
    value.replace(QString("/"), QString("\\/"));
    QProcess p;
    QString s = "sed -i s/" + key + "=.*/" + key + "=" + value + "/g config/config.sh";
    qDebug() << "string: " << s ;
    p.start(s);
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
}

void AllProxy::on_in_button_save_nproxy_clicked()
{
    QSettings project_settings("project_settings");
    QString nproxy_server, nproxy_port, nproxy_username, nproxy_password, nproxy_gateway;

    nproxy_server = project_settings.value("nproxy_server").toString();
    nproxy_port = project_settings.value("nproxy_port").toString();
    nproxy_username = project_settings.value("nproxy_username").toString();
    nproxy_password = project_settings.value("nproxy_password").toString();
    nproxy_gateway = project_settings.value("nproxy_gateway").toString();

    if(nproxy_server != this->ui->in_text_nproxy_server->text()){
        qDebug() << "Saving server : " << this->ui->in_text_nproxy_server->text() << " from " << project_settings.value("nproxy_server").toString();
        project_settings.setValue("nproxy_server", this->ui->in_text_nproxy_server->text());
        update_config("nproxy_server", this->ui->in_text_nproxy_server->text());
    }
    if(nproxy_port != this->ui->in_text_nproxy_port->text()){
//        qDebug() << "Saving port : " << this->ui->in_text_nproxy_port->text() << " from " << project_settings.value("nproxy_port").toString();
        project_settings.setValue("nproxy_port", this->ui->in_text_nproxy_port->text());
        update_config("nproxy_port", this->ui->in_text_nproxy_port->text());
    }
    if(nproxy_username != this->ui->in_text_nproxy_username->text() ){
//        qDebug() << "Saving username : " << this->ui->in_text_nproxy_username->text() << " from " << project_settings.value("nproxy_username").toString();
        project_settings.setValue("nproxy_username", this->ui->in_text_nproxy_username->text() );
        update_config("nproxy_username", this->ui->in_text_nproxy_username->text());
    }
    if(nproxy_password != this->ui->in_text_nproxy_password->text()){
//        qDebug() << "Saving password : " << this->ui->in_text_nproxy_password->text() << " from " << project_settings.value("nproxy_password").toString();
        project_settings.setValue("nproxy_password", this->ui->in_text_nproxy_password->text());
        update_config("nproxy_password", this->ui->in_text_nproxy_password->text());
    }
    if(nproxy_gateway != this->ui->in_text_nproxy_gateway->text() ){
//        qDebug() << "Saving gateway : " << this->ui->in_text_nproxy_gateway->text() << " from " << project_settings.value("nproxy_gateway").toString();
        project_settings.setValue("nproxy_gateway", this->ui->in_text_nproxy_gateway->text() );
        update_config("nproxy_gateway", this->ui->in_text_nproxy_gateway->text());
    }

    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "start.sh" << "nproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
}



void AllProxy::on_in_button_save_vproxy_clicked()
{
    QSettings project_settings("project_settings");
    QString vproxy_username, vproxy_password, vproxy_path, vproxy_server, vproxy_port, vproxy_proxy_username, vproxy_proxy_password;

    vproxy_username = project_settings.value("vproxy_username").toString();
    vproxy_password = project_settings.value("vproxy_password").toString();
    vproxy_path = project_settings.value("vproxy_path").toString();
    vproxy_server = project_settings.value("vproxy_server").toString();
    vproxy_port = project_settings.value("vproxy_port").toString();
    vproxy_proxy_username = project_settings.value("vproxy_proxy_username").toString();
    vproxy_proxy_password = project_settings.value("vproxy_proxy_password").toString();


    // qDebug() << this->ui->in_text_vproxy_path->text() << vproxy_path;
    
    if(vproxy_username != this->ui->in_text_vproxy_username->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_vproxy_username->text() << " from " << project_settings.value("vproxy_username").toString();
        project_settings.setValue("vproxy_username", this->ui->in_text_vproxy_username->text());
        update_config("vproxy_username", this->ui->in_text_vproxy_username->text());
    }
    if(vproxy_password != this->ui->in_text_vproxy_password->text()){
//        qDebug() << "Saving vproxy password : " << this->ui->in_text_vproxy_password->text() << " from " << project_settings.value("vproxy_password").toString();
        project_settings.setValue("vproxy_password", this->ui->in_text_vproxy_password->text());
        update_config("vproxy_password", this->ui->in_text_vproxy_password->text());
    }
    if(vproxy_path != this->ui->in_text_vproxy_path->text()){
       qDebug() << "Saving vproxy path : " << this->ui->in_text_vproxy_path->text() << " from " << project_settings.value("vproxy_path").toString();
        project_settings.setValue("vproxy_path", this->ui->in_text_vproxy_path->text());
        update_config("vproxy_path", this->ui->in_text_vproxy_path->text());
    }
    if(vproxy_server != this->ui->in_text_vproxy_server->text()){
       qDebug() << "Saving vproxy path : " << this->ui->in_text_vproxy_server->text() << " from " << project_settings.value("vproxy_server").toString();
        project_settings.setValue("vproxy_server", this->ui->in_text_vproxy_server->text());
        update_config("vproxy_server", this->ui->in_text_vproxy_server->text());
    }
    if(vproxy_port != this->ui->in_text_vproxy_port->text()){
       qDebug() << "Saving vproxy path : " << this->ui->in_text_vproxy_port->text() << " from " << project_settings.value("vproxy_port").toString();
        project_settings.setValue("vproxy_port", this->ui->in_text_vproxy_port->text());
        update_config("vproxy_port", this->ui->in_text_vproxy_port->text());
    }
    if(vproxy_proxy_username != this->ui->in_text_vproxy_proxy_username->text()){
       qDebug() << "Saving vproxy path : " << this->ui->in_text_vproxy_proxy_username->text() << " from " << project_settings.value("vproxy_proxy_username").toString();
        project_settings.setValue("vproxy_proxy_username", this->ui->in_text_vproxy_proxy_username->text());
        update_config("vproxy_proxy_username", this->ui->in_text_vproxy_proxy_username->text());
    }
    if(vproxy_proxy_password != this->ui->in_text_vproxy_proxy_password->text()){
       qDebug() << "Saving vproxy path : " << this->ui->in_text_vproxy_proxy_password->text() << " from " << project_settings.value("vproxy_proxy_password").toString();
        project_settings.setValue("vproxy_proxy_password", this->ui->in_text_vproxy_proxy_password->text());
        update_config("vproxy_proxy_password", this->ui->in_text_vproxy_proxy_password->text());
    }

    this->ui->in_button_save_vproxy->setText("Saved");
    this->ui->in_button_save_vproxy->setVisible(false);
}

void AllProxy::on_in_button_save_tproxy_clicked()
{
    QSettings project_settings("project_settings");
    QString tproxy_username, tproxy_password, tproxy_server, tproxy_port;

    tproxy_username = project_settings.value("tproxy_username").toString();
    tproxy_password = project_settings.value("tproxy_password").toString();
    tproxy_server = project_settings.value("tproxy_server").toString();
    tproxy_port = project_settings.value("tproxy_port").toString();


    if(tproxy_username != this->ui->in_text_tproxy_username->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_tproxy_username->text() << " from " << project_settings.value("tproxy_username").toString();
        project_settings.setValue("tproxy_username", this->ui->in_text_tproxy_username->text());
        update_config("tproxy_username", this->ui->in_text_tproxy_username->text());
    }
    if(tproxy_password != this->ui->in_text_tproxy_password->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_tproxy_password->text() << " from " << project_settings.value("tproxy_password").toString();
        project_settings.setValue("tproxy_password", this->ui->in_text_tproxy_password->text());
        update_config("tproxy_password", this->ui->in_text_tproxy_password->text());
    }
    if(tproxy_server != this->ui->in_text_tproxy_server->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_tproxy_server->text() << " from " << project_settings.value("tproxy_server").toString();
        project_settings.setValue("tproxy_server", this->ui->in_text_tproxy_server->text());
        update_config("tproxy_server", this->ui->in_text_tproxy_server->text());
    }
    if(tproxy_port != this->ui->in_text_tproxy_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_tproxy_port->text() << " from " << project_settings.value("tproxy_port").toString();
        project_settings.setValue("tproxy_port", this->ui->in_text_tproxy_port->text());
        update_config("tproxy_port", this->ui->in_text_tproxy_port->text());
    }
    this->ui->in_button_save_tproxy->setText("Saved");
    this->ui->in_button_save_tproxy->setVisible(false);
}

void AllProxy::on_in_button_save_lproxy_clicked()
{
    QSettings project_settings("project_settings");
    QString lproxy_local_port, lproxy_server, lproxy_port;

    lproxy_local_port = project_settings.value("lproxy_local_port").toString();
    lproxy_server = project_settings.value("lproxy_server").toString();
    lproxy_port = project_settings.value("lproxy_port").toString();

    if(lproxy_local_port != this->ui->in_text_lproxy_local_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_lproxy_local_port->text() << " from " << project_settings.value("lproxy_local_port").toString();
        project_settings.setValue("lproxy_local_port", this->ui->in_text_lproxy_local_port->text());
        update_config("lproxy_local_port", this->ui->in_text_lproxy_local_port->text());
    }
    if(lproxy_server != this->ui->in_text_lproxy_server->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_lproxy_server->text() << " from " << project_settings.value("lproxy_server").toString();
        project_settings.setValue("lproxy_server", this->ui->in_text_lproxy_server->text());
        update_config("lproxy_server", this->ui->in_text_lproxy_server->text());
    }
    if(lproxy_port != this->ui->in_text_lproxy_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_lproxy_port->text() << " from " << project_settings.value("lproxy_port").toString();
        project_settings.setValue("lproxy_port", this->ui->in_text_lproxy_port->text());
        update_config("lproxy_port", this->ui->in_text_lproxy_port->text());
    }
    this->ui->in_button_save_lproxy->setText("Saved");
    this->ui->in_button_save_lproxy->setVisible(false);
    
}

void AllProxy::on_in_button_save_sproxy_clicked()
{
    QSettings project_settings("project_settings");
    QString sproxy_username, sproxy_password, sproxy_server, sproxy_local_port, sproxy_port, sproxy_ssh_server;

    sproxy_username = project_settings.value("sproxy_username").toString();
    sproxy_password = project_settings.value("sproxy_password").toString();
    sproxy_server = project_settings.value("sproxy_server").toString();
    sproxy_local_port = project_settings.value("sproxy_local_port").toString();
    sproxy_port = project_settings.value("sproxy_port").toString();
    sproxy_ssh_server = project_settings.value("sproxy_ssh_server").toString();


    if(sproxy_username != this->ui->in_text_sproxy_username->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_username->text() << " from " << project_settings.value("sproxy_username").toString();
        project_settings.setValue("sproxy_username", this->ui->in_text_sproxy_username->text());
        update_config("sproxy_username", this->ui->in_text_sproxy_username->text());
    }
    if(sproxy_password != this->ui->in_text_sproxy_password->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_password->text() << " from " << project_settings.value("sproxy_password").toString();
        project_settings.setValue("sproxy_password", this->ui->in_text_sproxy_password->text());
        update_config("sproxy_password", this->ui->in_text_sproxy_password->text());
    }
    if(sproxy_server != this->ui->in_text_sproxy_server->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_server->text() << " from " << project_settings.value("sproxy_server").toString();
        project_settings.setValue("sproxy_server", this->ui->in_text_sproxy_server->text());
        update_config("sproxy_server", this->ui->in_text_sproxy_server->text());
    }
    if(sproxy_local_port != this->ui->in_text_sproxy_local_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_local_port->text() << " from " << project_settings.value("sproxy_local_port").toString();
        project_settings.setValue("sproxy_local_port", this->ui->in_text_sproxy_local_port->text());
        update_config("sproxy_local_port", this->ui->in_text_sproxy_local_port->text());
    }
    if(sproxy_port != this->ui->in_text_sproxy_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_port->text() << " from " << project_settings.value("sproxy_port").toString();
        project_settings.setValue("sproxy_port", this->ui->in_text_sproxy_port->text());
        update_config("sproxy_port", this->ui->in_text_sproxy_port->text());
    }
    if(sproxy_ssh_server != this->ui->in_text_sproxy_ssh_server->text()){
        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_ssh_server->text() << " from " << project_settings.value("sproxy_ssh_server").toString();
        project_settings.setValue("sproxy_ssh_server", this->ui->in_text_sproxy_ssh_server->text());
        update_config("sproxy_ssh_server", this->ui->in_text_sproxy_ssh_server->text());
    }
    this->ui->in_button_save_sproxy->setText("Saved");
    this->ui->in_button_save_sproxy->setVisible(false);
    
}

void AllProxy::on_push_tproxy_off_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "stop.sh" << "tproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_tproxy_off->setVisible(false);
    this->ui->push_tproxy_on->setVisible(true);
    
}

void AllProxy::on_push_tproxy_on_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "start.sh" << "tproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_tproxy_off->setVisible(false);
    this->ui->push_tproxy_on->setVisible(true);
}

void AllProxy::on_push_lproxy_off_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "stop.sh" << "lproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_lproxy_off->setVisible(false);
    this->ui->push_lproxy_on->setVisible(true);
}

void AllProxy::on_push_lproxy_on_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "start.sh" << "lproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_lproxy_off->setVisible(true);
    this->ui->push_lproxy_on->setVisible(false);
}

void AllProxy::on_push_sproxy_off_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "stop.sh" << "sproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_sproxy_off->setVisible(false);
    this->ui->push_sproxy_on->setVisible(true);
}

void AllProxy::on_push_sproxy_on_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "start.sh" << "sproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_sproxy_off->setVisible(true);
    this->ui->push_sproxy_on->setVisible(false);
}

void AllProxy::on_push_vproxy_off_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "stop.sh" << "vproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_vproxy_off->setVisible(false);
    this->ui->push_vproxy_on->setVisible(true);
}

void AllProxy::on_push_vproxy_on_clicked()
{
    QProcess p;
    QStringList args;

    p.start("gksudo", QStringList() << "bash" << "start.sh" << "vproxy");
    if (p.state() == QProcess::Running)
        p.waitForFinished(-1);
    p.waitForFinished(-1);
    this->ui->push_vproxy_off->setVisible(true);
    this->ui->push_vproxy_on->setVisible(false);
}

void AllProxy::on_in_text_nproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setVisible(true);
}

void AllProxy::on_in_text_nproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setVisible(true);
}

void AllProxy::on_in_text_nproxy_gateway_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setVisible(true);
}

void AllProxy::on_in_text_nproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setVisible(true);
}

void AllProxy::on_in_text_nproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setVisible(true);
}

void AllProxy::on_in_text_vproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setVisible(true);

}

void AllProxy::on_in_text_vproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setVisible(true);

}

void AllProxy::on_in_text_sproxy_local_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setVisible(true);
}

void AllProxy::on_in_text_sproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setVisible(true);
}

void AllProxy::on_in_text_sproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setVisible(true);
}

void AllProxy::on_in_text_sproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setVisible(true);
}

void AllProxy::on_in_text_sproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setVisible(true);

}

void AllProxy::on_in_text_lproxy_local_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_lproxy->setText("Save Configuration");
    this->ui->in_button_save_lproxy->setVisible(true);
}

void AllProxy::on_in_text_lproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_lproxy->setText("Save Configuration");
    this->ui->in_button_save_lproxy->setVisible(true);
}

void AllProxy::on_in_text_lproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_lproxy->setText("Save Configuration");
    this->ui->in_button_save_lproxy->setVisible(true);
}

void AllProxy::on_in_text_tproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setVisible(true);
}

void AllProxy::on_in_text_tproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setVisible(true);
}

void AllProxy::on_in_text_tproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setVisible(true);
}

void AllProxy::on_in_text_tproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setVisible(true);
}

void AllProxy::on_in_text_sproxy_ssh_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setVisible(true);

}

void AllProxy::on_in_text_vproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setVisible(true);

}

void AllProxy::on_in_text_vproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setVisible(true);

}

void AllProxy::on_in_text_vproxy_proxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setVisible(true);

}

void AllProxy::on_in_text_vproxy_proxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setVisible(true);

}

void AllProxy::on_browse_dproxy_clicked()
{
    QFile *selected_file;
    QString file_path,previous_path;

    if(previous_path=="")
        previous_path="/home";

    file_path = QFileDialog::getOpenFileName(this,
        tr("Any file"), previous_path, tr("All files (*)"));

    if( file_path != NULL ){

        selected_file = new QFile(file_path);

        this->ui->in_dproxy_filepath->setText(file_path);
    }


}

void AllProxy::on_push_dproxy_download_clicked()
{
    QProcess p;

    p.startDetached("pycurl-download", QStringList() << this->ui->in_dproxy_url->text() << this->ui->in_dproxy_filepath->text());
//    if (p.state() == QProcess::Running)
//        p.
//        p.waitForFinished(-1);

//    p.waitForFinished(-1);
}
