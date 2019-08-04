#include "mainwindow.h"
#include "common.h"

#include <QApplication>
#include <QDebug>
#include <QTranslator>

/**
 * @brief entry of the program,
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLocale locale;
    if( locale.language() == QLocale::Chinese )
    {
        qDebug() << "Chinese system";
        langType = 1;
    }
    else
    {
        langType = 0;
    }

    MainWindow* w = new MainWindow();
    QIcon ico(":/res/img/logo/logo.ico");
    w->setWindowIcon(ico);
    w->show();

    return a.exec();
}
