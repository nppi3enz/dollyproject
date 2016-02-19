#include "howto_1.h"
#include "ui_howto_1.h"

howto_1::howto_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::howto_1)
{
    ui->setupUi(this);
}

howto_1::~howto_1()
{
    delete ui;
}
