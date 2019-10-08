/**
 *    A program which can calculate a longest path of a rail system.
 *    Copyright (C) 2019  J. HUANG
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 */

/**
 *
 *
 *
 */

#include "mainwindow.h"
#include "common.h"

#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include <iostream>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QtWidgets>

#define NORMAL 0
#define CFGINITFAIL 1

/**
 * @brief saveErrorLog
 * @param errState
 */
void saveErrLog(int errState)
{
    QFile *errorLog = new QFile("./Logs/log-error-" + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss"));
    errorLog->open(QIODevice::WriteOnly);
    switch (errState)
    {
        case CFGINITFAIL:
        {
            errorLog->write("Config File Initialize Failed.");
            break;
        }
    }
    errorLog->close();
}

/**
 * @brief entry of the program, use config file to initialize the language Type
 * @param argc
 * @param argv
 * @return excuetion of the application
 */
int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(res);
    QApplication a(argc, argv);

    QDir *tempLogDir = new QDir();

    if (tempLogDir->exists("./Logs") == false)
    {
        if (tempLogDir->mkdir("./Logs") == false)
        {
            return 1;
        }
    }

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

    QSettings *pSetting;

    if (QFile::exists("./prgCfg/setting.ini"))
    {
        pSetting = new QSettings("./prgCfg/setting.ini", QSettings::IniFormat);
        langType = pSetting->value("languageType").toInt();
    }
    else
    {
        QDir *tempDir = new QDir();
        if( (tempDir->exists("./prgCfg")) == false)
        {
            if ( (tempDir->mkdir("./prgCfg")) == false)
            {
                saveErrLog(CFGINITFAIL);
                QErrorMessage *errorTip = new QErrorMessage();
                errorTip->setWindowTitle("ERROR");
                errorTip->showMessage("Program Config Folder Initialize Failed!");
                errorTip->exec();
                return CFGINITFAIL;
            }
        }
    }

    MainWindow* w = new MainWindow();
    w->show();

    return a.exec();
}
