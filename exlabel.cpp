#include "exlabel.h"

ExLabel::ExLabel(QWidget *parent) : QLabel(parent)
{

}

void ExLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked(ev);
}

void ExLabel::enterEvent(QEvent *e)
{
    Q_UNUSED(e);
    this->setStyleSheet("ExLabel {background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 127));}");
}

void ExLabel::leaveEvent(QEvent *e)
{
    Q_UNUSED(e);
    this->setStyleSheet("ExLabel {background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
}
