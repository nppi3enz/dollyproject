#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*homepage = new home(this);
    ui->horizontalLayout->addWidget(homepage);
    connect(homepage, SIGNAL(changeMode(int)), this, SLOT(swapMode(int)));
*/
    homepage = new home(this);
    hmode1 = new howto1(this);

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(homepage);
    stackedWidget->addWidget(hmode1);
    ui->horizontalLayout->addWidget(stackedWidget);

    connect(homepage, SIGNAL(changeMode(int)), this, SLOT(swapMode(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::swapMode(int s){
    if(s == 1) { //mode remote
        stackedWidget->setCurrentIndex(1);
    } else if(s == 2) { //mode auto tracking
        stackedWidget->setCurrentIndex(2);
    } else if(s == 3) { //mode time lapse
        stackedWidget->setCurrentIndex(3);
    }
    qDebug() << s;
}
