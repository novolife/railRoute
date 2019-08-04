#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

namespace Ui {
class about;
}

class about : public QWidget
{
    Q_OBJECT

public:
    explicit about();
    ~about();

private slots:
    void on_githubLabel_clicked();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
