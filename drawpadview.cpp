#include "drawpadview.h"
#include <QDebug>

DrawPadView::DrawPadView(QWidget *parent) :
    QGraphicsView (parent)
{

}

void DrawPadView::wheelEvent(QWheelEvent *event)
{
    int y = event->angleDelta().y();

    if (y > 0)
    {
        ZoomIn();
    }
    else
    {
        ZoomOut();
    }
}

void DrawPadView::ZoomIn()
{
    qreal temp_scale = m_scale + m_zoomDelta;

    if (temp_scale - 0.01 > 2.0 || temp_scale + 0.01 < 0.25)
    {
        return;
    }

    m_scale = temp_scale;
    Zoom(temp_scale);
}

void DrawPadView::ZoomOut()
{
    qreal temp_scale = m_scale - m_zoomDelta;

    if (temp_scale - 0.01 > 2.0 || temp_scale + 0.01 < 0.25)
    {
        return;
    }

    m_scale = temp_scale;
    Zoom(temp_scale);
}

void DrawPadView::Zoom(qreal newScale)
{
    qDebug() << newScale;

    QWidget* centralParent = static_cast<QWidget*>(parentWidget());
    DrawPad *padParent = static_cast<DrawPad*>(centralParent->parentWidget());
    padParent->ChangeComboBoxItem(newScale, 5);

    QMatrix oldMatrix = this->matrix();
    this->resetMatrix();
    this->translate(oldMatrix.dx(), oldMatrix.dy());
    this->scale(newScale, newScale);
}
