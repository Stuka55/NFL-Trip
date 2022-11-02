#ifndef EXECUTETRIP_H
#define EXECUTETRIP_H

#include <QDialog>
#include "data.h"
#include "QListWidgetItem"
#include "tripsummary.h"

namespace Ui {
class ExecuteTrip;
}

/*!
 * \brief The ExecuteTrip class
 */
/*!
 * The ExecuteTrip class contains four private data members\n
 * internal_data : class data&.............contains all of the data in the database.\n
 * journey       : QVector<QString>........holds the calculated travel plan.\n
 * shop          : QVector<Team_Souvenir.......contains the team souvenirs.\n
 * cityCart      : QVector<float>..............the shopping cart of each team.\n
 * dist          : QVector<int>................the distances used show how far travelled\n
 * distance      : int.........................the accumulated total distance gotten by dist\n
 * visited       : QVector<QString>............the teams that have already been visited.\n
 * receipt       : QVector<QVector<QString>>...receipt of what was bought at each city.\n
 * cost          : float.......................the total cost accumulated from all cities.\n
 * cityCost      : QVector<float>..............what is in the cart for one particular city.\n
 * cityCount     : int......................counter to track what city that is travelled to.\n
 *
 *  QVector<float> cityCost; /**< what is in the cart for one particular city
 *  int cityCount; /**< counter to track what city that is travelled to.
 */


class ExecuteTrip : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief overloaded constructor of executetrip
     * \param data dat is the data for teams info
     * \param jrny vector of strings to display cities
     * \param dist distances used to sum up the distances
     * \param QWidget *parent is if there is a parent window for tripplanner
     *
     * intializes variables in the executetrip object
     */
    explicit ExecuteTrip(class data& dat, QVector<QString> jrny,const QVector<int>& dist, QWidget *parent = nullptr);
    /*!
     * \brief overloaded constructor of executetrip
     * \param data dat is the data for teams info
     * \param QWidget *parent is if there is a parent window for tripplanner
     *
     * intializes variables in the executetrip object
     */
    explicit ExecuteTrip(class data& dat, QWidget *parent = nullptr);
    
    /*!
     * \brief function used recalculat price variable
     * @return a float variable to get current price
     *
     * recalculates the price
     */
    float reclaculatePrice();
    ~ExecuteTrip();

private slots:
    void on_pushButton_clicked();

    void on_next_clicked();

    void on_merchandise_itemDoubleClicked(QListWidgetItem *item);

    void on_add_clicked();

    void on_cancel_clicked();

    void on_cart_itemDoubleClicked(QListWidgetItem *item);

    void on_remove_clicked();

private:
    Ui::ExecuteTrip *ui;
    class data& internal_data; /**< contains all of the data in the database*/
    QVector<QString> journey; /**< holds the calculated travel plan.*/
    QVector<int> dist;/**< the distances used show how far travelled*/
    int distance; /**< the accumulated total distance gotten by dist*/
    QVector<QString> visited; /**< the teams that have already been visited*/
    QVector<Team_Souvenir*> shop; /**< contains the team souvenirs.*/
    QVector<float> cityCart; /**< the shopping cart of each team.*/
    QVector<QVector<QString>> receipt; /**< receipt of what was bought at each city*/
    float cost; /**< the total cost accumulated from all cities*/
    QVector<float> cityCost; /**< what is in the cart for one particular city*/
    int cityCount; /**< counter to track what city that is travelled to */
};

#endif // EXECUTETRIP_H
