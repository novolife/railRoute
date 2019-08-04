#include "drawpad.h"
#include "ui_drawpad.h"
#include "about.h"
#include <QtWidgets>

DrawPad::DrawPad(QWidget *parent, int lT) :
    QMainWindow(parent),
    ui(new Ui::DrawPad)
{
    ui->setupUi(this);
    langType = lT;
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
    }
}

DrawPad::~DrawPad()
{
    delete ui;
}

void DrawPad::closeEvent(QCloseEvent *event)
{
    qDebug() << "triggered close event";
    event->accept();
}


void DrawPad::on_actionNew_triggered()
{

}

void DrawPad::on_actionSave_triggered()
{

}

void DrawPad::on_actionLoad_triggered()
{

}

void DrawPad::on_actionExit_triggered()
{
    this->close();
}

void DrawPad::on_actionUndo_triggered()
{

}

void DrawPad::on_actionRedo_triggered()
{

}

void DrawPad::on_actionDelete_triggered()
{

}

void DrawPad::on_actionAbout_triggered()
{
    about *aView = new about(this->langType);
    aView->show();
}

void DrawPad::on_actionEnglish_triggered()
{
    QTranslator enTranslator;
    enTranslator.load(":/res/i18n/translate_EN.qm");
    qApp->installTranslator(&enTranslator);
    this->ui->retranslateUi(this);
    this->langType = 0;
}

void DrawPad::on_actionZHS_triggered()
{
    QTranslator zhsTranslator;
    zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
    qApp->installTranslator(&zhsTranslator);
    this->ui->retranslateUi(this);
    this->langType = 1;
}

void DrawPad::on_nodeButton_clicked()
{
    qDebug() << static_cast <QPushButton*> (sender())->isChecked();
}

void DrawPad::on_lineButton_clicked()
{
    qDebug() << static_cast <QPushButton*> (sender())->isChecked();
}
