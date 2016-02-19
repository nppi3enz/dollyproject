#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
}

Home::~Home()
{
    delete ui;
}
void Home::on_mode1Bt_clicked()
{
    emit changeMode(1);
}

void Home::on_mode2Bt_clicked()
{
    emit changeMode(2);
}

void Home::on_mode3Bt_clicked()
{
    emit changeMode(3);
}
void Home::close()
{
    QApplication::quit();
}

