#include "howto1.h"
#include "ui_howto1.h"

howto1::howto1(QWidget *parent) :
    QWidget(parent),
    uihowto1(new Ui::howto1)
{
    uihowto1->setupUi(this);

    QPixmap pPix(":/power");
    QIcon ButtonIcon(pPix);
    powerBtn = new QPushButton(this);
    powerBtn->setIcon(ButtonIcon);
    powerBtn->setIconSize(pPix.rect().size());
    powerBtn->setFixedSize(pPix.rect().size());
    powerBtn->move(422, 263);

    QPixmap pPix2(":/howtp_remote");
    QIcon ButtonIcon2(pPix2);
    showBtn = new QPushButton(this);
    showBtn->setIcon(ButtonIcon);


}

howto1::~howto1()
{
    delete uihowto1;
}

\
