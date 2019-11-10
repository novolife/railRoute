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

#ifndef DRAWPADVIEW_H
#define DRAWPADVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>

#include "drawpad.h"

class DrawPadView : public QGraphicsView
{
    Q_OBJECT

public:
    DrawPadView(QWidget *parent = nullptr);
    void setScale(qreal scale);

public Q_SLOT:
    void ZoomIn();
    void ZoomOut();
    void Zoom(qreal scaleFactor);

private:
    qreal m_scale = 1.0;
    qreal m_zoomDelta = 0.05;

protected:
    void wheelEvent(QWheelEvent *event = nullptr);
};

#endif // DRAWPADVIEW_H
