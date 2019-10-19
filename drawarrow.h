#ifndef DRAWARROW_H
#define DRAWARROW_H

#include <QObject>
#include <QtWidgets>
#include "drawitem.h"

class DrawArrow : public QGraphicsLineItem
{
    Q_OBJECT

public:
    DrawArrow(DrawItem *startItem, DrawItem *endItem,
              QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void updatePosition();

    void setColor(const QColor &color) { myColor = color; }
    DrawItem *startItem() const { return myStartItem; }
    DrawItem *endItem() const { return myEndItem; }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    DrawItem *myStartItem;
    DrawItem *myEndItem;
    QColor myColor;
};

#endif // DRAWARROW_H
