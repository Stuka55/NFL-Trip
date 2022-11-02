/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Database;
    QAction *actionQuit;
    QAction *actionLogin;
    QAction *actionGraph_Utility;
    QAction *actionTrip_Planner;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_18;
    QPushButton *nflSortButton;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *splash;
    QComboBox *nflSortingComboBox;
    QTextBrowser *allNFLTeams;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QComboBox *nflSelectComboBox;
    QLabel *label_2;
    QTextBrowser *nflSelectTextBrowser;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QLabel *teamSelect_Label;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QPushButton *ApplyChanges_pushButton_2;
    QGridLayout *gridLayout_9;
    QComboBox *stadium_comboBox;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_16;
    QLineEdit *teamName_lineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *addTeam_pushButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QTableWidget *Souvenirs_ListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addNewSouvenir_button;
    QPushButton *deleteSelected;
    QLabel *label_5;
    QPushButton *ApplyChanges_pushButton;
    QWidget *tab_3;
    QGridLayout *gridLayout_7;
    QFrame *line;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *editStad_button;
    QStackedWidget *Stadium_editor;
    QWidget *page;
    QGridLayout *gridLayout_12;
    QPushButton *addStadFile_pushButton;
    QPushButton *addStad_pushButton;
    QLabel *label_14;
    QGridLayout *fields;
    QLabel *label_6;
    QLineEdit *date_lineEdit;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_10;
    QLineEdit *div_lineEdit;
    QLabel *label_12;
    QLineEdit *loc_lineEdit;
    QComboBox *roof_combo;
    QLabel *label_8;
    QLineEdit *name_lineEdit;
    QLineEdit *conf_lineEdit;
    QComboBox *surface_combo;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *seats_lineEdit;
    QWidget *page_2;
    QGridLayout *gridLayout_8;
    QLabel *label_30;
    QPushButton *cancelChanges_button;
    QPushButton *accept_button;
    QGridLayout *fields_2;
    QLabel *label_22;
    QLineEdit *date_lineEdit_2;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *div_lineEdit_2;
    QLabel *label_26;
    QLineEdit *loc_lineEdit_2;
    QComboBox *roof_combo_2;
    QLabel *label_27;
    QLineEdit *name_lineEdit_2;
    QLineEdit *conf_lineEdit_2;
    QComboBox *surface_combo_2;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *seats_lineEdit_2;
    QCheckBox *checkBox;
    QWidget *tab_5;
    QGridLayout *gridLayout_13;
    QTableWidget *distance_table;
    QPushButton *deleteEdge_button;
    QGridLayout *gridLayout_14;
    QComboBox *toStad_combo;
    QComboBox *fromStad_combo;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *dist;
    QPushButton *addEdge_button;
    QWidget *tab_4;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_34;
    QPushButton *save_pushButton;
    QPushButton *revert_pushButton;
    QSpacerItem *verticalSpacer_2;
    QFrame *toolbox;
    QGridLayout *toolBox;
    QSpacerItem *horizontalSpacer;
    QFrame *line_4;
    ClickableLabel *open_Database;
    QLabel *label_20;
    ClickableLabel *graph_util;
    ClickableLabel *login;
    ClickableLabel *quit;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_3;
    QFrame *line_2;
    QFrame *line_3;
    ClickableLabel *planner_util;
    QLabel *label_35;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1365, 1226);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/window_icons/windowicons/main_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_Database = new QAction(MainWindow);
        actionOpen_Database->setObjectName(QString::fromUtf8("actionOpen_Database"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/window_icons/windowicons/database_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Database->setIcon(icon1);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/window_icons/windowicons/exit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon2);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/window_icons/windowicons/login_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogin->setIcon(icon3);
        actionGraph_Utility = new QAction(MainWindow);
        actionGraph_Utility->setObjectName(QString::fromUtf8("actionGraph_Utility"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/window_icons/windowicons/graph_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGraph_Utility->setIcon(icon4);
        actionTrip_Planner = new QAction(MainWindow);
        actionTrip_Planner->setObjectName(QString::fromUtf8("actionTrip_Planner"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/window_icons/windowicons/trip_util_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTrip_Planner->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_2->addWidget(label_18, 2, 0, 1, 1);

        nflSortButton = new QPushButton(frame);
        nflSortButton->setObjectName(QString::fromUtf8("nflSortButton"));

        gridLayout_2->addWidget(nflSortButton, 6, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        splash = new QLabel(frame);
        splash->setObjectName(QString::fromUtf8("splash"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splash->sizePolicy().hasHeightForWidth());
        splash->setSizePolicy(sizePolicy1);
        splash->setMinimumSize(QSize(258, 86));
        splash->setMaximumSize(QSize(258, 86));
        splash->setPixmap(QPixmap(QString::fromUtf8(":/Files/splash.png")));
        splash->setScaledContents(true);

        horizontalLayout_3->addWidget(splash);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        nflSortingComboBox = new QComboBox(frame);
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->addItem(QString());
        nflSortingComboBox->setObjectName(QString::fromUtf8("nflSortingComboBox"));

        gridLayout_2->addWidget(nflSortingComboBox, 5, 0, 1, 1);

        allNFLTeams = new QTextBrowser(frame);
        allNFLTeams->setObjectName(QString::fromUtf8("allNFLTeams"));

        gridLayout_2->addWidget(allNFLTeams, 3, 0, 1, 1);


        gridLayout->addWidget(frame, 3, 0, 3, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 2, 0, 1, 1);

        nflSelectComboBox = new QComboBox(frame_2);
        nflSelectComboBox->setObjectName(QString::fromUtf8("nflSelectComboBox"));

        gridLayout_3->addWidget(nflSelectComboBox, 1, 0, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        nflSelectTextBrowser = new QTextBrowser(frame_2);
        nflSelectTextBrowser->setObjectName(QString::fromUtf8("nflSelectTextBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nflSelectTextBrowser->sizePolicy().hasHeightForWidth());
        nflSelectTextBrowser->setSizePolicy(sizePolicy2);
        nflSelectTextBrowser->setMinimumSize(QSize(512, 256));
        nflSelectTextBrowser->setMaximumSize(QSize(512, 16777215));

        gridLayout_3->addWidget(nflSelectTextBrowser, 0, 1, 3, 1);


        gridLayout->addWidget(frame_2, 3, 1, 1, 1);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        teamSelect_Label = new QLabel(frame_3);
        teamSelect_Label->setObjectName(QString::fromUtf8("teamSelect_Label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell"));
        teamSelect_Label->setFont(font);
        teamSelect_Label->setLayoutDirection(Qt::LeftToRight);
        teamSelect_Label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(teamSelect_Label, 1, 0, 1, 1);

        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frame_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        ApplyChanges_pushButton_2 = new QPushButton(tab);
        ApplyChanges_pushButton_2->setObjectName(QString::fromUtf8("ApplyChanges_pushButton_2"));

        gridLayout_6->addWidget(ApplyChanges_pushButton_2, 6, 0, 1, 2);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        stadium_comboBox = new QComboBox(tab);
        stadium_comboBox->setObjectName(QString::fromUtf8("stadium_comboBox"));

        gridLayout_9->addWidget(stadium_comboBox, 2, 1, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_9->addWidget(label_15, 1, 0, 1, 1);

        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_17, 0, 0, 1, 2);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_9->addWidget(label_16, 2, 0, 1, 1);

        teamName_lineEdit = new QLineEdit(tab);
        teamName_lineEdit->setObjectName(QString::fromUtf8("teamName_lineEdit"));

        gridLayout_9->addWidget(teamName_lineEdit, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 3, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_9, 1, 0, 1, 2);

        addTeam_pushButton = new QPushButton(tab);
        addTeam_pushButton->setObjectName(QString::fromUtf8("addTeam_pushButton"));

        gridLayout_6->addWidget(addTeam_pushButton, 5, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        Souvenirs_ListWidget = new QTableWidget(tab_2);
        Souvenirs_ListWidget->setObjectName(QString::fromUtf8("Souvenirs_ListWidget"));
        Souvenirs_ListWidget->setEnabled(false);
        Souvenirs_ListWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        Souvenirs_ListWidget->setColumnCount(0);
        Souvenirs_ListWidget->horizontalHeader()->setMinimumSectionSize(35);

        gridLayout_5->addWidget(Souvenirs_ListWidget, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addNewSouvenir_button = new QPushButton(tab_2);
        addNewSouvenir_button->setObjectName(QString::fromUtf8("addNewSouvenir_button"));
        addNewSouvenir_button->setEnabled(false);

        horizontalLayout->addWidget(addNewSouvenir_button);

        deleteSelected = new QPushButton(tab_2);
        deleteSelected->setObjectName(QString::fromUtf8("deleteSelected"));
        deleteSelected->setEnabled(false);

        horizontalLayout->addWidget(deleteSelected);


        gridLayout_5->addLayout(horizontalLayout, 2, 0, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        ApplyChanges_pushButton = new QPushButton(tab_2);
        ApplyChanges_pushButton->setObjectName(QString::fromUtf8("ApplyChanges_pushButton"));
        ApplyChanges_pushButton->setEnabled(false);

        gridLayout_5->addWidget(ApplyChanges_pushButton, 3, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_7 = new QGridLayout(tab_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        line = new QFrame(tab_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line, 3, 0, 1, 1);

        listWidget = new QListWidget(tab_3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setModelColumn(0);

        gridLayout_7->addWidget(listWidget, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        editStad_button = new QPushButton(tab_3);
        editStad_button->setObjectName(QString::fromUtf8("editStad_button"));

        horizontalLayout_2->addWidget(editStad_button);


        gridLayout_7->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        Stadium_editor = new QStackedWidget(tab_3);
        Stadium_editor->setObjectName(QString::fromUtf8("Stadium_editor"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_12 = new QGridLayout(page);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        addStadFile_pushButton = new QPushButton(page);
        addStadFile_pushButton->setObjectName(QString::fromUtf8("addStadFile_pushButton"));

        gridLayout_12->addWidget(addStadFile_pushButton, 3, 0, 1, 1);

        addStad_pushButton = new QPushButton(page);
        addStad_pushButton->setObjectName(QString::fromUtf8("addStad_pushButton"));

        gridLayout_12->addWidget(addStad_pushButton, 2, 0, 1, 1);

        label_14 = new QLabel(page);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        gridLayout_12->addWidget(label_14, 0, 0, 1, 1);

        fields = new QGridLayout();
        fields->setObjectName(QString::fromUtf8("fields"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        fields->addWidget(label_6, 1, 0, 1, 1);

        date_lineEdit = new QLineEdit(page);
        date_lineEdit->setObjectName(QString::fromUtf8("date_lineEdit"));

        fields->addWidget(date_lineEdit, 6, 1, 1, 1);

        label_11 = new QLabel(page);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        fields->addWidget(label_11, 7, 0, 1, 1);

        label_13 = new QLabel(page);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        fields->addWidget(label_13, 6, 0, 1, 1);

        label_10 = new QLabel(page);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        fields->addWidget(label_10, 5, 0, 1, 1);

        div_lineEdit = new QLineEdit(page);
        div_lineEdit->setObjectName(QString::fromUtf8("div_lineEdit"));

        fields->addWidget(div_lineEdit, 5, 1, 1, 1);

        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        fields->addWidget(label_12, 8, 0, 1, 1);

        loc_lineEdit = new QLineEdit(page);
        loc_lineEdit->setObjectName(QString::fromUtf8("loc_lineEdit"));

        fields->addWidget(loc_lineEdit, 3, 1, 1, 1);

        roof_combo = new QComboBox(page);
        roof_combo->setObjectName(QString::fromUtf8("roof_combo"));

        fields->addWidget(roof_combo, 8, 1, 1, 1);

        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        fields->addWidget(label_8, 3, 0, 1, 1);

        name_lineEdit = new QLineEdit(page);
        name_lineEdit->setObjectName(QString::fromUtf8("name_lineEdit"));

        fields->addWidget(name_lineEdit, 1, 1, 1, 1);

        conf_lineEdit = new QLineEdit(page);
        conf_lineEdit->setObjectName(QString::fromUtf8("conf_lineEdit"));

        fields->addWidget(conf_lineEdit, 4, 1, 1, 1);

        surface_combo = new QComboBox(page);
        surface_combo->setObjectName(QString::fromUtf8("surface_combo"));

        fields->addWidget(surface_combo, 7, 1, 1, 1);

        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        fields->addWidget(label_7, 2, 0, 1, 1);

        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        fields->addWidget(label_9, 4, 0, 1, 1);

        seats_lineEdit = new QLineEdit(page);
        seats_lineEdit->setObjectName(QString::fromUtf8("seats_lineEdit"));

        fields->addWidget(seats_lineEdit, 2, 1, 1, 1);


        gridLayout_12->addLayout(fields, 1, 0, 1, 1);

        Stadium_editor->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_8 = new QGridLayout(page_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_30 = new QLabel(page_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font1);

        gridLayout_8->addWidget(label_30, 1, 0, 1, 1);

        cancelChanges_button = new QPushButton(page_2);
        cancelChanges_button->setObjectName(QString::fromUtf8("cancelChanges_button"));

        gridLayout_8->addWidget(cancelChanges_button, 4, 0, 1, 1);

        accept_button = new QPushButton(page_2);
        accept_button->setObjectName(QString::fromUtf8("accept_button"));

        gridLayout_8->addWidget(accept_button, 3, 0, 1, 1);

        fields_2 = new QGridLayout();
        fields_2->setObjectName(QString::fromUtf8("fields_2"));
        label_22 = new QLabel(page_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        fields_2->addWidget(label_22, 1, 0, 1, 1);

        date_lineEdit_2 = new QLineEdit(page_2);
        date_lineEdit_2->setObjectName(QString::fromUtf8("date_lineEdit_2"));

        fields_2->addWidget(date_lineEdit_2, 6, 1, 1, 1);

        label_23 = new QLabel(page_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        fields_2->addWidget(label_23, 7, 0, 1, 1);

        label_24 = new QLabel(page_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        fields_2->addWidget(label_24, 6, 0, 1, 1);

        label_25 = new QLabel(page_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        fields_2->addWidget(label_25, 5, 0, 1, 1);

        div_lineEdit_2 = new QLineEdit(page_2);
        div_lineEdit_2->setObjectName(QString::fromUtf8("div_lineEdit_2"));

        fields_2->addWidget(div_lineEdit_2, 5, 1, 1, 1);

        label_26 = new QLabel(page_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        fields_2->addWidget(label_26, 8, 0, 1, 1);

        loc_lineEdit_2 = new QLineEdit(page_2);
        loc_lineEdit_2->setObjectName(QString::fromUtf8("loc_lineEdit_2"));

        fields_2->addWidget(loc_lineEdit_2, 3, 1, 1, 1);

        roof_combo_2 = new QComboBox(page_2);
        roof_combo_2->setObjectName(QString::fromUtf8("roof_combo_2"));

        fields_2->addWidget(roof_combo_2, 8, 1, 1, 1);

        label_27 = new QLabel(page_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        fields_2->addWidget(label_27, 3, 0, 1, 1);

        name_lineEdit_2 = new QLineEdit(page_2);
        name_lineEdit_2->setObjectName(QString::fromUtf8("name_lineEdit_2"));
        name_lineEdit_2->setEnabled(false);

        fields_2->addWidget(name_lineEdit_2, 1, 1, 1, 1);

        conf_lineEdit_2 = new QLineEdit(page_2);
        conf_lineEdit_2->setObjectName(QString::fromUtf8("conf_lineEdit_2"));

        fields_2->addWidget(conf_lineEdit_2, 4, 1, 1, 1);

        surface_combo_2 = new QComboBox(page_2);
        surface_combo_2->setObjectName(QString::fromUtf8("surface_combo_2"));

        fields_2->addWidget(surface_combo_2, 7, 1, 1, 1);

        label_28 = new QLabel(page_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        fields_2->addWidget(label_28, 2, 0, 1, 1);

        label_29 = new QLabel(page_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        fields_2->addWidget(label_29, 4, 0, 1, 1);

        seats_lineEdit_2 = new QLineEdit(page_2);
        seats_lineEdit_2->setObjectName(QString::fromUtf8("seats_lineEdit_2"));

        fields_2->addWidget(seats_lineEdit_2, 2, 1, 1, 1);


        gridLayout_8->addLayout(fields_2, 2, 0, 1, 1);

        checkBox = new QCheckBox(page_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_8->addWidget(checkBox, 0, 0, 1, 1);

        Stadium_editor->addWidget(page_2);

        gridLayout_7->addWidget(Stadium_editor, 4, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_13 = new QGridLayout(tab_5);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        distance_table = new QTableWidget(tab_5);
        if (distance_table->columnCount() < 3)
            distance_table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        distance_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        distance_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        distance_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        distance_table->setObjectName(QString::fromUtf8("distance_table"));
        distance_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        distance_table->setSelectionMode(QAbstractItemView::SingleSelection);
        distance_table->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_13->addWidget(distance_table, 0, 0, 1, 1);

        deleteEdge_button = new QPushButton(tab_5);
        deleteEdge_button->setObjectName(QString::fromUtf8("deleteEdge_button"));

        gridLayout_13->addWidget(deleteEdge_button, 5, 0, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        toStad_combo = new QComboBox(tab_5);
        toStad_combo->setObjectName(QString::fromUtf8("toStad_combo"));

        gridLayout_14->addWidget(toStad_combo, 2, 1, 1, 1);

        fromStad_combo = new QComboBox(tab_5);
        fromStad_combo->setObjectName(QString::fromUtf8("fromStad_combo"));

        gridLayout_14->addWidget(fromStad_combo, 1, 1, 1, 1);

        label_31 = new QLabel(tab_5);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy3);

        gridLayout_14->addWidget(label_31, 1, 0, 1, 1);

        label_32 = new QLabel(tab_5);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_14->addWidget(label_32, 2, 0, 1, 1);

        label_33 = new QLabel(tab_5);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_14->addWidget(label_33, 3, 0, 1, 1);

        dist = new QLineEdit(tab_5);
        dist->setObjectName(QString::fromUtf8("dist"));

        gridLayout_14->addWidget(dist, 3, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout_14, 1, 0, 1, 1);

        addEdge_button = new QPushButton(tab_5);
        addEdge_button->setObjectName(QString::fromUtf8("addEdge_button"));

        gridLayout_13->addWidget(addEdge_button, 4, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_10 = new QGridLayout(tab_4);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_34 = new QLabel(tab_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy1.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy1);
        label_34->setMinimumSize(QSize(256, 256));
        label_34->setMaximumSize(QSize(256, 256));
        label_34->setPixmap(QPixmap(QString::fromUtf8(":/window_icons/windowicons/save_icon.png")));
        label_34->setScaledContents(true);

        horizontalLayout_4->addWidget(label_34);


        gridLayout_10->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        save_pushButton = new QPushButton(tab_4);
        save_pushButton->setObjectName(QString::fromUtf8("save_pushButton"));

        gridLayout_10->addWidget(save_pushButton, 1, 0, 1, 1);

        revert_pushButton = new QPushButton(tab_4);
        revert_pushButton->setObjectName(QString::fromUtf8("revert_pushButton"));

        gridLayout_10->addWidget(revert_pushButton, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_2, 3, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_4->addWidget(tabWidget, 2, 0, 1, 1);


        gridLayout->addWidget(frame_3, 4, 1, 1, 1);

        toolbox = new QFrame(centralwidget);
        toolbox->setObjectName(QString::fromUtf8("toolbox"));
        toolbox->setFrameShape(QFrame::Panel);
        toolbox->setFrameShadow(QFrame::Raised);
        toolBox = new QGridLayout(toolbox);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        toolBox->addItem(horizontalSpacer, 1, 9, 1, 1);

        line_4 = new QFrame(toolbox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        toolBox->addWidget(line_4, 1, 7, 1, 1);

        open_Database = new ClickableLabel(toolbox);
        open_Database->setObjectName(QString::fromUtf8("open_Database"));
        sizePolicy1.setHeightForWidth(open_Database->sizePolicy().hasHeightForWidth());
        open_Database->setSizePolicy(sizePolicy1);
        open_Database->setMinimumSize(QSize(128, 128));
        open_Database->setMaximumSize(QSize(128, 128));
        open_Database->setCursor(QCursor(Qt::PointingHandCursor));
        open_Database->setPixmap(QPixmap(QString::fromUtf8(":/window_icons/windowicons/database_icon.png")));
        open_Database->setScaledContents(true);
        open_Database->setAlignment(Qt::AlignCenter);

        toolBox->addWidget(open_Database, 1, 0, 1, 1);

        label_20 = new QLabel(toolbox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        toolBox->addWidget(label_20, 3, 6, 1, 1);

        graph_util = new ClickableLabel(toolbox);
        graph_util->setObjectName(QString::fromUtf8("graph_util"));
        sizePolicy1.setHeightForWidth(graph_util->sizePolicy().hasHeightForWidth());
        graph_util->setSizePolicy(sizePolicy1);
        graph_util->setMinimumSize(QSize(64, 64));
        graph_util->setMaximumSize(QSize(128, 128));
        graph_util->setCursor(QCursor(Qt::PointingHandCursor));
        graph_util->setPixmap(QPixmap(QString::fromUtf8(":/window_icons/windowicons/graph_icon.png")));
        graph_util->setScaledContents(true);

        toolBox->addWidget(graph_util, 1, 6, 1, 1);

        login = new ClickableLabel(toolbox);
        login->setObjectName(QString::fromUtf8("login"));
        sizePolicy1.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy1);
        login->setMinimumSize(QSize(128, 128));
        login->setMaximumSize(QSize(128, 128));
        login->setCursor(QCursor(Qt::PointingHandCursor));
        login->setPixmap(QPixmap(QString::fromUtf8(":/window_icons/windowicons/login_icon.png")));
        login->setScaledContents(true);

        toolBox->addWidget(login, 1, 3, 1, 1);

        quit = new ClickableLabel(toolbox);
        quit->setObjectName(QString::fromUtf8("quit"));
        sizePolicy1.setHeightForWidth(quit->sizePolicy().hasHeightForWidth());
        quit->setSizePolicy(sizePolicy1);
        quit->setMinimumSize(QSize(128, 128));
        quit->setMaximumSize(QSize(128, 128));
        quit->setCursor(QCursor(Qt::PointingHandCursor));
        quit->setPixmap(QPixmap(QString::fromUtf8(":/window_icons/windowicons/exit_icon.png")));
        quit->setScaledContents(true);
        quit->setAlignment(Qt::AlignCenter);

        toolBox->addWidget(quit, 1, 10, 1, 1);

        label_21 = new QLabel(toolbox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignCenter);

        toolBox->addWidget(label_21, 3, 10, 1, 1);

        label_19 = new QLabel(toolbox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        toolBox->addWidget(label_19, 3, 3, 1, 1);

        label_3 = new QLabel(toolbox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        toolBox->addWidget(label_3, 3, 0, 1, 1);

        line_2 = new QFrame(toolbox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        toolBox->addWidget(line_2, 1, 2, 1, 1);

        line_3 = new QFrame(toolbox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        toolBox->addWidget(line_3, 1, 4, 1, 1);

        planner_util = new ClickableLabel(toolbox);
        planner_util->setObjectName(QString::fromUtf8("planner_util"));
        sizePolicy1.setHeightForWidth(planner_util->sizePolicy().hasHeightForWidth());
        planner_util->setSizePolicy(sizePolicy1);
        planner_util->setMinimumSize(QSize(64, 64));
        planner_util->setMaximumSize(QSize(128, 128));
        planner_util->setCursor(QCursor(Qt::PointingHandCursor));
        planner_util->setPixmap(QPixmap(QString::fromUtf8(":/window_icons/windowicons/trip_util_icon.png")));
        planner_util->setScaledContents(true);

        toolBox->addWidget(planner_util, 1, 8, 1, 1);

        label_35 = new QLabel(toolbox);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setCursor(QCursor(Qt::ArrowCursor));
        label_35->setAlignment(Qt::AlignCenter);

        toolBox->addWidget(label_35, 3, 8, 1, 1);


        gridLayout->addWidget(toolbox, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1365, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_Database);
        menuFile->addSeparator();
        menuFile->addAction(actionLogin);
        menuFile->addAction(actionQuit);
        menuTools->addAction(actionGraph_Utility);
        menuTools->addAction(actionTrip_Planner);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        Stadium_editor->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sleepless Programmers NFL Planner", nullptr));
        actionOpen_Database->setText(QCoreApplication::translate("MainWindow", "Open Database", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_Database->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
#if QT_CONFIG(shortcut)
        actionLogin->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGraph_Utility->setText(QCoreApplication::translate("MainWindow", "Graph Utility", nullptr));
#if QT_CONFIG(shortcut)
        actionGraph_Utility->setShortcut(QCoreApplication::translate("MainWindow", "Alt+G", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTrip_Planner->setText(QCoreApplication::translate("MainWindow", "Trip Planner", nullptr));
#if QT_CONFIG(shortcut)
        actionTrip_Planner->setShortcut(QCoreApplication::translate("MainWindow", "Alt+T", nullptr));
#endif // QT_CONFIG(shortcut)
        label_18->setText(QCoreApplication::translate("MainWindow", "List of Teams:", nullptr));
        nflSortButton->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Sort NFL Teams by:", nullptr));
        splash->setText(QString());
        nflSortingComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "by team name", nullptr));
        nflSortingComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "by stadium name", nullptr));
        nflSortingComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "American Football Conference teams sorted by team name", nullptr));
        nflSortingComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "National Football Conference teams sorted by team name", nullptr));
        nflSortingComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "NFC North teams sorted by team name", nullptr));
        nflSortingComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "by date opened (Oldest to Newest)", nullptr));
        nflSortingComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "\342\200\234open\342\200\235 stadium roof type sorted by stadium name.", nullptr));
        nflSortingComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "seating capacity (smallest to largest)", nullptr));
        nflSortingComboBox->setItemText(8, QCoreApplication::translate("MainWindow", "conference name", nullptr));
        nflSortingComboBox->setItemText(9, QCoreApplication::translate("MainWindow", "Bermuda Grass", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Create Custom Plan", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Show Team:", nullptr));
        teamSelect_Label->setText(QCoreApplication::translate("MainWindow", "Selected Team: [None]", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Admin Area", nullptr));
        ApplyChanges_pushButton_2->setText(QCoreApplication::translate("MainWindow", "Apply Changes to Team", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Team Name:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Add Team Mode", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Stadium:", nullptr));
        addTeam_pushButton->setText(QCoreApplication::translate("MainWindow", "Add New Team", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Team Editor", nullptr));
        addNewSouvenir_button->setText(QCoreApplication::translate("MainWindow", "Add New", nullptr));
        deleteSelected->setText(QCoreApplication::translate("MainWindow", "Delete Selected", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Team Souvenirs", nullptr));
        ApplyChanges_pushButton->setText(QCoreApplication::translate("MainWindow", "Apply Changes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Souvenir Editor", nullptr));
        editStad_button->setText(QCoreApplication::translate("MainWindow", "Edit Selected", nullptr));
        addStadFile_pushButton->setText(QCoreApplication::translate("MainWindow", "Add Stadium From File", nullptr));
        addStad_pushButton->setText(QCoreApplication::translate("MainWindow", "Add New Stadium", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "New Stadium", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Surface Type:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Date Opened:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Division:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Roof Type:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Location:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Seating:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Conference:", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Edit Stadium", nullptr));
        cancelChanges_button->setText(QCoreApplication::translate("MainWindow", "Cancel Changes", nullptr));
        accept_button->setText(QCoreApplication::translate("MainWindow", "Accept Changes", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Surface Type:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Date Opened:", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Division:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Roof Type:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Location:", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Seating:", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Conference:", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Unlock Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Stadium Editor", nullptr));
        QTableWidgetItem *___qtablewidgetitem = distance_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = distance_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = distance_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        deleteEdge_button->setText(QCoreApplication::translate("MainWindow", "Delete Selected Connection", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "From:", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "To:", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Distance (Miles):", nullptr));
        addEdge_button->setText(QCoreApplication::translate("MainWindow", "Add New Connection", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Distance Editor", nullptr));
        label_34->setText(QString());
        save_pushButton->setText(QCoreApplication::translate("MainWindow", "Save Database", nullptr));
        revert_pushButton->setText(QCoreApplication::translate("MainWindow", "Revert All Changes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Save Database", nullptr));
#if QT_CONFIG(tooltip)
        open_Database->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Open Database</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        open_Database->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Graph Utility", nullptr));
#if QT_CONFIG(tooltip)
        graph_util->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Graph Utility</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        graph_util->setText(QString());
#if QT_CONFIG(tooltip)
        login->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Login</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        login->setText(QString());
#if QT_CONFIG(tooltip)
        quit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Open Database</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        quit->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Open Database", nullptr));
#if QT_CONFIG(tooltip)
        planner_util->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Graph Utility</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        planner_util->setText(QString());
        label_35->setText(QCoreApplication::translate("MainWindow", "Trip Planner", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
