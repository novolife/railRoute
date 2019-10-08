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


#include "drawitem.h"

DrawItem::DrawItem(ItemType itemType, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent)
{
    myItemType = itemType;
    QPainterPath path;

    switch (myItemType)
    {
        case Node:
        {
            QPainterPath bigCircle, midCircle, smlCircle;
            bigCircle.addEllipse(96, 96, 96, 96);
            midCircle.addEllipse(80, 80, 80, 80);
            smlCircle.addEllipse(48, 48, 48, 48);
            path = bigCircle - midCircle + smlCircle;
            break;
        }
    }
    setPolygon(myPolygon);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
