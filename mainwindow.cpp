#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentTeamSelection(-1)
    , dbOpen(false)
{
    ui->setupUi(this);

    dbOpen = connOpen();

    GForm = new GraphAlgorithmViewWidget(internal_data, dbOpen);
    PForm = new tripPlanner(internal_data, dbOpen);
    monk = new monke;

    // Add teams to the combo box
    // ----------------------------------------------------- //
    /* Here is where I add all of the teams to the combo box.
     * "None" is added first, then each team in the internal_data class is sorted thru
     * and added as well.
     * */
    refreshLists();

    ui->Souvenirs_ListWidget->setColumnCount(2);
    ui->Souvenirs_ListWidget->setHorizontalHeaderLabels({"Name", "Price"});
    ui->Souvenirs_ListWidget->setItemDelegateForColumn(1, new price_delegator);
    ui->distance_table->setItemDelegateForColumn(2, new distance_delegator);


    ui->frame_3->setVisible(false);

    ui->seats_lineEdit->setValidator(new QIntValidator(ui->seats_lineEdit));
    ui->date_lineEdit->setValidator(new QIntValidator(ui->date_lineEdit));
    ui->dist->setValidator(new QIntValidator(ui->dist));

    ui->surface_combo->addItems(SurfaceTypes);
    ui->roof_combo->addItems(RoofTypes);
    ui->surface_combo_2->addItems(SurfaceTypes);
    ui->roof_combo_2->addItems(RoofTypes);

    ui->ApplyChanges_pushButton_2->setVisible(false);
    ui->addTeam_pushButton->setVisible(true);


    connect(ui->open_Database, SIGNAL(clicked()), this, SLOT(on_actionOpen_Database_triggered()));
    connect(ui->login, SIGNAL(clicked()), this, SLOT(on_actionLogin_triggered()));
    connect(ui->graph_util, SIGNAL(clicked()), this, SLOT(on_actionGraph_Utility_triggered()));
    connect(ui->quit, SIGNAL(clicked()), this, SLOT(on_actionQuit_triggered()));
    connect(ui->planner_util, SIGNAL(clicked()), this, SLOT(on_actionTrip_Planner_triggered()));
    connect(this, SIGNAL(listsRefreshed()), GForm, SLOT(refreshLists()));
    connect(this, SIGNAL(listsRefreshed()), PForm, SLOT(refreshLists()));



}


bool MainWindow::connOpen(QString directory)
{
    QFileInfo check_file(directory);
    if(!check_file.exists() && !check_file.isFile())
        return false;

    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(directory);

        if(db.open())
        {
            qDebug() << "db is connected.";
            loadData();
            return true;
        }
        else
        {
            qDebug() << "Failed to open the db.";
            return false;
        }

        //internal_data.printTeams();

    }
    else
        qDebug() << "Driver not available";

    return false;
}

void MainWindow::connClose()
{
    if(dbOpen){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
        dbOpen = false;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete GForm;
    monk->close();

    delete monk;
}

void MainWindow::refreshLists(){
    ui->nflSelectComboBox->clear();

    ui->nflSelectComboBox->addItem("None");

    if(dbOpen){
        for(int i = 0; i < internal_data.getTeamsSize(); i++){
            ui->nflSelectComboBox->addItem(internal_data.getTeam_Alphabet(i).getTeamName());
        }
    }


    ui->listWidget->clear();

    if(dbOpen){
        for(int i = 0; i < internal_data.getStadiumsSize(); i++)
            ui->listWidget->addItem(internal_data.getStadium_index(i)->getstadiumName());
    }

        ui->stadium_comboBox->clear();
        ui->fromStad_combo->clear();
        ui->toStad_combo->clear();


        ui->distance_table->setRowCount(0);

    if(dbOpen){
        for(int i = 0 ; i < internal_data.getStadiumsSize(); i++){
            ui->stadium_comboBox->addItem(internal_data.getStadium_index(i)->getstadiumName());
            ui->fromStad_combo->addItem(internal_data.getStadium_index(i)->getstadiumName());
            ui->toStad_combo->addItem(internal_data.getStadium_index(i)->getstadiumName());
        }

        ui->distance_table->setRowCount(internal_data.getEdges().size());
        int i = 0;
        const std::vector<adjEdge<Stadium*,int>*>& a = internal_data.getEdges();
        for(auto e : a){
            ui->distance_table->setItem(i, 0, new QTableWidgetItem(e->endpoints.first->name->getstadiumName()));
            ui->distance_table->setItem(i, 1, new QTableWidgetItem(e->endpoints.second->name->getstadiumName()));
            ui->distance_table->setItem(i, 2, new QTableWidgetItem(QString::number(e->weight)));
            i++;
        }
    }

    if(dbOpen){
        emit listsRefreshed();
    }

}

bool MainWindow::loadData(){
    QSqlQuery q(db);

    q.exec("SELECT * FROM stadiums");

    int st_idID = q.record().indexOf("_id");
    int st_idName = q.record().indexOf("StadiumName");
    int st_idSeating = q.record().indexOf("SeatingCapacity");
    int st_idLocation = q.record().indexOf("Location");
    int st_idConference = q.record().indexOf("Conference");
    int st_idDivision = q.record().indexOf("Division");
    int st_idSurfaceType = q.record().indexOf("SurfaceType");
    int st_idRoofType = q.record().indexOf("StadiumRoofType");
    int st_idDateOpened = q.record().indexOf("DateOpened");

    while(q.next()){
        internal_data.addStadium(new Stadium(q.value(st_idID).toString().toInt(),
                                             q.value(st_idName).toString(),
                                             q.value(st_idSeating).toInt(),
                                             q.value(st_idLocation).toString(),
                                             q.value(st_idDivision).toString(),
                                             q.value(st_idConference).toString(),
                                             q.value(st_idSurfaceType).toString(),
                                             q.value(st_idRoofType).toString(),
                                             q.value(st_idDateOpened).toString().toInt()));
    }

    q.finish();

        q.exec("SELECT * FROM teams");

        int idID = q.record().indexOf("_id");
        int idName = q.record().indexOf("TeamName");
        int idSta = q.record().indexOf("StadiumID");


        while(q.next()){
            internal_data.addTeam(new team(q.value(idName).toString(), q.value(idID).toInt(), q.value(idSta).toInt()));
        }

        q.finish();

        q.exec("SELECT * FROM teams_souvenir");


        int s_idID = q.record().indexOf("_id");
        int s_SouvenirName = q.record().indexOf("SouvenirName");
        int s_TeamId = q.record().indexOf("TeamId");
        int s_Price = q.record().indexOf("Price");

        while(q.next()){
            internal_data.addSouvenir(internal_data.getTeam_ID(q.value(s_TeamId).toInt()).getId(), new Team_Souvenir(q.value(s_SouvenirName).toString(), q.value(s_Price).toDouble(), q.value(s_idID).toInt(), q.value(s_TeamId).toInt()));
        }


        q.finish();

        q.exec("SELECT * FROM stadiums_distances");

        int fromID = q.record().indexOf("FromStadiumId");
        int toID = q.record().indexOf("ToStadiumId");
        int distID = q.record().indexOf("Distance");

        while(q.next()){
            internal_data.addDistance(q.value(fromID).toInt(), q.value(toID).toInt(), q.value(distID).toInt());
        }

        q.finish();

    return true;
}


void MainWindow::on_nflSelectComboBox_currentTextChanged(const QString &arg1)
{

    // Show team info
    // ----------------------------------------------------- //
    /* Here is where I show team information.
     * First, we check if "None" is selected. arg1 is a
     * QString that contains the text inside of the currently
     * selected dropdown list index.
     *
     * If arg1 != "None", we shit out all of the data in a
     * nice, pretty format on the screen! Yay.
     * */
    if(dbOpen){
        if(!arg1.isEmpty() && internal_data.getTeam_Alphabet(arg1).getId() != currentTeamSelection)
        {
            if(arg1 == "None")
            {
                ui->Souvenirs_ListWidget->setEnabled(false);
                ui->ApplyChanges_pushButton->setEnabled(false);
                ui->addNewSouvenir_button->setEnabled(false);
                ui->deleteSelected->setEnabled(false);

                ui->nflSelectTextBrowser->setText("No team selected.");
                ui->teamSelect_Label->setText("Selected Team: [None]");
                currentTeamSelection = -1;

                ui->Souvenirs_ListWidget->blockSignals(true);


                for(int i = 0; i < ui->Souvenirs_ListWidget->rowCount(); i++){
                    delete ui->Souvenirs_ListWidget->takeItem(i, 0);
                    delete ui->Souvenirs_ListWidget->takeItem(i, 1);
                }

                ui->Souvenirs_ListWidget->reset();
                ui->Souvenirs_ListWidget->setRowCount(0);
                ui->Souvenirs_ListWidget->setColumnCount(2);

                ui->Souvenirs_ListWidget->blockSignals(false);

                ui->teamName_lineEdit->clear();
                ui->stadium_comboBox->setCurrentIndex(0);

                ui->label_17->setText("Add Team Mode");
                ui->addTeam_pushButton->setVisible(true);
                ui->ApplyChanges_pushButton_2->setVisible(false);

            }
            else
            {
                ui->Souvenirs_ListWidget->setEnabled(true);
                ui->ApplyChanges_pushButton->setEnabled(false);
                ui->addNewSouvenir_button->setEnabled(true);
                ui->deleteSelected->setEnabled(true);

                team tempTeam(internal_data.getTeam_Alphabet(arg1));
                Stadium tempStad(internal_data.getStadium_ID(tempTeam.getStadium()));
                currentTeamSelection = tempTeam.getId();
                comboSelection = arg1;

                QString text = "Team Name: " + tempTeam.getTeamName() + '\n'
                        + "Stadium Name: " + tempStad.getstadiumName() + '\n'
                        + "  Seating: " + QString::number(tempStad.getcapacity()) + " seats\n"
                        + "  Location: " + tempStad.getlocation() + '\n'
                        + "  Conference: " + tempStad.getConference() + '\n'
                        + "  Division: " + tempStad.getdivision() + '\n'
                        + "  Turf Surface Type: " + tempStad.getsurfaceType() + '\n'
                        + "  Roof Type: " + tempStad.getsurfaceRoofType() + '\n'
                        + "  Date Opened: " + QString::number(tempStad.getdateOpened()) + '\n'
                        + "Souveniers:\n";
                for(auto souv : tempTeam.getSouvenirs())
                    text.append("\t" + souv->getName() +", $" + QString::number(souv->getPrice(), 'f', 2) + '\n');
                text.remove(text.size() - 1, 1);

                ui->nflSelectTextBrowser->setText(text);


                ui->teamSelect_Label->setText("Selected Team: " + tempTeam.getTeamName());

                ui->Souvenirs_ListWidget->blockSignals(true);

                for(int i = 0; i < ui->Souvenirs_ListWidget->rowCount(); i++){
                    delete ui->Souvenirs_ListWidget->takeItem(i, 0);
                    delete ui->Souvenirs_ListWidget->takeItem(i, 1);
                }

                ui->Souvenirs_ListWidget->reset();
                ui->Souvenirs_ListWidget->clearContents();



                ui->Souvenirs_ListWidget->setRowCount(internal_data.getTeam_ID(currentTeamSelection).getSouvenirs().size());
                ui->Souvenirs_ListWidget->setColumnCount(2);


                for(int i = 0; i < internal_data.getTeam_ID(currentTeamSelection).getSouvenirs().size(); i++){
                    const QString tempname = internal_data.getTeam_ID(currentTeamSelection).getSouvenirs()[i]->getName();
                    const double tempprice = internal_data.getTeam_ID(currentTeamSelection).getSouvenirs()[i]->getPrice();

                    std::clog << internal_data.getTeam_ID(currentTeamSelection).getSouvenirs()[i]->getName().toStdString() << ", " << internal_data.getTeam_ID(currentTeamSelection).getSouvenirs()[i]->getPrice() << '\n';

                    ui->Souvenirs_ListWidget->setItem(i, 0, new QTableWidgetItem(tempname));
                    ui->Souvenirs_ListWidget->setItem(i, 1, new QTableWidgetItem(QString::number(tempprice, 'f', 2)));
                }
                ui->Souvenirs_ListWidget->blockSignals(false);

                // Team Editor



                ui->label_17->setText("Edit Team Mode");
                ui->addTeam_pushButton->setVisible(false);
                ui->ApplyChanges_pushButton_2->setVisible(true);

                ui->teamName_lineEdit->setText(internal_data.getTeam_ID(currentTeamSelection).getTeamName());

                int i = 0;
                for(i = 0;i <= internal_data.getStadiumsSize(); i++ ){
                    if (i == internal_data.getStadiumsSize())
                        throw "POO!";

                    if (internal_data.getStadium_index(i)->getstadiumName() == internal_data.getStadium_ID(internal_data.getTeam_ID(currentTeamSelection).getStadium()).getstadiumName())
                        break;
                }

                ui->stadium_comboBox->setCurrentIndex(i);
            }

        }
    }
}

void MainWindow::on_actionOpen_Database_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Database"), QDir::currentPath() + "/databases", "SQLlite Database (*.db)");

    if(fileName != ""){
        connClose();
        internal_data.clear();
        dbOpen = connOpen(fileName);
        refreshLists();
    }

}

void MainWindow::sortByName()
{
    {
         ui->allNFLTeams->clear();
        team tempTeam;

        Stadium tempStad;

        QString text;


        for(int i = 0; i < internal_data.getTeamsSize(); i++)
        {
            team tempTeam = internal_data.getTeam_Alphabet(i);
            Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());


                text = "Team Name: " + tempTeam.getTeamName() + '\n'
                     + "Stadium Name: " + tempStad.getstadiumName() + '\n' + '\n';
               ui->allNFLTeams->append(text);


        }
    }
}

void MainWindow::sortNfcByName()
{
    ui->allNFLTeams->clear();
    team tempTeam;

    Stadium tempStad;

    QString text;


    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        team tempTeam = internal_data.getTeam_Alphabet(i);
        Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());

        if(tempStad.getdivision() == "NFC  North")
        {
            text = "Team Name: " + tempTeam.getTeamName() + '\n'
                 + "Stadium Name: " + tempStad.getstadiumName() + '\n' + '\n';
           ui->allNFLTeams->append(text);
        }

    }
}

void MainWindow::sortByStadium()
{
    ui->allNFLTeams->clear();
   team tempTeam;

   Stadium tempStad;

   QString text;


   for(int i = 0; i < internal_data.getTeamsSize(); i++)
   {
       team tempTeam = internal_data.getTeam_Stadium(i);
       Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());

       text = "Team Name: " + tempTeam.getTeamName() + '\n'
              + "Stadium Name: " + tempStad.getstadiumName() + '\n' + '\n';
       ui->allNFLTeams->append(text);

   }
}

void MainWindow::sortNationalFootballConference()
{
    ui->allNFLTeams->clear();
    team tempTeam;

    Stadium tempStad;

    QString text;


    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        team tempTeam = internal_data.getTeam_Alphabet(i);
        Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());

        if(tempStad.getConference() == "National Football Conference")
        {
            text = "Team Name: " + tempTeam.getTeamName() + '\n'
                 + "Stadium Name: " + tempStad.getstadiumName() + '\n' + '\n';
           ui->allNFLTeams->append(text);
        }

    }
}

void MainWindow::sortAmericanFootballConference()
{
    ui->allNFLTeams->clear();
    team tempTeam;

    Stadium tempStad;

    QString text;


    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        team tempTeam = internal_data.getTeam_Alphabet(i);
        Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());

        if(tempStad.getConference() == "American Football Conference")
        {
            text = "Team Name: " + tempTeam.getTeamName() + '\n'
                 + "Stadium Name: " + tempStad.getstadiumName() + '\n' + '\n';
           ui->allNFLTeams->append(text);
        }

    }
}

void MainWindow::sortOpenRoofType()
{
    ui->allNFLTeams->clear();
    QString text;

    QVector<QString> stadCheck;
    bool stadBool = false;
    int numOpen = 0;

    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        team tempTeam = internal_data.getTeam_Stadium(i);
        Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());

        if(tempStad.getsurfaceRoofType() == "Open")
        {
            text = "Team Name: " + tempTeam.getTeamName() + '\n'
                 + "Stadium Name: " + tempStad.getstadiumName() + '\n' + '\n';
           ui->allNFLTeams->append(text);
        }

        for(int j = 0; j < stadCheck.size(); j++)
        {
         if( stadCheck[j] == tempStad.getstadiumName())
         {
             stadBool = true;
             break;
         }
        }

        if(stadBool == false)
        {
            numOpen += 1;
        }
        stadCheck.push_back(tempStad.getstadiumName());
    }

    QString num = QString::number(numOpen);
     ui->allNFLTeams->append("Number of Stadiums with an Open roof type: " + num);
}

void MainWindow::sortBermuda()
{
    ui->allNFLTeams->clear();
    QString text;
    QVector<QString> stadCheck;
    bool stadBool = false;


    int numBermuda = 0;

    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        stadBool = false;
        team tempTeam = internal_data.getTeam_Stadium(i);
        Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());

        if(tempStad.getsurfaceType() == "Bermuda Grass")
        {
            text = "Team Name: " + tempTeam.getTeamName() + '\n'
                 + "Stadium Name: " + tempStad.getstadiumName() + '\n' + '\n';
           ui->allNFLTeams->append(text);

           for(int j = 0; j < stadCheck.size(); j++)
           {
            if( stadCheck[j] == tempStad.getstadiumName())
            {
                stadBool = true;
                break;
            }
           }

           if(stadBool == false)
           {
               numBermuda += 1;
           }
           stadCheck.push_back(tempStad.getstadiumName());
        }
    }
    QString num = QString::number(numBermuda);
     ui->allNFLTeams->append("Number of Stadiums with Bermuda Grass: " + num);
}

void MainWindow::sortConference()
{
    ui->allNFLTeams->clear();
    team tempTeam;

    Stadium tempStad;

    QString text;


    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        team tempTeam = internal_data.getTeam_Conference(i);
        Stadium tempStad = internal_data.getStadium_ID(tempTeam.getStadium());

        text = "Team Name: " + tempTeam.getTeamName() + '\n'
               + "Conference: " + tempStad.getConference() + '\n'
               + "Stadium Name: " + tempStad.getstadiumName() + "\n\n";
        ui->allNFLTeams->append(text);
    }
}

void MainWindow::sortDateOpened()
{
    ui->allNFLTeams->clear();
    QString text;

    qDebug() << "Size: " << QString::number(internal_data.getTeamsSize());

    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        qDebug() << QString::number(i);
        team tempTeam = internal_data.getTeam_Date(i);
        Stadium tempStadium = internal_data.getStadium_ID(tempTeam.getStadium());

        text = "Team Name: " + tempTeam.getTeamName() + '\n'
                + "Stadium: " + tempStadium.getstadiumName() + '\n'
                + "Date Opened: " + QString::number(tempStadium.getdateOpened()) + "\n\n";
        ui->allNFLTeams->append(text);
    }
}

void MainWindow::sortCapacity()
{
    ui->allNFLTeams->clear();
    QString text;

    qDebug() << "Size: " << QString::number(internal_data.getTeamsSize());

    for(int i = 0; i < internal_data.getTeamsSize(); i++)
    {
        qDebug() << QString::number(i);
        team tempTeam = internal_data.getTeam_Capacity(i);
        Stadium tempStadium = internal_data.getStadium_ID(tempTeam.getStadium());

        text = "Team Name: " + tempTeam.getTeamName() + '\n'
                + "Stadium: " + tempStadium.getstadiumName() + '\n'
                + "Capacity: " + QString::number(tempStadium.getcapacity()) + " seats\n\n";
        ui->allNFLTeams->append(text);
    }

    int capac = 0;

    for(int i = 0; i < internal_data.getStadiumsSize(); i++)
        capac += internal_data.getStadium_index(i)->getcapacity();

    ui->allNFLTeams->append("Total Capacity of All Stadiums: " + QString::number(capac));
}

void MainWindow::on_nflSortButton_clicked()
{
    if(dbOpen){
        if(ui->nflSortingComboBox->currentText() == "by team name")
        {
            sortByName();
        }
        else if (ui->nflSortingComboBox->currentText() == "by stadium name")
        {
            sortByStadium();
        }
        else if(ui->nflSortingComboBox->currentText() == "NFC North teams sorted by team name")
        {
            sortNfcByName();
        }
        else if(ui->nflSortingComboBox->currentText() == "National Football Conference teams sorted by team name")
        {
           sortNationalFootballConference();
        }
        else if(ui->nflSortingComboBox->currentText() == "American Football Conference teams sorted by team name")
        {
            sortAmericanFootballConference();
        }
        else if(ui->nflSortingComboBox->currentText() == "by date opened (Oldest to Newest)")
        {
            sortDateOpened();
        }
        else if (ui->nflSortingComboBox->currentText() == "“open” stadium roof type sorted by stadium name.")
        {
            sortOpenRoofType();
        }
        else if (ui->nflSortingComboBox->currentText() == "seating capacity (smallest to largest)")
        {
            sortCapacity();
        }
        else if (ui->nflSortingComboBox->currentText() == "conference name")
        {
            sortConference();
        }
        else if (ui->nflSortingComboBox->currentText() == "Bermuda Grass")
        {
            sortBermuda();
        }
    }
    else{
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(dbOpen){
        if(ui->nflSelectComboBox->currentText() != "None"){
            PForm->takeCustomTrip(ui->nflSelectComboBox->currentText());
            PForm->show();
        }
        else
            QMessageBox::information(this, "Please Select Team", "Please select a starting team to plan your trip around.");
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit(EXIT_SUCCESS);
}

void MainWindow::on_actionLogin_triggered()
{
    login window(this);

    window.addData();

    connect(&window, &login::userIsAdmin, this, &MainWindow::userIsAdmin);
    connect(&window, &login::monkie, this, &MainWindow::userIsMonkey);

    window.exec();
}

void MainWindow::userIsAdmin()
{
    QMessageBox::information(this, "Login", "Username and Password is Correct");
    ui->frame_3->setVisible(true);
}

void MainWindow::on_deleteSelected_clicked()
{
    if(dbOpen){
        if(ui->Souvenirs_ListWidget->currentRow() == -1)
            QMessageBox::information(this, "Uh oh!", "No selection made.");
        else{
            ui->ApplyChanges_pushButton->setEnabled(true);
            ui->Souvenirs_ListWidget->removeRow(ui->Souvenirs_ListWidget->currentRow());
        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_addNewSouvenir_button_clicked()
{
    if(dbOpen){
        ui->ApplyChanges_pushButton->setEnabled(true);
        ui->Souvenirs_ListWidget->setRowCount(ui->Souvenirs_ListWidget->rowCount() + 1);
        ui->Souvenirs_ListWidget->setItem(ui->Souvenirs_ListWidget->rowCount() - 1, 0, new QTableWidgetItem("Default Souvenir"));
        ui->Souvenirs_ListWidget->setItem(ui->Souvenirs_ListWidget->rowCount() - 1, 1, new QTableWidgetItem("9.99"));
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_ApplyChanges_pushButton_clicked()
{
    if(dbOpen){
        if(ui->nflSelectComboBox->currentText() != "None")
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Overwrite Souvenirs", "This will overwrite the current team's souvenir list. Are you sure?");

            if(reply == QMessageBox::Yes)
            {
                std::clog << "Before: " << internal_data.getSouvenirSize() << '\n';

                internal_data.clearSouvenirs(ui->nflSelectComboBox->currentText());

                for(int i = 0; i < ui->Souvenirs_ListWidget->rowCount(); i++)
                {
                    internal_data.addSouvenir(internal_data.getTeam_Alphabet(ui->nflSelectComboBox->currentText()).getId(), new Team_Souvenir(ui->Souvenirs_ListWidget->item(i, 0)->text(), ui->Souvenirs_ListWidget->item(i, 1)->text().toDouble(),i, internal_data.getTeam_Alphabet(ui->nflSelectComboBox->currentText()).getId()));
                }
                //ui->ApplyChanges_pushButton->setEnabled(false);

                std::clog << "After: " << internal_data.getSouvenirSize() << '\n';

                refreshLists();
            }
        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}


//This is the apply changes button for the team/stadium info editor
void MainWindow::on_ApplyChanges_pushButton_2_clicked()
{
    if(dbOpen){
        if(ui->nflSelectComboBox->currentText() != "None")
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Overwrite Team/Stadium info", "This will overwrite the current team's information. Are you sure?");

            if(reply == QMessageBox::Yes)
            {
                internal_data.getTeam_ID(currentTeamSelection).setTeamName(ui->teamName_lineEdit->text());
                internal_data.getTeam_ID(currentTeamSelection).setStadium(internal_data.getStadium_index(ui->stadium_comboBox->currentIndex())->getID());
                //ui->ApplyChanges_pushButton_2->setEnabled(false);
            }
            refreshLists();
        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_Souvenirs_ListWidget_cellChanged(int row, int column)
{
    ui->ApplyChanges_pushButton->setEnabled(true);
}


void MainWindow::on_addTeam_pushButton_clicked()
{
    if(dbOpen){
        internal_data.addTeam(new team(ui->teamName_lineEdit->text(), internal_data.getTeam_ID(INT32_MAX).getId() + 1, internal_data.getStadium_index(ui->stadium_comboBox->currentIndex())->getID()));
        internal_data.addSouvenir(internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), new Team_Souvenir("Signed helmets", 77.99, internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), 0));
        internal_data.addSouvenir(internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), new Team_Souvenir("Autographed football", 99.89, internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), 1));
        internal_data.addSouvenir(internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), new Team_Souvenir("Team pennant", 17.99, internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), 2));
        internal_data.addSouvenir(internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), new Team_Souvenir("Team picture", 29.99, internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), 3));
        internal_data.addSouvenir(internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), new Team_Souvenir("Team jersey", 199.99, internal_data.getTeam_Alphabet(ui->teamName_lineEdit->text()).getId(), 4));

        QMessageBox::information(this, "Team Added", "Added Team \"" + ui->teamName_lineEdit->text() + "\" to the system.");
        ui->teamName_lineEdit->clear();
        ui->stadium_comboBox->setCurrentIndex(0);

        refreshLists();
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_actionGraph_Utility_triggered()
{
    if(dbOpen){
        GForm->show();
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}
void MainWindow::on_addStad_pushButton_clicked()
{
    if(dbOpen){
        if(ui->name_lineEdit->text().isEmpty())
            QMessageBox::information(this, "Must Name Stadium", "You must at least enter a name for  your stadium.");
        else{
            internal_data.addStadium(new Stadium(internal_data.getStadium_ID(INT32_MAX).getID() + 1, ui->name_lineEdit->text(), ui->seats_lineEdit->text().toInt(), ui->loc_lineEdit->text(), ui->div_lineEdit->text(), ui->conf_lineEdit->text(), ui->surface_combo->currentText(), ui->roof_combo->currentText(), ui->date_lineEdit->text().toInt()));
            QMessageBox::information(this, "Added " + ui->name_lineEdit->text(), "Succesfully added " + ui->name_lineEdit->text() + " to the stadium list!");

            ui->name_lineEdit->clear();
            ui->loc_lineEdit->clear();
            ui->seats_lineEdit->clear();
            ui->conf_lineEdit->clear();
            ui->div_lineEdit->clear();
            ui->date_lineEdit->clear();
            ui->roof_combo->setCurrentIndex(0);
            ui->surface_combo->setCurrentIndex(0);

            refreshLists();
        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_addStadFile_pushButton_clicked()
{
    if(dbOpen){
        if(!QDir(QDir::currentPath() + "/stadiums").exists())
            QDir().mkdir(QDir::currentPath() + "/stadiums");

        QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Stadium"), QDir::currentPath() + "/stadiums", "SP Stadiums (*.sp)");

        QStringList Error;
        SPFileParser parse(internal_data);


        if(!parse.read(fileName, Error)){
            QString ErrorMessage = Error[0] + '\n';
            if(Error.size() > 1) ErrorMessage += Error[1];
            QMessageBox::information(this, "Error Parsing File", ErrorMessage);
        }
        else
            QMessageBox::information(this, "Added File", "Added file:\n" + fileName);
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");

    refreshLists();
}

void MainWindow::on_editStad_button_clicked()
{
    if(dbOpen){
        if(ui->listWidget->selectedItems().isEmpty())
            QMessageBox::information(this, "Select Stadium", "Please select a Stadium to edit.");
        else{
            ui->editStad_button->setEnabled(false);
            ui->listWidget->setEnabled(false);

            ui->Stadium_editor->setCurrentIndex(1);

            QString name = ui->listWidget->currentItem()->text();
            Stadium& current = internal_data.getStadium_Alphabet(name);

            ui->name_lineEdit_2->setText(current.getstadiumName());
            ui->seats_lineEdit_2->setText(QString::number(current.getcapacity()));
            ui->loc_lineEdit_2->setText(current.getlocation());
            ui->conf_lineEdit_2->setText(current.getConference());
            ui->div_lineEdit_2->setText(current.getdivision());
            ui->date_lineEdit_2->setText(QString::number(current.getdateOpened()));

            for(int i = 0; i < SurfaceTypes.size(); i++){
                if (current.getsurfaceType() == SurfaceTypes[i]){
                    ui->surface_combo_2->setCurrentIndex(i);
                    break;
                }
            }

            for(int i = 0; i < RoofTypes.size(); i++){
                if(current.getsurfaceRoofType() == RoofTypes[i]){
                    ui->roof_combo_2->setCurrentIndex(i);
                    break;
                }
            }
        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked){
        ui->name_lineEdit_2->setText(ui->listWidget->currentItem()->text());
        ui->name_lineEdit_2->setEnabled(false);
    }
    if(arg1 == Qt::Checked){
        ui->name_lineEdit_2->setEnabled(true);
    }
}

void MainWindow::on_cancelChanges_button_clicked()
{
    if(dbOpen){
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->name_lineEdit_2->clear();
        ui->seats_lineEdit_2->clear();
        ui->loc_lineEdit_2->clear();
        ui->conf_lineEdit_2->clear();
        ui->div_lineEdit_2->clear();
        ui->date_lineEdit_2->clear();

        ui->roof_combo_2->setCurrentIndex(0);
        ui->surface_combo_2->setCurrentIndex(0);

        ui->Stadium_editor->setCurrentIndex(0);

        ui->editStad_button->setEnabled(true);
        ui->listWidget->setEnabled(true);
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_accept_button_clicked()
{
    if(dbOpen){
        if(ui->checkBox->checkState() == Qt::Checked && ui->name_lineEdit_2->text() != ui->listWidget->currentItem()->text()){
            const QString& name = ui->listWidget->currentItem()->text();
            internal_data.getStadium_Alphabet(name).setcapacity(ui->seats_lineEdit_2->text().toInt());
            internal_data.getStadium_Alphabet(name).setlocation(ui->loc_lineEdit_2->text());
            internal_data.getStadium_Alphabet(name).setConference(ui->conf_lineEdit_2->text());
            internal_data.getStadium_Alphabet(name).setdivision(ui->div_lineEdit_2->text());
            internal_data.getStadium_Alphabet(name).setdateOpened(ui->date_lineEdit_2->text().toInt());
            internal_data.getStadium_Alphabet(name).setsurfaceRoofType(SurfaceTypes[ui->surface_combo_2->currentIndex()]);
            internal_data.getStadium_Alphabet(name).setsurfaceType(RoofTypes[ui->roof_combo_2->currentIndex()]);
            internal_data.rename_Stadium(ui->listWidget->currentItem()->text(), ui->name_lineEdit_2->text());

            on_cancelChanges_button_clicked();
        }
        else {
            const QString& name = ui->name_lineEdit_2->text();

            internal_data.getStadium_Alphabet(name).setcapacity(ui->seats_lineEdit_2->text().toInt());
            internal_data.getStadium_Alphabet(name).setlocation(ui->loc_lineEdit_2->text());
            internal_data.getStadium_Alphabet(name).setConference(ui->conf_lineEdit_2->text());
            internal_data.getStadium_Alphabet(name).setdivision(ui->div_lineEdit_2->text());
            internal_data.getStadium_Alphabet(name).setdateOpened(ui->date_lineEdit_2->text().toInt());
            internal_data.getStadium_Alphabet(name).setsurfaceRoofType(SurfaceTypes[ui->surface_combo_2->currentIndex()]);
            internal_data.getStadium_Alphabet(name).setsurfaceType(RoofTypes[ui->roof_combo_2->currentIndex()]);

            on_cancelChanges_button_clicked();
        }

        refreshLists();
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::userIsMonkey(){
    monk->screech();
    monk->show();
}

void MainWindow::on_addEdge_button_clicked()
{
    if(dbOpen){
        if(ui->dist->text().isEmpty()){
            QMessageBox::information(this,"Enter Distance", "Please enter a distance between the two edges.");
        }
        else
        {
            for(auto e : internal_data.getEdges()){
                if(e->endpoints.first->name == internal_data.getStadium_index(ui->fromStad_combo->currentIndex())
                        && e->endpoints.second->name == internal_data.getStadium_index(ui->toStad_combo->currentIndex())){
                 QMessageBox::information(this, "Edge Already Exists", "This edge already exists in the system.\nCould not create duplicate edge.");
                 return;
                }
            }

            internal_data.addDistance(internal_data.getStadium_Alphabet(ui->fromStad_combo->currentText()).getID(), internal_data.getStadium_Alphabet(ui->toStad_combo->currentText()).getID(), ui->dist->text().toInt());
            internal_data.addDistance(internal_data.getStadium_Alphabet(ui->toStad_combo->currentText()).getID(), internal_data.getStadium_Alphabet(ui->fromStad_combo->currentText()).getID(), ui->dist->text().toInt());

            refreshLists();

        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_deleteEdge_button_clicked()
{
    if(dbOpen){
        if(ui->distance_table->selectedItems().isEmpty()){
            QMessageBox::information(this, "No Edge Selected", "Please select an edge on the above tale.");
        }
        else{
            const QString from = ui->distance_table->selectedItems()[0]->text();
            const QString to = ui->distance_table->selectedItems()[1]->text();

            internal_data.eraseDistance(ui->distance_table->selectedItems()[0]->text(), ui->distance_table->selectedItems()[1]->text());
            internal_data.eraseDistance(ui->distance_table->selectedItems()[1]->text(), ui->distance_table->selectedItems()[0]->text());
            refreshLists();

            //QMessageBox::information(this, "Test", "Selected:\nfrom " + ui->distance_table->selectedItems()[0]->text() + "\nto " + ui->distance_table->selectedItems()[1]->text());
        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");

    return;
}

void MainWindow::on_revert_pushButton_clicked()
{
    if(dbOpen){
        auto reply = QMessageBox::question(this, "Are You Sure?", "If you revert your changes, any modifications you made to the teams will be deleted.");

        if(reply == QMessageBox::Yes){
            internal_data.clear();

            loadData();
            refreshLists();

            QMessageBox::information(this, "Changes Reverted", "Database has been reset.");
        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");

    return;
}

void MainWindow::on_save_pushButton_clicked()
{
    if(dbOpen){
        if(!QDir(QDir::currentPath() + "/databases").exists())
            QDir().mkdir(QDir::currentPath() + "/databases");

        QString fileName = QFileDialog::getSaveFileName(this, "Save As", QDir::currentPath() + "/databases", "SQLite Databases (*.db)");

        if(!fileName.isEmpty()){
            if(QFile(fileName).exists())
                QFile(fileName).remove();

            QSqlDatabase temp;
            temp = QSqlDatabase::addDatabase("QSQLITE", "Temp");
            temp.setDatabaseName(fileName);

            if(temp.open()){
                QSqlQuery q(temp);

                q.exec("CREATE TABLE `stadiums` (`_id` INTEGER PRIMARY KEY, `StadiumName` varchar(255), `SeatingCapacity` int(11), `Location` varchar(255), `Conference` varchar(255), `Division` varchar(255), `SurfaceType` varchar(255), `StadiumRoofType` varchar(255), `DateOpened` INTEGER)");
                q.exec("CREATE TABLE `stadiums_distances` (`_id` INTEGER PRIMARY KEY, `FromStadiumId` INTEGER, `ToStadiumId` INTEGER, `Distance` INTEGER)");
                q.exec("CREATE TABLE `teams` (`_id` INTEGER PRIMARY KEY, `TeamName` varchar(255), `StadiumID` INTEGER)");
                q.exec("CREATE TABLE `teams_souvenir` (`_id` INTEGER PRIMARY KEY, `SouvenirName` varchar(100), `TeamId` INTEGER, `Price` float)");
                q.exec("CREATE TABLE `users` ( `_id` INTEGER PRIMARY KEY, `FName` varchar(30) , `LName` varchar(30) , `Email` varchar(50) , `Password` varchar(32) , `Permission` int(11) )");


                for(auto e : internal_data.getStadiums()){

                    q.prepare("INSERT INTO stadiums VALUES (:id, :name, :capacity, :location, :conference, :division, :surface, :roof, :date)");
                    q.bindValue(":id", e->getID());
                    q.bindValue(":name", e->getstadiumName());
                    q.bindValue(":capacity", e->getcapacity());
                    q.bindValue(":location", e->getlocation());
                    q.bindValue(":conference", e->getConference());
                    q.bindValue(":division", e->getdivision());
                    q.bindValue(":surface", e->getsurfaceType());
                    q.bindValue(":roof", e->getsurfaceRoofType());
                    q.bindValue(":date", e->getdateOpened());
                    q.exec();
                }

                q.finish();

                int index = 0;
                for(auto e : internal_data.getEdges()){
                    q.prepare("INSERT INTO stadiums_distances VALUES (:id, :from, :to, :distance)");
                    q.bindValue(":id", index);
                    q.bindValue(":from", e->endpoints.first->name->getID());
                    q.bindValue(":to", e->endpoints.first->name->getID());
                    q.bindValue(":distance", e->weight);
                    q.exec();

                    index++;
                }

                q.finish();

                for(auto e : internal_data.getTeams()){
                    q.prepare("INSERT INTO teams VALUES (:id, :name, :stadiumid)");
                    q.bindValue(":id", e->getId());
                    q.bindValue(":name", e->getTeamName());
                    q.bindValue(":stadiumid", e->getStadium());
                    q.exec();
                }

                q.finish();

                for(int i = 0; i < internal_data.getSouvenirSize(); i++){
                    q.prepare("INSERT INTO teams_souvenir VALUES (:id, :name, :team, :price)");
                    q.bindValue(":id", i);
                    q.bindValue(":name", internal_data.getSouvenirs()[i]->getName());
                    q.bindValue(":team", internal_data.getSouvenirs()[i]->getTeamId());
                    q.bindValue(":price", internal_data.getSouvenirs()[i]->getPrice());
                    q.exec();

                }

                q.finish();


                q.prepare("INSERT INTO users VALUES (:id, :fname, :lname, :email, :pass, :perm)");
                q.bindValue(":id", 1);
                q.bindValue(":fname", "Administrator");
                q.bindValue(":lname", "Anon");
                q.bindValue(":email", "admin");
                q.bindValue(":pass", "admin");
                q.bindValue(":perm", 1);
                q.exec();
                q.finish();


                q.prepare("INSERT INTO users VALUES (:id, :fname, :lname, :email, :pass, :perm)");
                q.bindValue(":id", 2);
                q.bindValue(":fname", "Fan");
                q.bindValue(":lname", "Fanon");
                q.bindValue(":email", "fan");
                q.bindValue(":pass", "fan");
                q.bindValue(":perm", 2);
                q.exec();
                q.finish();


                q.prepare("INSERT INTO users VALUES (:id, :fname, :lname, :email, :pass, :perm)");
                q.bindValue(":id", 3);
                q.bindValue(":fname", "Monkey");
                q.bindValue(":lname", "Literal Ape");
                q.bindValue(":email", "monkey");
                q.bindValue(":pass", "banana");
                q.bindValue(":perm", 1);
                q.exec();
                q.finish();
            }
            else{
                QMessageBox::warning(this, "Warning", "Something went wrong Check permissions of the folder you are writing to.");
                return;
            }

            temp.close();
            temp.removeDatabase("Temp");

        }
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}

void MainWindow::on_actionTrip_Planner_triggered()
{
    if(dbOpen){
        PForm->show();
    }
    else
        QMessageBox::information(this, "No Data Loaded", "Please load a db file to access this feature.");
}
