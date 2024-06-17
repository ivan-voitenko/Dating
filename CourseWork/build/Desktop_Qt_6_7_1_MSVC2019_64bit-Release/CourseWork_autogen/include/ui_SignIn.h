/********************************************************************************
** Form generated from reading UI file 'SignIn.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignIn
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *email;
    QLabel *label_5;
    QLineEdit *password;
    QPushButton *pushButton;
    QLabel *label_6;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName("SignIn");
        SignIn->resize(465, 376);
        SignIn->setMinimumSize(QSize(465, 376));
        SignIn->setMaximumSize(QSize(465, 376));
        SignIn->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 48, 71);"));
        layoutWidget = new QWidget(SignIn);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 20, 341, 311));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        QFont font2;
        font2.setPointSize(14);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        email = new QLineEdit(layoutWidget);
        email->setObjectName("email");
        QFont font3;
        font3.setPointSize(10);
        email->setFont(font3);
        email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(4, 4, 4);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, email);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        password = new QLineEdit(layoutWidget);
        password->setObjectName("password");
        password->setFont(font3);
        password->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(4, 4, 4);"));
        password->setInputMethodHints(Qt::ImhNone);

        formLayout->setWidget(1, QFormLayout::FieldRole, password);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(337, 29));
        pushButton->setMaximumSize(QSize(337, 29));
        QFont font4;
        font4.setPointSize(12);
        pushButton->setFont(font4);

        verticalLayout->addWidget(pushButton);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        label_6->setFont(font5);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font4);

        verticalLayout->addWidget(pushButton_2);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(SignIn);

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QDialog *SignIn)
    {
        SignIn->setWindowTitle(QCoreApplication::translate("SignIn", "Sign in", nullptr));
        label->setText(QCoreApplication::translate("SignIn", "Welcome!", nullptr));
        label_2->setText(QCoreApplication::translate("SignIn", "You should sign in to continue", nullptr));
        label_3->setText(QCoreApplication::translate("SignIn", "Sign In", nullptr));
        label_4->setText(QCoreApplication::translate("SignIn", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("SignIn", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("SignIn", "Sign In", nullptr));
        label_6->setText(QCoreApplication::translate("SignIn", "Dont have an account? Register below", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SignIn", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
