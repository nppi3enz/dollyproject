#ifndef HOWTO1_H
#define HOWTO1_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class howto1;
}

class howto1 : public QWidget
{
    Q_OBJECT

public:
    explicit howto1(QWidget *parent = 0);
    ~howto1();

private:
    Ui::howto1 *uihowto1;
    QPixmap* pPix;
    QPixmap* pPix2;
    QPushButton *powerBtn;
    QPushButton *showBtn;
};

#endif // HOWTO1_H
