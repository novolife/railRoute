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

#include "drawpadview.h"
#include <QDebug>

/**
 * @brief DrawPadView::DrawPadView
 * @param parent
 */
DrawPadView::DrawPadView(QWidget *parent) :
    QGraphicsView (parent)
{

}

/**
 * @brief wheelEvent
 * @param event
 */
void DrawPadView::wheelEvent(QWheelEvent *event)
{
    int y = event->angleDelta().y();

    if (y > 0)
    {
        ZoomIn();
    }
    else
    {
        ZoomOut();
    }
}

/**
 * @brief wrapper for private member m_scale
 * @param scale
 */
void DrawPadView::setScale(qreal scale)
{
    m_scale = scale;
}

/**
 * @brief calculate the new scale if zoom in
 */
void DrawPadView::ZoomIn()
{
    qreal temp_scale = m_scale + m_zoomDelta;

    if (temp_scale - 0.01 > 4.0)
    {
        return;
    }

    setScale(temp_scale);
    Zoom(temp_scale);
}

/**
 * @brief calculate the new scale if zoom out
 */
void DrawPadView::ZoomOut()
{
    qreal temp_scale = m_scale - m_zoomDelta;

    if (temp_scale + 0.01 < 0.25)
    {
        return;
    }

    setScale(temp_scale);
    Zoom(temp_scale);
}

/**
 * @brief zoom in/out the view
 * @param newScale
 */
void DrawPadView::Zoom(qreal newScale)
{
    DrawPad *padParent = static_cast<DrawPad*>(parentWidget()->parentWidget());
    QMatrix oldMatrix = this->matrix();

    padParent->ChangeComboBoxItem(newScale, 5);

    this->resetMatrix();
    this->translate(oldMatrix.dx(), oldMatrix.dy());
    this->scale(newScale, newScale);
}
