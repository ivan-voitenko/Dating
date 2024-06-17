#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include "LoginData.h"

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

    const QString& getEmail() const;
    const QString& getPassword() const;

signals:
    void login_button_clicked();
    void register_button_clicked();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_email_textEdited(const QString &arg1);
    void on_password_textEdited(const QString &arg1);

private:
    Ui::SignIn *ui;

    LoginData* login_data;
};

#endif // SIGNIN_H
