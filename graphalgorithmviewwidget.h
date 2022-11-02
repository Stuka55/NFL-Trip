#ifndef GRAPHALGORITHMVIEWWIDGET_H
#define GRAPHALGORITHMVIEWWIDGET_H

#include <QWidget>
#include "data.h"
#include <QMessageBox>

namespace Ui {
class GraphAlgorithmViewWidget;
}
/*!
 * \brief The GraphAlgorithmViewWidget class
 */
/*!
 * The GraphAlgorithmViewWidget class has two private data members\n
 * internal_data :class data&...Holds all of the data in the programs database\n
 * dbStatus      :bool&.........keeps track on whether teh SQL database connection is open or closed\n
 */
class GraphAlgorithmViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphAlgorithmViewWidget(class data& dat, bool& dbStatus, QWidget *parent = nullptr);
    ~GraphAlgorithmViewWidget();

private slots:
    void on_closeWindow_pushButton_clicked();

    void on_showGraph_pushButton_clicked();

    void on_algo_comboBox_currentIndexChanged(int index);

    void on_showGraph2_pushButton_clicked();

    void refreshLists();

private:
    Ui::GraphAlgorithmViewWidget *ui;

    class data& internal_data;
    bool& dbStatus;
};

#endif // GRAPHALGORITHMVIEWWIDGET_H
