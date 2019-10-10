#include "nodeitem.h"

NodeItem::NodeItem(QGraphicsItemGroup *parent) : QGraphicsPolygonItem(parent)
{
    QPainterPath *path = new QPainterPath();
    path->addEllipse(-12, -12, 24, 24);
    myPolygon = path->toFillPolygon();

    setPolygon(myPolygon);
}
