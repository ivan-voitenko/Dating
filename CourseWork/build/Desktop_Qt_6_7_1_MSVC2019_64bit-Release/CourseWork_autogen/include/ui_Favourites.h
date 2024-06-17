/********************************************************************************
** Form generated from reading UI file 'Favourites.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAVOURITES_H
#define UI_FAVOURITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Favourites
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *Favourites)
    {
        if (Favourites->objectName().isEmpty())
            Favourites->setObjectName("Favourites");
        Favourites->resize(582, 433);
        Favourites->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 48, 71);"));
        widget = new QWidget(Favourites);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 581, 431));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(130, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 577, 390));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Favourites);

        QMetaObject::connectSlotsByName(Favourites);
    } // setupUi

    void retranslateUi(QDialog *Favourites)
    {
        Favourites->setWindowTitle(QCoreApplication::translate("Favourites", "Favourites", nullptr));
        pushButton->setText(QCoreApplication::translate("Favourites", "Back", nullptr));
        label->setText(QCoreApplication::translate("Favourites", "Your favourites", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Favourites: public Ui_Favourites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAVOURITES_H
