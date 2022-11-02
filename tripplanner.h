#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

/**
 * @brief A class to represent a tripplanner.
 */
/*!
 * The stadium data class contains eight(8) private data members:\n
 * ui;             :   Ui::tripPlanner *.........................ui for the trip planner.\n
 * internal_data   :   class data& .....................the data for the stadiums and teams.\n
 * dbStatus         :  bool .............................checks to see if database is loaded\n\n
 * Getters and setter functions all exist. A constructor with default values exists, and takes an\n
 * It is not reccomended to use Default values for any reason except to create a temporary food item.
*/


#include <QDialog>
#include "data.h"
#include "executetrip.h"
#include <QListWidgetItem>

namespace Ui {
class tripPlanner;
}

class tripPlanner : public QDialog
{
    Q_OBJECT

public:

    /*!
     * \brief overloaded constructor of tripplanner
     * \param data dat is the data for teams info
     * \param QWidget *parent is if there is a parent window for tripplanner
     *
     * This function sets all items in tripplanner
     */
    explicit tripPlanner(class data& dat, bool& dbStatus, QWidget *parent = nullptr);

    /*!
     * \brief Pathfinding to find shortest distance
     * \param start the starting team for the trip
     * \param teams a vector of teams that is planned to be visted
     * \param sorted a vector of teams that is being sorted into correct order
     * @return a sorted team of vectors in the correct order for the trip
     *
     * This function recusivly finds the shortest distance path of the teams
     */
    std::vector<team> recursivePathing(team start, std::vector<team> &teams, std::vector<team> &sorted);

    /*!
     * \brief intializes a trip
     * \param team name of the team used to intialize
     *
     * initializes the trip and adjusts ui
     */
    void takeCustomTrip(const QString& team);

    /*!
     * \brief a destructor to clean up memory
     */
    ~tripPlanner();

private slots:

    void refreshLists();

    void on_preset_checkBox_stateChanged(int arg1);

    void on_starting_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_close_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_custom2_optionsList_itemDoubleClicked(QListWidgetItem *item);

    void on_custom2_selected_itemDoubleClicked(QListWidgetItem *item);

    void on_startingTeam_combo_2_currentTextChanged(const QString &arg1);

private:
    Ui::tripPlanner *ui; /**< ui for the trip planner*/
    class data& internal_data; /**< the data for the stadiums and teams.*/
    bool& dbStatus; /**<checks to see if database is loaded*/
};

#endif // TRIPPLANNER_H
