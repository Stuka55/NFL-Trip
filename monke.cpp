#include "monke.h"
#include "ui_monke.h"

monke::monke(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::monke)
{
    ui->setupUi(this);

    OOOH_OOOH_AAAH.setMedia(QUrl("qrc:/MONKEE/windowicons/monke/monkey1.wav"));

    connect(ui->label, SIGNAL(clicked()), this, SLOT(screech()));
}

monke::~monke()
{
    delete ui;
}

void monke::screech(){
    OOOH_OOOH_AAAH.play();
}
