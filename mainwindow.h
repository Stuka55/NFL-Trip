#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QRandomGenerator>

#include "delegators.h"
#include "data.h"
#include "tripplanner.h"
#include "login.h"
#include "graphalgorithmviewwidget.h"
#include "spfileparser.h"
#include "monke.h"

extern const QStringList SurfaceTypes;
extern const QStringList RoofTypes;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 */
/*!
 * The MainWindow class contains seven private data members:\n
 * GForm                : GraphAlgorithmViewWidget*...\n
 * internal_Data        : class data..................Contains all the data in the database.\n
 * currentTeamSelection : int.........................the index of the current team selected.\n
 * comboSelection       : QString.....................This holds the team selected in the combobox whent he program is running.\n
 * db                   : QSqlDatabase................Handles the connection with the SQL database\n
 * dbOpen               : bool........................This indicates whether the database is opened or closed.\n
 * monk                 : monke*......................Monke much confused\n\n
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*!
     * \brief connOpen is a member function
     * \param directory is the location of the database
     * \return a boolean variable
     *
     * connOpen allows the program to open the connection between
     * the SQLite database and the program.
     */
    bool connOpen(QString directory = "nfl.db");

    /*!
     * \brief connClose is a member function
     *
     * connClose closes the connection betweeen the program
     * and the SQLite database.
     */
    void connClose();

    /*!
     * \brief sortByName is a member function
     *
     * This function sorts the stadiums by name and displays them
     * to the user.
     */
    void sortByName();

    /*!
     * \brief sortNfcByName is a member function
     *
     * This function sorts the NFC teams by name and
     * displays them to the user.
     */
    void sortNfcByName();

    /*!
     * \brief sortByStadium is a member function
     *
     * This function sorts the teams by stadium name and
     * displays them to the user.
     */
    void sortByStadium();

    /*!
     * \brief sortNationalFootballConference is a member function
     *
     * This function displays all of the NFC teams.
     */
    void sortNationalFootballConference();

    /*!
     * \brief sortAmericanFootballConference is a member function
     *
     * This function displays all the AFC teams.
     */
    void sortAmericanFootballConference();

    /*!
     * \brief sortDateOpened is a member function
     *
     * This sorts the stadiums by the date they were opened
     * and displays them to the user.
     */
    void sortDateOpened();

    /*!
     * \brief sortOpenRoofType is a member function
     *
     * This displays all of the stadiums that have open roofs.
     */
    void sortOpenRoofType();

    /*!
     * \brief sortCapacity is a member function
     *
     * This sorts the stadiums by their seating capacity
     * and displays them to the user.
     */
    void sortCapacity();

    /*!
     * \brief sortConference is a member function
     *
     * This sorts the teams by their conference.
     */
    void sortConference();

    /*!
     * \brief sortBermuda is a member function
     *
     * This displays all the stadiums that contains Bermuda grass surface type.
     */
    void sortBermuda();

    /*!
     * \brief userIsAdmin is a member function
     *
     * This recieves a signal from the login.ui
     * which indicates when a user is logged in as admin.
     */
    void userIsAdmin();

private slots:
    void on_nflSelectComboBox_currentTextChanged(const QString &arg1);
    bool loadData();
    void refreshLists();

    void on_actionOpen_Database_triggered();

    void on_nflSortButton_clicked();


    void on_pushButton_clicked();

    void on_actionQuit_triggered();

    void on_actionLogin_triggered();


    void on_deleteSelected_clicked();

    void on_addNewSouvenir_button_clicked();

    void on_ApplyChanges_pushButton_clicked();

    void on_Souvenirs_ListWidget_cellChanged(int row, int column);

    void on_ApplyChanges_pushButton_2_clicked();

    void on_addTeam_pushButton_clicked();

    void on_actionGraph_Utility_triggered();

    void on_addStad_pushButton_clicked();

    void on_addStadFile_pushButton_clicked();

    void on_editStad_button_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_cancelChanges_button_clicked();

    void on_accept_button_clicked();

    void userIsMonkey();

    void on_addEdge_button_clicked();

    void on_deleteEdge_button_clicked();

    void on_revert_pushButton_clicked();


    void on_save_pushButton_clicked();

    void on_actionTrip_Planner_triggered();

signals:
    void listsRefreshed();

private:
    Ui::MainWindow *ui;

    GraphAlgorithmViewWidget* GForm;
    tripPlanner* PForm;

    class data internal_data;

    int currentTeamSelection;

    QString comboSelection;

    QSqlDatabase db;
    bool dbOpen;

    monke* monk;
};
#endif // MAINWINDOW_H
