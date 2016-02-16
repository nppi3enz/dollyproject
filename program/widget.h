#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "home.h"
#include "howto1.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QStackedWidget *stackedWidget;
    home *homepage;
    howto1 *hmode1;

private slots:
    void swapMode(int s);
};

#endif // WIDGET_H
