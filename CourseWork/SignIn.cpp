#include "SignIn.h"
#include "ui_SignIn.h"

SignIn::SignIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
    this->ui->password->setEchoMode(QLineEdit::Password);
    login_data = new LoginData;
}

SignIn::~SignIn()
{
    delete ui;
    delete login_data;
}

const QString& SignIn::getEmail() const
{
    return login_data->get_email();
}

const QString& SignIn::getPassword() const
{
    return login_data->get_password();
}

void SignIn::on_pushButton_clicked()
{
    emit login_button_clicked();
}

void SignIn::on_pushButton_2_clicked()
{
    emit register_button_clicked();
}

void SignIn::on_email_textEdited(const QString &arg1)
{
    login_data->set_email(arg1);
}


void SignIn::on_password_textEdited(const QString &arg1)
{
    login_data->set_password(arg1);
}

