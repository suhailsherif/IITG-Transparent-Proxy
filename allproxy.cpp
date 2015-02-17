#include "allproxy.h"
#include "ui_allproxy.h"
#include "constants.h"

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

AllProxy::AllProxy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllProxy)
{

    ui->setupUi(this);
    this->load_configuration();

//    ui->group_proxy->hide();
//    ui->group_vpn->hide();
//    ui->group_tproxy->hide();

}

AllProxy::~AllProxy()
{
    delete ui;
}

void AllProxy::load_configuration(){
    QSettings project_settings("project_settings");

//    qDebug() << project_settings.fileName();
//    qDebug() << "Gateway : " << project_settings.value("proxy_gateway").toString();
//    qDebug() << "Server : " << project_settings.value("proxy_server").toString();
//    qDebug() << "Port : " << project_settings.value("proxy_port").toString();
//    qDebug() << "Username : " << project_settings.value("proxy_username").toString();
//    qDebug() << "Password : " << project_settings.value("proxy_password").toString();
//    qDebug() << "VPN Username : " << project_settings.value("vpn_username").toString();
//    qDebug() << "VPN password : " << project_settings.value("vpn_password").toString();


    this->ui->in_text_proxy_gateway->setText(project_settings.value("proxy_gateway").toString());
    this->ui->in_text_proxy_server->setText(project_settings.value("proxy_server").toString());
    this->ui->in_text_proxy_port->setText(project_settings.value("proxy_port").toString());
    this->ui->in_text_proxy_username->setText(project_settings.value("proxy_username").toString());
    this->ui->in_text_proxy_password->setText(project_settings.value("proxy_password").toString());
    this->ui->in_text_vpn_username->setText(project_settings.value("vpn_username").toString());
    this->ui->in_text_vpn_password->setText(project_settings.value("vpn_password").toString());
    this->ui->in_text_vpn_path->setText(project_settings.value("vpn_path").toString());



}

void AllProxy::on_in_button_browse_clicked()
{
    this->ui->in_button_save_vpn->setText("Save Configuration");
    this->ui->in_button_save_vpn->setEnabled(true);

    QSettings project_settings("project_settings");
    QFile *selected_file;
    QString file_path,previous_path;

    previous_path=project_settings.value("vpn_path").toString();

    if(previous_path=="")
        previous_path="/home";

    file_path = QFileDialog::getOpenFileName(this,
        tr("Open Server config file (.ovpn)"), previous_path, tr("Text files (*.ovpn)"));

    if( file_path != NULL ){

        selected_file = new QFile(file_path);
        project_settings.setValue("vpn_path",file_path);

        this->ui->in_text_vpn_path->setText(file_path);
    }
}

void AllProxy::display_error(QString error){
    QMessageBox::critical(this,tr("Error"),error);
}

void AllProxy::on_in_button_save_proxy_clicked()
{
    QSettings project_settings("project_settings");
    QString proxy_server, proxy_port, proxy_username, proxy_password, proxy_gateway;

    proxy_server = project_settings.value("proxy_server").toString();
    proxy_port = project_settings.value("proxy_port").toString();
    proxy_username = project_settings.value("proxy_username").toString();
    proxy_password = project_settings.value("proxy_password").toString();
    proxy_gateway = project_settings.value("proxy_gateway").toString();

    if(proxy_server != this->ui->in_text_proxy_server->text()){
//        qDebug() << "Saving server : " << this->ui->in_text_proxy_server->text() << " from " << project_settings.value("proxy_server").toString();
        project_settings.setValue("proxy_server", this->ui->in_text_proxy_server->text());
    }
    if(proxy_port != this->ui->in_text_proxy_port->text()){
//        qDebug() << "Saving port : " << this->ui->in_text_proxy_port->text() << " from " << project_settings.value("proxy_port").toString();
        project_settings.setValue("proxy_port", this->ui->in_text_proxy_port->text());
    }
    if(proxy_username != this->ui->in_text_proxy_username->text() ){
//        qDebug() << "Saving username : " << this->ui->in_text_proxy_username->text() << " from " << project_settings.value("proxy_username").toString();
        project_settings.setValue("proxy_username", this->ui->in_text_proxy_username->text() );
    }
    if(proxy_password != this->ui->in_text_proxy_password->text()){
//        qDebug() << "Saving password : " << this->ui->in_text_proxy_password->text() << " from " << project_settings.value("proxy_password").toString();
        project_settings.setValue("proxy_password", this->ui->in_text_proxy_password->text());
    }
    if(proxy_gateway != this->ui->in_text_proxy_gateway->text() ){
//        qDebug() << "Saving gateway : " << this->ui->in_text_proxy_gateway->text() << " from " << project_settings.value("proxy_gateway").toString();
        project_settings.setValue("proxy_gateway", this->ui->in_text_proxy_gateway->text() );
    }

    this->ui->in_button_save_proxy->setText("Saved");
    this->ui->in_button_save_proxy->setEnabled(false);
}

void AllProxy::on_in_text_proxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_proxy->setText("Save Configuration");
    this->ui->in_button_save_proxy->setEnabled(true);
}

void AllProxy::on_in_text_proxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_proxy->setText("Save Configuration");
    this->ui->in_button_save_proxy->setEnabled(true);
}

void AllProxy::on_in_text_proxy_gateway_textChanged(const QString &arg1)
{
    this->ui->in_button_save_proxy->setText("Save Configuration");
    this->ui->in_button_save_proxy->setEnabled(true);
}

void AllProxy::on_in_text_proxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_proxy->setText("Save Configuration");
    this->ui->in_button_save_proxy->setEnabled(true);
}

void AllProxy::on_in_text_proxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_proxy->setText("Save Configuration");
    this->ui->in_button_save_proxy->setEnabled(true);
}



void AllProxy::on_in_button_save_vpn_clicked()
{
    QSettings project_settings("project_settings");
    QString vpn_username, vpn_password, vpn_path;

    vpn_username = project_settings.value("vpn_username").toString();
    vpn_password = project_settings.value("vpn_password").toString();
    vpn_path = project_settings.value("vpn_path").toString();


    if(vpn_username != this->ui->in_text_vpn_username->text()){
//        qDebug() << "Saving vpn username : " << this->ui->in_text_vpn_username->text() << " from " << project_settings.value("vpn_username").toString();
        project_settings.setValue("vpn_username", this->ui->in_text_vpn_username->text());
    }
    if(vpn_password != this->ui->in_text_vpn_password->text()){
//        qDebug() << "Saving vpn password : " << this->ui->in_text_vpn_password->text() << " from " << project_settings.value("vpn_password").toString();
        project_settings.setValue("vpn_password", this->ui->in_text_vpn_password->text());
    }
    if(vpn_path != this->ui->in_text_vpn_path->text()){
//        qDebug() << "Saving vpn path : " << this->ui->in_text_vpn_path->text() << " from " << project_settings.value("vpn_path").toString();
        project_settings.setValue("vpn_path", this->ui->in_text_vpn_path->text());
    }

    this->ui->in_button_save_vpn->setText("Saved");
    this->ui->in_button_save_vpn->setEnabled(false);
}

void AllProxy::on_in_text_vpn_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vpn->setText("Save Configuration");
    this->ui->in_button_save_vpn->setEnabled(true);

}

void AllProxy::on_in_text_vpn_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vpn->setText("Save Configuration");
    this->ui->in_button_save_vpn->setEnabled(true);

}

void AllProxy::on_push_tproxy_off_clicked()
{

}

void AllProxy::on_push_tproxy_on_clicked()
{

}
