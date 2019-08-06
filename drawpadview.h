#ifndef DRAWPADVIEW_H
#define DRAWPADVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>

#include "drawpad.h"

class DrawPadView : public QGraphicsView
{
    Q_OBJECT

public:
    DrawPadView(QWidget *parent = nullptr);

    QWidget *padParent;

public Q_SLOT:
    void ZoomIn();
    void ZoomOut();
    void Zoom(qreal scaleFactor);

private:
    qreal m_scale = 1.0;
    qreal m_zoomDelta = 0.05;

protected:
    void wheelEvent(QWheelEvent *event = nullptr);
};

#endif // DRAWPADVIEW_H
