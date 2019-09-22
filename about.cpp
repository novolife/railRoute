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
#include "common.h"

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
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/Yu1Aragaki/railRoute")));
}

void about::on_zhihuLabel_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://zhuanlan.zhihu.com/p/51794962")));
}

void about::on_copyrightButton_clicked()
{
    QMessageBox *c = new QMessageBox();
    c->setModal(true);
    c->setWindowTitle(tr("COPYRIGHT"));
    c->setText(tr("IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING "
               "WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS "
               "THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY "
               "GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE "
               "USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF "
               "DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD "
               "PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), "
               "EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF "
               "SUCH DAMAGES. "));
    c->exec();
}

void about::on_warrantyButton_clicked()
{
    QMessageBox *w = new QMessageBox();
    w->setModal(true);
    w->setWindowTitle(tr("WARRANTY"));
    w->setText(tr("THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW. "
               "EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES "
               "PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, "
               "INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS "
               "FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF "
               "THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF "
               "ALL NECESSARY SERVICING, REPAIR OR CORRECTION. "));
    w->exec();
}
