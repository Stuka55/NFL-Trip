/********************************************************************************
** Form generated from reading UI file 'graphalgorithmviewwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHALGORITHMVIEWWIDGET_H
#define UI_GRAPHALGORITHMVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphAlgorithmViewWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QComboBox *algo_comboBox;
    QPushButton *showGraph_pushButton;
    QFrame *select_city;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *starting_Label;
    QLabel *from_Label;
    QComboBox *city1_comboBox;
    QPushButton *showGraph2_pushButton;
    QLabel *label;
    QPlainTextEdit *output_plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeWindow_pushButton;

    void setupUi(QWidget *GraphAlgorithmViewWidget)
    {
        if (GraphAlgorithmViewWidget->objectName().isEmpty())
            GraphAlgorithmViewWidget->setObjectName(QString::fromUtf8("GraphAlgorithmViewWidget"));
        GraphAlgorithmViewWidget->resize(1164, 616);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/window_icons/windowicons/graph_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GraphAlgorithmViewWidget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(GraphAlgorithmViewWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_2 = new QLabel(GraphAlgorithmViewWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        algo_comboBox = new QComboBox(GraphAlgorithmViewWidget);
        algo_comboBox->addItem(QString());
        algo_comboBox->addItem(QString());
        algo_comboBox->addItem(QString());
        algo_comboBox->addItem(QString());
        algo_comboBox->addItem(QString());
        algo_comboBox->setObjectName(QString::fromUtf8("algo_comboBox"));
        algo_comboBox->setMinimumSize(QSize(512, 0));
        algo_comboBox->setMaximumSize(QSize(512, 16777215));

        horizontalLayout->addWidget(algo_comboBox);

        showGraph_pushButton = new QPushButton(GraphAlgorithmViewWidget);
        showGraph_pushButton->setObjectName(QString::fromUtf8("showGraph_pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showGraph_pushButton->sizePolicy().hasHeightForWidth());
        showGraph_pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(showGraph_pushButton);


        verticalLayout->addLayout(horizontalLayout);

        select_city = new QFrame(GraphAlgorithmViewWidget);
        select_city->setObjectName(QString::fromUtf8("select_city"));
        select_city->setFrameShape(QFrame::NoFrame);
        select_city->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(select_city);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        starting_Label = new QLabel(select_city);
        starting_Label->setObjectName(QString::fromUtf8("starting_Label"));

        horizontalLayout_3->addWidget(starting_Label);

        from_Label = new QLabel(select_city);
        from_Label->setObjectName(QString::fromUtf8("from_Label"));

        horizontalLayout_3->addWidget(from_Label);

        city1_comboBox = new QComboBox(select_city);
        city1_comboBox->addItem(QString());
        city1_comboBox->setObjectName(QString::fromUtf8("city1_comboBox"));

        horizontalLayout_3->addWidget(city1_comboBox);

        showGraph2_pushButton = new QPushButton(select_city);
        showGraph2_pushButton->setObjectName(QString::fromUtf8("showGraph2_pushButton"));

        horizontalLayout_3->addWidget(showGraph2_pushButton);


        verticalLayout->addWidget(select_city);

        label = new QLabel(GraphAlgorithmViewWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        output_plainTextEdit = new QPlainTextEdit(GraphAlgorithmViewWidget);
        output_plainTextEdit->setObjectName(QString::fromUtf8("output_plainTextEdit"));
        output_plainTextEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(output_plainTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        closeWindow_pushButton = new QPushButton(GraphAlgorithmViewWidget);
        closeWindow_pushButton->setObjectName(QString::fromUtf8("closeWindow_pushButton"));

        horizontalLayout_2->addWidget(closeWindow_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(GraphAlgorithmViewWidget);

        QMetaObject::connectSlotsByName(GraphAlgorithmViewWidget);
    } // setupUi

    void retranslateUi(QWidget *GraphAlgorithmViewWidget)
    {
        GraphAlgorithmViewWidget->setWindowTitle(QCoreApplication::translate("GraphAlgorithmViewWidget", "Graph Utility", nullptr));
        label_2->setText(QCoreApplication::translate("GraphAlgorithmViewWidget", "Select Traversal Algorithm:", nullptr));
        algo_comboBox->setItemText(0, QCoreApplication::translate("GraphAlgorithmViewWidget", "None", nullptr));
        algo_comboBox->setItemText(1, QCoreApplication::translate("GraphAlgorithmViewWidget", "Depth-First Traversal (DFS)", nullptr));
        algo_comboBox->setItemText(2, QCoreApplication::translate("GraphAlgorithmViewWidget", "Breadth-First Traversal (BFS)", nullptr));
        algo_comboBox->setItemText(3, QCoreApplication::translate("GraphAlgorithmViewWidget", "Minimum Spanning Tree (MST)", nullptr));
        algo_comboBox->setItemText(4, QCoreApplication::translate("GraphAlgorithmViewWidget", "Dijkstra's Algorithm (Shortest Path)", nullptr));

        showGraph_pushButton->setText(QCoreApplication::translate("GraphAlgorithmViewWidget", "Show Graph", nullptr));
        starting_Label->setText(QCoreApplication::translate("GraphAlgorithmViewWidget", "Starting City:", nullptr));
        from_Label->setText(QCoreApplication::translate("GraphAlgorithmViewWidget", "From :", nullptr));
        city1_comboBox->setItemText(0, QCoreApplication::translate("GraphAlgorithmViewWidget", "None", nullptr));

        showGraph2_pushButton->setText(QCoreApplication::translate("GraphAlgorithmViewWidget", "Show Graph", nullptr));
        label->setText(QCoreApplication::translate("GraphAlgorithmViewWidget", "Viewing: Nothing", nullptr));
        closeWindow_pushButton->setText(QCoreApplication::translate("GraphAlgorithmViewWidget", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphAlgorithmViewWidget: public Ui_GraphAlgorithmViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHALGORITHMVIEWWIDGET_H
