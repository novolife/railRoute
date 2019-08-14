#ifndef DRAWPAD_H
#define DRAWPAD_H

#include <QMainWindow>
#include <QComboBox>
#include "drawpadscene.h"

namespace Ui {
class DrawPad;
}

class DrawPad : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawPad(QWidget *parent = nullptr);
    QIcon createColorToolButtonIcon(const QString &imageFile, QColor color);
    void sceneScaleChanged(const QString &scale);
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
    Ui::DrawPad *ui;
    QComboBox* sceneScaleCombo;
    DrawPadScene *scene;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // DRAWPAD_H
