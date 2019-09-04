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

/**
 * @brief entry of the program,
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    if (argc == 3 && strcmp(argv[1], "show"))
    {
        if (strncmp(argv[2], "w", 1))
        {
            printf_s("%s",  "THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW. "
                            "EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES "
                            "PROVIDE THE PROGRAM “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, "
                            "INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS "
                            "FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF "
                            "THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF "
                            "ALL NECESSARY SERVICING, REPAIR OR CORRECTION.");
        }
        else if (strncmp(argv[2], "c", 1))
        {
            printf_s("%s",  "IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING "
                            "WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS "
                            "THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY "
                            "GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE "
                            "USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF "
                            "DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD "
                            "PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), "
                            "EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF "
                            "SUCH DAMAGES. ");
        }
    }
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
    qDebug() << "aaa";
    w->show();
    qDebug() << "aaa";

    return a.exec();
}
