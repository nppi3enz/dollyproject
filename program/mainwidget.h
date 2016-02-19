#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "home.h"
#include "howto_1.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QStackedWidget *stackedWidget;
    Home *homepage;
    howto_1 *howto1;

private slots:
    void swapMode(int s);
};


#endif // MAINWIDGET_H
