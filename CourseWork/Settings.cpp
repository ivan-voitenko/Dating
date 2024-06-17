#include "Settings.h"
#include "ui_Settings.h"
#include <QMessageBox>
#include <QStandardPaths>

Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);

    ui->higher_ed_cbox->setCheckState(Qt::Unchecked);
    ui->university->setEnabled(false);
    ui->faculty->setEnabled(false);
    ui->speciality->setEnabled(false);
    ui->degree->setEnabled(false);
    ui->admissionSpinBox->setEnabled(false);
    ui->graduationSpinBox->setEnabled(false);
    ui->student_cbox->setCheckState(Qt::Unchecked);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::setUser(User* user_)
{
    user = user_;
}

void Settings::setLogin(LoginData* login_)
{
    login_info = login_;
}

void Settings::showInfo()
{
    ui->surname->setText(user->surname());
    ui->name->setText(user->name());
    ui->last_name->setText(user->lastname());
    ui->ageSpinBox->setValue(user->age());
    ui->genderComboBox->setCurrentText(user->gender());
    ui->sec_ed_cbox->setCheckState(user->secondary_education() ? Qt::Checked : Qt::Unchecked);
    ui->higher_ed_cbox->setCheckState(user->higher_education() ? Qt::Checked : Qt::Unchecked);
    ui->student_cbox->setCheckState(user->is_getting_higher_ed() ? Qt::Checked : Qt::Unchecked);
    if (user->is_getting_higher_ed())
    {
        ui->university->setText(user->university());
        ui->faculty->setText(user->faculty());
        ui->speciality->setText(user->speciality());
        ui->degree->setText(user->degree());
        ui->admissionSpinBox->setValue(user->year_of_admission());
        ui->graduationSpinBox->setValue(user->year_of_graduation());
    }

    QJsonObject obj = json.get_object_from_file(json.get_user_interests(), login_info->get_email());
    if (obj.empty()) return;
    ui->interests_edit->setText(obj["interests"].toString());
}

void Settings::on_higher_ed_cbox_stateChanged(int arg1)
{
    if (arg1 == Qt::Unchecked)
    {
        user->set_higher_ed(false);
        user->set_getting_higher_ed(false);
        ui->university->setEnabled(false);
        ui->faculty->setEnabled(false);
        ui->speciality->setEnabled(false);
        ui->degree->setEnabled(false);
        ui->admissionSpinBox->setEnabled(false);
        ui->graduationSpinBox->setEnabled(false);
        ui->student_cbox->setCheckState(Qt::Unchecked);
        ui->student_cbox->setEnabled(false);
    }
    else
    {
        user->set_higher_ed(true);
        ui->university->setEnabled(true);
        ui->faculty->setEnabled(true);
        ui->speciality->setEnabled(true);
        ui->degree->setEnabled(true);
        ui->admissionSpinBox->setEnabled(true);
        ui->graduationSpinBox->setEnabled(true);
        ui->student_cbox->setEnabled(true);
    }
}


void Settings::on_student_cbox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        user->set_getting_higher_ed(true);
        ui->graduationSpinBox->setEnabled(false);
    }
    else
    {
        user->set_getting_higher_ed(false);
        ui->graduationSpinBox->setEnabled(true);
    }
}

void Settings::on_pushButton_clicked()
{
    this->destroy();
}

void Settings::write_interests()
{
    QJsonObject obj = json.get_object_from_file(json.get_user_interests(), login_info->get_email());
    if (obj.empty())
    {
        json.write_user_interests(login_info->get_email(), ui->interests_edit->toPlainText());
        return;
    }

    obj["interests"] = ui->interests_edit->toPlainText();
    json.write_obj_to_file(json.get_user_interests(), obj);
}

void Settings::write_user()
{
    QJsonObject obj = json.get_object_from_file(json.get_user_info(), login_info->get_email());
    if (obj.empty()) return;
    json.change_user_info(obj, user->surname(), user->name(), user->lastname(), user->gender(), user->age(),
                        user->secondary_education() ? "yes" : "no", user->higher_education() ? "yes" : "no",
                        user->higher_education() ? (user->is_getting_higher_ed() ? "yes" : "no") : "no",  user->higher_education() ? user->university() : "-",
                        user->higher_education() ? user->faculty() : "-", user->higher_education() ? user->speciality() : "-",
                        user->higher_education() ? user->degree() : "-", user->higher_education() ? QString(std::to_string(user->year_of_admission()).c_str()) : "-",
                        user->higher_education() ? QString(std::to_string(user->year_of_graduation()).c_str()) : "-");
    json.write_obj_to_file(json.get_user_info(), obj);
}

void Settings::on_pushButton_2_clicked()
{
    write_interests();
    write_user();
    QMessageBox::information(this, "Success", "Your information were modified successfully!", QMessageBox::Ok);
    this->destroy();
}

void Settings::on_surname_textEdited(const QString &arg1)
{
    user->set_surname(arg1);
}


void Settings::on_name_textEdited(const QString &arg1)
{
    user->set_name(arg1);
}


void Settings::on_last_name_textEdited(const QString &arg1)
{
    user->set_lastname(arg1);
}


void Settings::on_ageSpinBox_valueChanged(int arg1)
{
    user->set_age(arg1);
}


void Settings::on_genderComboBox_currentTextChanged(const QString &arg1)
{
    user->set_gender(arg1);
}


void Settings::on_sec_ed_cbox_stateChanged(int arg1)
{
    user->set_secondary_ed(arg1 == Qt::Checked ? true : false);
}


void Settings::on_university_textEdited(const QString &arg1)
{
    user->set_university(arg1);
}


void Settings::on_faculty_textEdited(const QString &arg1)
{
    user->set_faculty(arg1);
}


void Settings::on_speciality_textEdited(const QString &arg1)
{
    user->set_speciality(arg1);
}


void Settings::on_degree_textEdited(const QString &arg1)
{
    user->set_degree(arg1);
}


void Settings::on_admissionSpinBox_valueChanged(int arg1)
{
    user->set_admission(arg1);
}


void Settings::on_graduationSpinBox_valueChanged(int arg1)
{
    user->set_graduation(arg1);
}

