#include "LoginData.h"

LoginData::LoginData() : email(), password() {}

LoginData::LoginData(const QString& email_, const QString& password_) : email(email_), password(password_) {}

LoginData::LoginData(const LoginData& other) : email(other.email), password(other.password) {}


LoginData& LoginData::operator=(const LoginData& other)
{
    if (this != &other)
    {
        email = other.email;
        password = other.password;
    }
    return *this;
}


void LoginData::set_email(const QString& email_)
{
    email = email_;
}

void LoginData::set_password(const QString& password_)
{
    password = password_;
}


const QString& LoginData::get_email() const
{
    return email;
}

const QString& LoginData::get_password() const
{
    return password;
}
