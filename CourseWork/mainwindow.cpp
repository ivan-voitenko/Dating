#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QLayout>
#include <QTextBrowser>
#include <QIcon>
#include "Settings.h"
#include "Favourites.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), login_data(nullptr), user(nullptr),
    random_users(nullptr), user_interests(nullptr), user_type_relationship(nullptr)
{
    connect(&sign_in, SIGNAL(login_button_clicked()),
            this, SLOT(SignInUser()));
    connect(&sign_in, SIGNAL(destroyed()),
            this, SLOT(show()));
    connect(&sign_in, SIGNAL(register_button_clicked()),
            this, SLOT(SignUpWindowShow()));
    connect(&sign_up, SIGNAL(register_button_clicked2()),
            this, SLOT(SignUpUser()));
    connect(&sign_up, SIGNAL(finished(int)),
            &sign_in, SLOT(show()));

    connect(this, SIGNAL(view_button_clicked()),
            this, SLOT(ViewBtnClicked()));
    connect(&view_rand_user, SIGNAL(back_button_clicked()),
            this, SLOT(BackBtnClicked()));
    connect(&view_rand_user, SIGNAL(destroyed()),
            this, SLOT(show()));

    connect(this, SIGNAL(fav_button_clicked()),
            this, SLOT(FavBtnClicked()));

    ui->setupUi(this);
    login_successfull = false;
    ui->scrollArea->hide();

    ui->setting_toolbtn->setIcon(QIcon(json.get_settings_icon()));
    ui->favourites_toolbtn->setIcon(QIcon(json.get_favourites_icon()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete user;
    delete login_data;
    delete[] random_users;
    delete user_type_relationship;
}

void MainWindow::ViewBtnClicked()
{
    view_rand_user.set_user(&random_users[select_view], rand_photos[select_view]);
    this->hide();
    view_rand_user.show();
}

void MainWindow::BackBtnClicked()
{
    view_rand_user.hide();
    this->show();
}

void MainWindow::display()
{
    sign_in.show();
}

void MainWindow::SignInUser()
{
    QString userEmail(sign_in.getEmail());
    QString userPassword(sign_in.getPassword());

    if (userEmail == "" || userPassword == "")
    {
        QMessageBox::critical(this, "Error", "Email and password cannot be empty", QMessageBox::Ok);
        return;
    }
    else if (!userEmail.contains('@') || !userEmail.contains('.'))
    {
        QMessageBox::critical(this, "Error", "Email should contain @ and .", QMessageBox::Ok);
        return;
    }
    else if (!userEmail.contains("@gmail.com") && !userEmail.contains("@ukr.net") && !userEmail.contains("@outlook.com") &&
             !userEmail.contains("@yahoo.com") && !userEmail.contains("@icloud.com"))
    {
        QMessageBox::critical(this, "Error", "Email should contain one of this mails:\n"
                                             "@gmail.com, @ukr.net, @outlook.com, @yahoo.com, @icloud.com", QMessageBox::Ok);
        return;
    }

    if (!json.check_sign_in_info(userEmail, userPassword))
    {
        QMessageBox::warning(this, "Warning", "This account does not exist", QMessageBox::Ok);
        login_successfull = false;
    }
    else
    {
        delete login_data;
        login_data = new LoginData(sign_in.getEmail(), sign_in.getPassword());

        login_successfull = true;
        sign_in.close();
        sign_up.close();

        QLabel* statusLabel = new QLabel("Welcome, " + userEmail + "!");
        statusLabel->setAlignment(Qt::AlignCenter);
        QFont font = statusLabel->font();
        font.setBold(true);
        font.setPointSize(12);
        statusLabel->setFont(font);
        QWidget *centerWidget = new QWidget(this);
        QHBoxLayout *layout = new QHBoxLayout(centerWidget);
        layout->addWidget(statusLabel);
        layout->setContentsMargins(0, 0, 0, 0);
        centerWidget->setLayout(layout);
        this->ui->statusbar->addPermanentWidget(centerWidget, 1);

        QPixmap import_img(json.get_import_image());
        int w = this->ui->user_photo->width();
        int h = this->ui->user_photo->height();
        this->ui->user_photo->setPixmap(import_img.scaled(w, h, Qt::KeepAspectRatioByExpanding));
        this->ui->user_photo->setScaledContents(true);
        this->ui->user_photo->update();

        if (!user)
        {
            QJsonObject obj = json.get_object_from_file(json.get_user_info(), login_data->get_email());
            if (!obj.empty())
            {
                user = create_user(obj["surname"].toString(), obj["name"].toString(),
                                   obj["lastname"].toString(), obj["age"].toInt(), obj["gender"].toString(),
                                   obj["secondary_education"].toString() == "yes" ? true : false,
                                   obj["higher_education"].toString() == "yes" ? true : false,
                                   obj["still_learning"].toString() == "yes" ? true : false,
                                   obj["university"].toString(), obj["faculty"].toString(),
                                   obj["speciality"].toString(), obj["degree"].toString(),
                                   obj["admission"].toString().toInt(), obj["graduation"].toString().toInt());
            }
        }
        this->ui->label->setText(user->surname() + " " + user->name());

        QJsonObject obj = json.get_object_from_file(json.get_images(), login_data->get_email());
        if (!obj.empty())
        {
            QPixmap pixmap(obj["image"].toString());
            pixmap.scaled(this->ui->user_photo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            this->ui->user_photo->setPixmap(pixmap);
        }

        this->show();
    }
}

void MainWindow::SignUpWindowShow()
{
    sign_in.hide();
    sign_up.set_default();
    sign_up.show();
}

User* MainWindow::create_user(const QString& surname, const QString& name, const QString& lastname,
                  int age, const QString& gender, bool secodary_ed, bool higher_ed, bool still_learning,
                  const QString& university, const QString& faculty, const QString& speciality, const QString& degree,
                  int admission, int graduation)
{
    PersonInfo* info = new PersonInfo(surname, name, lastname, age, gender);
    UniversityInfo* un = higher_ed == true ? new UniversityInfo(university, degree, speciality, faculty, admission, graduation, still_learning) : nullptr;
    PersonEducation* education = new PersonEducation(secodary_ed, higher_ed, still_learning, un);
    return new User(info, education);
}

void MainWindow::SignUpUser()
{
    QString userEmail(sign_up.getEmail());
    QString userPassword(sign_up.getPassword());

    user = create_user(sign_up.getSurname(), sign_up.getName(), sign_up.getLastname(), sign_up.getAge(), sign_up.getGender(),
                       sign_up.getSecondaryEd(), sign_up.getHigherEd(), sign_up.getStillLearning(),
                       sign_up.getUniversity(), sign_up.getFaculty(), sign_up.getSpeciality(),
                       sign_up.getDegree(), sign_up.getAdmission(), sign_up.getGraduation());

    if (userEmail == "" || userPassword == "" || user->surname() == "" || user->name() == "" || user->lastname() == "" ||
        (user->higher_education() && (user->university() == "" || user->speciality() == "" || user->faculty() == "" || user->degree() == "")))
    {
        QMessageBox::critical(this, "Error", "Fields cannot be empty", QMessageBox::Ok);
        free(user);
        user = nullptr;
        return;
    }
    else if (!userEmail.contains('@') || !userEmail.contains('.'))
    {
        QMessageBox::critical(this, "Error", "Email should contain @ and .", QMessageBox::Ok);
        free(user);
        user = nullptr;
        return;
    }
    else if (!userEmail.contains("@gmail.com") && !userEmail.contains("@ukr.net") && !userEmail.contains("@outlook.com") &&
             !userEmail.contains("@yahoo.com") && !userEmail.contains("@icloud.com"))
    {
        QMessageBox::critical(this, "Error", "Email should contain one of this mails:\n"
                                             "@gmail.com, @ukr.net, @outlook.com, @yahoo.com, @icloud.com", QMessageBox::Ok);
        free(user);
        user = nullptr;
        return;
    }
    else if (user->higher_education() && !user->is_getting_higher_ed() && (user->year_of_graduation() - user->year_of_admission() < 4))
    {
        QMessageBox::critical(this, "Error", "Minimum studying time is 4 years", QMessageBox::Ok);
        free(user);
        user = nullptr;
        return;
    }

    if (json.check_sign_in_info(userEmail, userPassword))
    {
        QMessageBox::warning(this, "Warning", "This account already exist", QMessageBox::Ok);
        free(user);
        user = nullptr;
        return;
    }

    json.write_sign_in_info(userEmail, userPassword);

    delete login_data;
    login_data = new LoginData(sign_up.getEmail(), sign_up.getPassword());

    json.write_user_info(userEmail, user->surname(), user->name(), user->lastname(), user->gender(), user->age(),
                        user->secondary_education() ? "yes" : "no", user->higher_education() ? "yes" : "no",
                        user->higher_education() ? (user->is_getting_higher_ed() ? "yes" : "no") : "no",
                        user->higher_education() ? user->university() : "-", user->higher_education() ? user->faculty() : "-",
                        user->higher_education() ? user->speciality() : "-", user->higher_education() ? user->degree() : "-",
                        user->higher_education() ? QString(std::to_string(user->year_of_admission()).c_str()) : "-",
                        user->higher_education() ? QString(std::to_string(user->year_of_graduation()).c_str()) : "-");

    QMessageBox::information(this, "Success", "Registration completed successfully!", QMessageBox::Ok);

    sign_up.hide();
    sign_in.show();
}

void MainWindow::on_import_btn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image File", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if (!fileName.isEmpty())
    {
        QJsonObject obj = json.get_object_from_file(json.get_images(), login_data->get_email());
        if (!obj.empty())
        {
            obj["image"] = fileName;
            json.write_obj_to_file(json.get_images(), obj);
        }
        else
        {
            obj.insert("email", login_data->get_email());
            obj.insert("image", fileName);
            json.write_obj_to_file(json.get_images(), obj);
        }
    }
    QPixmap pixmap(fileName);
    this->ui->user_photo->setScaledContents(true);
    this->ui->user_photo->setPixmap(pixmap);
}

void MainWindow::on_search_btn_clicked()
{
    if (ui->scrollArea->isHidden())
    {
        ui->scrollArea->show();
    }

    rand_photos.clear();

    delete user_type_relationship;
    user_type_relationship = nullptr;

    delete[] random_users;
    random_users = nullptr;

    user_type_relationship = new TypeRelationship(
        ui->relationship_cbox->isChecked(),
        ui->friendship_cbox->isChecked(),
        ui->flirting_cbox->isChecked(),
        ui->companionship_cbox->isChecked(),
        ui->not_decide_cbox->isChecked()
        );

    bool secondary_ed = ui->secondary_ed_cbox->isChecked();
    bool higher_ed = ui->higher_ed_cbox->isChecked();
    bool getting_higher_ed = ui->student_cbox->isChecked();
    int min_age = ui->min_age_sbox->value();
    int max_age = ui->max_age_sbox->value();
    bool male = ui->male_cbox->isChecked();
    bool female = ui->female_cbox->isChecked();

    int size = 12;
    random_users = new RandomUser[size];

    for (int i = 0; i < size; ++i)
    {
        random_users[i].random_user(*user_type_relationship, secondary_ed, higher_ed,
                                    getting_higher_ed, min_age, max_age, male, female);
    }

    QLayout* frameLayout = ui->frame->layout();

    if (!frameLayout)
    {
        qDebug() << "Frame layout not found!";
        return;
    }

    for (int i = 0; i < frameLayout->count(); ++i)
    {
        if (i >= size) break;

        QLayoutItem* item = frameLayout->itemAt(i);
        if (!item) continue;

        QHBoxLayout* horLayout = qobject_cast<QHBoxLayout*>(item->layout());
        if (!horLayout) continue;

        QLabel* photoLabel = qobject_cast<QLabel*>(horLayout->itemAt(0)->widget());
        if (!photoLabel) continue;

        QPixmap random_photo;
        if (random_users[i].gender() == "male")
        {
            int r = rand() % 86;
            QString s = QString::number(r + 1);
            random_photo.load(QDir::currentPath() + "/randomGenerator/photos/male/" + s + ".jpg");
            rand_photos.append(QDir::currentPath() + "/randomGenerator/photos/male/" + s + ".jpg");
        }
        else
        {
            int r = rand() % 89;
            QString s = QString::number(r + 1);
            random_photo.load(QDir::currentPath() + "/randomGenerator/photos/female/" + s + ".jpg");
            rand_photos.append(QDir::currentPath() + "/randomGenerator/photos/female/" + s + ".jpg");
        }

        random_photo = random_photo.scaled(photoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        photoLabel->setPixmap(random_photo);

        QVBoxLayout* innerVerLayout = qobject_cast<QVBoxLayout*>(horLayout->itemAt(1)->layout());
        if (!innerVerLayout) continue;

        QLabel* fioLabel = qobject_cast<QLabel*>(innerVerLayout->itemAt(0)->widget());
        if (!fioLabel) continue;

        fioLabel->setText(random_users[i].surname() + " " + random_users[i].name() + " " + random_users[i].lastname());

        QTextBrowser* textBrowser = qobject_cast<QTextBrowser*>(innerVerLayout->itemAt(1)->widget());
        if (!textBrowser) continue;

        auto interests = random_users[i].get_interests();
        QString str;
        str += "Age " + QString::number(random_users[i].age()) + "\n";
        for (int j = 0; j < interests.size(); ++j)
        {
            str += QString(interests[j]);
            if (j != interests.size() - 1)
            {
                str += ", ";
            }
        }
        textBrowser->setText(str);
    }

    ui->scrollArea->update();
}

void MainWindow::add_rand_user_to_jsonobj(QJsonObject& obj) const
{
    obj.insert("surname", random_users[favourites_view].surname());
    obj.insert("name", random_users[favourites_view].name());
    obj.insert("lastname", random_users[favourites_view].lastname());
    obj.insert("gender", random_users[favourites_view].gender());
    obj.insert("age", random_users[favourites_view].age());
    obj.insert("secondary_education", random_users[favourites_view].secondary_education() ? "yes" : "no");
    obj.insert("higher_education", random_users[favourites_view].higher_education() ? "yes" : "no");
    obj.insert("still_learning", random_users[favourites_view].higher_education() ? (random_users[favourites_view].is_getting_higher_ed() ? "yes" : "no") : "no");
    obj.insert("university", random_users[favourites_view].higher_education() ? random_users[favourites_view].university() : "-");
    obj.insert("faculty", random_users[favourites_view].higher_education() ? random_users[favourites_view].faculty() : "-");
    obj.insert("speciality", random_users[favourites_view].higher_education() ? random_users[favourites_view].speciality() : "-");
    obj.insert("degree", random_users[favourites_view].higher_education() ? random_users[favourites_view].degree() : "-");
    obj.insert("admission", random_users[favourites_view].higher_education() ? QString(std::to_string(random_users[favourites_view].year_of_admission()).c_str()) : "-");
    obj.insert("graduation", random_users[favourites_view].higher_education() ? QString(std::to_string(random_users[favourites_view].year_of_graduation()).c_str()) : "-");
    obj.insert("photo", rand_photos[favourites_view]);

    auto vec = random_users[favourites_view].get_interests();
    QString str;
    for (int i = 0; i < vec.size(); ++i)
    {
        str += vec[i];
        if (i != vec.size() - 1)
        {
            str += ", ";
        }
    }
    obj.insert("interests", str);
}

void MainWindow::FavBtnClicked()
{
    QJsonObject obj = json.get_object_from_file(json.get_fav_info(), login_data->get_email());
    if (!obj.empty())
    {
        QJsonArray users = obj["users"].toArray();
        for (const QJsonValue& inner_value : users)
        {
            QJsonObject inner_obj = inner_value.toObject();
            if (inner_obj["surname"] == random_users[favourites_view].surname() &&
                inner_obj["name"] == random_users[favourites_view].name() &&
                inner_obj["lastname"] == random_users[favourites_view].lastname())
            {
                QMessageBox::warning(this, "Failed", random_users[favourites_view].surname() + " " +
                                    random_users[favourites_view].name() + " " + random_users[favourites_view].lastname() +
                                    " is already in your favourites!", QMessageBox::Ok);
                return;
            }
        }
        QJsonObject new_obj;
        add_rand_user_to_jsonobj(new_obj);
        users.append(new_obj);
        obj["users"] = users;
        json.write_obj_to_file(json.get_fav_info(), obj);
    }
    else
    {
        QJsonObject new_fav;
        new_fav.insert("email", login_data->get_email());
        QJsonArray arr;
        QJsonObject obj;
        add_rand_user_to_jsonobj(obj);
        arr.append(obj);
        new_fav.insert("users", arr);
        json.write_obj_to_file(json.get_fav_info(), new_fav);
    }

    QMessageBox::information(this, "Success", random_users[favourites_view].surname() + " " +
                            random_users[favourites_view].name() + " " + random_users[favourites_view].lastname() +
                            " were successfully added to favourites!", QMessageBox::Ok);
}

void MainWindow::on_pushButton_clicked()
{
    select_view = 0;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_2_clicked()
{
    select_view = 1;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_3_clicked()
{
    select_view = 2;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_4_clicked()
{
    select_view = 3;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_5_clicked()
{
    select_view = 4;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_6_clicked()
{
    select_view = 5;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_7_clicked()
{
    select_view = 6;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_8_clicked()
{
    select_view = 7;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_9_clicked()
{
    select_view = 8;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_10_clicked()
{
    select_view = 9;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_11_clicked()
{
    select_view = 10;
    emit view_button_clicked();
}


void MainWindow::on_pushButton_12_clicked()
{
    select_view = 11;
    emit view_button_clicked();
}


void MainWindow::on_setting_toolbtn_clicked()
{
    Settings settings;
    settings.setModal(true);
    settings.setUser(user);
    settings.setLogin(login_data);
    settings.showInfo();
    settings.exec();
}


void MainWindow::on_pushButton_13_clicked()
{
    favourites_view = 0;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_14_clicked()
{
    favourites_view = 1;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_15_clicked()
{
    favourites_view = 2;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_16_clicked()
{
    favourites_view = 3;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_17_clicked()
{
    favourites_view = 4;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_18_clicked()
{
    favourites_view = 5;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_19_clicked()
{
    favourites_view = 6;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_20_clicked()
{
    favourites_view = 7;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_21_clicked()
{
    favourites_view = 8;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_22_clicked()
{
    favourites_view = 9;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_23_clicked()
{
    favourites_view = 10;
    emit fav_button_clicked();
}


void MainWindow::on_pushButton_24_clicked()
{
    favourites_view = 11;
    emit fav_button_clicked();
}

void MainWindow::on_favourites_toolbtn_clicked()
{
    Favourites window;
    window.setModal(true);

    QJsonObject obj = json.get_object_from_file(json.get_fav_info(), login_data->get_email());

    if (obj["users"].toArray().empty())
    {
        QMessageBox::warning(this, "Warning", "You dont have any favourites users", QMessageBox::Ok);
        return;
    }

    window.show_users(login_data->get_email());
    window.exec();
}
