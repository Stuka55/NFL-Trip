#include "graphalgorithmviewwidget.h"
#include "ui_graphalgorithmviewwidget.h"

GraphAlgorithmViewWidget::GraphAlgorithmViewWidget(class data& dat, bool& dbStatus, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphAlgorithmViewWidget),
    internal_data( dat ),
    dbStatus(dbStatus)
{
    ui->setupUi(this);
    ui->showGraph_pushButton->setText("Clear Text");
    ui->select_city->setVisible(false);


    if(dbStatus){
    // When you add refreshLists, put this in there, stinky.
        refreshLists();
    }
}

GraphAlgorithmViewWidget::~GraphAlgorithmViewWidget()
{
    delete ui;
}

void GraphAlgorithmViewWidget::refreshLists(){
    for(int i = 0; i < internal_data.getStadiumsSize(); i++){
        ui->city1_comboBox->addItem(internal_data.getStadium_index(i)->getstadiumName());
    }
}

void GraphAlgorithmViewWidget::on_closeWindow_pushButton_clicked()
{
    close();
}

void GraphAlgorithmViewWidget::on_showGraph_pushButton_clicked() // case 1,2, & 4 will never occur. See on_showGraph2_pushButton_clicked() for those cases.
{
    switch(ui->algo_comboBox->currentIndex()){
    case 0:
        ui->label->setText("Viewing: Nothing");
        ui->output_plainTextEdit->clear();
        return;
    case 1:
        return;
    case 2:

        return;
    case 3:{
        ui->label->setText("Viewing: Minimum Spanning Tree");
        QStringList tempList = internal_data.getMST();
        QString temp;
        for (auto e : tempList)
            temp += e;
        ui->output_plainTextEdit->setPlainText(temp);
        return;
    }
    case 4:
        return;

    }
}

void GraphAlgorithmViewWidget::on_algo_comboBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        ui->select_city->setVisible(false);
        ui->showGraph_pushButton->setVisible(true);
        ui->showGraph_pushButton->setText("Clear Text");
        break;
    case 1:
    case 2:
        ui->showGraph_pushButton->setVisible(false);
        ui->select_city->setVisible(true);
        ui->from_Label->setVisible(false);
        ui->starting_Label->setVisible(true);
        break;
    case 3:
        ui->select_city->setVisible(false);
        ui->showGraph_pushButton->setVisible(true);
        ui->showGraph_pushButton->setText("Show Graph");
        break;
    case 4:
        ui->showGraph_pushButton->setVisible(false);
        ui->select_city->setVisible(true);
        ui->from_Label->setVisible(true);
        ui->starting_Label->setVisible(false);
        break;
    }
}

void GraphAlgorithmViewWidget::on_showGraph2_pushButton_clicked()
{
    switch(ui->algo_comboBox->currentIndex()){
    case 1:
        if(ui->city1_comboBox->currentIndex() != 0){
            ui->label->setText("Viewing: Depth First Traversal (DFS)");
            QStringList tempList = internal_data.getDFS(ui->city1_comboBox->currentText());
            QString temp;
            for (auto e : tempList)
                temp += e;
            ui->output_plainTextEdit->setPlainText(temp);
        }
        else
            QMessageBox::information(this, "No Starting Stadium", "Please select a starting stadium.");
        break;
    case 2:
        if(ui->city1_comboBox->currentIndex() != 0){
            ui->label->setText("Viewing: Breadth First Traversal (BFS)");
            QStringList tempList = internal_data.getBFS(ui->city1_comboBox->currentText());
            QString temp;
            for(auto e : tempList)
                temp += e + '\n';
            ui->output_plainTextEdit->setPlainText(temp);
        }
        else
            QMessageBox::information(this, "No Starting Stadium", "Please select a starting stadium.");
        break;
    case 4:
        if(ui->city1_comboBox->currentIndex() != 0){
            ui->label->setText("Viewing: Djikstra's Shortest Path Algorithm");

            std::vector<int> a = internal_data.getDjikstra(ui->city1_comboBox->currentText());

            QStringList tempList;

            for(int i = 0; i < int(a.size()); i++){
                tempList << "Distance From " + ui->city1_comboBox->currentText() + " to " + internal_data.getStadiumByPosInGraph(i)->getstadiumName() + ": " + QString::number(a[i]) + '\n';
            }

            for(auto e : tempList)
                ui->output_plainTextEdit->setPlainText(ui->output_plainTextEdit->document()->toPlainText().append(e));

        }
        else
            QMessageBox::information(this, "No Starting Stadium", "Please select a starting stadium.");
        break;
    }

    return;
}
