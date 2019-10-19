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
    myItemColor = Qt::black;
    myTextColor = Qt::black;
    myLineColor = Qt::black;
    myMode      = MoveItem;
    myItemType  = DrawItem::Node;
}
/*
bool DrawPadScene::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QGraphicsSceneEvent::MouseButtonPress)
    {

    }
}
*/
void DrawPadScene::setMode(Mode mode)
{
    myMode = mode;
}

void DrawPadScene::setItemType(DrawItem::ItemType type)
{
    myItemType = type;
}

void DrawPadScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;


    if (itemAt(mouseEvent->screenPos(), QTransform()))
    {
        QGraphicsScene::mousePressEvent(mouseEvent);
    }
    else
    {
        switch (myMode)
        {
        case InsertItem:
        {
            DrawItem *item = new DrawItem(myItemType, myItemColor);
            item->setFlag(QGraphicsItem::ItemIsMovable, true);
            item->setFlag(QGraphicsItem::ItemIsSelectable, true);
            item->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

            this->installEventFilter(item);
            addItem(item);
            item->setPos(mouseEvent->scenePos());
            emit itemInserted(item);
            break;
        }

        default:
            break;
        }
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}
