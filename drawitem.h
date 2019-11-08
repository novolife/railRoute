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
#include <QObject>
#include "nodeitem.h"
#include "common.h"

class DrawItem : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    /**
     * @brief The ItemType enum
     * @note  can add more item
     */
    enum ItemType
    {
        Node
    };
    Q_ENUM(ItemType)

    DrawItem(ItemType itemType, QColor itemColor);
    ItemType type() {return myItemType;}
    NodeItem *NodeChild() {return nodeChild;}
    QGraphicsTextItem *TextChild() {return textChild;}

private slots:
    void on_textchild_contentschanged();

private:
    using QGraphicsItemGroup::type; // avoid virtual func overload warning
    ItemType myItemType;
    NodeItem *nodeChild;
    QGraphicsTextItem *textChild;
    QTimer *myTimer;

};

#endif // DRAWITEM_H
