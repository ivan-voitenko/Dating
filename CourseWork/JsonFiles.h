#ifndef JSONFILES_H
#define JSONFILES_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include "FileNames.h"

class JsonFiles
{
private:
    FileNames file_names;

    QJsonArray read_data_from_json(const QString& fileName) const;
    void add_rand_user_to_jsonobj(QJsonObject& obj);
    void write_arr_to_file(const QString& fileName, const QJsonArray& arr) const;

public:
    JsonFiles() = default;
    JsonFiles(const JsonFiles& other);
    ~JsonFiles() noexcept = default;

    JsonFiles& operator=(const JsonFiles&) = delete;

    QJsonObject get_object_from_file(const QString& fileName, const QString& email) const;
    bool check_sign_in_info(const QString& email, const QString& password) const;

    void change_user_info(QJsonObject& obj, const QString& surname, const QString& name,
                          const QString& lastname, const QString& gender, int age,
                          const QString& sec_ed, const QString& hig_ed, const QString& is_student,
                          const QString& university, const QString& faculty, const QString& speciality,
                          const QString& degree, const QString& admission, const QString& graduation) const;

    void write_sign_in_info(const QString& email, const QString& password);
    void write_user_info(const QString& email, const QString& surname, const QString& name,
                         const QString& lastname, const QString& gender, int age,
                         const QString& sec_ed, const QString& hig_ed, const QString& is_student,
                         const QString& university, const QString& faculty, const QString& speciality,
                         const QString& degree, const QString& admission, const QString& graduation) const;
    void write_user_interests(const QString& email, const QString& interests) const;
    void write_obj_to_file(const QString& fileName, const QJsonObject& obj) const;

    const QString get_settings_icon() const;
    const QString get_import_image() const;
    const QString get_favourites_icon() const;

    const QString get_login_info() const;
    const QString get_user_info() const;
    const QString get_images() const;
    const QString get_fav_info() const;
    const QString get_user_interests() const;
};

#endif // JSONFILES_H
