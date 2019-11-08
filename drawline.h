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


#ifndef DRAWLINE_H
#define DRAWLINE_H

#include <QObject>
#include <QtWidgets>
#include "drawitem.h"

class DrawLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT

public:
    DrawLine(DrawItem *startItem, DrawItem *endItem,
              QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void updatePosition();

    void setColor(const QColor &color) { myColor = color; }
    DrawItem *startItem() const { return myStartItem; }
    DrawItem *endItem() const { return myEndItem; }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    DrawItem *myStartItem;
    DrawItem *myEndItem;
    QColor myColor;
};

#endif // DRAWLINE_H
