/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QCheckBox *student_cbox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_19;
    QTextEdit *interests_edit;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QCheckBox *sec_ed_cbox;
    QCheckBox *higher_ed_cbox;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label_3;
    QLineEdit *surname;
    QLabel *label_4;
    QLineEdit *name;
    QLabel *label_5;
    QLineEdit *last_name;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *ageSpinBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *genderComboBox;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
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

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(570, 483);
        Settings->setMinimumSize(QSize(570, 483));
        Settings->setMaximumSize(QSize(570, 483));
        Settings->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 48, 71);"));
        scrollArea = new QScrollArea(Settings);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 571, 481));
        scrollArea->setMinimumSize(QSize(571, 481));
        scrollArea->setMaximumSize(QSize(571, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, -305, 555, 938));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(scrollAreaWidgetContents_2);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 920));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        student_cbox = new QCheckBox(frame);
        student_cbox->setObjectName("student_cbox");
        student_cbox->setGeometry(QRect(10, 620, 507, 20));
        QFont font;
        font.setPointSize(11);
        student_cbox->setFont(font);
        student_cbox->setLayoutDirection(Qt::RightToLeft);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 640, 511, 231));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName("label_19");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_19->setFont(font1);

        verticalLayout->addWidget(label_19);

        interests_edit = new QTextEdit(layoutWidget);
        interests_edit->setObjectName("interests_edit");
        interests_edit->setFont(font);

        verticalLayout->addWidget(interests_edit);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 880, 511, 41));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(250, 0));
        QFont font2;
        font2.setPointSize(12);
        pushButton->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(250, 0));
        pushButton_2->setMaximumSize(QSize(250, 16777215));
        pushButton_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton_2);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 270, 511, 87));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName("label_9");
        label_9->setFont(font1);

        verticalLayout_3->addWidget(label_9);

        sec_ed_cbox = new QCheckBox(layoutWidget2);
        sec_ed_cbox->setObjectName("sec_ed_cbox");
        sec_ed_cbox->setFont(font);

        verticalLayout_3->addWidget(sec_ed_cbox);

        higher_ed_cbox = new QCheckBox(layoutWidget2);
        higher_ed_cbox->setObjectName("higher_ed_cbox");
        higher_ed_cbox->setFont(font);

        verticalLayout_3->addWidget(higher_ed_cbox);

        layoutWidget3 = new QWidget(frame);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 0, 511, 292));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName("label_2");
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName("label_10");
        label_10->setFont(font1);

        verticalLayout_2->addWidget(label_10);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        surname = new QLineEdit(layoutWidget3);
        surname->setObjectName("surname");
        QFont font4;
        font4.setPointSize(10);
        surname->setFont(font4);
        surname->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout_2->addWidget(surname);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        name = new QLineEdit(layoutWidget3);
        name->setObjectName("name");
        name->setFont(font4);
        name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout_2->addWidget(name);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        last_name = new QLineEdit(layoutWidget3);
        last_name->setObjectName("last_name");
        last_name->setFont(font4);
        last_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout_2->addWidget(last_name);


        verticalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        ageSpinBox = new QSpinBox(layoutWidget3);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setMinimum(16);
        ageSpinBox->setMaximum(100);

        horizontalLayout_6->addWidget(ageSpinBox);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        horizontalLayout_7->addWidget(label_8);

        genderComboBox = new QComboBox(layoutWidget3);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");

        horizontalLayout_7->addWidget(genderComboBox);


        verticalLayout_5->addLayout(horizontalLayout_7);

        layoutWidget4 = new QWidget(frame);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 355, 511, 258));
        verticalLayout_6 = new QVBoxLayout(layoutWidget4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        verticalLayout_4->addWidget(label_11);

        university = new QLineEdit(layoutWidget4);
        university->setObjectName("university");
        university->setFont(font4);
        university->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_4->addWidget(university);

        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName("label_12");
        label_12->setFont(font);

        verticalLayout_4->addWidget(label_12);

        faculty = new QLineEdit(layoutWidget4);
        faculty->setObjectName("faculty");
        faculty->setFont(font4);
        faculty->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_4->addWidget(faculty);

        label_14 = new QLabel(layoutWidget4);
        label_14->setObjectName("label_14");
        label_14->setFont(font);

        verticalLayout_4->addWidget(label_14);

        speciality = new QLineEdit(layoutWidget4);
        speciality->setObjectName("speciality");
        speciality->setFont(font4);
        speciality->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_4->addWidget(speciality);

        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName("label_13");
        label_13->setFont(font);

        verticalLayout_4->addWidget(label_13);

        degree = new QLineEdit(layoutWidget4);
        degree->setObjectName("degree");
        degree->setFont(font4);
        degree->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));

        verticalLayout_4->addWidget(degree);


        verticalLayout_6->addLayout(verticalLayout_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_15 = new QLabel(layoutWidget4);
        label_15->setObjectName("label_15");
        label_15->setFont(font);

        horizontalLayout_12->addWidget(label_15);

        admissionSpinBox = new QSpinBox(layoutWidget4);
        admissionSpinBox->setObjectName("admissionSpinBox");
        admissionSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        admissionSpinBox->setMinimum(1950);
        admissionSpinBox->setMaximum(2024);

        horizontalLayout_12->addWidget(admissionSpinBox);

        label_16 = new QLabel(layoutWidget4);
        label_16->setObjectName("label_16");
        label_16->setFont(font);

        horizontalLayout_12->addWidget(label_16);

        graduationSpinBox = new QSpinBox(layoutWidget4);
        graduationSpinBox->setObjectName("graduationSpinBox");
        graduationSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        graduationSpinBox->setMinimum(1954);
        graduationSpinBox->setMaximum(2050);

        horizontalLayout_12->addWidget(graduationSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_12);


        horizontalLayout_2->addWidget(frame);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Settings", nullptr));
        student_cbox->setText(QCoreApplication::translate("Settings", "Still learning", nullptr));
        label_19->setText(QCoreApplication::translate("Settings", "Interests", nullptr));
        pushButton->setText(QCoreApplication::translate("Settings", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Settings", "Save", nullptr));
        label_9->setText(QCoreApplication::translate("Settings", "Education", nullptr));
        sec_ed_cbox->setText(QCoreApplication::translate("Settings", "Secondary education", nullptr));
        higher_ed_cbox->setText(QCoreApplication::translate("Settings", "Higher education", nullptr));
        label_2->setText(QCoreApplication::translate("Settings", "Settings", nullptr));
        label_10->setText(QCoreApplication::translate("Settings", "Personal information", nullptr));
        label_3->setText(QCoreApplication::translate("Settings", "Surname", nullptr));
        label_4->setText(QCoreApplication::translate("Settings", "Name", nullptr));
        label_5->setText(QCoreApplication::translate("Settings", "Father name", nullptr));
        label_7->setText(QCoreApplication::translate("Settings", "Age", nullptr));
        label_8->setText(QCoreApplication::translate("Settings", "Gender", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("Settings", "male", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("Settings", "female", nullptr));

        label_11->setText(QCoreApplication::translate("Settings", "University", nullptr));
        label_12->setText(QCoreApplication::translate("Settings", "Faculty", nullptr));
        faculty->setText(QString());
        label_14->setText(QCoreApplication::translate("Settings", "Speciality", nullptr));
        label_13->setText(QCoreApplication::translate("Settings", "Degree", nullptr));
        label_15->setText(QCoreApplication::translate("Settings", "Year of admission", nullptr));
        label_16->setText(QCoreApplication::translate("Settings", "Year of graduation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
