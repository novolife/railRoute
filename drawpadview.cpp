#include "drawpadview.h"
#include <QDebug>

DrawPadView::DrawPadView(QWidget *parent) :
    QGraphicsView (parent)
{

}

/**
 * @brief wheelEvent
 * @param event
 */
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

/**
 * @brief calculate the new scale if zoom in
 */
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

/**
 * @brief calculate the new scale if zoom out
 */
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

/**
 * @brief zoom in/out the view
 * @param newScale
 */
void DrawPadView::Zoom(qreal newScale)
{
    DrawPad *padParent = static_cast<DrawPad*>(parentWidget()->parentWidget());
    QMatrix oldMatrix = this->matrix();

    padParent->ChangeComboBoxItem(newScale, 5);

    this->resetMatrix();
    this->translate(oldMatrix.dx(), oldMatrix.dy());
    this->scale(newScale, newScale);
}
