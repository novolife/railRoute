#include "drawitem.h"

DrawItem::DrawItem(ItemType itemType, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent)
{
    myItemType = itemType;

    QPainterPath *path = new QPainterPath();
    switch(myItemType)
    {
        case Node:
        {
            path->addEllipse(-12, -12, 24, 24);
            myPolygon = path->toFillPolygon();
        }
    }

    setPolygon(myPolygon);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
