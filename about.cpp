#include "about.h"
#include "ui_about.h"
#include "common.h"

#include <QtWidgets>
#include <QDesktopServices>

/**
 * @brief constructor of "about"
 */
about::about() :
    ui(new Ui::about)
{
    ui->setupUi(this);
    switch (langType)
    {
        case 0:
            {
                QTranslator enTranslator;
                enTranslator.load(":/res/i18n/translate_EN.qm");
                qApp->installTranslator(&enTranslator);
                this->ui->retranslateUi(this);
                break;
            }

        case 1:
            {
                QTranslator zhsTranslator;
                zhsTranslator.load(":/res/i18n/translate_ZHS.qm");
                qApp->installTranslator(&zhsTranslator);
                this->ui->retranslateUi(this);
                break;
            }

    }

    setAttribute(Qt::WA_ShowModal, true);
}

/**
 * @brief about::~about
 */
about::~about()
{
    delete ui;
}

/**
 * @brief slot function of the github label, open the github repo
 */
void about::on_githubLabel_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/Yu1Aragaki/railRoute")));
}
