#ifndef DRAWITEM_H
#define DRAWITEM_H

#include <QtWidgets>
#include "nodeitem.h"

class DrawItem : public QGraphicsItemGroup
{
    Q_GADGET

public:
    enum ItemType
    {
        Node
    };
    Q_ENUM(ItemType)

    DrawItem(ItemType itemType, QColor itemColor);
    ItemType type() {return myItemType;}

private:
    ItemType myItemType;
    NodeItem *nodeChild;
    QGraphicsSimpleTextItem *myText;
};

#endif // DRAWITEM_H
