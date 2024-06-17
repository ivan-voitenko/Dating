#ifndef VIEWRANDUSER_H
#define VIEWRANDUSER_H

#include <QDialog>
#include "RandomUser.h"

namespace Ui {
class ViewRandUser;
}

class ViewRandUser : public QDialog
{
    Q_OBJECT

public:
    explicit ViewRandUser(QWidget *parent = nullptr);
    ~ViewRandUser();

    void set_user(RandomUser* user_, const QString& photo_path);

signals:
    void back_button_clicked();

private slots:
    void on_back_button_clicked();

private:
    Ui::ViewRandUser *ui;
    RandomUser* rand_user;
};

#endif // VIEWRANDUSER_H
