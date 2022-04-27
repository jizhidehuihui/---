/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *startgame;
    QPushButton *gamelevel;
    QPushButton *exitgame;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        Widget->setContextMenuPolicy(Qt::NoContextMenu);
        Widget->setStyleSheet(QStringLiteral("background-color: rgb(186, 189, 182);"));
        startgame = new QPushButton(Widget);
        startgame->setObjectName(QStringLiteral("startgame"));
        startgame->setGeometry(QRect(290, 210, 89, 25));
        startgame->setStyleSheet(QLatin1String("background-color: rgb(239, 41, 41);\n"
"QPushButton press:\n"
"{\n"
"	background-color: rgb(164, 0, 0);\n"
"}"));
        gamelevel = new QPushButton(Widget);
        gamelevel->setObjectName(QStringLiteral("gamelevel"));
        gamelevel->setGeometry(QRect(290, 250, 89, 25));
        gamelevel->setContextMenuPolicy(Qt::ActionsContextMenu);
        gamelevel->setStyleSheet(QLatin1String("background-color: rgb(239, 41, 41);\n"
"QPushButton press:\n"
"{\n"
"	background-color: rgb(164, 0, 0);\n"
"}"));
        exitgame = new QPushButton(Widget);
        exitgame->setObjectName(QStringLiteral("exitgame"));
        exitgame->setGeometry(QRect(290, 290, 89, 25));
        exitgame->setStyleSheet(QLatin1String("background-color: rgb(239, 41, 41);\n"
"QPushButton press:\n"
"{\n"
"	background-color: rgb(164, 0, 0);\n"
"}"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        startgame->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        gamelevel->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\347\255\211\347\272\247", Q_NULLPTR));
        exitgame->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
