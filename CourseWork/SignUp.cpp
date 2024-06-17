#include "SignUp.h"
#include "ui_SignUp.h"

SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->ui->university->setEnabled(false);
    this->ui->degree->setEnabled(false);
    this->ui->faculty->setEnabled(false);
    this->ui->speciality->setEnabled(false);
    this->ui->checkBox_3->setEnabled(false);
    this->ui->admissionSpinBox->setEnabled(false);
    this->ui->graduationSpinBox->setEnabled(false);

    user = new User;
    login_data = new LoginData;

    user->set_gender("male");
    user->set_getting_higher_ed(false);
    user->set_secondary_ed(false);
    user->set_higher_ed(false);
    user->set_admission(1950);
    user->set_graduation(1950);
    user->set_age(16);
}

SignUp::~SignUp()
{
    delete ui;
    delete user;
    delete login_data;
}

void SignUp::set_default()
{
    ui->email->clear();
    ui->password->clear();
    ui->university->clear();
    ui->degree->clear();
    ui->faculty->clear();
    ui->speciality->clear();
    ui->surname->clear();
    ui->name->clear();
    ui->last_name->clear();
    ui->ageSpinBox->setValue(ui->ageSpinBox->minimum());
    ui->admissionSpinBox->setValue(ui->admissionSpinBox->minimum());
    ui->graduationSpinBox->setValue(ui->graduationSpinBox->minimum());
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
    ui->university->setEnabled(false);
    ui->degree->setEnabled(false);
    ui->faculty->setEnabled(false);
    ui->speciality->setEnabled(false);
    ui->checkBox_3->setEnabled(false);
    ui->admissionSpinBox->setEnabled(false);
    ui->graduationSpinBox->setEnabled(false);
}

const QString& SignUp::getEmail() const
{
    return login_data->get_email();
}

const QString& SignUp::getPassword() const
{
    return login_data->get_password();
}

const QString& SignUp::getSurname() const
{
    return user->surname();
}

const QString& SignUp::getName() const
{
    return user->name();
}

const QString& SignUp::getLastname() const
{
    return user->lastname();
}

const QString& SignUp::getUniversity() const
{
    return user->university();
}

const QString& SignUp::getDegree() const
{
    return user->degree();
}

const QString& SignUp::getSpeciality() const
{
    return user->speciality();
}

const QString& SignUp::getFaculty() const
{
    return user->faculty();
}

const QString& SignUp::getGender() const
{
    return user->gender();
}

int SignUp::getAge() const
{
    return user->age();
}

int SignUp::getAdmission() const
{
    return user->year_of_admission();
}

int SignUp::getGraduation() const
{
    return user->year_of_graduation();
}

int SignUp::getSecondaryEd() const
{
    return user->secondary_education();
}

int SignUp::getHigherEd() const
{
    return user->higher_education();
}

int SignUp::getStillLearning() const
{
    return user->is_getting_higher_ed();
}

void SignUp::on_checkBox_3_stateChanged(int arg1)
{
    user->set_getting_higher_ed(arg1 == Qt::Checked ? true : false);
    if (arg1 == Qt::Checked)
    {
        this->ui->graduationSpinBox->setEnabled(false);
    }
    else
    {
        this->ui->graduationSpinBox->setEnabled(true);
    }
}

void SignUp::on_email_textEdited(const QString &arg1)
{
    login_data->set_email(arg1);
}

void SignUp::on_password_textEdited(const QString &arg1)
{
    login_data->set_password(arg1);
}

void SignUp::on_pushButton_clicked()
{
    emit register_button_clicked2();
}

void SignUp::on_checkBox_2_stateChanged(int arg1)
{
    user->set_higher_ed(arg1 == Qt::Checked ? true : false);
    if (arg1 == Qt::Unchecked)
    {
        this->ui->university->setEnabled(false);
        this->ui->degree->setEnabled(false);
        this->ui->faculty->setEnabled(false);
        this->ui->speciality->setEnabled(false);
        this->ui->checkBox_3->setEnabled(false);
        this->ui->admissionSpinBox->setEnabled(false);
        this->ui->graduationSpinBox->setEnabled(false);
    }
    else
    {
        this->ui->university->setEnabled(true);
        this->ui->degree->setEnabled(true);
        this->ui->faculty->setEnabled(true);
        this->ui->speciality->setEnabled(true);
        this->ui->checkBox_3->setEnabled(true);
        this->ui->admissionSpinBox->setEnabled(true);
        this->ui->graduationSpinBox->setEnabled(true);
        this->ui->checkBox_3->setCheckState(Qt::Unchecked);
    }
}


void SignUp::on_surname_textEdited(const QString &arg1)
{
    user->set_surname(arg1);
}


void SignUp::on_name_textEdited(const QString &arg1)
{
   user->set_name(arg1);
}


void SignUp::on_last_name_textEdited(const QString &arg1)
{
    user->set_lastname(arg1);
}


void SignUp::on_ageSpinBox_valueChanged(int arg1)
{
    user->set_age(arg1);
}


void SignUp::on_genderComboBox_currentTextChanged(const QString &arg1)
{
    user->set_gender(arg1);
}

void SignUp::on_checkBox_stateChanged(int arg1)
{
    user->set_secondary_ed(arg1 == Qt::Checked ? true : false);
}


void SignUp::on_university_textEdited(const QString &arg1)
{
    user->set_university(arg1);
}


void SignUp::on_faculty_textEdited(const QString &arg1)
{
    user->set_faculty(arg1);
}


void SignUp::on_speciality_textEdited(const QString &arg1)
{
    user->set_speciality(arg1);
}


void SignUp::on_degree_textEdited(const QString &arg1)
{
    user->set_degree(arg1);
}


void SignUp::on_admissionSpinBox_valueChanged(int arg1)
{
    user->set_admission(arg1);
}


void SignUp::on_graduationSpinBox_valueChanged(int arg1)
{
    user->set_graduation(arg1);
}

