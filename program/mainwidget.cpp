#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    homepage = new Home(this);
    howto1 = new howto_1(this);

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(homepage);
    stackedWidget->addWidget(howto1);
    ui->horizontalLayout->addWidget(stackedWidget);

    connect(homepage, SIGNAL(changeMode(int)), this, SLOT(swapMode(int)));

}

MainWidget::~MainWidget()
{
    delete ui;
}
void MainWidget::swapMode(int s){
    if(s == 1) { //mode remote
        stackedWidget->setCurrentIndex(1);
    } else if(s == 2) { //mode auto tracking
        stackedWidget->setCurrentIndex(2);
    } else if(s == 3) { //mode time lapse
        stackedWidget->setCurrentIndex(3);
    }
    qDebug() << "Scene" << s;
}
