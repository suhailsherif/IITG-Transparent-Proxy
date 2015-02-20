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
    this->load_configuration();

}

AllProxy::~AllProxy()
{
    delete ui;
}

void AllProxy::load_configuration(){
    QSettings project_settings("project_settings");

//    qDebug() << project_settings.fileName();
//    qDebug() << "Gateway : " << project_settings.value("nproxy_gateway").toString();
//    qDebug() << "Server : " << project_settings.value("nproxy_server").toString();
//    qDebug() << "Port : " << project_settings.value("nproxy_port").toString();
//    qDebug() << "Username : " << project_settings.value("nproxy_username").toString();
//    qDebug() << "Password : " << project_settings.value("nproxy_password").toString();
//    qDebug() << "Vproxy Username : " << project_settings.value("vproxy_username").toString();
//    qDebug() << "Vproxy password : " << project_settings.value("vproxy_password").toString();


    this->ui->in_text_nproxy_gateway->setText(project_settings.value("nproxy_gateway").toString());
    this->ui->in_text_nproxy_server->setText(project_settings.value("nproxy_server").toString());
    this->ui->in_text_nproxy_port->setText(project_settings.value("nproxy_port").toString());
    this->ui->in_text_nproxy_username->setText(project_settings.value("nproxy_username").toString());
    this->ui->in_text_nproxy_password->setText(project_settings.value("nproxy_password").toString());

    this->ui->in_text_vproxy_username->setText(project_settings.value("vproxy_username").toString());
    this->ui->in_text_vproxy_password->setText(project_settings.value("vproxy_password").toString());
    this->ui->in_text_vproxy_path->setText(project_settings.value("vproxy_path").toString());





}

void AllProxy::on_in_button_browse_clicked()
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setEnabled(true);

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
        project_settings.setValue("vproxy_path",file_path);

        this->ui->in_text_vproxy_path->setText(file_path);
    }
}

void AllProxy::display_error(QString error){
    QMessageBox::critical(this,tr("Error"),error);
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
//        qDebug() << "Saving server : " << this->ui->in_text_nnproxy_server->text() << " from " << project_settings.value("nproxy_server").toString();
        project_settings.setValue("nproxy_server", this->ui->in_text_nproxy_server->text());
    }
    if(nproxy_port != this->ui->in_text_nproxy_port->text()){
//        qDebug() << "Saving port : " << this->ui->in_text_nproxy_port->text() << " from " << project_settings.value("nproxy_port").toString();
        project_settings.setValue("nproxy_port", this->ui->in_text_nproxy_port->text());
    }
    if(nproxy_username != this->ui->in_text_nproxy_username->text() ){
//        qDebug() << "Saving username : " << this->ui->in_text_nproxy_username->text() << " from " << project_settings.value("nproxy_username").toString();
        project_settings.setValue("nproxy_username", this->ui->in_text_nproxy_username->text() );
    }
    if(nproxy_password != this->ui->in_text_nproxy_password->text()){
//        qDebug() << "Saving password : " << this->ui->in_text_nproxy_password->text() << " from " << project_settings.value("nproxy_password").toString();
        project_settings.setValue("nproxy_password", this->ui->in_text_nproxy_password->text());
    }
    if(nproxy_gateway != this->ui->in_text_nproxy_gateway->text() ){
//        qDebug() << "Saving gateway : " << this->ui->in_text_nproxy_gateway->text() << " from " << project_settings.value("nproxy_gateway").toString();
        project_settings.setValue("nproxy_gateway", this->ui->in_text_nproxy_gateway->text() );
    }

    this->ui->in_button_save_nproxy->setText("Saved");
    this->ui->in_button_save_nproxy->setEnabled(false);
}



void AllProxy::on_in_button_save_vproxy_clicked()
{
    QSettings project_settings("project_settings");
    QString vproxy_username, vproxy_password, vproxy_path;

    vproxy_username = project_settings.value("vproxy_username").toString();
    vproxy_password = project_settings.value("vproxy_password").toString();
    vproxy_path = project_settings.value("vproxy_path").toString();


    
    if(vproxy_username != this->ui->in_text_vproxy_username->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_vproxy_username->text() << " from " << project_settings.value("vproxy_username").toString();
        project_settings.setValue("vproxy_username", this->ui->in_text_vproxy_username->text());
    }
    if(vproxy_password != this->ui->in_text_vproxy_password->text()){
//        qDebug() << "Saving vproxy password : " << this->ui->in_text_vproxy_password->text() << " from " << project_settings.value("vproxy_password").toString();
        project_settings.setValue("vproxy_password", this->ui->in_text_vproxy_password->text());
    }
    if(vproxy_path != this->ui->in_text_vproxy_path->text()){
//        qDebug() << "Saving vproxy path : " << this->ui->in_text_vproxy_path->text() << " from " << project_settings.value("vproxy_path").toString();
        project_settings.setValue("vproxy_path", this->ui->in_text_vproxy_path->text());
    }

    this->ui->in_button_save_vproxy->setText("Saved");
    this->ui->in_button_save_vproxy->setEnabled(false);
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
        project_settings.setValue("tproxy_username", this->ui->in_text_vproxy_username->text());
    }
    if(tproxy_password != this->ui->in_text_tproxy_password->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_tproxy_password->text() << " from " << project_settings.value("tproxy_password").toString();
        project_settings.setValue("tproxy_password", this->ui->in_text_vproxy_username->text());
    }
    if(tproxy_server != this->ui->in_text_tproxy_server->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_tproxy_server->text() << " from " << project_settings.value("tproxy_server").toString();
        project_settings.setValue("tproxy_server", this->ui->in_text_vproxy_username->text());
    }
    if(tproxy_port != this->ui->in_text_tproxy_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_tproxy_port->text() << " from " << project_settings.value("tproxy_port").toString();
        project_settings.setValue("tproxy_port", this->ui->in_text_vproxy_username->text());
    }
    this->ui->in_button_save_tproxy->setText("Saved");
    this->ui->in_button_save_tproxy->setEnabled(false);
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
        project_settings.setValue("lproxy_local_port", this->ui->in_text_vproxy_username->text());
    }
    if(lproxy_server != this->ui->in_text_lproxy_server->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_lproxy_server->text() << " from " << project_settings.value("lproxy_server").toString();
        project_settings.setValue("lproxy_server", this->ui->in_text_vproxy_username->text());
    }
    if(lproxy_port != this->ui->in_text_lproxy_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_lproxy_port->text() << " from " << project_settings.value("lproxy_port").toString();
        project_settings.setValue("lproxy_port", this->ui->in_text_vproxy_username->text());
    }
    this->ui->in_button_save_lproxy->setText("Saved");
    this->ui->in_button_save_lproxy->setEnabled(false);
    
}

void AllProxy::on_in_button_save_sproxy_clicked()
{
    QSettings project_settings("project_settings");
    QString sproxy_username, sproxy_password, sproxy_server, sproxy_local_port, sproxy_port;

    sproxy_username = project_settings.value("sproxy_username").toString();
    sproxy_password = project_settings.value("sproxy_password").toString();
    sproxy_server = project_settings.value("sproxy_server").toString();
    sproxy_local_port = project_settings.value("sproxy_local_port").toString();
    sproxy_port = project_settings.value("sproxy_port").toString();

    if(sproxy_username != this->ui->in_text_sproxy_username->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_username->text() << " from " << project_settings.value("sproxy_username").toString();
        project_settings.setValue("sproxy_username", this->ui->in_text_vproxy_username->text());
    }
    if(sproxy_password != this->ui->in_text_sproxy_password->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_password->text() << " from " << project_settings.value("sproxy_password").toString();
        project_settings.setValue("sproxy_password", this->ui->in_text_vproxy_username->text());
    }
    if(sproxy_server != this->ui->in_text_sproxy_server->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_server->text() << " from " << project_settings.value("sproxy_server").toString();
        project_settings.setValue("sproxy_server", this->ui->in_text_vproxy_username->text());
    }
    if(sproxy_local_port != this->ui->in_text_sproxy_local_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_local_port->text() << " from " << project_settings.value("sproxy_local_port").toString();
        project_settings.setValue("sproxy_local_port", this->ui->in_text_vproxy_username->text());
    }
    if(sproxy_port != this->ui->in_text_sproxy_port->text()){
//        qDebug() << "Saving vproxy username : " << this->ui->in_text_sproxy_port->text() << " from " << project_settings.value("sproxy_port").toString();
        project_settings.setValue("sproxy_port", this->ui->in_text_vproxy_username->text());
    }
    this->ui->in_button_save_sproxy->setText("Saved");
    this->ui->in_button_save_sproxy->setEnabled(false);
    
}

void AllProxy::on_push_tproxy_off_clicked()
{

}

void AllProxy::on_push_tproxy_on_clicked()
{

}

void AllProxy::on_push_lproxy_off_clicked()
{

}

void AllProxy::on_push_lproxy_on_clicked()
{

}

void AllProxy::on_push_sproxy_off_clicked()
{

}

void AllProxy::on_push_sproxy_on_clicked()
{

}

void AllProxy::on_push_vproxy_off_clicked()
{

}

void AllProxy::on_push_vproxy_on_clicked()
{

}

void AllProxy::on_in_text_nproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setEnabled(true);
}

void AllProxy::on_in_text_nproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setEnabled(true);
}

void AllProxy::on_in_text_nproxy_gateway_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setEnabled(true);
}

void AllProxy::on_in_text_nproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setEnabled(true);
}

void AllProxy::on_in_text_nproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_nproxy->setText("Save Configuration");
    this->ui->in_button_save_nproxy->setEnabled(true);
}

void AllProxy::on_in_text_vproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setEnabled(true);

}

void AllProxy::on_in_text_vproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_vproxy->setText("Save Configuration");
    this->ui->in_button_save_vproxy->setEnabled(true);

}

void AllProxy::on_in_text_sproxy_local_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setEnabled(true);
}

void AllProxy::on_in_text_sproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setEnabled(true);
}

void AllProxy::on_in_text_sproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setEnabled(true);
}

void AllProxy::on_in_text_sproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setEnabled(true);
}

void AllProxy::on_in_text_sproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_sproxy->setText("Save Configuration");
    this->ui->in_button_save_sproxy->setEnabled(true);

}

void AllProxy::on_in_text_lproxy_local_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_lproxy->setText("Save Configuration");
    this->ui->in_button_save_lproxy->setEnabled(true);
}

void AllProxy::on_in_text_lproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_lproxy->setText("Save Configuration");
    this->ui->in_button_save_lproxy->setEnabled(true);
}

void AllProxy::on_in_text_lproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_lproxy->setText("Save Configuration");
    this->ui->in_button_save_lproxy->setEnabled(true);
}

void AllProxy::on_in_text_tproxy_server_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setEnabled(true);
}

void AllProxy::on_in_text_tproxy_username_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setEnabled(true);
}

void AllProxy::on_in_text_tproxy_port_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setEnabled(true);
}

void AllProxy::on_in_text_tproxy_password_textChanged(const QString &arg1)
{
    this->ui->in_button_save_tproxy->setText("Save Configuration");
    this->ui->in_button_save_tproxy->setEnabled(true);
}
