#ifndef LOGINDATA_H
#define LOGINDATA_H

#include <QString>

class LoginData
{
private:
    QString email;
    QString password;

public:
    LoginData();
    LoginData(const QString& email_, const QString& password_);
    LoginData(const LoginData& other);
    ~LoginData() noexcept = default;

    LoginData& operator=(const LoginData& other);

    void set_email(const QString& email_);
    void set_password(const QString& password_);

    const QString& get_email() const;
    const QString& get_password() const;
};

#endif // LOGINDATA_H
