#ifndef LICENSEDIALOG_H
#define LICENSEDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "../Algorithm/common.h"

namespace Ui {
class licenseDialog;
}

class licenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit licenseDialog(QWidget *parent = nullptr);
    ~licenseDialog();

private:
    Ui::licenseDialog *ui;
};

#endif // LICENSEDIALOG_H
