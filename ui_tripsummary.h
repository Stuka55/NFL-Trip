/********************************************************************************
** Form generated from reading UI file 'tripsummary.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPSUMMARY_H
#define UI_TRIPSUMMARY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_tripSummary
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QListWidget *teams;
    QTextBrowser *receipt;
    QPushButton *close;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QDialog *tripSummary)
    {
        if (tripSummary->objectName().isEmpty())
            tripSummary->setObjectName(QString::fromUtf8("tripSummary"));
        tripSummary->resize(622, 459);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/window_icons/windowicons/trip_summary.png"), QSize(), QIcon::Normal, QIcon::Off);
        tripSummary->setWindowIcon(icon);
        gridLayout = new QGridLayout(tripSummary);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(tripSummary);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        teams = new QListWidget(tripSummary);
        teams->setObjectName(QString::fromUtf8("teams"));

        gridLayout->addWidget(teams, 2, 0, 1, 2);

        receipt = new QTextBrowser(tripSummary);
        receipt->setObjectName(QString::fromUtf8("receipt"));

        gridLayout->addWidget(receipt, 2, 2, 1, 2);

        close = new QPushButton(tripSummary);
        close->setObjectName(QString::fromUtf8("close"));

        gridLayout->addWidget(close, 3, 0, 1, 4);

        label_3 = new QLabel(tripSummary);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label = new QLabel(tripSummary);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 4);


        retranslateUi(tripSummary);

        QMetaObject::connectSlotsByName(tripSummary);
    } // setupUi

    void retranslateUi(QDialog *tripSummary)
    {
        tripSummary->setWindowTitle(QCoreApplication::translate("tripSummary", "Trip Summary", nullptr));
        label_2->setText(QCoreApplication::translate("tripSummary", "Teams:", nullptr));
        close->setText(QCoreApplication::translate("tripSummary", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("tripSummary", "Receipt:", nullptr));
        label->setText(QCoreApplication::translate("tripSummary", "Trip Summary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tripSummary: public Ui_tripSummary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPSUMMARY_H
