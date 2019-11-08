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
 * @brief   drawpad window of the program
 * @file    drawpad.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/8/2
 * @note    the core part of this program, could draw graphs and can save in / load from files
 * @todo    do the todos
 */

#include "drawpad.h"
#include "ui_drawpad.h"
#include "about.h"
#include "common.h"
#include "drawpadscene.h"
#include "drawpadview.h"

#include <QtWidgets>

/**
 * @brief constructor of DrawPad
 * @param parent
 */
DrawPad::DrawPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawPad)
{
    ui->setupUi(this);

    ui->verticalLayout->setAlignment(Qt::AlignTop);

    // Get settings
    if (QFile::exists("./prgCfg/setting.ini") == false)
    {
        QFile *tempFile = new QFile("./prgCfg/setting.ini");
        if (tempFile->open(QIODevice::WriteOnly) == false)
        {
            QErrorMessage *errorTip = new QErrorMessage();
            errorTip->setWindowTitle("ERROR");
            errorTip->showMessage("Program Config File Initialize Failed!");
            errorTip->exec();
            runningState = CFGINITFAIL;
            this->close();
        }
        tempFile->close();
        pSetting = new QSettings("./prgCfg/setting.ini", QSettings::IniFormat);
    }
    else
    {
        pSetting = new QSettings("./prgCfg/setting.ini", QSettings::IniFormat);
        this->setGeometry(pSetting->value("x").toInt(), pSetting->value("y").toInt(),
                          pSetting->value("width").toInt(), pSetting->value("height").toInt());

        if (pSetting->value("isMaximized") == 1)
        {
            this->setWindowState(Qt::WindowMaximized);
        }
    }

    // translate the ui
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

    // Initialize the comboBox of scale
    sceneScaleCombo = new QComboBox();
    QStringList scales;
    scales << "50%" << "75%" << "100%" << "200%" << "400%" << "100%";
    sceneScaleCombo->addItems(scales);
    sceneScaleCombo->setCurrentIndex(2);
    connect(sceneScaleCombo, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            this, &DrawPad::SceneScaleChanged);
    ui->toolBar->addWidget(sceneScaleCombo);

    // Initiaize the QGraphicsScene
    scene = new DrawPadScene();
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    ui->graphicsView->setScene(scene);

    // Initialize the icon the color select
    ui->actionNodeColor->setIcon(createColorToolButtonIcon(":/res/img/opr/node.png", Qt::black));
    ui->actionLineColor->setIcon(createColorToolButtonIcon(":/res/img/opr/line.png", Qt::black));
    ui->actionTextColor->setIcon(createColorToolButtonIcon(":/res/img/opr/text.png", Qt::black));

    // Initialize the connection between drawpad and scene
    connect(scene, &DrawPadScene::itemInserted, this, &DrawPad::itemInserted);
    //connect(scene, &DrawPadScene::itemSelected, this, &DrawPad::itemSelected);
    //connect(scene, &DrawPadScene::textInserted, this, &DrawPad::textInserted);
}

/**
 * @brief DrawPad::~DrawPad
 */
DrawPad::~DrawPad()
{
    delete ui;
}

/**
 * @brief reset the selected scale
 * @param scale
 * @param index
 */
void DrawPad::ChangeComboBoxItem(qreal scale, int index)
{
    sceneScaleCombo->setCurrentIndex(index);
    QString tempString = QString(QString::number(qRound(scale * 100)) + QString('%'));
    sceneScaleCombo->setItemText(index, tempString);
}

/**
 * @brief change scale from the combo box
 * @param scale
 */
void DrawPad::SceneScaleChanged(const QString &scale)
{
    double newScale = scale.left(scale.indexOf("%")).toDouble() / 100.0;
    ui->graphicsView->Zoom(newScale);
    this->ui->graphicsView->setScale(newScale);
}

/**
 * @brief create Color ToolButton Icon
 * @param imageFile
 * @param color
 * @return a icon
 */
QIcon DrawPad::createColorToolButtonIcon(const QString &imageFile, QColor color)
{
    QPixmap pixmap(50, 80);
    pixmap.fill(Qt::transparent);
    QPainter *painter = new QPainter(&pixmap);
    QPixmap image(imageFile);

    // Draw icon centred horizontally on button.
    QRect target(4, 0, 42, 43);
    QRect source(0, 0, 42, 43);
    painter->fillRect(QRect(0, 60, 50, 80), color);
    painter->drawPixmap(target, image, source);

    return QIcon(pixmap);
}

/**
 * @brief save the location & size of drawpad
 */
void DrawPad::saveUISetting()
{
    if (this->isMaximized())
    {
        pSetting->setValue("isMaximized", 1);
        pSetting->setValue("x", ((qApp->desktop()->width() - 800) / 2) );
        pSetting->setValue("y", ((qApp->desktop()->height() - 600) / 2) );
        pSetting->setValue("width", 800);
        pSetting->setValue("height", 600);
    }
    else
    {
        pSetting->setValue("isMaximized", 0);
        pSetting->setValue("x", this->geometry().x());
        pSetting->setValue("y", this->geometry().y());
        pSetting->setValue("width", this->geometry().width());
        pSetting->setValue("height", this->geometry().height());
    }
    pSetting->setValue("languageType", langType);
}

/**
 * @brief DrawPad::saveErrorLog
 * @param errState
 */
void DrawPad::saveErrorLog(int errState)
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
 * @brief deal with the close event, to make sure that the user's project has been saved.
 * @param event
 */
void DrawPad::closeEvent(QCloseEvent *event)
{
    switch(runningState)
    {
        case NORMAL:
        {
            saveUISetting();
            break;
        }

        case CFGINITFAIL:
        {
            saveErrorLog(CFGINITFAIL);
            break;
        }
    }

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
    QTranslator translator;
    translator.load(":/res/i18n/translate_EN.qm");
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);
    langType = 0;
}

/**
 * @brief slot function of "jiantizhongwen" in menubar, switch language into Chinese(Simplified)
 */
void DrawPad::on_actionZHS_triggered()
{
    QTranslator translator;
    translator.load(":/res/i18n/translate_ZHS.qm");
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);
    langType = 1;
}

/**
 * @brief slot function of "nihongo" in menubar, switch language into Japanese
 */
void DrawPad::on_actionJP_triggered()
{
    QTranslator translator;
    translator.load(":/res/i18n/translate_JP.qm");
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);
    langType = 2;
}

/**
 * @brief slot function of "Node" tool button in toolbox
 * @todo  switch the type of operation to draw a node
 */
void DrawPad::on_nodeButton_clicked()
{
    if ((static_cast <QPushButton*> (sender()))->isChecked() == true)
    {
        if (ui->lineButton->isChecked() == true)
        {
            ui->lineButton->setChecked(false);
        }
    }

    scene->setMode(DrawPadScene::InsertItem);
    scene->setItemType(DrawItem::Node);
}

/**
 * @brief slot function of "line" tool button in toolbox
 * @todo  switch the type of operation to draw a line
 */
void DrawPad::on_lineButton_clicked()
{
    if ((static_cast <QPushButton*> (sender()))->isChecked() == true)
    {
        if (ui->nodeButton->isChecked() == true)
        {
            ui->nodeButton->setChecked(false);
        }
    }

    scene->setMode(DrawPadScene::InsertLine);
}

/**
 * @brief a inline function used to translate dialogs(eg. QColorDialog)
 */
inline void DrawPad::dialogTranslate()
{
    QTranslator *translator = new QTranslator();
    switch (langType)
    {
        case 0:
        {
            translator->load(":/res/i18n/qt_en.qm");
            qApp->installTranslator(translator);
            this->ui->retranslateUi(this);
            break;
        }

        case 1:
        {
            translator->load(":/res/i18n/qt_zh_CN.qm");
            qApp->installTranslator(translator);
            this->ui->retranslateUi(this);
            break;
        }

        case 2:
        {
            translator->load(":/res/i18n/qt_ja.qm");
            qApp->installTranslator(translator);
            this->ui->retranslateUi(this);
            break;
        }
    }
}

/**
 * @brief DrawPad::drawpadRetranslate
 */
inline void DrawPad::drawpadRetranslate()
{
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
 * @brief select the color for node
 */
void DrawPad::on_actionNodeColor_triggered()
{
    QColorDialog *colorDialog = new QColorDialog();
    //dialogTranslate();
    nodeColor = colorDialog->getColor(nodeColor, this);
    ui->actionNodeColor->setIcon(createColorToolButtonIcon(":/res/img/opr/node.png", nodeColor));
    //drawpadRetranslate();
    scene->setItemColor(nodeColor);
}

/**
 * @brief select the color for line
 */
void DrawPad::on_actionLineColor_triggered()
{
    QColorDialog *colorDialog = new QColorDialog();
    dialogTranslate();
    lineColor = colorDialog->getColor(lineColor, this);
    ui->actionLineColor->setIcon(createColorToolButtonIcon(":/res/img/opr/line.png", lineColor));
    drawpadRetranslate();
}

/**
 * @brief select the color for text
 */
void DrawPad::on_actionTextColor_triggered()
{
    QColorDialog *colorDialog = new QColorDialog();
    dialogTranslate();
    textColor = colorDialog->getColor(textColor);
    ui->actionTextColor->setIcon(createColorToolButtonIcon(":/res/img/opr/text.png", textColor));
    drawpadRetranslate();
}

/**
 * @brief DrawPad::on_actionRun_triggered
 */
void DrawPad::on_actionRun_triggered()
{

}

/**
 * @brief DrawPad::itemInserted
 * @param item
 */
void DrawPad::itemInserted(DrawItem *item)
{
    if (item->type() == DrawItem::Node)
    {
        scene->setMode(DrawPadScene::MoveItem);
        this->ui->nodeButton->setChecked(false);
    }
}
