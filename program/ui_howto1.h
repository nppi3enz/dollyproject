/********************************************************************************
** Form generated from reading UI file 'howto1.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWTO1_H
#define UI_HOWTO1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_howto1
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *howto1)
    {
        if (howto1->objectName().isEmpty())
            howto1->setObjectName(QStringLiteral("howto1"));
        howto1->resize(480, 320);
        howto1->setAutoFillBackground(false);
        howto1->setStyleSheet(QStringLiteral("background-color: #242424;"));
        label = new QLabel(howto1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 211, 21));
        QFont font;
        font.setFamily(QStringLiteral("supermarket"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(false);
        label->setIndent(6);
        label_2 = new QLabel(howto1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(324, 18, 142, 21));
        label_2->setLineWidth(0);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/logoMini")));

        retranslateUi(howto1);

        QMetaObject::connectSlotsByName(howto1);
    } // setupUi

    void retranslateUi(QWidget *howto1)
    {
        howto1->setWindowTitle(QApplication::translate("howto1", "Form", 0));
        label->setText(QApplication::translate("howto1", "\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241\340\270\234\340\271\210\340\270\262\340\270\231\340\270\241\340\270\267\340\270\255\340\270\226\340\270\267\340\270\255", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class howto1: public Ui_howto1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWTO1_H
