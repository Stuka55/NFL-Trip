#include "executetrip.h"
#include "ui_executetrip.h"
#include "QtDebug"

ExecuteTrip::ExecuteTrip(class data& dat, QVector<QString> jrny, const QVector<int>& dist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExecuteTrip),
    internal_data(dat),
    dist(dist),
    distance(0),
    cost(0),
    cityCount(0)
{
    ui->setupUi(this);
    journey = jrny;
    ui->info->clear();
    ui->merchandise->clear();

    team tempTeam(internal_data.getTeam_Alphabet(journey.at(0)));
    Stadium tempStad(internal_data.getStadium_ID(tempTeam.getStadium()));
    QString text = "Team Name: " + tempTeam.getTeamName() + '\n'
            + "Stadium Name: " + tempStad.getstadiumName() + '\n'
            + "  Seating: " + QString::number(tempStad.getcapacity()) + " seats\n"
            + "  Location: " + tempStad.getlocation() + '\n'
            + "  Conference: " + tempStad.getConference() + '\n'
            + "  Division: " + tempStad.getdivision() + '\n'
            + "  Turf Surface Type: " + tempStad.getsurfaceType() + '\n'
            + "  Roof Type: " + tempStad.getsurfaceRoofType() + '\n'
            + "  Date Opened: " + QString::number(tempStad.getdateOpened()) + '\n'
            + "\n\n  Total distance travelled so far: " +  QString::number(distance) + " miles.";
    ui->info->setText(text);

    shop = tempTeam.getSouvenirs();
    for (int i = 0; i < shop.size(); i++)
    {
        QString item = shop.at(i)->getName()+ "($" + QString::number(shop.at(i)->getPrice()) + ')';
        ui->merchandise->addItem(item);
    }

    visited.push_back(journey.at(0));
    journey.pop_front();
    if(journey.empty())
    {
        ui->next->setText("Finish Trip");
    }

    //ui->textBrowser->setText("dfghjhg");
}

ExecuteTrip::ExecuteTrip(class data& dat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExecuteTrip),
    internal_data(dat)
{
    ui->setupUi(this);
    journey.push_back("TESTING");
}

ExecuteTrip::~ExecuteTrip()
{
    delete ui;
}

void ExecuteTrip::on_pushButton_clicked()
{
    close();
}

void ExecuteTrip::on_next_clicked()
{
    if(journey.empty())
    {
        QVector<QString> pseudoRecipt;
        for(int i = 0; i < ui->cart->count(); i++)
        {
            QString tempItem = ui->cart->item(i)->text();
            pseudoRecipt.push_back(tempItem);
        }
        receipt.push_back(pseudoRecipt);
        ui->cart->clear();

        cityCost.push_back(reclaculatePrice()); // fix this
        cost += reclaculatePrice();
        tripSummary summary(visited,receipt,cost,cityCost,distance);
        summary.exec();
        close();
    }
    else
    {
        ui->info->clear();
        ui->merchandise->clear();

        distance += dist.at(cityCount);
        cityCount++;



        team tempTeam(internal_data.getTeam_Alphabet(journey.at(0)));
        Stadium tempStad(internal_data.getStadium_ID(tempTeam.getStadium()));
        //QString text = "Test";
        QString text = "Team Name: " + tempTeam.getTeamName() + '\n'
                + "Stadium Name: " + tempStad.getstadiumName() + '\n'
                + "  Seating: " + QString::number(tempStad.getcapacity()) + " seats\n"
                + "  Location: " + tempStad.getlocation() + '\n'
                + "  Conference: " + tempStad.getConference() + '\n'
                + "  Division: " + tempStad.getdivision() + '\n'
                + "  Turf Surface Type: " + tempStad.getsurfaceType() + '\n'
                + "  Roof Type: " + tempStad.getsurfaceRoofType() + '\n'
                + "  Date Opened: " + QString::number(tempStad.getdateOpened()) + '\n'
                + "\n\nDistance from last team: " + QString::number(dist.at(cityCount-1)) + " miles."
                + "\nTotal distance travelled so far: " +  QString::number(distance) + " miles.";
        ui->info->setText(text);

        shop = tempTeam.getSouvenirs();
        for (int i = 0; i < shop.size(); i++)
        {
            QString item = shop.at(i)->getName()+ "($" + QString::number(shop.at(i)->getPrice()) + ')';
            ui->merchandise->addItem(item);
        }

        QVector<QString> pseudoRecipt;
        for(int i = 0; i < ui->cart->count(); i++)
        {
            QString tempItem = ui->cart->item(i)->text();
            pseudoRecipt.push_back(tempItem);
        }
        receipt.push_back(pseudoRecipt);
        ui->cart->clear();

        cityCost.push_back(reclaculatePrice());
        cost += reclaculatePrice();
        cityCart.clear();

        visited.push_back(journey.at(0));
        journey.pop_front();
        if(journey.empty())
        {
            ui->next->setText("Finish Trip");
        }
    }
}

void ExecuteTrip::on_merchandise_itemDoubleClicked(QListWidgetItem *item)
{
    QString purchase = shop.at(ui->merchandise->currentRow())->getName()
                       + " x1 ($"
                       + QString::number(shop.at(ui->merchandise->currentRow())->getPrice())
                       + ')';
    ui->cart->addItem(purchase);

    cityCart.push_back(shop.at(ui->merchandise->currentRow())->getPrice());
    reclaculatePrice();
}

void ExecuteTrip::on_add_clicked()
{
    //ui->lineEdit.int
    QString purchase = shop.at(ui->merchandise->currentRow())->getName()
                       + " x"
                       + QString::number(ui->quantity->value())
                       + " ($"
                       + QString::number(shop.at(ui->merchandise->currentRow())->getPrice() * ui->quantity->value())
                       + ')';
    ui->cart->addItem(purchase);

    cityCart.push_back(shop.at(ui->merchandise->currentRow())->getPrice() * ui->quantity->value());
    reclaculatePrice();
    //recalculatePrice(ui->quantity->value())
}

void ExecuteTrip::on_cancel_clicked()
{
    close();
}

void ExecuteTrip::on_cart_itemDoubleClicked(QListWidgetItem *item)
{

    cityCart.removeAt(ui->cart->currentRow());
    ui->cart->takeItem(ui->cart->row(item));
    reclaculatePrice();
}

void ExecuteTrip::on_remove_clicked()
{

    if(ui->cart->selectedItems().size() == 0)
    {
        return;
    }
    else
    {
        cityCart.removeAt(ui->cart->currentRow());
        ui->cart->takeItem(ui->cart->currentRow());
        reclaculatePrice();
    }


}

float ExecuteTrip::reclaculatePrice()
{
    if(cityCart.empty() && cost == 0)
    {
        ui->price->setText("Current Total: $0.00");
        return 0;
    }
    else
    {
        float price = 0;
        for(int i = 0; i < cityCart.size(); i++)
        {
            price += cityCart.at(i);
        }
        ui->price->setText("Current Total: $" + QString::number(price + cost));
        return price;
    }
}
