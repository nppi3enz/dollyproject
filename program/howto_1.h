#ifndef HOWTO_1_H
#define HOWTO_1_H

#include <QWidget>

namespace Ui {
class howto_1;
}

class howto_1 : public QWidget
{
    Q_OBJECT

public:
    explicit howto_1(QWidget *parent = 0);
    ~howto_1();

private:
    Ui::howto_1 *ui;
};

#endif // HOWTO_1_H
