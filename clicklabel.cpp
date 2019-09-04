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
 * @file    clicklabel.cpp
 * @author  Mahajana
 * @version 1.0
 * @date    2019/8/3
 * @note    this kind of label can be clicked
 */

#include "clicklabel.h"

/**
 * @brief clickLabel::clickLabel
 * @param parent
 */
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

