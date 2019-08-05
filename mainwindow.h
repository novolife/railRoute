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
};

#endif // MAINWINDOW_H
