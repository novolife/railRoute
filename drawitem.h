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

#ifndef DRAWITEM_H
#define DRAWITEM_H

#include <QtWidgets>

class DrawItem : public QObject, public QGraphicsPolygonItem
{
    //Q_GADGET
    Q_OBJECT

public:

    /**
     * @brief The ItemType enum
     * @note  This enum is for the further improvement
     */
    enum ItemType
    {
        Node
    };

    Q_ENUM(ItemType)

    DrawItem(ItemType itemType, QGraphicsItem *parent = nullptr);

private:
    QPolygonF myPolygon;
    ItemType  myItemType;

};

#endif // DRAWITEM_H
