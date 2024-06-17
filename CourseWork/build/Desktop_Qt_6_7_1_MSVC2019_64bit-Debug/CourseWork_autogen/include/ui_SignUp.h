/********************************************************************************
** Form generated from reading UI file 'SignUp.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_10;
    QLabel *label_2;
    QLineEdit *surname;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label_4;
    QLineEdit *last_name;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *ageSpinBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *genderComboBox;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_11;
    QLineEdit *university;
    QLabel *label_12;
    QLineEdit *faculty;
    QLabel *label_14;
    QLineEdit *speciality;
    QLabel *label_13;
    QLineEdit *degree;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QSpinBox *admissionSpinBox;
    QLabel *label_16;
    QSpinBox *graduationSpinBox;
    QCheckBox *checkBox_3;
    QLabel *label_17;
    QLabel *label_5;
    QLineEdit *email;
    QLabel *label_6;
    QLineEdit *password;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(480, 376);
        SignUp->setMinimumSize(QSize(480, 376));
        SignUp->setMaximumSize(QSize(480, 376));
        SignUp->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 48, 71);"));
        horizontalLayout = new QHBoxLayout(SignUp);
        horizontalLayout->setObjectName("horizontalLayout");
        scrollArea = new QScrollArea(SignUp);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, -420, 446, 818));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(scrollAreaWidgetContents_2);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 800));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(frame);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_10->setFont(font1);

        verticalLayout->addWidget(label_10);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(11);
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        surname = new QLineEdit(frame);
        surname->setObjectName("surname");
        QFont font3;
        font3.setPointSize(10);
        surname->setFont(font3);
        surname->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout->addWidget(surname);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        name = new QLineEdit(frame);
        name->setObjectName("name");
        name->setFont(font3);
        name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout->addWidget(name);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        last_name = new QLineEdit(frame);
        last_name->setObjectName("last_name");
        last_name->setFont(font3);
        last_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout->addWidget(last_name);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);

        horizontalLayout_6->addWidget(label_7);

        ageSpinBox = new QSpinBox(frame);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setMinimum(16);
        ageSpinBox->setMaximum(100);

        horizontalLayout_6->addWidget(ageSpinBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);

        horizontalLayout_7->addWidget(label_8);

        genderComboBox = new QComboBox(frame);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");

        horizontalLayout_7->addWidget(genderComboBox);


        verticalLayout->addLayout(horizontalLayout_7);

        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setFont(font1);

        verticalLayout->addWidget(label_9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font2);

        verticalLayout_2->addWidget(checkBox);


        verticalLayout->addLayout(verticalLayout_2);

        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setFont(font2);

        verticalLayout->addWidget(checkBox_2);

        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        verticalLayout->addWidget(label_11);

        university = new QLineEdit(frame);
        university->setObjectName("university");
        university->setFont(font3);
        university->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout->addWidget(university);

        label_12 = new QLabel(frame);
        label_12->setObjectName("label_12");
        label_12->setFont(font2);

        verticalLayout->addWidget(label_12);

        faculty = new QLineEdit(frame);
        faculty->setObjectName("faculty");
        faculty->setFont(font3);
        faculty->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout->addWidget(faculty);

        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        label_14->setFont(font2);

        verticalLayout->addWidget(label_14);

        speciality = new QLineEdit(frame);
        speciality->setObjectName("speciality");
        speciality->setFont(font3);
        speciality->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout->addWidget(speciality);

        label_13 = new QLabel(frame);
        label_13->setObjectName("label_13");
        label_13->setFont(font2);

        verticalLayout->addWidget(label_13);

        degree = new QLineEdit(frame);
        degree->setObjectName("degree");
        degree->setFont(font3);
        degree->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout->addWidget(degree);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_15 = new QLabel(frame);
        label_15->setObjectName("label_15");
        label_15->setFont(font2);

        horizontalLayout_12->addWidget(label_15);

        admissionSpinBox = new QSpinBox(frame);
        admissionSpinBox->setObjectName("admissionSpinBox");
        admissionSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        admissionSpinBox->setMinimum(1950);
        admissionSpinBox->setMaximum(2024);

        horizontalLayout_12->addWidget(admissionSpinBox);

        label_16 = new QLabel(frame);
        label_16->setObjectName("label_16");
        label_16->setFont(font2);

        horizontalLayout_12->addWidget(label_16);

        graduationSpinBox = new QSpinBox(frame);
        graduationSpinBox->setObjectName("graduationSpinBox");
        graduationSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        graduationSpinBox->setMinimum(1954);
        graduationSpinBox->setMaximum(2050);

        horizontalLayout_12->addWidget(graduationSpinBox);


        verticalLayout->addLayout(horizontalLayout_12);

        checkBox_3 = new QCheckBox(frame);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setFont(font2);
        checkBox_3->setLayoutDirection(Qt::RightToLeft);

        verticalLayout->addWidget(checkBox_3);

        label_17 = new QLabel(frame);
        label_17->setObjectName("label_17");
        label_17->setFont(font1);

        verticalLayout->addWidget(label_17);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        email = new QLineEdit(frame);
        email->setObjectName("email");
        email->setFont(font3);
        email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout->addWidget(email);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);

        password = new QLineEdit(frame);
        password->setObjectName("password");
        password->setFont(font3);
        password->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout->addWidget(password);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font2);

        verticalLayout->addWidget(pushButton);


        horizontalLayout_2->addWidget(frame);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Sign up", nullptr));
        label->setText(QCoreApplication::translate("SignUp", "Fill in each input field", nullptr));
        label_10->setText(QCoreApplication::translate("SignUp", "Personal information", nullptr));
        label_2->setText(QCoreApplication::translate("SignUp", "Surname", nullptr));
        label_3->setText(QCoreApplication::translate("SignUp", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("SignUp", "Father name", nullptr));
        label_7->setText(QCoreApplication::translate("SignUp", "Age", nullptr));
        label_8->setText(QCoreApplication::translate("SignUp", "Gender", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("SignUp", "male", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("SignUp", "female", nullptr));

        label_9->setText(QCoreApplication::translate("SignUp", "Education", nullptr));
        checkBox->setText(QCoreApplication::translate("SignUp", "Secondary education", nullptr));
        checkBox_2->setText(QCoreApplication::translate("SignUp", "Higher education", nullptr));
        label_11->setText(QCoreApplication::translate("SignUp", "University", nullptr));
        label_12->setText(QCoreApplication::translate("SignUp", "Faculty", nullptr));
        faculty->setText(QString());
        label_14->setText(QCoreApplication::translate("SignUp", "Speciality", nullptr));
        label_13->setText(QCoreApplication::translate("SignUp", "Degree", nullptr));
        label_15->setText(QCoreApplication::translate("SignUp", "Year of admission", nullptr));
        label_16->setText(QCoreApplication::translate("SignUp", "Year of graduation", nullptr));
        checkBox_3->setText(QCoreApplication::translate("SignUp", "Still learning", nullptr));
        label_17->setText(QCoreApplication::translate("SignUp", "Sign in information", nullptr));
        label_5->setText(QCoreApplication::translate("SignUp", "Email", nullptr));
        label_6->setText(QCoreApplication::translate("SignUp", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("SignUp", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
