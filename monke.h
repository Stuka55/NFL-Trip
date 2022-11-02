#ifndef MONKE_H
#define MONKE_H

#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class monke;
}

class monke : public QWidget
{
    Q_OBJECT

public:
    explicit monke(QWidget *parent = nullptr);
    ~monke();

public slots:
    void screech();

private:
    Ui::monke *ui;
    QMediaPlayer OOOH_OOOH_AAAH;
};

#endif // MONKE_H
