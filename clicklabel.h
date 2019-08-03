#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class clickLabel : public QLabel
{
    Q_OBJECT
public:
    explicit clickLabel(QWidget *parent = nullptr);

signals:
    void clicked(QMouseEvent *ev);

protected:
    void mouseReleaseEvent(QMouseEvent *ev);

public slots:
};

#endif // CLICKLABEL_H
