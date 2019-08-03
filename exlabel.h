#ifndef EXLABEL_H
#define EXLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class ExLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ExLabel(QWidget *parent = nullptr);

signals:
    void clicked(QMouseEvent *ev);

protected:
    void mouseReleaseEvent(QMouseEvent *ev);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

public slots:
};

#endif // EXLABEL_H
