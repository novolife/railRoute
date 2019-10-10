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

    myText = new QGraphicsSimpleTextItem("bbb");

    myText->setPos(nodeChild->pos().x(), nodeChild->pos().y()+nodeChild->boundingRect().height());

    this->addToGroup(nodeChild);
    this->addToGroup(myText);
    this->setHandlesChildEvents(false);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    //setFlag(QGraphicsItem::ItemIsSelectable, true);
    //setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
