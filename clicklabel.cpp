#include "clicklabel.h"

clickLabel::clickLabel(QWidget *parent) : QLabel (parent)
{

}

void clickLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked(ev);
}

