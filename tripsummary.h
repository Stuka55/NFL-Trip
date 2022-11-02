#ifndef TRIPSUMMARY_H
#define TRIPSUMMARY_H

#include <QDialog>
#include "QListWidgetItem"

namespace Ui {
class tripSummary;
}

class tripSummary : public QDialog
{
    Q_OBJECT

public:
    explicit tripSummary(QVector<QString> tms,
                         QVector<QVector<QString>> rcpt,
                         float cst,
                         QVector<float> ctyCst,
                         int dist,
                         QWidget *parent = nullptr);
    ~tripSummary();

private slots:
    void on_close_clicked();

    void on_teams_itemClicked(QListWidgetItem *item);

private:
    Ui::tripSummary *ui;
    QVector<QVector<QString>>& receipt;
    float cost;
    QVector<float> cityCosts;
    int distance;

};

#endif // TRIPSUMMARY_H
