/********************************************************************************
** Form generated from reading UI file 'monke.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONKE_H
#define UI_MONKE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_monke
{
public:
    QGridLayout *gridLayout;
    ClickableLabel *label;

    void setupUi(QWidget *monke)
    {
        if (monke->objectName().isEmpty())
            monke->setObjectName(QString::fromUtf8("monke"));
        monke->resize(830, 560);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MONKEE/windowicons/monke/banana.png"), QSize(), QIcon::Normal, QIcon::Off);
        monke->setWindowIcon(icon);
        gridLayout = new QGridLayout(monke);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new ClickableLabel(monke);
        label->setObjectName(QString::fromUtf8("label"));
        label->setCursor(QCursor(Qt::PointingHandCursor));
        label->setPixmap(QPixmap(QString::fromUtf8(":/MONKEE/windowicons/monke/monke.jpg")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(monke);

        QMetaObject::connectSlotsByName(monke);
    } // setupUi

    void retranslateUi(QWidget *monke)
    {
        monke->setWindowTitle(QCoreApplication::translate("monke", "Monkey", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class monke: public Ui_monke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONKE_H
