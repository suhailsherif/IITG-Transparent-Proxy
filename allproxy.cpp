#include "allproxy.h"
#include "ui_allproxy.h"

AllProxy::AllProxy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllProxy)
{
    ui->setupUi(this);
}

AllProxy::~AllProxy()
{
    delete ui;
}
