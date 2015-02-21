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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QGroupBox *group_vproxy_switch;
    QPushButton *push_vproxy_on;
    QPushButton *push_vproxy_off;
    QLineEdit *in_text_vproxy_port;
    QLineEdit *in_text_vproxy_server;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *in_text_vproxy_proxy_username;
    QLineEdit *in_text_vproxy_proxy_password;
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
    QGroupBox *group_sproxy_switch;
    QPushButton *push_sproxy_on;
    QPushButton *push_sproxy_off;
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
    QGroupBox *group_lproxy_switch;
    QPushButton *push_lproxy_on;
    QPushButton *push_lproxy_off;
    QPushButton *in_button_save_lproxy;
    QWidget *page_tproxy;
    QGroupBox *group_tproxy_switch;
    QPushButton *push_tproxy_on;
    QPushButton *push_tproxy_off;
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
    QGroupBox *group_tproxy;
    QRadioButton *in_radio_tproxy;

    void setupUi(QMainWindow *AllProxy)
    {
        if (AllProxy->objectName().isEmpty())
            AllProxy->setObjectName(QStringLiteral("AllProxy"));
        AllProxy->setEnabled(true);
        AllProxy->resize(671, 420);
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
        toolbox_main->setGeometry(QRect(10, 10, 651, 401));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        toolbox_main->setFont(font);
        toolbox_main->setStyleSheet(QLatin1String("QToolBox::tab {\n"
"background-color: rgba(80, 80, 80, 150);\n"
"border-radius: 3px;\n"
"color: white;\n"
"}\n"
"\n"
"QToolBox::tab:selected { \n"
"background-color: rgba(50, 180, 50, 150);\n"
"font: italic;\n"
"color: black;\n"
"}\n"
""));
        toolbox_main->setFrameShape(QFrame::NoFrame);
        toolbox_main->setFrameShadow(QFrame::Sunken);
        page_nproxy = new QWidget();
        page_nproxy->setObjectName(QStringLiteral("page_nproxy"));
        page_nproxy->setGeometry(QRect(0, 0, 651, 215));
        page_nproxy->setStyleSheet(QLatin1String(" QWidget#page_nproxy {\n"
"     background-color: rgba(250, 155, 50, 20);\n"
" }"));
        group_proxy = new QGroupBox(page_nproxy);
        group_proxy->setObjectName(QStringLiteral("group_proxy"));
        group_proxy->setGeometry(QRect(0, 0, 731, 171));
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
        toolbox_main->addItem(page_nproxy, QStringLiteral("Nproxy                                                                                                                 - Normal Proxy Settings"));
        page_vproxy = new QWidget();
        page_vproxy->setObjectName(QStringLiteral("page_vproxy"));
        page_vproxy->setGeometry(QRect(0, 0, 651, 215));
        page_vproxy->setStyleSheet(QLatin1String(" QWidget#page_vproxy {\n"
"     background-color: rgba(250, 155, 50, 20);\n"
" }"));
        group_vpn = new QGroupBox(page_vproxy);
        group_vpn->setObjectName(QStringLiteral("group_vpn"));
        group_vpn->setGeometry(QRect(10, 0, 731, 171));
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
        group_vproxy_switch = new QGroupBox(group_vpn);
        group_vproxy_switch->setObjectName(QStringLiteral("group_vproxy_switch"));
        group_vproxy_switch->setGeometry(QRect(510, 130, 81, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(150, 150, 150, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(164, 164, 164, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(136, 136, 136, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(54, 54, 54, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(72, 72, 72, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        QBrush brush8(QColor(109, 109, 109, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        group_vproxy_switch->setPalette(palette);
        group_vproxy_switch->setAutoFillBackground(false);
        group_vproxy_switch->setStyleSheet(QLatin1String("QGroupBox#group_vproxy_switch{\n"
"	background-color: rgb(150,150,150);\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        push_vproxy_on = new QPushButton(group_vproxy_switch);
        push_vproxy_on->setObjectName(QStringLiteral("push_vproxy_on"));
        push_vproxy_on->setGeometry(QRect(41, 2, 38, 27));
        push_vproxy_on->setStyleSheet(QLatin1String(" QPushButton#push_vproxy_on {\n"
"     background-color: rgb(50, 255, 50);\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
        push_vproxy_off = new QPushButton(group_vproxy_switch);
        push_vproxy_off->setObjectName(QStringLiteral("push_vproxy_off"));
        push_vproxy_off->setGeometry(QRect(1, 2, 38, 27));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush9(QColor(255, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(247, 52, 52, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(120, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(160, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush13(QColor(247, 127, 127, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        QBrush brush14(QColor(255, 105, 105, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        QBrush brush15(QColor(240, 0, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        push_vproxy_off->setPalette(palette1);
        push_vproxy_off->setAutoFillBackground(false);
        push_vproxy_off->setStyleSheet(QLatin1String(" QPushButton#push_vproxy_off {\n"
"     background-color: red;\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
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
        toolbox_main->addItem(page_vproxy, QStringLiteral("Vproxy                                                                                                            - OpenVPN Proxy Settings"));
        page_sproxy = new QWidget();
        page_sproxy->setObjectName(QStringLiteral("page_sproxy"));
        page_sproxy->setGeometry(QRect(0, 0, 651, 215));
        page_sproxy->setStyleSheet(QLatin1String(" QWidget#page_sproxy {\n"
"     background-color: rgba(250, 155, 50, 20);\n"
" }"));
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
        group_sproxy_switch = new QGroupBox(page_sproxy);
        group_sproxy_switch->setObjectName(QStringLiteral("group_sproxy_switch"));
        group_sproxy_switch->setGeometry(QRect(100, 110, 81, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        group_sproxy_switch->setPalette(palette2);
        group_sproxy_switch->setAutoFillBackground(false);
        group_sproxy_switch->setStyleSheet(QLatin1String("QGroupBox#group_sproxy_switch{\n"
"	background-color: rgb(150,150,150);\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        push_sproxy_on = new QPushButton(group_sproxy_switch);
        push_sproxy_on->setObjectName(QStringLiteral("push_sproxy_on"));
        push_sproxy_on->setGeometry(QRect(41, 2, 38, 27));
        push_sproxy_on->setStyleSheet(QLatin1String(" QPushButton#push_sproxy_on {\n"
"     background-color: rgb(50, 255, 50);\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
        push_sproxy_off = new QPushButton(group_sproxy_switch);
        push_sproxy_off->setObjectName(QStringLiteral("push_sproxy_off"));
        push_sproxy_off->setGeometry(QRect(1, 2, 38, 27));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        push_sproxy_off->setPalette(palette3);
        push_sproxy_off->setAutoFillBackground(false);
        push_sproxy_off->setStyleSheet(QLatin1String(" QPushButton#push_sproxy_off {\n"
"     background-color: red;\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
        in_button_save_sproxy = new QPushButton(page_sproxy);
        in_button_save_sproxy->setObjectName(QStringLiteral("in_button_save_sproxy"));
        in_button_save_sproxy->setGeometry(QRect(80, 70, 161, 27));
        in_text_sproxy_ssh_server = new QLineEdit(page_sproxy);
        in_text_sproxy_ssh_server->setObjectName(QStringLiteral("in_text_sproxy_ssh_server"));
        in_text_sproxy_ssh_server->setGeometry(QRect(450, 70, 113, 27));
        label_21 = new QLabel(page_sproxy);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(360, 80, 91, 20));
        toolbox_main->addItem(page_sproxy, QStringLiteral("Sproxy                                                                                                          -  SSH Tunnel Proxy Settings"));
        page_lproxy = new QWidget();
        page_lproxy->setObjectName(QStringLiteral("page_lproxy"));
        page_lproxy->setGeometry(QRect(0, 0, 651, 215));
        page_lproxy->setStyleSheet(QLatin1String(" QWidget#page_lproxy {\n"
"     background-color: rgba(250, 155, 50, 20);\n"
" }"));
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
        group_lproxy_switch = new QGroupBox(page_lproxy);
        group_lproxy_switch->setObjectName(QStringLiteral("group_lproxy_switch"));
        group_lproxy_switch->setGeometry(QRect(190, 120, 81, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        group_lproxy_switch->setPalette(palette4);
        group_lproxy_switch->setAutoFillBackground(false);
        group_lproxy_switch->setStyleSheet(QLatin1String("QGroupBox#group_lproxy_switch{\n"
"	background-color: rgb(150,150,150);\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        push_lproxy_on = new QPushButton(group_lproxy_switch);
        push_lproxy_on->setObjectName(QStringLiteral("push_lproxy_on"));
        push_lproxy_on->setGeometry(QRect(41, 2, 38, 27));
        push_lproxy_on->setStyleSheet(QLatin1String(" QPushButton#push_lproxy_on {\n"
"     background-color: rgb(50, 255, 50);\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
        push_lproxy_off = new QPushButton(group_lproxy_switch);
        push_lproxy_off->setObjectName(QStringLiteral("push_lproxy_off"));
        push_lproxy_off->setGeometry(QRect(1, 2, 38, 27));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        push_lproxy_off->setPalette(palette5);
        push_lproxy_off->setAutoFillBackground(false);
        push_lproxy_off->setStyleSheet(QLatin1String(" QPushButton#push_lproxy_off {\n"
"     background-color: red;\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
        in_button_save_lproxy = new QPushButton(page_lproxy);
        in_button_save_lproxy->setObjectName(QStringLiteral("in_button_save_lproxy"));
        in_button_save_lproxy->setGeometry(QRect(360, 110, 161, 27));
        toolbox_main->addItem(page_lproxy, QStringLiteral("Lproxy                                                                                                         - Squid Proxy Server Settings "));
        page_tproxy = new QWidget();
        page_tproxy->setObjectName(QStringLiteral("page_tproxy"));
        page_tproxy->setGeometry(QRect(0, 0, 651, 215));
        page_tproxy->setStyleSheet(QLatin1String(" QWidget#page_tproxy {\n"
"     background-color: rgba(250, 155, 50, 20);\n"
" }"));
        group_tproxy_switch = new QGroupBox(page_tproxy);
        group_tproxy_switch->setObjectName(QStringLiteral("group_tproxy_switch"));
        group_tproxy_switch->setGeometry(QRect(110, 80, 81, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        group_tproxy_switch->setPalette(palette6);
        group_tproxy_switch->setAutoFillBackground(false);
        group_tproxy_switch->setStyleSheet(QLatin1String("QGroupBox#group_tproxy_switch {\n"
"	background-color: rgb(150,150,150);\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        push_tproxy_on = new QPushButton(group_tproxy_switch);
        push_tproxy_on->setObjectName(QStringLiteral("push_tproxy_on"));
        push_tproxy_on->setGeometry(QRect(41, 2, 38, 27));
        push_tproxy_on->setStyleSheet(QLatin1String("QPushButton#push_tproxy_on{\n"
"     background-color: rgb(50, 255, 50);\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
        push_tproxy_off = new QPushButton(group_tproxy_switch);
        push_tproxy_off->setObjectName(QStringLiteral("push_tproxy_off"));
        push_tproxy_off->setGeometry(QRect(1, 2, 38, 27));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        push_tproxy_off->setPalette(palette7);
        push_tproxy_off->setAutoFillBackground(false);
        push_tproxy_off->setStyleSheet(QLatin1String(" QPushButton#push_tproxy_off {\n"
"     background-color: red;\n"
"     border-radius: 5px;\n"
"	 border-width: 1px;\n"
" }"));
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
        toolbox_main->addItem(page_tproxy, QStringLiteral("Tproxy                                                                                                           - Transparent Proxy Settings"));
        page_new = new QWidget();
        page_new->setObjectName(QStringLiteral("page_new"));
        page_new->setGeometry(QRect(0, 0, 651, 215));
        page_new->setStyleSheet(QStringLiteral(""));
        group_tproxy = new QGroupBox(page_new);
        group_tproxy->setObjectName(QStringLiteral("group_tproxy"));
        group_tproxy->setGeometry(QRect(-120, 20, 731, 41));
        in_radio_tproxy = new QRadioButton(group_tproxy);
        in_radio_tproxy->setObjectName(QStringLiteral("in_radio_tproxy"));
        in_radio_tproxy->setGeometry(QRect(10, 10, 116, 22));
        QFont font2;
        font2.setFamily(QStringLiteral("Sawasdee"));
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        in_radio_tproxy->setFont(font2);
        toolbox_main->addItem(page_new, QStringLiteral("To be added ..."));
        AllProxy->setCentralWidget(widget_main);
        QWidget::setTabOrder(in_text_sproxy_local_port, in_text_sproxy_server);
        QWidget::setTabOrder(in_text_sproxy_server, in_text_sproxy_port);
        QWidget::setTabOrder(in_text_sproxy_port, in_text_sproxy_ssh_server);
        QWidget::setTabOrder(in_text_sproxy_ssh_server, in_text_sproxy_username);
        QWidget::setTabOrder(in_text_sproxy_username, in_text_sproxy_password);
        QWidget::setTabOrder(in_text_sproxy_password, in_button_save_sproxy);
        QWidget::setTabOrder(in_button_save_sproxy, push_sproxy_on);
        QWidget::setTabOrder(push_sproxy_on, push_sproxy_off);
        QWidget::setTabOrder(push_sproxy_off, in_button_browse);
        QWidget::setTabOrder(in_button_browse, in_text_vproxy_username);
        QWidget::setTabOrder(in_text_vproxy_username, in_text_vproxy_password);
        QWidget::setTabOrder(in_text_vproxy_password, in_text_vproxy_server);
        QWidget::setTabOrder(in_text_vproxy_server, in_text_vproxy_port);
        QWidget::setTabOrder(in_text_vproxy_port, in_text_vproxy_proxy_username);
        QWidget::setTabOrder(in_text_vproxy_proxy_username, in_text_vproxy_proxy_password);
        QWidget::setTabOrder(in_text_vproxy_proxy_password, in_button_save_vproxy);
        QWidget::setTabOrder(in_button_save_vproxy, push_vproxy_on);
        QWidget::setTabOrder(push_vproxy_on, push_vproxy_off);
        QWidget::setTabOrder(push_vproxy_off, in_text_nproxy_server);
        QWidget::setTabOrder(in_text_nproxy_server, in_text_nproxy_port);
        QWidget::setTabOrder(in_text_nproxy_port, in_text_nproxy_username);
        QWidget::setTabOrder(in_text_nproxy_username, in_text_nproxy_password);
        QWidget::setTabOrder(in_text_nproxy_password, in_text_nproxy_gateway);
        QWidget::setTabOrder(in_text_nproxy_gateway, in_button_save_nproxy);
        QWidget::setTabOrder(in_button_save_nproxy, in_text_lproxy_local_port);
        QWidget::setTabOrder(in_text_lproxy_local_port, in_text_lproxy_server);
        QWidget::setTabOrder(in_text_lproxy_server, in_text_lproxy_port);
        QWidget::setTabOrder(in_text_lproxy_port, in_button_save_lproxy);
        QWidget::setTabOrder(in_button_save_lproxy, push_lproxy_on);
        QWidget::setTabOrder(push_lproxy_on, push_lproxy_off);
        QWidget::setTabOrder(push_lproxy_off, in_text_tproxy_server);
        QWidget::setTabOrder(in_text_tproxy_server, in_text_tproxy_port);
        QWidget::setTabOrder(in_text_tproxy_port, in_text_tproxy_username);
        QWidget::setTabOrder(in_text_tproxy_username, in_text_tproxy_password);
        QWidget::setTabOrder(in_text_tproxy_password, in_button_save_tproxy);
        QWidget::setTabOrder(in_button_save_tproxy, push_tproxy_on);
        QWidget::setTabOrder(push_tproxy_on, push_tproxy_off);
        QWidget::setTabOrder(push_tproxy_off, in_radio_tproxy);

        retranslateUi(AllProxy);

        toolbox_main->setCurrentIndex(1);


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
        in_button_save_nproxy->setText(QApplication::translate("AllProxy", "Apply", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_nproxy), QApplication::translate("AllProxy", "Nproxy                                                                                                                 - Normal Proxy Settings", 0));
        group_vpn->setTitle(QString());
        in_button_save_vproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        label_7->setText(QApplication::translate("AllProxy", "VPN Password", 0));
        in_text_vproxy_path->setText(QApplication::translate("AllProxy", "path", 0));
        label_6->setText(QApplication::translate("AllProxy", "VPN Username", 0));
        in_button_browse->setText(QApplication::translate("AllProxy", "Browse ...", 0));
        label_5->setText(QApplication::translate("AllProxy", "Server config file", 0));
        group_vproxy_switch->setTitle(QString());
        push_vproxy_on->setText(QApplication::translate("AllProxy", "On", 0));
        push_vproxy_off->setText(QApplication::translate("AllProxy", "Off", 0));
        label_22->setText(QApplication::translate("AllProxy", "Proxy Port", 0));
        label_23->setText(QApplication::translate("AllProxy", "Proxy Server", 0));
        label_24->setText(QApplication::translate("AllProxy", "Proxy Username", 0));
        label_25->setText(QApplication::translate("AllProxy", "Proxy Password", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_vproxy), QApplication::translate("AllProxy", "Vproxy                                                                                                            - OpenVPN Proxy Settings", 0));
        label_9->setText(QApplication::translate("AllProxy", "Local Port", 0));
        label_10->setText(QApplication::translate("AllProxy", "Proxy Server", 0));
        label_11->setText(QApplication::translate("AllProxy", "Proxy Port", 0));
        label_12->setText(QApplication::translate("AllProxy", "SSH Login Username", 0));
        label_13->setText(QApplication::translate("AllProxy", "SSH Login Password", 0));
        group_sproxy_switch->setTitle(QString());
        push_sproxy_on->setText(QApplication::translate("AllProxy", "On", 0));
        push_sproxy_off->setText(QApplication::translate("AllProxy", "Off", 0));
        in_button_save_sproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        label_21->setText(QApplication::translate("AllProxy", "SSH Server", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_sproxy), QApplication::translate("AllProxy", "Sproxy                                                                                                          -  SSH Tunnel Proxy Settings", 0));
        label_14->setText(QApplication::translate("AllProxy", "Local port", 0));
        label_15->setText(QApplication::translate("AllProxy", "Proxy server", 0));
        label_16->setText(QApplication::translate("AllProxy", "Proxy port", 0));
        group_lproxy_switch->setTitle(QString());
        push_lproxy_on->setText(QApplication::translate("AllProxy", "On", 0));
        push_lproxy_off->setText(QApplication::translate("AllProxy", "Off", 0));
        in_button_save_lproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_lproxy), QApplication::translate("AllProxy", "Lproxy                                                                                                         - Squid Proxy Server Settings ", 0));
        group_tproxy_switch->setTitle(QString());
        push_tproxy_on->setText(QApplication::translate("AllProxy", "On", 0));
        push_tproxy_off->setText(QApplication::translate("AllProxy", "Off", 0));
        label_17->setText(QApplication::translate("AllProxy", "Proxy Server", 0));
        label_18->setText(QApplication::translate("AllProxy", "Proxy Port", 0));
        label_19->setText(QApplication::translate("AllProxy", "Proxy Username", 0));
        label_20->setText(QApplication::translate("AllProxy", "Proxy Password", 0));
        in_button_save_tproxy->setText(QApplication::translate("AllProxy", "Save configuration", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_tproxy), QApplication::translate("AllProxy", "Tproxy                                                                                                           - Transparent Proxy Settings", 0));
        group_tproxy->setTitle(QString());
        in_radio_tproxy->setText(QApplication::translate("AllProxy", "Tproxy", 0));
        toolbox_main->setItemText(toolbox_main->indexOf(page_new), QApplication::translate("AllProxy", "To be added ...", 0));
    } // retranslateUi

};

namespace Ui {
    class AllProxy: public Ui_AllProxy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLPROXY_H
