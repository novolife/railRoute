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
