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
 * @brief   about window of the program
 * @file    about.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/8/2
 * @note    shows the information of the program
 */

#include "about.h"
#include "ui_about.h"
#include "../Algorithm/common.h"

#include <QtWidgets>
#include <QDesktopServices>

/**
 * @brief constructor of "about"
 */
about::about() :
    ui(new Ui::about)
{
    ui->setupUi(this);
    switch (langType)
    {
        case 0:
        {
            QTranslator enTranslator;
            enTranslator.load(":/res/i18n/translate_EN.qm");
            qApp->installTranslator(&enTranslator);
            this->ui->retranslateUi(this);
            break;
        }

        case 1:
        {
            QTranslator zhsTranslator;
            zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
            qApp->installTranslator(&zhsTranslator);
            this->ui->retranslateUi(this);
            break;
        }

        case 2:
        {
            QTranslator jpTranslator;
            jpTranslator.load(":/res/i18n/translate_JP.qm");
            qApp->installTranslator(&jpTranslator);
            this->ui->retranslateUi(this);
            break;
        }
    }
    setAttribute(Qt::WA_ShowModal, true);
}

/**
 * @brief about::~about
 */
about::~about()
{
    delete ui;
}

/**
 * @brief slot function of the github label, open the github repo
 */
void about::on_githubLabel_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/novolife/railRoute")));
}

/**
 * @brief slot function of the zhihu label, open the zhihu article
 */
void about::on_zhihuLabel_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://zhuanlan.zhihu.com/p/51794962")));
}

/**
 * @brief slot function of the LICENSE button, open the license dialog
 */
void about::on_licenseButton_clicked()
{
    licenseDialog *msgBox = new licenseDialog();
    msgBox->exec();
}
