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
 * @brief   start window of the program
 * @file    mainwindow.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/7/16
 */

#include "about.h"

/**
 * @brief constructor of MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTranslator *translator = new QTranslator();

    switch (langType)
    {
        case 0:
        {
            translator->load(":/res/i18n/translate_EN.qm");
            qApp->installTranslator(translator);
            this->ui->retranslateUi(this);
            break;
        }

        case 1:
        {
            translator->load(":/res/i18n/translate_ZHS.qm");
            qApp->installTranslator(translator);
            this->ui->retranslateUi(this);
            break;
        }

        case 2:
        {
            translator->load(":/res/i18n/translate_JP.qm");
            qApp->installTranslator(translator);
            this->ui->retranslateUi(this);
            break;
        }
    }
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief a mid function of several "New" actions, open a drawpad
 */
void MainWindow::OpenNewProject()
{
    skipFlag = 1;
    DrawPad *dp = new DrawPad(nullptr);
    dp->show();
    this->close();
}

/**
 * @brief a mid function of several "Load" actions
 * @todo  open the file-select window and load the selected file into the program
 */
void MainWindow::LoadProject()
{
    QString prjName = QFileDialog().getOpenFileName();
    QFile* prjFile = new QFile(prjName);
}

/**
 * @brief slot function of "About" in menubar, open a "about" window
 */
void MainWindow::on_actionAbout_triggered()
{
    about *aView = new about();
    aView->show();
}

/**
 * @brief slot function of "English" in menubar, switch the language into English
 */
void MainWindow::on_actionEnglish_triggered()
{
    QTranslator enTranslator;
    enTranslator.load(":/res/i18n/translate_EN.qm");
    qApp->installTranslator(&enTranslator);
    this->ui->retranslateUi(this);
    langType = 0;
}

/**
 * @brief slot function of "jiantizhongwen" in menubar, switch language into Chinese(Simplified)
 */
void MainWindow::on_actionZHS_triggered()
{
    QTranslator zhsTranslator;
    zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
    qApp->installTranslator(&zhsTranslator);
    this->ui->retranslateUi(this);
    langType = 1;
}

/**
 * @brief MainWindow::on_actionJP_triggered
 */
void MainWindow::on_actionJP_triggered()
{
    QTranslator jpTranslator;
    jpTranslator.load(":/res/i18n/translate_JP.qm");
    qApp->installTranslator(&jpTranslator);
    this->ui->retranslateUi(this);
    langType = 2;
}

/**
 * @brief slot function of "New" in menubar, jump to the OpenNewProject function
 */
void MainWindow::on_actionNew_triggered()
{
    OpenNewProject();
}

/**
 * @brief slot function of "Load" in menubar, jump to the LoadProject function
 */
void MainWindow::on_actionLoad_triggered()
{
    LoadProject();
}

/**
 * @brief slot function of "Exit" in menubar, trigger a closeEvent
 */
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

/**
 * @brief slot function of "New Project", jump to the OpenNewProject function
 */
void MainWindow::on_newProject_clicked()
{
    OpenNewProject();
}

/**
 * @brief slot function of "Load Project", jump to the LoadProject function
 */
void MainWindow::on_loadProject_clicked()
{
    LoadProject();
}

/**
 * @brief slot function of "Exit", trigger a closeEvent
 */
void MainWindow::on_exitLabel_clicked()
{
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (skipFlag == 0)
    {
        QSettings *pSetting = new QSettings("./prgCfg/setting.ini", QSettings::IniFormat);
        pSetting->setValue("languageType", langType);
    }
    event->accept();
}
