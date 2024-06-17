#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "User.h"
#include "LoginData.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

    const QString& getEmail() const;
    const QString& getPassword() const;
    const QString& getSurname() const;
    const QString& getName() const;
    const QString& getLastname() const;
    const QString& getUniversity() const;
    const QString& getDegree() const;
    const QString& getSpeciality() const;
    const QString& getFaculty() const;
    const QString& getGender() const;

    int getAge() const;
    int getAdmission() const;
    int getGraduation() const;
    int getSecondaryEd() const;
    int getHigherEd() const;
    int getStillLearning() const;

    void set_default();

signals:
    void register_button_clicked2();

private slots:
    void on_checkBox_3_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_email_textEdited(const QString &arg1);
    void on_password_textEdited(const QString &arg1);
    void on_checkBox_2_stateChanged(int arg1);
    void on_surname_textEdited(const QString &arg1);
    void on_name_textEdited(const QString &arg1);
    void on_last_name_textEdited(const QString &arg1);
    void on_ageSpinBox_valueChanged(int arg1);
    void on_genderComboBox_currentTextChanged(const QString &arg1);
    void on_checkBox_stateChanged(int arg1);
    void on_university_textEdited(const QString &arg1);
    void on_faculty_textEdited(const QString &arg1);
    void on_speciality_textEdited(const QString &arg1);
    void on_degree_textEdited(const QString &arg1);
    void on_admissionSpinBox_valueChanged(int arg1);
    void on_graduationSpinBox_valueChanged(int arg1);

private:
    Ui::SignUp *ui;

    User* user;
    LoginData* login_data;
};

#endif // SIGNUP_H
