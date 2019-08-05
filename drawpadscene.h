#ifndef DRAWPADSCENE_H
#define DRAWPADSCENE_H

#include <QGraphicsScene>

class DrawPadScene : public QGraphicsScene
{
public:
    enum Mode
    {
        InsertItem,
        InsertLine,
        InsertText,
        MoveItem
    };

    DrawPadScene();
    QFont font() const { return myFont; }
    QColor textColor() const { return myTextColor; }
    QColor itemColor() const { return myItemColor; }
    QColor lineColor() const { return myLineColor; }
    void setLineColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setItemColor(const QColor &color);
    void setFont(const QFont &font);

private:
    QColor myTextColor;
    QColor myItemColor;
    QColor myLineColor;
    QFont  myFont;

};

#endif // DRAWPADSCENE_H
