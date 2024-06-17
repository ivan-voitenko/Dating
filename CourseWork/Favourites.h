#ifndef FAVOURITES_H
#define FAVOURITES_H

#include <QDialog>
#include "JsonFiles.h"

namespace Ui
{
class Favourites;
}

class Favourites : public QDialog
{
    Q_OBJECT

public:
    explicit Favourites(QWidget *parent = nullptr);
    ~Favourites();

    void show_users(const QString& email);

private slots:
    void on_pushButton_clicked();
    void on_del_favourites_clicked();

private:
    Ui::Favourites *ui;

    JsonFiles json;

    QString user_email;
};

#endif // FAVOURITES_H
