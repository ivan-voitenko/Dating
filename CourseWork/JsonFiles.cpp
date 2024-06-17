#include "JsonFiles.h"

JsonFiles::JsonFiles(const JsonFiles& other) : file_names(other.file_names) {}

QJsonObject JsonFiles::get_object_from_file(const QString& fileName, const QString& email) const
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen())
    {
        return QJsonObject();
    }
    QByteArray fileData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    file.close();

    QJsonArray arr = jsonDoc.array();

    for (const QJsonValue &value : arr)
    {
        QJsonObject obj = value.toObject();
        if (obj["email"].toString() == email)
        {
            return obj;
        }
    }
    return QJsonObject();
}

QJsonArray JsonFiles::read_data_from_json(const QString& fileName) const
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        return QJsonArray();
    }
    QByteArray fileData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    QJsonArray arr = jsonDoc.array();
    file.close();
    return arr;
}

void JsonFiles::write_arr_to_file(const QString& fileName, const QJsonArray& arr) const
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QJsonDocument result(arr);
    file.write(result.toJson());
    file.close();
}

void JsonFiles::write_sign_in_info(const QString& email, const QString& password)
{
    QJsonArray arr = read_data_from_json(file_names.get_login_info());
    QJsonObject new_user;
    new_user.insert("email", email);
    new_user.insert("password", password);
    arr.append(new_user);

    write_arr_to_file(file_names.get_login_info(), arr);
}

void JsonFiles::change_user_info(QJsonObject& obj, const QString& surname, const QString& name,
                      const QString& lastname, const QString& gender, int age,
                      const QString& sec_ed, const QString& hig_ed, const QString& is_student,
                      const QString& university, const QString& faculty, const QString& speciality,
                      const QString& degree, const QString& admission, const QString& graduation) const
{
    obj["surname"] = surname;
    obj["name"] = name;
    obj["lastname"] =lastname;
    obj["gender"] = gender;
    obj["age"] = age;
    obj["secondary_education"] = sec_ed;
    obj["higher_education"] = hig_ed;
    obj["still_learning"] = is_student;
    obj["university"] = university;
    obj["faculty"] = faculty;
    obj["speciality"] = speciality;
    obj["degree"] = degree;
    obj["admission"] = admission;
    obj["graduation"] = graduation;
}

void JsonFiles::write_user_info(const QString& email, const QString& surname, const QString& name,
                                const QString& lastname, const QString& gender, int age,
                                const QString& sec_ed, const QString& hig_ed, const QString& is_student,
                                const QString& university, const QString& faculty, const QString& speciality,
                                const QString& degree, const QString& admission, const QString& graduation) const
{
    QJsonArray arr = read_data_from_json(file_names.get_user_info());
    QJsonObject info;
    info.insert("email", email);
    info.insert("surname", surname);
    info.insert("name", name);
    info.insert("lastname", lastname);
    info.insert("gender", gender);
    info.insert("age", age);
    info.insert("secondary_education", sec_ed);
    info.insert("higher_education", hig_ed);
    info.insert("still_learning", is_student);
    info.insert("university", university);
    info.insert("faculty", faculty);
    info.insert("speciality", speciality);
    info.insert("degree", degree);
    info.insert("admission", admission);
    info.insert("graduation", graduation);
    arr.append(info);

    write_arr_to_file(file_names.get_user_info(), arr);
}

void JsonFiles::write_user_interests(const QString& email, const QString& interests) const
{
    QJsonArray arr = read_data_from_json(file_names.get_user_interests());
    QJsonObject obj;
    obj.insert("email", email);
    obj.insert("interests", interests);
    arr.append(obj);
    write_arr_to_file(file_names.get_user_interests(), arr);
}

void JsonFiles::write_obj_to_file(const QString& fileName, const QJsonObject& obj) const
{
    QJsonArray arr = read_data_from_json(fileName);
    int size = arr.size();

    for (int i = 0; i < size; ++i)
    {
        QJsonObject o = arr[i].toObject();
        if (o["email"].toString() == obj["email"].toString())
        {
            arr.removeAt(i);
            break;
        }
    }
    arr.append(obj);

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QJsonDocument result(arr);
    file.write(result.toJson());
    file.close();
}

bool JsonFiles::check_sign_in_info(const QString& email, const QString& password) const
{
    QJsonObject obj = get_object_from_file(file_names.get_login_info(), email);
    if (obj.size() == 0) return false;

    if (obj["password"].toString() == password)
    {
        return true;
    }

    return false;
}

const QString JsonFiles::get_settings_icon() const
{
    return file_names.get_settings_icon();
}

const QString JsonFiles::get_import_image() const
{
    return file_names.get_import_image();
}

const QString JsonFiles::get_favourites_icon() const
{
    return file_names.get_favourites_icon();
}

const QString JsonFiles::get_login_info() const
{
    return file_names.get_login_info();
}

const QString JsonFiles::get_user_info() const
{
    return file_names.get_user_info();
}

const QString JsonFiles::get_images() const
{
    return file_names.get_images_info();
}

const QString JsonFiles::get_fav_info() const
{
    return file_names.get_fav_info();
}

const QString JsonFiles::get_user_interests() const
{
    return file_names.get_user_interests();
}
