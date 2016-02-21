#include "allproxy.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AllProxy w;
    w.show();

    return a.exec();
}
