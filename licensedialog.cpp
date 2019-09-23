#include "licensedialog.h"
#include "ui_licensedialog.h"

licenseDialog::licenseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::licenseDialog)
{
    ui->setupUi(this);

    QTranslator *translator = new QTranslator();
    switch (langType)
    {
    case 0:
    {
        translator->load(":/res/i18n/translate_EN.qm");
        qApp->installTranslator(translator);
        this->ui->retranslateUi(this);
        break;
    }

    case 1:
    {
        translator->load(":/res/i18n/translate_ZHS.qm");
        qApp->installTranslator(translator);
        this->ui->retranslateUi(this);
        break;
    }

    case 2:
    {
        translator->load(":/res/i18n/translate_JP.qm");
        qApp->installTranslator(translator);
        this->ui->retranslateUi(this);
        break;
    }
    }
}

licenseDialog::~licenseDialog()
{
    delete ui;
}
