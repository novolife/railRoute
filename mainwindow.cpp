#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "drawpad.h"

#include <QAction>
#include <QWidget>
#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << this->frameGeometry().width() << this->frameGeometry().height();
    this->langType = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenNewProject()
{
    DrawPad *dp = new DrawPad(nullptr, langType);
    dp->show();
    this->close();
}

void MainWindow::printMessage(QString s)
{
    qDebug() << s;
}

void MainWindow::on_actionAbout_triggered()
{
    about *aView = new about(this->langType);
    aView->show();
}

void MainWindow::on_actionEnglish_triggered()
{
    QTranslator enTranslator;
    enTranslator.load(":/res/i18n/translate_EN.qm");
    qApp->installTranslator(&enTranslator);
    this->ui->retranslateUi(this);
    this->langType = 0;
}

void MainWindow::on_actionZHS_triggered()
{
    QTranslator zhsTranslator;
    zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
    qApp->installTranslator(&zhsTranslator);
    this->ui->retranslateUi(this);
    this->langType = 1;
}

void MainWindow::on_actionNew_triggered()
{
    OpenNewProject();
}

void MainWindow::on_actionLoad_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_newProject_clicked()
{
    OpenNewProject();
}

void MainWindow::on_loadProject_clicked()
{
    printMessage(QString("mouse click Load Project\n"));
}

void MainWindow::on_exitLabel_clicked()
{
    this->close();
}
