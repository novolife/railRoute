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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void OpenNewProject();
    void LoadProject();
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionAbout_triggered();
    void on_actionEnglish_triggered();
    void on_actionZHS_triggered();
    void on_actionNew_triggered();
    void on_actionLoad_triggered();
    void on_actionExit_triggered();
    void on_newProject_clicked();
    void on_loadProject_clicked();
    void on_exitLabel_clicked();
    void on_actionJP_triggered();
};

#endif // MAINWINDOW_H
