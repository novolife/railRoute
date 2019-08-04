/**
  * @author Mahajana
  * @todo   do the todos
  */
#include "drawpad.h"
#include "ui_drawpad.h"
#include "about.h"
#include "common.h"

#include <QtWidgets>

/**
 * @brief constructor of DdrawPad
 * @param parent
 */
DrawPad::DrawPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawPad)
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
    }
}

/**
 * @brief DrawPad::~DrawPad
 */
DrawPad::~DrawPad()
{
    delete ui;
}

/**
 * @brief deal with the close event, to make sure that the user's project has been saved.
 * @param event
 */
void DrawPad::closeEvent(QCloseEvent *event)
{
    qDebug() << "triggered close event";
    event->accept();
}

/**
 * @brief slot function of "New" in menubar
 * @todo  save the present project and open a new drawPad
 */
void DrawPad::on_actionNew_triggered()
{

}

/**
 * @brief slot function of "Save" in menubar
 * @todo  save the present project into a project file
 */
void DrawPad::on_actionSave_triggered()
{

}

/**
 * @brief slot function of "Load" in menubar
 * @todo  open the file-select window and load the selected file into the program
 */
void DrawPad::on_actionLoad_triggered()
{

}

/**
 * @brief slot function of "Exit" in menubar
 */
void DrawPad::on_actionExit_triggered()
{
    this->close();
}

/**
 * @brief slot function of "Undo" in menubar
 * @todo  add the undo lib of Qt
 */
void DrawPad::on_actionUndo_triggered()
{

}

/**
 * @brief slot function of "Redo" in menubar
 * @todo  add the redo lib of Qt
 */
void DrawPad::on_actionRedo_triggered()
{

}

/**
 * @brief slot function of "Delete" in menubar
 * @todo  delete the selected item
 */
void DrawPad::on_actionDelete_triggered()
{

}

/**
 * @brief slot function of "About" in menubar, open a "about" window
 */
void DrawPad::on_actionAbout_triggered()
{
    about *aView = new about();
    aView->show();
}

/**
 * @brief slot function of "English" in menubar, switch language to English
 */
void DrawPad::on_actionEnglish_triggered()
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
void DrawPad::on_actionZHS_triggered()
{
    QTranslator zhsTranslator;
    zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
    qApp->installTranslator(&zhsTranslator);
    this->ui->retranslateUi(this);
    langType = 1;
}

/**
 * @brief slot function of "Node" tool button in toolbox
 * @todo  switch the type of operation to draw a node
 */
void DrawPad::on_nodeButton_clicked()
{
    qDebug() << static_cast <QPushButton*> (sender())->isChecked();
}

/**
 * @brief slot function of "line" tool button in toolbox
 * @todo  switch the type of operation to draw a line
 */
void DrawPad::on_lineButton_clicked()
{
    qDebug() << static_cast <QPushButton*> (sender())->isChecked();
}
