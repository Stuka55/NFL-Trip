/********************************************************************************
** Form generated from reading UI file 'tripplanner.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPLANNER_H
#define UI_TRIPPLANNER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tripPlanner
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QStackedWidget *stackedWidget;
    QWidget *noTrip_tab;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QWidget *kimTrip_tab;
    QGridLayout *gridLayout_6;
    QLabel *label_9;
    QLabel *label_8;
    QComboBox *packers_comboBox;
    QWidget *zachTrip_tab;
    QGridLayout *gridLayout_5;
    QLabel *label_6;
    QListWidget *patriots_listWidget;
    QLabel *label_7;
    QWidget *straussTrip_tab;
    QGridLayout *gridLayout_3;
    QLabel *starting_label;
    QListWidget *listWidget;
    QLabel *label_2;
    QLabel *label;
    QListWidget *listWidget_2;
    QLabel *label_3;
    QComboBox *starting_comboBox;
    QLabel *label_13;
    QWidget *tranTrip_tab;
    QGridLayout *gridLayout_7;
    QListWidget *custom2_optionsList;
    QListWidget *custom2_selected;
    QComboBox *startingTeam_combo_2;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_15;
    QComboBox *comboBox;
    QPushButton *close_pushButton;

    void setupUi(QDialog *tripPlanner)
    {
        if (tripPlanner->objectName().isEmpty())
            tripPlanner->setObjectName(QString::fromUtf8("tripPlanner"));
        tripPlanner->resize(882, 992);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tripPlanner->sizePolicy().hasHeightForWidth());
        tripPlanner->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/window_icons/windowicons/tripform_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tripPlanner->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(tripPlanner);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(tripPlanner);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(2);
        label_5 = new QLabel(tripPlanner);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(tripPlanner);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        noTrip_tab = new QWidget();
        noTrip_tab->setObjectName(QString::fromUtf8("noTrip_tab"));
        gridLayout_4 = new QGridLayout(noTrip_tab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(noTrip_tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        stackedWidget->addWidget(noTrip_tab);
        kimTrip_tab = new QWidget();
        kimTrip_tab->setObjectName(QString::fromUtf8("kimTrip_tab"));
        gridLayout_6 = new QGridLayout(kimTrip_tab);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_9 = new QLabel(kimTrip_tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 1, 0, 1, 1);

        label_8 = new QLabel(kimTrip_tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_8->setFont(font1);

        gridLayout_6->addWidget(label_8, 0, 0, 1, 1);

        packers_comboBox = new QComboBox(kimTrip_tab);
        packers_comboBox->setObjectName(QString::fromUtf8("packers_comboBox"));

        gridLayout_6->addWidget(packers_comboBox, 2, 0, 1, 1);

        stackedWidget->addWidget(kimTrip_tab);
        zachTrip_tab = new QWidget();
        zachTrip_tab->setObjectName(QString::fromUtf8("zachTrip_tab"));
        gridLayout_5 = new QGridLayout(zachTrip_tab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_6 = new QLabel(zachTrip_tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        patriots_listWidget = new QListWidget(zachTrip_tab);
        patriots_listWidget->setObjectName(QString::fromUtf8("patriots_listWidget"));

        gridLayout_5->addWidget(patriots_listWidget, 2, 0, 1, 1);

        label_7 = new QLabel(zachTrip_tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        stackedWidget->addWidget(zachTrip_tab);
        straussTrip_tab = new QWidget();
        straussTrip_tab->setObjectName(QString::fromUtf8("straussTrip_tab"));
        gridLayout_3 = new QGridLayout(straussTrip_tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        starting_label = new QLabel(straussTrip_tab);
        starting_label->setObjectName(QString::fromUtf8("starting_label"));

        gridLayout_3->addWidget(starting_label, 2, 0, 1, 1);

        listWidget = new QListWidget(straussTrip_tab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout_3->addWidget(listWidget, 5, 0, 1, 1);

        label_2 = new QLabel(straussTrip_tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(straussTrip_tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 4, 0, 1, 1);

        listWidget_2 = new QListWidget(straussTrip_tab);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        gridLayout_3->addWidget(listWidget_2, 7, 0, 1, 1);

        label_3 = new QLabel(straussTrip_tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 6, 0, 1, 1);

        starting_comboBox = new QComboBox(straussTrip_tab);
        starting_comboBox->setObjectName(QString::fromUtf8("starting_comboBox"));

        gridLayout_3->addWidget(starting_comboBox, 3, 0, 1, 1);

        label_13 = new QLabel(straussTrip_tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        stackedWidget->addWidget(straussTrip_tab);
        tranTrip_tab = new QWidget();
        tranTrip_tab->setObjectName(QString::fromUtf8("tranTrip_tab"));
        gridLayout_7 = new QGridLayout(tranTrip_tab);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        custom2_optionsList = new QListWidget(tranTrip_tab);
        custom2_optionsList->setObjectName(QString::fromUtf8("custom2_optionsList"));

        gridLayout_7->addWidget(custom2_optionsList, 6, 0, 1, 1);

        custom2_selected = new QListWidget(tranTrip_tab);
        custom2_selected->setObjectName(QString::fromUtf8("custom2_selected"));

        gridLayout_7->addWidget(custom2_selected, 8, 0, 1, 1);

        startingTeam_combo_2 = new QComboBox(tranTrip_tab);
        startingTeam_combo_2->setObjectName(QString::fromUtf8("startingTeam_combo_2"));

        gridLayout_7->addWidget(startingTeam_combo_2, 4, 0, 1, 1);

        label_11 = new QLabel(tranTrip_tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_7->addWidget(label_11, 5, 0, 1, 1);

        label_10 = new QLabel(tranTrip_tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_7->addWidget(label_10, 2, 0, 1, 1);

        label_14 = new QLabel(tranTrip_tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        gridLayout_7->addWidget(label_14, 0, 0, 1, 1);

        label_12 = new QLabel(tranTrip_tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_7->addWidget(label_12, 7, 0, 1, 1);

        label_15 = new QLabel(tranTrip_tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_7->addWidget(label_15, 1, 0, 1, 1);

        stackedWidget->addWidget(tranTrip_tab);

        gridLayout->addWidget(stackedWidget, 2, 0, 1, 1);

        comboBox = new QComboBox(tripPlanner);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        close_pushButton = new QPushButton(tripPlanner);
        close_pushButton->setObjectName(QString::fromUtf8("close_pushButton"));

        gridLayout_2->addWidget(close_pushButton, 2, 0, 1, 1);


        retranslateUi(tripPlanner);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(tripPlanner);
    } // setupUi

    void retranslateUi(QDialog *tripPlanner)
    {
        tripPlanner->setWindowTitle(QCoreApplication::translate("tripPlanner", "Trip Planner", nullptr));
        pushButton->setText(QCoreApplication::translate("tripPlanner", "Execute Trip", nullptr));
        label_5->setText(QCoreApplication::translate("tripPlanner", "Trip Selector:", nullptr));
        label_4->setText(QCoreApplication::translate("tripPlanner", "Please select a trip from the dropdown menu.", nullptr));
        label_9->setText(QCoreApplication::translate("tripPlanner", "Select one other team to visit:", nullptr));
        label_8->setText(QCoreApplication::translate("tripPlanner", "Trip Information", nullptr));
        label_6->setText(QCoreApplication::translate("tripPlanner", "Trip Information", nullptr));
        label_7->setText(QCoreApplication::translate("tripPlanner", "The following Stadiums will be visited on this trip, starting with the New England Patriots:", nullptr));
        starting_label->setText(QCoreApplication::translate("tripPlanner", "Starting Team:", nullptr));
        label_2->setText(QCoreApplication::translate("tripPlanner", "Trip Information", nullptr));
        label->setText(QCoreApplication::translate("tripPlanner", "Select Multiple Teams:", nullptr));
        label_3->setText(QCoreApplication::translate("tripPlanner", "Current Trip:", nullptr));
        label_13->setText(QCoreApplication::translate("tripPlanner", "This trip visits the teams in the specified order.", nullptr));
        label_11->setText(QCoreApplication::translate("tripPlanner", "Select Multiple Teams:", nullptr));
        label_10->setText(QCoreApplication::translate("tripPlanner", "Starting Team:", nullptr));
        label_14->setText(QCoreApplication::translate("tripPlanner", "Trip Information", nullptr));
        label_12->setText(QCoreApplication::translate("tripPlanner", "Current Trip:", nullptr));
        label_15->setText(QCoreApplication::translate("tripPlanner", "This trip visits the selected trips in the optimal order.", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("tripPlanner", "None", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("tripPlanner", "Green Bay Packers Trip", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("tripPlanner", "New England Patriots Trip", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("tripPlanner", "Custom Trip (Specified Order)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("tripPlanner", "Custom Trip (Shortest Distance)", nullptr));

        close_pushButton->setText(QCoreApplication::translate("tripPlanner", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tripPlanner: public Ui_tripPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPLANNER_H
