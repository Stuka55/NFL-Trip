/********************************************************************************
** Form generated from reading UI file 'executetrip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXECUTETRIP_H
#define UI_EXECUTETRIP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ExecuteTrip
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QTextBrowser *info;
    QListWidget *merchandise;
    QSpinBox *quantity;
    QPushButton *add;
    QLabel *label_3;
    QListWidget *cart;
    QPushButton *next;
    QPushButton *cancel;
    QLabel *price;
    QPushButton *remove;

    void setupUi(QDialog *ExecuteTrip)
    {
        if (ExecuteTrip->objectName().isEmpty())
            ExecuteTrip->setObjectName(QString::fromUtf8("ExecuteTrip"));
        ExecuteTrip->resize(695, 445);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/window_icons/windowicons/trip_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExecuteTrip->setWindowIcon(icon);
        gridLayout = new QGridLayout(ExecuteTrip);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(ExecuteTrip);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(ExecuteTrip);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        info = new QTextBrowser(ExecuteTrip);
        info->setObjectName(QString::fromUtf8("info"));

        gridLayout->addWidget(info, 1, 0, 4, 2);

        merchandise = new QListWidget(ExecuteTrip);
        merchandise->setObjectName(QString::fromUtf8("merchandise"));

        gridLayout->addWidget(merchandise, 1, 2, 1, 2);

        quantity = new QSpinBox(ExecuteTrip);
        quantity->setObjectName(QString::fromUtf8("quantity"));

        gridLayout->addWidget(quantity, 2, 2, 1, 1);

        add = new QPushButton(ExecuteTrip);
        add->setObjectName(QString::fromUtf8("add"));

        gridLayout->addWidget(add, 2, 3, 1, 1);

        label_3 = new QLabel(ExecuteTrip);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 2, 1, 1);

        cart = new QListWidget(ExecuteTrip);
        cart->setObjectName(QString::fromUtf8("cart"));

        gridLayout->addWidget(cart, 4, 2, 2, 2);

        next = new QPushButton(ExecuteTrip);
        next->setObjectName(QString::fromUtf8("next"));

        gridLayout->addWidget(next, 5, 0, 1, 2);

        cancel = new QPushButton(ExecuteTrip);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        gridLayout->addWidget(cancel, 6, 1, 1, 1);

        price = new QLabel(ExecuteTrip);
        price->setObjectName(QString::fromUtf8("price"));

        gridLayout->addWidget(price, 6, 2, 1, 1);

        remove = new QPushButton(ExecuteTrip);
        remove->setObjectName(QString::fromUtf8("remove"));

        gridLayout->addWidget(remove, 6, 3, 1, 1);


        retranslateUi(ExecuteTrip);

        QMetaObject::connectSlotsByName(ExecuteTrip);
    } // setupUi

    void retranslateUi(QDialog *ExecuteTrip)
    {
        ExecuteTrip->setWindowTitle(QCoreApplication::translate("ExecuteTrip", "Trip", nullptr));
        label_2->setText(QCoreApplication::translate("ExecuteTrip", "Current Team Info:", nullptr));
        label->setText(QCoreApplication::translate("ExecuteTrip", "Souvenirs: ", nullptr));
        info->setHtml(QCoreApplication::translate("ExecuteTrip", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter info: </p></body></html>", nullptr));
        add->setText(QCoreApplication::translate("ExecuteTrip", "Add", nullptr));
        label_3->setText(QCoreApplication::translate("ExecuteTrip", "Shopping Cart:", nullptr));
        next->setText(QCoreApplication::translate("ExecuteTrip", "Next", nullptr));
        cancel->setText(QCoreApplication::translate("ExecuteTrip", "Cancel", nullptr));
        price->setText(QCoreApplication::translate("ExecuteTrip", "Current Price: $0.00", nullptr));
        remove->setText(QCoreApplication::translate("ExecuteTrip", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExecuteTrip: public Ui_ExecuteTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXECUTETRIP_H
