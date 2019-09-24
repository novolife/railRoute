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

#ifndef DRAWPAD_H
#define DRAWPAD_H

#define NORMAL 0
#define CFGINITFAIL 1

#include <QMainWindow>
#include <QComboBox>
#include <QtWidgets>
#include "drawpadscene.h"

namespace Ui {
class DrawPad;
}

class DrawPad : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawPad(QWidget *parent = nullptr);
    void SceneScaleChanged(const QString &scale);
    void ChangeComboBoxItem(qreal scale, int index);
    ~DrawPad();

    QColor nodeColor = Qt::black;
    QColor lineColor = Qt::black;
    QColor textColor = Qt::black;

private slots:
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionExit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionDelete_triggered();
    void on_actionAbout_triggered();
    void on_actionEnglish_triggered();
    void on_actionZHS_triggered();
    void on_actionJP_triggered();
    void on_nodeButton_clicked();
    void on_lineButton_clicked();
    void on_actionNodeColor_triggered();
    void on_actionLineColor_triggered();
    void on_actionTextColor_triggered();

private:
    inline void dialogTranslate();
    inline void drawpadRetranslate();
    QIcon createColorToolButtonIcon(const QString &imageFile, QColor color);
    void saveUISetting();
    void saveErrorLog(int errState);
    Ui::DrawPad *ui;
    QComboBox* sceneScaleCombo;
    DrawPadScene *scene;
    QSettings *pSetting;
    int runningState = NORMAL;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // DRAWPAD_H
