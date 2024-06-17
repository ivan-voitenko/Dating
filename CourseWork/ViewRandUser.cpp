#include "ViewRandUser.h"
#include "ui_ViewRandUser.h"

ViewRandUser::ViewRandUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewRandUser)
{
    ui->setupUi(this);
}

ViewRandUser::~ViewRandUser()
{
    delete ui;
}

void ViewRandUser::set_user(RandomUser* user_, const QString& photo_path)
{
    this->show();

    rand_user = user_;

    ui->label->setText(rand_user->surname() + " " + rand_user->name() + " " + rand_user->lastname());

    QPixmap random_photo(photo_path);
    random_photo = random_photo.scaled(ui->user_photo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->user_photo->setPixmap(random_photo);

    QString str;
    str += "Age: " + QString::number(rand_user->age()) + "\n";

    str += "Secondary education: " + (rand_user->secondary_education() ? QString("yes") : QString("no")) + "\n";
    str += "Higher education: " + (rand_user->higher_education() ? QString("yes") : QString("no")) + "\n";
    str += "Student: " + (rand_user->is_getting_higher_ed() ? QString("yes") : QString("no")) + "\n";

    if (rand_user->higher_education())
    {
        str += "University: " + rand_user->university() + "\n";
        str += "Faculty: " + rand_user->faculty() + "\n";
        str += "Speciality: " + rand_user->speciality() + "\n";
        str += "Degree: " + rand_user->degree() + "\n";
        str += "Admission: " + QString::number(rand_user->year_of_admission()) + "\n";
        if (rand_user->is_getting_higher_ed())
        {
            str += "Still studying\n";
        }
        else
        {
            str += "Graduation: " + QString::number(rand_user->year_of_graduation()) + "\n";
        }
    }

    auto interests = rand_user->get_interests();
    str += "Interests:\n";
    for (int j = 0; j < interests.size(); ++j)
    {
        str += QString(interests[j]);
        if (j != interests.size() - 1)
        {
            str += ", ";
        }
    }

    ui->about->setText(str);
}

void ViewRandUser::on_back_button_clicked()
{
    emit back_button_clicked();
}
