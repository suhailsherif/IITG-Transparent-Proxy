#ifndef ALLPROXY_H
#define ALLPROXY_H

#include <QMainWindow>

namespace Ui {
class AllProxy;
}

class AllProxy : public QMainWindow
{
    Q_OBJECT

public:
    explicit AllProxy(QWidget *parent = 0);
    ~AllProxy();

private:
    Ui::AllProxy *ui;
};

#endif // ALLPROXY_H
