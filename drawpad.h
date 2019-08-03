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

private:
    Ui::DrawPad *ui;
};

#endif // DRAWPAD_H
