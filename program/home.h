#ifndef HOME_H
#define HOME_H

#include <QWidget>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();
signals:
    void changeMode(int);
private slots:
    void on_mode1Bt_clicked();
    void on_mode2Bt_clicked();
    void on_mode3Bt_clicked();
    void close();
private:
    Ui::Home *ui;
};

#endif // HOME_H
