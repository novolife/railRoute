/**
 * @brief   entry of the program
 * @file    main.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/7/16
 */

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
    Q_INIT_RESOURCE(res);
    QApplication a(argc, argv);

    QLocale locale;
    if ( locale.language() == QLocale::Chinese )
    {
        langType = 1;
    }
    else if (locale.language() == QLocale::Japanese)
    {
        langType = 2;
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
