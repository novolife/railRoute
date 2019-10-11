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

private slots:
    void slotTimerTimeOut();

private:
    //using QGraphicsItem::mousePressEvent;
    //using QGraphicsItem::mouseDoubleClickEvent;
    using QGraphicsItemGroup::type; // avoid virtual func overload warning
    ItemType myItemType;
    NodeItem *nodeChild;
    QGraphicsSimpleTextItem *TextChild;
    QTimer *m_cTimer;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // DRAWITEM_H
