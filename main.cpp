#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon ico(":/res/img/logo/logo.ico");
    w.setWindowIcon(ico);
    w.show();

    return a.exec();
}
