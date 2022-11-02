#include "tripsummary.h"
#include "ui_tripsummary.h"

tripSummary::tripSummary(QVector<QString> teams, QVector<QVector<QString> > rcpt, float cst, QVector<float> ctyCst, int dist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tripSummary),
    receipt(rcpt),
    cost(cst),
    distance(dist),
    cityCosts(ctyCst)
{
    ui->setupUi(this);

    for(int i = 0; i < teams.size(); i++)
    {
        ui->teams->addItem(teams.at(i));
    }
}

tripSummary::~tripSummary()
{
    delete ui;
}

void tripSummary::on_close_clicked()
{
    close();
}

void tripSummary::on_teams_itemClicked(QListWidgetItem *item)
{
    QString text = "Receipt for the " + ui->teams->item(ui->teams->currentRow())->text() + " team:\n\n";
    //text = text + QString::number(receipt[ui->teams->currentRow()].size());

    if (receipt[ui->teams->currentRow()].empty())
    {
        text.append(" - Nothing was purched here.\n");
    }
    else
    {
        for (int i = 0; i < receipt[ui->teams->currentRow()].size(); i++)
        {
            text.append(" - " + receipt[ui->teams->currentRow()][i] + '\n');
            //text = text + QString::number(i) + '\n';
        }
    }

    text.append("\n----------------------------------");
    text.append("\nTeam cost: $" + QString::number(cityCosts.at(ui->teams->currentRow())));
    text.append("\nTotal cost: $" + QString::number(cost));
    text.append("\n\nTotal distance: " + QString::number(distance)+ " miles.");

    //receipt.at(2).at(3).
    ui->receipt->setPlainText(text);
    //ui->receipt->setText(QString::number(ui->teams->currentRow()));
}
