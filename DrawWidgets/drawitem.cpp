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

/**
 * @brief DrawItem::DrawItem
 * @param itemType : Node
 * @param itemColor
 */
DrawItem::DrawItem(ItemType itemType, QColor itemColor)
    : QGraphicsItemGroup()
{
    myItemType = itemType;

    switch(myItemType)
    {
        case Node:
        {
            nodeChild = new NodeItem(this);
            nodeChild->setPen(QPen(QBrush(itemColor), 6));
        }
    }

    textChild = new QGraphicsTextItem("-");
    textChild->setTextInteractionFlags(Qt::TextEditorInteraction);
    textChild->setPos(nodeChild->boundingRect().width() - 10, -10);

    this->addToGroup(nodeChild);
    this->addToGroup(textChild);
    this->setHandlesChildEvents(false);

    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    myTimer = new QTimer();

    connect(textChild->document(), &QTextDocument::contentsChanged, this, &DrawItem::DrawItem::on_textchild_contentschanged);
}

/**
 * @brief slot function of the contents-changed-signal in textitem
 */
void DrawItem::on_textchild_contentschanged()
{
    this->removeFromGroup(textChild);
    this->addToGroup(textChild);
}
