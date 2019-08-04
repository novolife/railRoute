/**
 * @brief   a special label based on QLabel
 * @file    clicklabel.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/8/3
 * @note    this kind of label can be clicked
 */

#include "clicklabel.h"

clickLabel::clickLabel(QWidget *parent) : QLabel (parent)
{

}

/**
 * @brief clickLabel::mouseReleaseEvent
 * @param ev
 */
void clickLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked(ev);
}

