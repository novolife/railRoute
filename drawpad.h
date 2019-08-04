#ifndef DRAWPAD_H
#define DRAWPAD_H

#include <QMainWindow>

namespace Ui {
class DrawPad;
}

class DrawPad : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawPad(QWidget *parent = nullptr);
    ~DrawPad();

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

    void on_nodeButton_clicked();

    void on_lineButton_clicked();

private:
    Ui::DrawPad *ui;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // DRAWPAD_H
