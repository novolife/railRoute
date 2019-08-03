#include "drawpad.h"
#include "ui_drawpad.h"

DrawPad::DrawPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawPad)
{
    ui->setupUi(this);
}

DrawPad::~DrawPad()
{
    delete ui;
}
