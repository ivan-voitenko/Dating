#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SignIn.h"
#include "SignUp.h"
#include "PersonInterests.h"
#include "TypeRelationship.h"
#include "ViewRandUser.h"
#include "JsonFiles.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void display();

private:
    Ui::MainWindow *ui;

    SignIn sign_in;
    SignUp sign_up;
    ViewRandUser view_rand_user;

    LoginData* login_data;
    User* user;

    RandomUser* random_users;
    QList<QString> rand_photos;

    PersonInterests* user_interests;
    TypeRelationship* user_type_relationship;

    int select_view;
    int favourites_view;
    bool login_successfull;

    User* create_user(const QString& surname, const QString& name, const QString& lastname,
                    int age, const QString& gender, bool secodary_ed, bool higher_ed, bool still_learning,
                    const QString& university, const QString& faculty, const QString& speciality, const QString& degree,
                    int admission, int graduation);
    void add_rand_user_to_jsonobj(QJsonObject& obj) const;

    JsonFiles json;

signals:
    void view_button_clicked();
    void fav_button_clicked();

private slots:
    void SignInUser();
    void SignUpWindowShow();
    void SignUpUser();
    void BackBtnClicked();
    void ViewBtnClicked();
    void FavBtnClicked();

    void on_import_btn_clicked();
    void on_search_btn_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_setting_toolbtn_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_favourites_toolbtn_clicked();
};
#endif // MAINWINDOW_H
