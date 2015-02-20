#ifndef ALLPROXY_H
#define ALLPROXY_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QString>
#include <QToolBox>

namespace Ui {
class AllProxy;
}

class AllProxy : public QMainWindow
{
    Q_OBJECT

public:
    explicit AllProxy(QWidget *parent = 0);
    ~AllProxy();

private slots:
    void on_in_button_browse_clicked();

    void on_in_text_proxy_server_textChanged(const QString &arg1);

    void on_in_text_proxy_username_textChanged(const QString &arg1);

    void on_in_text_proxy_gateway_textChanged(const QString &arg1);

    void on_in_text_proxy_port_textChanged(const QString &arg1);

    void on_in_text_proxy_password_textChanged(const QString &arg1);
        
    void on_push_tproxy_off_clicked();
    
    void on_push_tproxy_on_clicked();
    
    void on_push_lproxy_off_clicked();

    void on_push_lproxy_on_clicked();

    void on_push_sproxy_off_clicked();

    void on_push_sproxy_on_clicked();

    void on_push_vproxy_off_clicked();

    void on_push_vproxy_on_clicked();

    void on_in_text_vproxy_username_cursorPositionChanged(int arg1, int arg2);

    void on_in_text_vproxy_username_textChanged(const QString &arg1);

    void on_in_text_vproxy_password_textChanged(const QString &arg1);

    void on_in_button_save_vproxy_clicked();

    void on_in_button_save_nproxy_clicked();

    void on_in_button_save_tproxy_clicked();

    void on_in_button_save_lproxy_clicked();

    void on_in_button_save_sproxy_clicked();

    void on_in_text_sproxy_local_port_textChanged(const QString &arg1);

    void on_in_text_sproxy_proxy_password_textChanged(const QString &arg1);

    void on_in_text_sproxy_server_textChanged(const QString &arg1);

    void on_in_text_sproxy_port_textChanged(const QString &arg1);

    void on_in_text_sproxy_username_textChanged(const QString &arg1);

    void on_in_text_sproxy_password_textChanged(const QString &arg1);

    void on_in_text_lproxy_local_port_textChanged(const QString &arg1);

    void on_in_text_lproxy_server_textChanged(const QString &arg1);

    void on_in_text_lproxy_port_textChanged(const QString &arg1);

    void on_in_text_tproxy_server_textChanged(const QString &arg1);

    void on_in_text_tproxy_username_textChanged(const QString &arg1);

    void on_in_text_tproxy_port_textChanged(const QString &arg1);

    void on_in_text_tproxy_password_textChanged(const QString &arg1);

    void on_in_text_nproxy_server_textChanged(const QString &arg1);

    void on_in_text_nproxy_port_textChanged(const QString &arg1);

    void on_in_text_nproxy_username_textChanged(const QString &arg1);

    void on_in_text_nproxy_gateway_textChanged(const QString &arg1);

    void on_in_text_nproxy_password_textChanged(const QString &arg1);

private:
    Ui::AllProxy *ui;
    QToolBox *box;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    QString module_name,project_path;
    QStringList files_list;
    QString project_config_file_name;
    void load_configuration();

    void display_error(QString error);
    void update_config(QString key, QString value)
};

#endif // ALLPROXY_H
