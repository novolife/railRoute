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


#ifndef NODEITEM_H
#define NODEITEM_H

#include <QtWidgets>

class NodeItem : public QGraphicsPolygonItem
{
    Q_GADGET

public:
    NodeItem(QGraphicsItemGroup *parent = nullptr);

private:
    QPolygonF myPolygon;
};

Q_DECLARE_METATYPE(NodeItem*)

#endif // NODEITEM_H
