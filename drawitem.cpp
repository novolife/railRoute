#include "drawitem.h"

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

void DrawItem::on_textchild_contentschanged()
{
    this->removeFromGroup(textChild);
    this->addToGroup(textChild);
}
