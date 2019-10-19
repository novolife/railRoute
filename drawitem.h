#ifndef DRAWITEM_H
#define DRAWITEM_H

#include <QtWidgets>
#include <QObject>
#include "nodeitem.h"
#include "common.h"

class DrawItem : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    /**
     * @brief The ItemType enum
     * @note  can add more item
     */
    enum ItemType
    {
        Node
    };
    Q_ENUM(ItemType)

    DrawItem(ItemType itemType, QColor itemColor);
    ItemType type() {return myItemType;}
    NodeItem *NodeChild() {return nodeChild;}
    QGraphicsTextItem *TextChild() {return textChild;}

private slots:
    void on_textchild_contentschanged();

private:
    using QGraphicsItemGroup::type; // avoid virtual func overload warning
    ItemType myItemType;
    NodeItem *nodeChild;
    QGraphicsTextItem *textChild;
    QTimer *myTimer;

};

#endif // DRAWITEM_H
