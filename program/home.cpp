#include "home.h"
#include "ui_home.h"
home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

    QPixmap pPix(":/power");
    QIcon ButtonIcon(pPix);
    powerBtn = new QPushButton(this);
    powerBtn->setIcon(ButtonIcon);
    powerBtn->setIconSize(pPix.rect().size());
    powerBtn->setFixedSize(pPix.rect().size());
    powerBtn->move(422, 263);

    QPixmap pPix2(":/info");
    QIcon ButtonIcon2(pPix2);
    infoBtn = new QPushButton(this);
    infoBtn->setIcon(ButtonIcon2);
    infoBtn->setIconSize(pPix.rect().size());
    infoBtn->setFixedSize(pPix.rect().size());
    infoBtn->move(5, 263);

}

home::~home()
{
    delete ui;
}

void home::on_mode1Bt_clicked()
{
    emit changeMode(1);
}

void home::on_mode2Bt_clicked()
{
    emit changeMode(2);
}

void home::on_mode3Bt_clicked()
{
    emit changeMode(3);
}
