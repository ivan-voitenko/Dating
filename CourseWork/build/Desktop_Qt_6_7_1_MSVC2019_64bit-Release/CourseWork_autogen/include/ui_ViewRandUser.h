/********************************************************************************
** Form generated from reading UI file 'ViewRandUser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWRANDUSER_H
#define UI_VIEWRANDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewRandUser
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QSplitter *splitter;
    QLabel *user_photo;
    QTextBrowser *about;
    QPushButton *back_button;

    void setupUi(QDialog *ViewRandUser)
    {
        if (ViewRandUser->objectName().isEmpty())
            ViewRandUser->setObjectName("ViewRandUser");
        ViewRandUser->resize(600, 390);
        ViewRandUser->setMinimumSize(QSize(600, 390));
        ViewRandUser->setMaximumSize(QSize(600, 390));
        ViewRandUser->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 48, 71);"));
        layoutWidget = new QWidget(ViewRandUser);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 601, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 10));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        user_photo = new QLabel(splitter);
        user_photo->setObjectName("user_photo");
        sizePolicy.setHeightForWidth(user_photo->sizePolicy().hasHeightForWidth());
        user_photo->setSizePolicy(sizePolicy);
        user_photo->setMinimumSize(QSize(250, 0));
        splitter->addWidget(user_photo);
        about = new QTextBrowser(splitter);
        about->setObjectName("about");
        QFont font2;
        font2.setPointSize(11);
        about->setFont(font2);
        splitter->addWidget(about);

        verticalLayout->addWidget(splitter);

        back_button = new QPushButton(layoutWidget);
        back_button->setObjectName("back_button");
        back_button->setFont(font2);

        verticalLayout->addWidget(back_button);


        retranslateUi(ViewRandUser);

        QMetaObject::connectSlotsByName(ViewRandUser);
    } // setupUi

    void retranslateUi(QDialog *ViewRandUser)
    {
        ViewRandUser->setWindowTitle(QCoreApplication::translate("ViewRandUser", "Information", nullptr));
        label->setText(QCoreApplication::translate("ViewRandUser", "Surname name lastname", nullptr));
        label_2->setText(QCoreApplication::translate("ViewRandUser", "INFO", nullptr));
        user_photo->setText(QString());
        back_button->setText(QCoreApplication::translate("ViewRandUser", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewRandUser: public Ui_ViewRandUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWRANDUSER_H
