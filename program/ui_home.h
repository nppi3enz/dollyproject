/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QPushButton *mode1Bt;
    QPushButton *mode2Bt;
    QPushButton *mode3Bt;
    QLabel *logoName;
    QLabel *label;

    void setupUi(QWidget *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName(QStringLiteral("home"));
        home->resize(480, 320);
        home->setAutoFillBackground(false);
        home->setStyleSheet(QStringLiteral("background-color: #242424;"));
        mode1Bt = new QPushButton(home);
        mode1Bt->setObjectName(QStringLiteral("mode1Bt"));
        mode1Bt->setGeometry(QRect(19, 93, 138, 145));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/mode_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        mode1Bt->setIcon(icon);
        mode1Bt->setIconSize(QSize(138, 145));
        mode2Bt = new QPushButton(home);
        mode2Bt->setObjectName(QStringLiteral("mode2Bt"));
        mode2Bt->setGeometry(QRect(172, 93, 138, 145));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/mode_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        mode2Bt->setIcon(icon1);
        mode2Bt->setIconSize(QSize(138, 145));
        mode3Bt = new QPushButton(home);
        mode3Bt->setObjectName(QStringLiteral("mode3Bt"));
        mode3Bt->setGeometry(QRect(326, 93, 138, 145));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/mode_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        mode3Bt->setIcon(icon2);
        mode3Bt->setIconSize(QSize(138, 145));
        mode3Bt->setCheckable(false);
        logoName = new QLabel(home);
        logoName->setObjectName(QStringLiteral("logoName"));
        logoName->setGeometry(QRect(139, 36, 205, 25));
        logoName->setPixmap(QPixmap(QString::fromUtf8(":/logoMenu")));
        label = new QLabel(home);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 280, 211, 21));
        QFont font;
        font.setFamily(QStringLiteral("supermarket"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label->setWordWrap(false);
        label->setIndent(6);

        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QWidget *home)
    {
        home->setWindowTitle(QApplication::translate("home", "Form", 0));
        mode1Bt->setText(QString());
        mode2Bt->setText(QString());
        mode3Bt->setText(QString());
        logoName->setText(QString());
        label->setText(QApplication::translate("home", "\340\271\200\340\270\245\340\270\267\340\270\255\340\270\201\340\271\202\340\270\253\340\270\241\340\270\224\340\270\227\340\270\265\340\271\210\340\270\225\340\271\211\340\270\255\340\270\207\340\270\201\340\270\262\340\270\243", 0));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
