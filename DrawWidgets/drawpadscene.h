/**
 *    A program which can calculate a longest path of a rail system.
 *    Copyright (C) 2019  J. HUANG
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 */

#ifndef DRAWPADSCENE_H
#define DRAWPADSCENE_H

#include <QGraphicsScene>
#include "drawitem.h"

class DrawPadScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum Mode
    {
        InsertItem,
        InsertLine,
        InsertText,
        MoveItem
    };
    Q_ENUM(Mode)

    DrawPadScene();

    QFont font() const { return myFont; }
    QColor textColor() const { return myTextColor; }
    QColor itemColor() const { return myItemColor; }
    QColor lineColor() const { return myLineColor; }
    void setLineColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setItemColor(const QColor &color);
    void setFont(const QFont &font);

public slots:
    void setMode(Mode mode);
    void setItemType(DrawItem::ItemType type);
    //void editorLostFocus(DrawItem *item);

signals:
    void itemInserted(DrawItem *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    QColor myTextColor;
    QColor myItemColor;
    QColor myLineColor;
    QFont  myFont;
    Mode   myMode;
    DrawItem::ItemType myItemType;

};

#endif // DRAWPADSCENE_H
