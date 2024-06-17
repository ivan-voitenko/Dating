#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "User.h"
#include "LoginData.h"
#include "PersonInterests.h"
#include "JsonFiles.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    void setUser(User* user_);
    void setLogin(LoginData* login_);
    void showInfo();

private slots:
    void on_higher_ed_cbox_stateChanged(int arg1);
    void on_student_cbox_stateChanged(int arg1);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_surname_textEdited(const QString &arg1);
    void on_name_textEdited(const QString &arg1);
    void on_last_name_textEdited(const QString &arg1);

    void on_ageSpinBox_valueChanged(int arg1);
    void on_genderComboBox_currentTextChanged(const QString &arg1);
    void on_sec_ed_cbox_stateChanged(int arg1);

    void on_university_textEdited(const QString &arg1);
    void on_faculty_textEdited(const QString &arg1);
    void on_speciality_textEdited(const QString &arg1);
    void on_degree_textEdited(const QString &arg1);

    void on_admissionSpinBox_valueChanged(int arg1);
    void on_graduationSpinBox_valueChanged(int arg1);

private:
    Ui::Settings *ui;

    User* user;
    LoginData* login_info;
    PersonInterests* interests;

    JsonFiles json;

    void write_interests();
    void write_user();
};

#endif // SETTINGS_H
