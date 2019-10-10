#ifndef DRAWITEM_H
#define DRAWITEM_H

#include <QtWidgets>

class DrawItem : public QGraphicsPolygonItem
{
    Q_GADGET

public:
    enum ItemType
    {
        Node
    };
    Q_ENUM(ItemType)

    DrawItem(ItemType itemType, QGraphicsItem *parent = nullptr);

private:
    ItemType myItemType;
    QPolygonF myPolygon;
};

#endif // DRAWITEM_H
