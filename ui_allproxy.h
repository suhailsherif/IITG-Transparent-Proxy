/********************************************************************************
** Form generated from reading UI file 'allproxy.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLPROXY_H
#define UI_ALLPROXY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllProxy
{
public:
    QWidget *widget_main;
    QToolBox *toolbox_main;
    QWidget *page_nproxy;
    QGroupBox *group_proxy;
    QLineEdit *in_text_nproxy_password;
    QLineEdit *in_text_nproxy_port;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *in_text_nproxy_server;
    QLineEdit *in_text_nproxy_username;
    QLineEdit *in_text_nproxy_gateway;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QPushButton *in_button_save_nproxy;
    QWidget *page_cproxy;
    QTextEdit *textEdit;
    QPushButton *in_button_cproxy_send;
    QLabel *in_text_vproxy_path_5;
    QLineEdit *in_text_cproxy_dip;
    QPushButton *in_button_cproxy_change_settings;
    QWidget *page_vproxy;
    QGroupBox *group_vpn;
    QPushButton *in_button_save_vproxy;
    QLineEdit *in_text_vproxy_password;
    QLabel *label_7;
    QLabel *in_text_vproxy_path;
    QLineEdit *in_text_vproxy_username;
    QLabel *label_6;
    QPushButton *in_button_browse;
    QLabel *label_5;
    QLineEdit *in_text_vproxy_port;
    QLineEdit *in_text_vproxy_server;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *in_text_vproxy_proxy_username;
    QLineEdit *in_text_vproxy_proxy_password;
    QWidget *page_dproxy;
    QLineEdit *in_dproxy_url;
    QLineEdit *in_dproxy_filepath;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *browse_dproxy;
    QPushButton *push_dproxy_download;
    QProgressBar *dproxy_progress;
    QWidget *page_sproxy;
    QLineEdit *in_text_sproxy_local_port;
    QLineEdit *in_text_sproxy_server;
    QLineEdit *in_text_sproxy_username;
    QLineEdit *in_text_sproxy_port;
    QLineEdit *in_text_sproxy_password;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *in_button_save_sproxy;
    QLineEdit *in_text_sproxy_ssh_server;
    QLabel *label_21;
    QWidget *page_lproxy;
    QLabel *label_14;
    QLineEdit *in_text_lproxy_local_port;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *in_text_lproxy_server;
    QLineEdit *in_text_lproxy_port;
    QPushButton *in_button_save_lproxy;
    QLineEdit *in_text_lproxy_username;
    QLineEdit *in_text_lproxy_password;
    QLabel *label_28;
    QLabel *label_29;
    QWidget *page_tproxy;
    QLineEdit *in_text_tproxy_server;
    QLineEdit *in_text_tproxy_port;
    QLineEdit *in_text_tproxy_username;
    QLineEdit *in_text_tproxy_password;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *in_button_save_tproxy;
    QWidget *page_new;
    QPushButton *switch_tproxy;
    QPushButton *switch_lproxy;
    QPushButton *switch_sproxy;
    QPushButton *switch_vproxy;
    QPushButton *switch_cproxy;

    void setupUi(QMainWindow *AllProxy)
    {
        if (AllProxy->objectName().isEmpty())
            AllProxy->setObjectName(QStringLiteral("AllProxy"));
        AllProxy->setEnabled(true);
        AllProxy->resize(671, 538);
        AllProxy->setStyleSheet(QLatin1String("QMainWindow#Allproxy{\n"
"     background-color: rgba(50, 255, 50, 20);\n"
" }"));
        widget_main = new QWidget(AllProxy);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setStyleSheet(QLatin1String("QWidget#widget_main{\n"
"	rgb(170, 170, 255);\n"
"}"));
        toolbox_main = new QToolBox(widget_main);
        toolbox_main->setObjectName(QStringLiteral("toolbox_main"));
        toolbox_main->setGeometry(QRect(10, 10, 651, 481));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        toolbox_main->setFont(font);
        toolbox_main->setStyleSheet(QLatin1String("QToolBox::tab {\n"
"background-color: rgba(180, 180, 180, 150);\n"
"border-radius: 3px;\n"
"color: black;\n"
"}\n"
"\n"
"QToolBox::tab:selected { \n"
"background-color: rgba(50, 50, 50, 150);\n"
"font: italic;\n"
"color: white;\n"
"}\n"
""));
        toolbox_main->setFrameShape(QFrame::NoFrame);
        toolbox_main->setFrameShadow(QFrame::Sunken);
        page_nproxy = new QWidget();
        page_nproxy->setObjectName(QStringLiteral("page_nproxy"));
        page_nproxy->setGeometry(QRect(0, 0, 651, 233));
        page_nproxy->setStyleSheet(QStringLiteral(""));
        group_proxy = new QGroupBox(page_nproxy);
        group_proxy->setObjectName(QStringLiteral("group_proxy"));
        group_proxy->setGeometry(QRect(0, 0, 601, 171));
        group_proxy->setAutoFillBackground(false);
        in_text_nproxy_password = new QLineEdit(group_proxy);
        in_text_nproxy_password->setObjectName(QStringLiteral("in_text_nproxy_password"));
        in_text_nproxy_password->setGeometry(QRect(130, 90, 131, 27));
        in_text_nproxy_password->setMaxLength(20);
        in_text_nproxy_password->setEchoMode(QLineEdit::Password);
        in_text_nproxy_port = new QLineEdit(group_proxy);
        in_text_nproxy_port->setObjectName(QStringLiteral("in_text_nproxy_port"));
        in_text_nproxy_port->setGeometry(QRect(420, 0, 71, 27));
        in_text_nproxy_port->setMaxLength(5);
        label_4 = new QLabel(group_proxy);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 100, 121, 20));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);
        label_3 = new QLabel(group_proxy);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 0, 81, 20));
        label_3->setFont(font1);
        in_text_nproxy_server = new QLineEdit(group_proxy);
        in_text_nproxy_server->setObjectName(QStringLiteral("in_text_nproxy_server"));
        in_text_nproxy_server->setGeometry(QRect(130, 0, 113, 27));
        in_text_nproxy_server->setMaxLength(20);
        in_text_nproxy_username = new QLineEdit(group_proxy);
        in_text_nproxy_username->setObjectName(QStringLiteral("in_text_nproxy_username"));
        in_text_nproxy_username->setGeometry(QRect(130, 60, 131, 27));
        in_text_nproxy_username->setMaxLength(20);
        in_text_nproxy_username->setEchoMode(QLineEdit::Normal);
        in_text_nproxy_gateway = new QLineEdit(group_proxy);
        in_text_nproxy_gateway->setObjectName(QStringLiteral("in_text_nproxy_gateway"));
        in_text_nproxy_gateway->setGeometry(QRect(420, 70, 113, 27));
        in_text_nproxy_gateway->setMaxLength(20);
        in_text_nproxy_gateway->setEchoMode(QLineEdit::Normal);
        label = new QLabel(group_proxy);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 91, 17));
        label->setFont(font1);
        label_2 = new QLabel(group_proxy);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 70, 121, 17));
        label_2->setFont(font1);
        label_8 = new QLabel(group_proxy);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(290, 70, 131, 20));
        label_8->setFont(font1);
        in_button_save_nproxy = new QPushButton(group_proxy);
        in_button_save_nproxy->setObjectName(QStringLiteral("in_button_save_nproxy"));
        in_button_save_nproxy->setGeometry(QRect(260, 140, 141, 27));
        toolbox_main->addItem(page_nproxy, QStringLiteral("Nproxy                                                                                                                                     - Normal Proxy"));
        page_cproxy = new QWidget();
        page_cproxy->setObjectName(QStringLiteral("page_cproxy"));
        page_cproxy->setGeometry(QRect(0, 0, 651, 233));
        textEdit = new QTextEdit(page_cproxy);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(3, 120, 411, 78));
        in_button_cproxy_send = new QPushButton(page_cproxy);
        in_button_cproxy_send->setObjectName(QStringLiteral("in_button_cproxy_send"));
        in_button_cproxy_send->setGeometry(QRect(440, 140, 161, 27));
        in_text_vproxy_path_5 = new QLabel(page_cproxy);
        in_text_vproxy_path_5->setObjectName(QStringLiteral("in_text_vproxy_path_5"));
        in_text_vproxy_path_5->setGeometry(QRect(10, 10, 21, 31));
        in_text_cproxy_dip = new QLineEdit(page_cproxy);
        in_text_cproxy_dip->setObjectName(QStringLiteral("in_text_cproxy_dip"));
        in_text_cproxy_dip->setGeometry(QRect(30, 10, 131, 27));
        in_button_cproxy_change_settings = new QPushButton(page_cproxy);
        in_button_cproxy_change_settings->setObjectName(QStringLiteral("in_button_cproxy_change_settings"));
        in_button_cproxy_change_settings->setGeometry(QRect(360, 10, 251, 27));
        toolbox_main->addItem(page_cproxy, QStringLiteral("Cproxy                                                                                                                                                      - Chat"));
        page_vproxy = new QWidget();
        page_vproxy->setObjectName(QStringLiteral("page_vproxy"));
        page_vproxy->setGeometry(QRect(0, 0, 651, 233));
        page_vproxy->setStyleSheet(QStringLiteral(""));
        group_vpn = new QGroupBox(page_vproxy);
        group_vpn->setObjectName(QStringLiteral("group_vpn"));
        group_vpn->setGeometry(QRect(10, 11, 631, 171));
        in_button_save_vproxy = new QPushButton(group_vpn);
        in_button_save_vproxy->setObjectName(QStringLiteral("in_button_save_vproxy"));
        in_button_save_vproxy->setGeometry(QRect(270, 140, 161, 27));
        in_text_vproxy_password = new QLineEdit(group_vpn);
        in_text_vproxy_password->setObjectName(QStringLiteral("in_text_vproxy_password"));
        in_text_vproxy_password->setGeometry(QRect(130, 120, 113, 27));
        in_text_vproxy_password->setStyleSheet(QStringLiteral(""));
        label_7 = new QLabel(group_vpn);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 120, 111, 20));
        label_7->setFont(font1);
        in_text_vproxy_path = new QLabel(group_vpn);
        in_text_vproxy_path->setObjectName(QStringLiteral("in_text_vproxy_path"));
        in_text_vproxy_path->setGeometry(QRect(250, 30, 481, 31));
        in_text_vproxy_username = new QLineEdit(group_vpn);
        in_text_vproxy_username->setObjectName(QStringLiteral("in_text_vproxy_username"));
        in_text_vproxy_username->setGeometry(QRect(130, 90, 113, 27));
        label_6 = new QLabel(group_vpn);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 90, 111, 20));
        label_6->setFont(font1);
        in_button_browse = new QPushButton(group_vpn);
        in_button_browse->setObjectName(QStringLiteral("in_button_browse"));
        in_button_browse->setGeometry(QRect(140, 30, 98, 27));
        label_5 = new QLabel(group_vpn);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 30, 131, 20));
        label_5->setFont(font1);
        in_text_vproxy_port = new QLineEdit(group_vpn);
        in_text_vproxy_port->setObjectName(QStringLiteral("in_text_vproxy_port"));
        in_text_vproxy_port->setGeometry(QRect(390, 0, 113, 27));
        in_text_vproxy_server = new QLineEdit(group_vpn);
        in_text_vproxy_server->setObjectName(QStringLiteral("in_text_vproxy_server"));
        in_text_vproxy_server->setGeometry(QRect(110, 0, 113, 27));
        label_22 = new QLabel(group_vpn);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(310, 0, 81, 20));
        label_22->setFont(font1);
        label_23 = new QLabel(group_vpn);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 0, 101, 20));
        label_23->setFont(font1);
        label_24 = new QLabel(group_vpn);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(370, 70, 121, 20));
        label_24->setFont(font1);
        label_25 = new QLabel(group_vpn);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(370, 100, 121, 20));
        label_25->setFont(font1);
        in_text_vproxy_proxy_username = new QLineEdit(group_vpn);
        in_text_vproxy_proxy_username->setObjectName(QStringLiteral("in_text_vproxy_proxy_username"));
        in_text_vproxy_proxy_username->setGeometry(QRect(500, 70, 113, 27));
        in_text_vproxy_proxy_password = new QLineEdit(group_vpn);
        in_text_vproxy_proxy_password->setObjectName(QStringLiteral("in_text_vproxy_proxy_password"));
        in_text_vproxy_proxy_password->setGeometry(QRect(500, 100, 113, 27));
        in_text_vproxy_proxy_password->setEchoMode(QLineEdit::Password);
        toolbox_main->addItem(page_vproxy, QStringLiteral("Vproxy                                                                                                                                - OpenVPN Proxy"));
        page_dproxy = new QWidget();
        page_dproxy->setObjectName(QStringLiteral("page_dproxy"));
        page_dproxy->setGeometry(QRect(0, 0, 651, 233));
        in_dproxy_url = new QLineEdit(page_dproxy);
        in_dproxy_url->setObjectName(QStringLiteral("in_dproxy_url"));
        in_dproxy_url->setGeometry(QRect(90, 0, 561, 27));
        in_dproxy_filepath = new QLineEdit(page_dproxy);
        in_dproxy_filepath->setObjectName(QStringLiteral("in_dproxy_filepath"));
        in_dproxy_filepath->setGeometry(QRect(120, 80, 531, 27));
        label_26 = new QLabel(page_dproxy);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(50, 0, 31, 20));
        label_26->setFont(font1);
        label_27 = new QLabel(page_dproxy);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(0, 60, 191, 20));
        label_27->setFont(font1);
        browse_dproxy = new QPushButton(page_dproxy);
        browse_dproxy->setObjectName(QStringLiteral("browse_dproxy"));
        browse_dproxy->setGeometry(QRect(20, 80, 98, 27));
        push_dproxy_download = new QPushButton(page_dproxy);
        push_dproxy_download->setObjectName(QStringLiteral("push_dproxy_download"));
        push_dproxy_download->setGeometry(QRect(250, 130, 98, 27));
        dproxy_progress = new QProgressBar(page_dproxy);
        dproxy_progress->setObjectName(QStringLiteral("dproxy_progress"));
        dproxy_progress->setGeometry(QRect(450, 130, 191, 23));
        dproxy_progress->setValue(24);
        toolbox_main->addItem(page_dproxy, QStringLiteral("Dproxy                                                                                                                                  - Download files"));
        page_sproxy = new QWidget();
        page_sproxy->setObjectName(QStringLiteral("page_sproxy"));
        page_sproxy->setGeometry(QRect(0, 0, 651, 233));
        page_sproxy->setStyleSheet(QStringLiteral(""));
        in_text_sproxy_local_port = new QLineEdit(page_sproxy);
        in_text_sproxy_local_port->setObjectName(QStringLiteral("in_text_sproxy_local_port"));
        in_text_sproxy_local_port->setGeometry(QRect(120, 10, 113, 27));
        in_text_sproxy_server = new QLineEdit(page_sproxy);
        in_text_sproxy_server->setObjectName(QStringLiteral("in_text_sproxy_server"));
        in_text_sproxy_server->setGeometry(QRect(450, 0, 113, 27));
        in_text_sproxy_username = new QLineEdit(page_sproxy);
        in_text_sproxy_username->setObjectName(QStringLiteral("in_text_sproxy_username"));
        in_text_sproxy_username->setGeometry(QRect(450, 110, 113, 27));
        in_text_sproxy_port = new QLineEdit(page_sproxy);
        in_text_sproxy_port->setObjectName(QStringLiteral("in_text_sproxy_port"));
        in_text_sproxy_port->setGeometry(QRect(450, 30, 113, 27));
        in_text_sproxy_password = new QLineEdit(page_sproxy);
        in_text_sproxy_password->setObjectName(QStringLiteral("in_text_sproxy_password"));
        in_text_sproxy_password->setGeometry(QRect(450, 140, 113, 27));
        in_text_sproxy_password->setEchoMode(QLineEdit::Password);
        label_9 = new QLabel(page_sproxy);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 10, 67, 17));
        label_10 = new QLabel(page_sproxy);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(350, 0, 91, 20));
        label_11 = new QLabel(page_sproxy);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(360, 30, 91, 20));
        label_12 = new QLabel(page_sproxy);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(296, 120, 141, 20));
        label_13 = new QLabel(page_sproxy);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(296, 150, 141, 20));
        in_button_save_sproxy = new QPushButton(page_sproxy);
        in_button_save_sproxy->setObjectName(QStringLiteral("in_button_save_sproxy"));
        in_button_save_sproxy->setGeometry(QRect(80, 70, 161, 27));
        in_text_sproxy_ssh_server = new QLineEdit(page_sproxy);
        in_text_sproxy_ssh_server->setObjectName(QStringLiteral("in_text_sproxy_ssh_server"));
        in_text_sproxy_ssh_server->setGeometry(QRect(450, 70, 113, 27));
        label_21 = new QLabel(page_sproxy);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(360, 80, 91, 20));
        toolbox_main->addItem(page_sproxy, QStringLiteral("Sproxy                                                                                                                             -  SSH Tunnel Proxy"));
        page_lproxy = new QWidget();
        page_lproxy->setObjectName(QStringLiteral("page_lproxy"));
        page_lproxy->setGeometry(QRect(0, 0, 651, 233));
        page_lproxy->setStyleSheet(QStringLiteral(""));
        label_14 = new QLabel(page_lproxy);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(90, 20, 81, 20));
        in_text_lproxy_local_port = new QLineEdit(page_lproxy);
        in_text_lproxy_local_port->setObjectName(QStringLiteral("in_text_lproxy_local_port"));
        in_text_lproxy_local_port->setGeometry(QRect(180, 20, 113, 27));
        label_15 = new QLabel(page_lproxy);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(360, 20, 91, 20));
        label_16 = new QLabel(page_lproxy);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(370, 50, 81, 20));
        in_text_lproxy_server = new QLineEdit(page_lproxy);
        in_text_lproxy_server->setObjectName(QStringLiteral("in_text_lproxy_server"));
        in_text_lproxy_server->setGeometry(QRect(460, 20, 113, 27));
        in_text_lproxy_port = new QLineEdit(page_lproxy);
        in_text_lproxy_port->setObjectName(QStringLiteral("in_text_lproxy_port"));
        in_text_lproxy_port->setGeometry(QRect(460, 50, 113, 27));
        in_button_save_lproxy = new QPushButton(page_lproxy);
        in_button_save_lproxy->setObjectName(QStringLiteral("in_button_save_lproxy"));
        in_button_save_lproxy->setGeometry(QRect(360, 110, 161, 27));
        in_text_lproxy_username = new QLineEdit(page_lproxy);
        in_text_lproxy_username->setObjectName(QStringLiteral("in_text_lproxy_username"));
        in_text_lproxy_username->setGeometry(QRect(120, 80, 113, 27));
        in_text_lproxy_password = new QLineEdit(page_lproxy);
        in_text_lproxy_password->setObjectName(QStringLiteral("in_text_lproxy_password"));
        in_text_lproxy_password->setGeometry(QRect(120, 110, 113, 27));
        in_text_lproxy_password->setEchoMode(QLineEdit::Password);
        label_28 = new QLabel(page_lproxy);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 80, 111, 20));
        label_29 = new QLabel(page_lproxy);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(10, 110, 111, 20));
        toolbox_main->addItem(page_lproxy, QStringLiteral("Lproxy                                                                                                                          - Local Proxy Server "));
        page_tproxy = new QWidget();
        page_tproxy->setObjectName(QStringLiteral("page_tproxy"));
        page_tproxy->setGeometry(QRect(0, 0, 651, 233));
        page_tproxy->setStyleSheet(QStringLiteral(""));
        in_text_tproxy_server = new QLineEdit(page_tproxy);
        in_text_tproxy_server->setObjectName(QStringLiteral("in_text_tproxy_server"));
        in_text_tproxy_server->setGeometry(QRect(230, 10, 113, 27));
        in_text_tproxy_port = new QLineEdit(page_tproxy);
        in_text_tproxy_port->setObjectName(QStringLiteral("in_text_tproxy_port"));
        in_text_tproxy_port->setGeometry(QRect(230, 40, 113, 27));
        in_text_tproxy_username = new QLineEdit(page_tproxy);
        in_text_tproxy_username->setObjectName(QStringLiteral("in_text_tproxy_username"));
        in_text_tproxy_username->setGeometry(QRect(530, 10, 113, 27));
        in_text_tproxy_password = new QLineEdit(page_tproxy);
        in_text_tproxy_password->setObjectName(QStringLiteral("in_text_tproxy_password"));
        in_text_tproxy_password->setGeometry(QRect(530, 40, 113, 27));
        in_text_tproxy_password->setEchoMode(QLineEdit::Password);
        label_17 = new QLabel(page_tproxy);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(106, 10, 91, 20));
        label_18 = new QLabel(page_tproxy);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(116, 40, 81, 20));
        label_19 = new QLabel(page_tproxy);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(386, 10, 111, 20));
        label_20 = new QLabel(page_tproxy);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(386, 40, 111, 20));
        in_button_save_tproxy = new QPushButton(page_tproxy);
        in_button_save_tproxy->setObjectName(QStringLiteral("in_button_save_tproxy"));
        in_button_save_tproxy->setGeometry(QRect(420, 120, 161, 27));
        toolbox_main->addItem(page_tproxy, QStringLiteral("Tproxy                                                                                                                            - Transparent Proxy"));
        page_new = new QWidget();
        page_new->setObjectName(QStringLiteral("page_new"));
        page_new->setEnabled(false);
        page_new->setGeometry(QRect(0, 0, 651, 233));
        page_new->setStyleSheet(QStringLiteral(""));
        toolbox_main->addItem(page_new, QStringLiteral("To be added ..."));
        switch_tproxy = new QPushButton(widget_main);
        switch_tproxy->setObjectName(QStringLiteral("switch_tproxy"));
        switch_tproxy->setGeometry(QRect(560, 500, 41, 31));
        switch_lproxy = new QPushButton(widget_main);
        switch_lproxy->setObjectName(QStringLiteral("switch_lproxy"));
        switch_lproxy->setGeometry(QRect(510, 500, 41, 31));
        switch_sproxy = new QPushButton(widget_main);
        switch_sproxy->setObjectName(QStringLiteral("switch_sproxy"));
        switch_sproxy->setGeometry(QRect(460, 500, 41, 31));
        switch_vproxy = new QPushButton(widget_main);
        switch_vproxy->setObjectName(QStringLiteral("switch_vproxy"));
        switch_vproxy->setGeometry(QRect(410, 500, 41, 31));
        switch_cproxy = new QPushButton(widget_main);
        switch_cproxy->setObjectName(QStringLiteral("switch_cproxy"));
        switch_cproxy->setGeometry(QRect(610, 500, 41, 31));
        AllProxy->setCentralWidget(widget_main);
        QWidget::setTabOrder(in_text_sproxy_local_port, in_text_sproxy_server);
        QWidget::setTabOrder(in_text_sproxy_server, in_text_sproxy_port);
        QWidget::setTabOrder(in_text_sproxy_port, in_text_sproxy_ssh_server);
        QWidget::setTabOrder(in_text_sproxy_ssh_server, in_text_sproxy_username);
        QWidget::setTabOrder(in_text_sproxy_username, in_text_sproxy_password);
        QWidget::setTabOrder(in_text_sproxy_password, in_button_save_sproxy);
        QWidget::setTabOrder(in_button_save_sproxy, in_button_browse);
        QWidget::setTabOrder(in_button_browse, in_text_vproxy_username);
        QWidget::setTabOrder(in_text_vproxy_username, in_text_vproxy_password);
        QWidget::setTabOrder(in_text_vproxy_password, in_text_vproxy_server);
        QWidget::setTabOrder(in_text_vproxy_server, in_text_vproxy_port);
        QWidget::setTabOrder(in_text_vproxy_port, in_text_vproxy_proxy_username);
        QWidget::setTabOrder(in_text_vproxy_proxy_username, in_text_vproxy_proxy_password);
        QWidget::setTabOrder(in_text_vproxy_proxy_password, in_button_save_vproxy);
        QWidget::setTabOrder(in_button_save_vproxy, in_text_nproxy_server);
        QWidget::setTabOrder(in_text_nproxy_server, in_text_nproxy_port);
        QWidget::setTabOrder(in_text_nproxy_port, in_text_nproxy_username);
        QWidget::setTabOrder(in_text_nproxy_username, in_text_nproxy_password);
        QWidget::setTabOrder(in_text_nproxy_password, in_text_nproxy_gateway);
        QWidget::setTabOrder(in_text_nproxy_gateway, in_button_save_nproxy);
        QWidget::setTabOrder(in_button_save_nproxy, in_text_lproxy_local_port);
        QWidget::setTabOrder(in_text_lproxy_local_port, in_text_lproxy_server);
        QWidget::setTabOrder(in_text_lproxy_server, in_text_lproxy_port);
        QWidget::setTabOrder(in_text_lproxy_port, in_button_save_lproxy);
        QWidget::setTabOrder(in_button_save_lproxy, in_text_tproxy_server);
        QWidget::setTabOrder(in_text_tproxy_server, in_text_tproxy_port);
        QWidget::setTabOrder(in_text_tproxy_port, in_text_tproxy_username);
        QWidget::setTabOrder(in_text_tproxy_username, in_text_tproxy_password);
        QWidget::setTabOrder(in_text_tproxy_password, in_button_save_tproxy);

        retranslateUi(AllProxy);

        toolbox_main->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(AllProxy);
    } // setupUi

    void retranslateUi(QMainWindow *AllProxy)
    {
        AllProxy->setWindowTitle(QApplication::translate("AllProxy", "AllProxy", 0));
        group_proxy->setTitle(QString());
        label_4->setText(QApplication::translate("AllProxy", "Proxy Password", 0));
        label_3->setText(QApplication::translate("AllProxy", "Proxy Port", 0));
        label->setText(QApplication::translate("AllProxy", "Proxy Server", 0));
        label_2->setText(QApplication::translate("AllProxy", "Proxy Username", 0));
        label_8->setText(QApplication::translate("AllProxy", "Default Gateway", 0));
        in_button_save_nproxy->setText(QApplication::translate("AllProxy", "Apply Settings", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_nproxy), QApplication::translate("AllProxy", "Nproxy                                                                                                                                     - Normal Proxy", 0));
        in_button_cproxy_send->setText(QApplication::translate("AllProxy", "Send   Message", 0));
        in_text_vproxy_path_5->setText(QApplication::translate("AllProxy", "IP", 0));
        in_button_cproxy_change_settings->setText(QApplication::translate("AllProxy", "Change Notification Settings", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_cproxy), QApplication::translate("AllProxy", "Cproxy                                                                                                                                                      - Chat", 0));
        group_vpn->setTitle(QString());
        in_button_save_vproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        label_7->setText(QApplication::translate("AllProxy", "VPN Password", 0));
        in_text_vproxy_path->setText(QApplication::translate("AllProxy", "path", 0));
        label_6->setText(QApplication::translate("AllProxy", "VPN Username", 0));
        in_button_browse->setText(QApplication::translate("AllProxy", "Browse ...", 0));
        label_5->setText(QApplication::translate("AllProxy", "Server config file", 0));
        label_22->setText(QApplication::translate("AllProxy", "Proxy Port", 0));
        label_23->setText(QApplication::translate("AllProxy", "Proxy Server", 0));
        label_24->setText(QApplication::translate("AllProxy", "Proxy Username", 0));
        label_25->setText(QApplication::translate("AllProxy", "Proxy Password", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_vproxy), QApplication::translate("AllProxy", "Vproxy                                                                                                                                - OpenVPN Proxy", 0));
        label_26->setText(QApplication::translate("AllProxy", "URL", 0));
        label_27->setText(QApplication::translate("AllProxy", "Full path (with filename) :", 0));
        browse_dproxy->setText(QApplication::translate("AllProxy", "Browse ...", 0));
        push_dproxy_download->setText(QApplication::translate("AllProxy", "Download", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_dproxy), QApplication::translate("AllProxy", "Dproxy                                                                                                                                  - Download files", 0));
        label_9->setText(QApplication::translate("AllProxy", "Local Port", 0));
        label_10->setText(QApplication::translate("AllProxy", "Proxy Server", 0));
        label_11->setText(QApplication::translate("AllProxy", "Proxy Port", 0));
        label_12->setText(QApplication::translate("AllProxy", "SSH Login Username", 0));
        label_13->setText(QApplication::translate("AllProxy", "SSH Login Password", 0));
        in_button_save_sproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        label_21->setText(QApplication::translate("AllProxy", "SSH Server", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_sproxy), QApplication::translate("AllProxy", "Sproxy                                                                                                                             -  SSH Tunnel Proxy", 0));
        label_14->setText(QApplication::translate("AllProxy", "Local port", 0));
        label_15->setText(QApplication::translate("AllProxy", "Proxy server", 0));
        label_16->setText(QApplication::translate("AllProxy", "Proxy port", 0));
        in_button_save_lproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        label_28->setText(QApplication::translate("AllProxy", "Proxy password", 0));
        label_29->setText(QApplication::translate("AllProxy", "Proxy username", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_lproxy), QApplication::translate("AllProxy", "Lproxy                                                                                                                          - Local Proxy Server ", 0));
        label_17->setText(QApplication::translate("AllProxy", "Proxy Server", 0));
        label_18->setText(QApplication::translate("AllProxy", "Proxy Port", 0));
        label_19->setText(QApplication::translate("AllProxy", "Proxy Username", 0));
        label_20->setText(QApplication::translate("AllProxy", "Proxy Password", 0));
        in_button_save_tproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_tproxy), QApplication::translate("AllProxy", "Tproxy                                                                                                                            - Transparent Proxy", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_new), QApplication::translate("AllProxy", "To be added ...", 0));
        switch_tproxy->setText(QApplication::translate("AllProxy", "T", 0));
        switch_lproxy->setText(QApplication::translate("AllProxy", "L", 0));
        switch_sproxy->setText(QApplication::translate("AllProxy", "S", 0));
        switch_vproxy->setText(QApplication::translate("AllProxy", "V", 0));
        switch_cproxy->setText(QApplication::translate("AllProxy", "C", 0));
    } // retranslateUi

};

namespace Ui {
    class AllProxy: public Ui_AllProxy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLPROXY_H
