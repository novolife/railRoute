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
