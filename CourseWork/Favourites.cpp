#include "Favourites.h"
#include "ui_Favourites.h"
#include <QFile>
#include <QPixMap>
#include <QTextBrowser>
#include <QMessageBox>
#include <QStandardPaths>

Favourites::Favourites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Favourites)
{
    ui->setupUi(this);
}

Favourites::~Favourites()
{
    delete ui;
}

void Favourites::on_del_favourites_clicked()
{
    QString surname, name, lastname;

    QWidget* parentWidget = nullptr;
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        parentWidget = button->parentWidget();
        if (parentWidget)
        {
            QVBoxLayout* verLayout = qobject_cast<QVBoxLayout*>(parentWidget->layout());
            if (verLayout)
            {
                QHBoxLayout* horLayout = nullptr;
                for (int i = 0; i < verLayout->count(); ++i)
                {
                    horLayout = qobject_cast<QHBoxLayout*>(verLayout->itemAt(i)->layout());
                    QVBoxLayout* innerVerLayout = qobject_cast<QVBoxLayout*>(horLayout->itemAt(1)->layout());
                    if (qobject_cast<QPushButton*>(innerVerLayout->itemAt(2)->widget()) != button)
                    {
                        continue;
                    }
                    QLabel* fioLabel = qobject_cast<QLabel*>(innerVerLayout->itemAt(0)->widget());
                    if (fioLabel)
                    {
                        QStringList fioList = fioLabel->text().split(" ");
                        if (fioList.size() >= 3)
                        {
                            surname = fioList[0];
                            name = fioList[1];
                            lastname = fioList[2];
                        }
                    }

                    delete innerVerLayout->takeAt(0)->widget();
                    delete innerVerLayout->takeAt(0)->widget();
                    delete innerVerLayout->takeAt(0)->widget();

                    QLayoutItem* item;
                    while ((item = horLayout->takeAt(0)) != nullptr)
                    {
                        delete item->widget();
                        delete item;
                    }

                    delete horLayout;
                    break;
                }
            }
        }
    }


    QJsonObject obj = json.get_object_from_file(json.get_fav_info(), user_email);
    QJsonArray users = obj["users"].toArray();
    for (int j = 0; j < users.size(); ++j)
    {
        QJsonObject user = users[j].toObject();
        if (user["surname"].toString() == surname && user["name"].toString() == name && user["lastname"].toString() == lastname)
        {
            users.removeAt(j);
            obj["users"] = users;
            if (users.empty())
            {
                delete parentWidget;
            }
            break;
        }
    }

    json.write_obj_to_file(json.get_fav_info(), obj);
}

void Favourites::show_users(const QString& email)
{
    user_email = email;
    QJsonObject obj = json.get_object_from_file(json.get_fav_info(), email);
    if (obj.empty()) return;

    QVBoxLayout* mainLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);

    QJsonArray arr = obj["users"].toArray();
    for (const QJsonValue& inner_value : arr)
    {
        QJsonObject inner_obj = inner_value.toObject();

        QLabel* photo = new QLabel;
        photo->setFixedSize(220, 224);
        QPixmap pixmap(inner_obj["photo"].toString());
        pixmap.scaled(photo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        photo->setPixmap(pixmap);
        photo->setScaledContents(true);

        QLabel* fio = new QLabel;
        fio->setText(inner_obj["surname"].toString() + " " +
                     inner_obj["name"].toString() + " " +
                     inner_obj["lastname"].toString());

        QTextBrowser* info = new QTextBrowser;
        QString str;

        str += "Age: " + QString::number(inner_obj["age"].toInt()) + "\n";

        str += "Secondary education: " + inner_obj["secondary_education"].toString() + "\n";
        str += "Higher education: " + inner_obj["higher_education"].toString() + "\n";
        str += "Student: " + inner_obj["still_learning"].toString() + "\n";

        if (inner_obj["higher_education"].toString() == "yes")
        {
            str += "University: " + inner_obj["university"].toString() + "\n";
            str += "Faculty: " + inner_obj["faculty"].toString() + "\n";
            str += "Speciality: " + inner_obj["speciality"].toString() + "\n";
            str += "Degree: " + inner_obj["degree"].toString() + "\n";
            str += "Admission: " + inner_obj["admission"].toString() + "\n";
            if (inner_obj["still_learning"].toString() == "yes")
            {
                str += "Still studying\n";
            }
            else
            {
                str += "Graduation: " + QString::number(inner_obj["graduation"].toInt()) + "\n";
            }
        }

        str += "Interests:\n" + inner_obj["interests"].toString();
        info->setText(str);

        QFont font = fio->font();
        font.setBold(true);
        font.setPointSize(13);
        fio->setFont(font);
        fio->setAlignment(Qt::AlignHCenter);
        info->setFontPointSize(10);

        QPushButton* del_btn = new QPushButton;
        del_btn->setText("Remove from favourites");
        font = del_btn->font();
        font.setPointSize(11);
        del_btn->setFont(font);
        connect(del_btn, &QPushButton::clicked, this, &Favourites::on_del_favourites_clicked);

        QVBoxLayout* verLayout = new QVBoxLayout;
        verLayout->addWidget(fio);
        verLayout->addWidget(info);
        verLayout->addWidget(del_btn);

        QHBoxLayout* horLayout = new QHBoxLayout;
        horLayout->addWidget(photo);
        horLayout->addLayout(verLayout);

        mainLayout->addLayout(horLayout);
    }

    ui->scrollAreaWidgetContents->setLayout(mainLayout);
    ui->scrollArea->setWidgetResizable(true);
}

void Favourites::on_pushButton_clicked()
{
    this->destroy();
}

