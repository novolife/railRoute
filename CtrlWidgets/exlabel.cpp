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
 * @brief   a special label based on QLabel
 * @file    exlabel.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/8/2
 * @note    this kind of label can be clicked and shows different styles when cursor in/out the label
 */

#include "exlabel.h"

/**
 * @brief ExLabel::ExLabel
 * @param parent
 */
ExLabel::ExLabel(QWidget *parent) : QLabel(parent)
{

}

/**
 * @brief ExLabel::mouseReleaseEvent
 * @param ev
 */
void ExLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked(ev);
}

/**
 * @brief ExLabel::enterEvent
 * @param e
 */
void ExLabel::enterEvent(QEvent *e)
{
    Q_UNUSED(e)
    this->setStyleSheet("ExLabel {background-color: "
                        "qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, "
                        "stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 127));}");
}

/**
 * @brief ExLabel::leaveEvent
 * @param e
 */
void ExLabel::leaveEvent(QEvent *e)
{
    Q_UNUSED(e)
    this->setStyleSheet("ExLabel {background-color: "
                        "qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, "
                        "stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
}
