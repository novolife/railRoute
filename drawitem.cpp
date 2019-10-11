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

    TextChild = new QGraphicsSimpleTextItem("name");
    TextChild->setPos(nodeChild->boundingRect().width(), -10);

    this->addToGroup(nodeChild);
    this->addToGroup(TextChild);
    this->setHandlesChildEvents(true);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    m_cTimer = new QTimer();

    connect(m_cTimer, &QTimer::timeout, this, &DrawItem::slotTimerTimeOut);
}

void DrawItem::mousePressEvent(QMouseEvent *e)
{
    m_cTimer->start(500);
    qDebug() << "aaaaabb";
    e->accept();
}

void DrawItem::mouseDoubleClickEvent(QMouseEvent *e)
{
    m_cTimer->stop();

    qDebug() << "aaaaa";

    QString nodeName;

    switch (langType)
    {
        case 0:
        {
            nodeName = QInputDialog::getText(nullptr, "Input the name", "Input the name of the selecetd node:");
            break;
        }

        case 1:
        {
            nodeName = QInputDialog::getText(nullptr, QString::fromLocal8Bit("输入名称"), QString::fromLocal8Bit("输入所选节点的名称: "));
            break;
        }

        case 2:
        {
            nodeName = QInputDialog::getText(nullptr, "Input the name", "Input the name of the selecetd node:");
            break;
        }
    }

    this->TextChild->setText(nodeName);
    e->accept();
}

void DrawItem::slotTimerTimeOut()
{
    m_cTimer->stop();
}
