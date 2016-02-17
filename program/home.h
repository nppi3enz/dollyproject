#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QStackedWidget>

namespace Ui {
class home;
}

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = 0);
    ~home();

signals:
    void changeMode(int);

private slots:
    void on_mode1Bt_clicked();

    void on_mode2Bt_clicked();

    void on_mode3Bt_clicked();

    void close();

private:
    Ui::home *ui;
    QPixmap* pPix;
    QPushButton *powerBtn;
    QPixmap* pPix2;
    QPushButton *infoBtn;

};

#endif // HOME_H
