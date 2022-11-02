#include "tripplanner.h"
#include "ui_tripplanner.h"
#include "QtDebug"
#include "qmessagebox.h"

tripPlanner::tripPlanner(class data& dat, bool& dbStatus, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tripPlanner),
    internal_data( dat ),
    dbStatus(dbStatus)
{
    ui->setupUi(this);
   // ui->starting_comboBox->addItem("None");
   // ui->startingTeam_combo_2->addItem("None");

    refreshLists();

    ui->pushButton->setEnabled(false);
}

tripPlanner::~tripPlanner()
{
    delete ui;
}

void tripPlanner::refreshLists(){
    if(dbStatus)
    {
        ui->patriots_listWidget->clear();
        ui->startingTeam_combo_2->clear();
        ui->starting_comboBox->clear();
        ui->packers_comboBox->clear();

        ui->starting_comboBox->addItem("None");
        ui->startingTeam_combo_2->addItem("None");
        ui->packers_comboBox->addItem("None");

        for(int i = 0 ; i < internal_data.getTeamsSize() ; i++)
        {

            team tempTeam = internal_data.getTeam_Alphabet(i);
            ui->starting_comboBox->addItem(tempTeam.getTeamName());
            ui->startingTeam_combo_2->addItem(tempTeam.getTeamName());

            if(tempTeam.getTeamName() != "New England Patriots")
                ui->patriots_listWidget->addItem(tempTeam.getTeamName());

            if(tempTeam.getTeamName() != "Green Bay Packers")
                ui->packers_comboBox->addItem(tempTeam.getTeamName());
         }
    }

}

void tripPlanner::on_preset_checkBox_stateChanged(int arg1)
{
    switch(arg1){
    case Qt::Unchecked:
        ui->starting_label->setEnabled(true);
        ui->starting_comboBox->setEnabled(true);
        break;
    case Qt::Checked:
        ui->starting_label->setEnabled(false);
        ui->starting_comboBox->setEnabled(false);
        break;
    }
}

void tripPlanner::on_starting_comboBox_currentTextChanged(const QString &arg1)
{
    ui->listWidget->clear();
    if (arg1 != "None")
    {
        for(int i = 0; i < internal_data.getTeamsSize();i++)
        {
            team tempTeam = internal_data.getTeam_Alphabet(i);
            if (tempTeam.getTeamName() != arg1)
            {
                ui->listWidget->addItem(tempTeam.getTeamName());
            }
        }
    }
}

void tripPlanner::on_pushButton_clicked()
{
    QVector<QString> journey; // TODO vector for cities wanted
    QVector<int> distances;

    switch(ui->comboBox->currentIndex()){   // case 0 will never occur.
    case 1:
    {
        if (ui->packers_comboBox->currentText() == "None")
        {
            QMessageBox::information(this, "ERROR", "Please select a team from the dropdown menu.");
            return;
        }

        QString destinationStr = ui->packers_comboBox->currentText();

        QString stadium = internal_data.getStadium_ID(internal_data.getTeam_Alphabet(destinationStr).getStadium()).getstadiumName();

        journey.push_back("Green Bay Packers");
        journey.push_back(destinationStr);

        int totalDistance = internal_data.getDistance("Lambeau Field", stadium);

        distances.push_back(totalDistance);
        break;
    }
    case 2:
    {
        if(internal_data.teamExists("New England Patriots")){

            std::vector<team> allTeams;
            std::vector<team> finalJourneyII;

            team startingTeam = internal_data.getTeam_Alphabet("New England Patriots");

            for(int i = 0; i < ui->patriots_listWidget->count(); i++){
                team tempTeam = internal_data.getTeam_Alphabet(ui->patriots_listWidget->item(i)->text());
                allTeams.push_back(tempTeam);
            }
            finalJourneyII = recursivePathing(startingTeam, allTeams, finalJourneyII);

            for(int j = 0; j < int(finalJourneyII.size()); j++){
                team tempTeam = finalJourneyII[j];
                journey.push_back(tempTeam.getTeamName());
            }

            for(int k = 1; k < int(journey.size()); k++)
                distances.push_back(internal_data.getDistance(internal_data.getStadium_ID(internal_data.getTeam_Alphabet(journey[k-1]).getStadium()).getstadiumName(),internal_data.getStadium_ID(internal_data.getTeam_Alphabet(journey[k]).getStadium()).getstadiumName()));


        }
        else{
            QMessageBox::information(this, "ERROR", "An Entry for the Green Bay Packers could not be found.\nPlease add it to the database to access this trip.");
            return;
        }
        break;
    }
    case 3:
    {
        if (ui->starting_comboBox->currentText() == "None")
        {
            QMessageBox::information(this, "ERROR", "Please select a team from the dropdown menu.");
            return;
        }


        journey.push_back(ui->starting_comboBox->currentText());
        for(int i = 0; i < ui->listWidget_2->count(); i++)
        {
            //team tempTeam = internal_data.getTeam_Alphabet(i);
            team tempTeam = internal_data.getTeam_Alphabet(ui->listWidget_2->item(i)->text());
            journey.push_back(tempTeam.getTeamName());
        }

        for(int j = 1; j < int(journey.size()); j++)
            distances.push_back(internal_data.getDistance(internal_data.getStadium_ID(internal_data.getTeam_Alphabet(journey[j-1]).getStadium()).getstadiumName(),internal_data.getStadium_ID(internal_data.getTeam_Alphabet(journey[j]).getStadium()).getstadiumName()));

        break;
    }
    case 4:
    {
        if(ui->startingTeam_combo_2->currentText() == "None")
        {
            QMessageBox::information(this, "ERROR", "Please select a team from the dropdown menu.");
            return;
        }

        std::vector<team> selectedTeams;
        std::vector<team> finalJourneyIV;
        team startingTeam = internal_data.getTeam_Alphabet(ui->startingTeam_combo_2->currentText());

        for(int i = 0; i < ui->custom2_selected->count();i++)
        {
            team tempTeam = internal_data.getTeam_Alphabet(ui->custom2_selected->item(i)->text());
            selectedTeams.push_back(tempTeam);
        }
        finalJourneyIV = recursivePathing(startingTeam, selectedTeams, finalJourneyIV);

        for(int copy = 0; copy < int(finalJourneyIV.size()); copy++)
        {
            team tempTeam = finalJourneyIV.at(copy);
            journey.push_back(tempTeam.getTeamName());
        }

        for(int k = 1; k < int(journey.size()); k++)
            distances.push_back(internal_data.getDistance(internal_data.getStadium_ID(internal_data.getTeam_Alphabet(journey[k-1]).getStadium()).getstadiumName(),internal_data.getStadium_ID(internal_data.getTeam_Alphabet(journey[k]).getStadium()).getstadiumName()));
        break;
    }

    }

    ExecuteTrip trip(internal_data, journey, distances);

    trip.exec();
}

void tripPlanner::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget_2->addItem(item->text());
    ui->listWidget->takeItem(ui->listWidget->row(item));
}

void tripPlanner::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget->addItem(item->text());
    ui->listWidget_2->takeItem(ui->listWidget_2->row(item));
}

void tripPlanner::on_close_pushButton_clicked()
{
    close();
}

void tripPlanner::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
        ui->pushButton->setEnabled(false);
    else
        ui->pushButton->setEnabled(true);

    ui->stackedWidget->setCurrentIndex(index);
}

void tripPlanner::on_custom2_optionsList_itemDoubleClicked(QListWidgetItem *item)
{
    ui->custom2_selected->addItem(item->text());
    ui->custom2_optionsList->takeItem(ui->custom2_optionsList->row(item));
}

void tripPlanner::on_custom2_selected_itemDoubleClicked(QListWidgetItem *item)
{
    ui->custom2_optionsList->addItem(item->text());
    ui->custom2_selected->takeItem(ui->custom2_selected->row(item));
}

void tripPlanner::on_startingTeam_combo_2_currentTextChanged(const QString &arg1)
{
    ui->custom2_optionsList->clear();
    if (arg1 != "None")
    {
        for(int i = 0; i < internal_data.getTeamsSize();i++)
        {
            team tempTeam = internal_data.getTeam_Alphabet(i);
            if (tempTeam.getTeamName() != arg1)
            {
                ui->custom2_optionsList->addItem(tempTeam.getTeamName());
            }
        }
    }
}

std::vector<team> tripPlanner::recursivePathing(team start, std::vector<team> &teams, std::vector<team> &sorted)
{
    team tempTeam;
    int shortestDistance = INT32_MAX;
    int index            = 0;

    std::vector<int> tempDistances = internal_data.getDjikstra(internal_data.getStadium_ID(start.getStadium()).getstadiumName());

    //Base case
    if(teams.size() == 0)
    {
           return sorted;
    }

    //General case
    if(sorted.size() == 0)
    {
        tempTeam = start;
        sorted.push_back(tempTeam);
        return recursivePathing(tempTeam, teams, sorted);
    }
    else if(teams.size() >= 1)
    {
        for(int i = 0; i < teams.size(); i++)
        {
            if(tempDistances[internal_data.getPosOfTeamInGraph(teams[i].getTeamName())] < shortestDistance)
            {
                   index = i;
                   shortestDistance = tempDistances[internal_data.getPosOfTeamInGraph(teams[i].getTeamName())];
            }

        }
        tempTeam = teams[index];
        teams.erase(teams.begin() + index);
        sorted.push_back(tempTeam);

        return recursivePathing(tempTeam, teams, sorted);
    }
}

void tripPlanner::takeCustomTrip(const QString& team){
    ui->comboBox->setCurrentIndex(4);
    ui->startingTeam_combo_2->setCurrentIndex(ui->startingTeam_combo_2->findText(team));
    ui->starting_comboBox->setCurrentIndex(ui->starting_comboBox->findText(team));
}
