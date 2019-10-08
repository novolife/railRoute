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

#include "drawpadscene.h"
#include <QGraphicsScene>

/**
 * @brief DrawPadScene::DrawPadScene
 */
DrawPadScene::DrawPadScene() :
    QGraphicsScene()
{
    myItemColor = Qt::white;
    myTextColor = Qt::black;
    myLineColor = Qt::black;
    myMode      = MoveItem;
    myItemType  = DrawItem::Node;
}


void DrawPadScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    DrawItem *item;
    switch (myMode)
    {
        case InsertItem:
        {
            item = new DrawItem(myItemType);
            item->setBrush(myItemColor);
            addItem(item);
            item->setPos(mouseEvent->scenePos());
            emit itemInserted(item);
            break;
        }

        default:
            break;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}
