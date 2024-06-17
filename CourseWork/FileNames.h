#ifndef FILENAMES_H
#define FILENAMES_H

#include <QString>
#include <QDir>
#include <QStandardPaths>

class FileNames
{
private:
    const QString settings_icon_file_name = ":/img/build/Desktop_Qt_6_7_1_MSVC2019_64bit-Release/img/settings_icon.png";
    const QString favourites_icon_file_name = ":/img/build/Desktop_Qt_6_7_1_MSVC2019_64bit-Release/img/heart_icon.png";
    const QString import_photo_file_name = ":/img/build/Desktop_Qt_6_7_1_MSVC2019_64bit-Release/img/import_image.png";
    const QString login_info_file_name = "login_information.json";
    const QString user_info_file_name = "user_information.json";
    const QString images_file_name = "images.json";
    const QString fav_info_file_name = "user_favourites.json";
    const QString user_interests_file_name = "user_interests.json";
    QDir dir;

public:

    FileNames()
    {
        QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/Dating";
        dir.setPath(appDataPath);
        if (!dir.exists())
        {
            dir.mkpath(appDataPath);
        }
    }

    FileNames(const FileNames& other) : settings_icon_file_name(other.settings_icon_file_name), favourites_icon_file_name(other.favourites_icon_file_name),
        import_photo_file_name(other.import_photo_file_name), login_info_file_name(other.login_info_file_name), user_interests_file_name(other.user_interests_file_name),
        user_info_file_name(other.user_info_file_name), images_file_name(other.images_file_name), fav_info_file_name(other.fav_info_file_name)
    {
        dir = other.dir;
    }

    ~FileNames() noexcept = default;

    FileNames operator=(const FileNames&) = delete;

    const QString get_appData_path(const QString& fileName) const
    {
        return dir.filePath(fileName);
    }

    const QString get_settings_icon() const
    {
        return get_appData_path(settings_icon_file_name);
    }

    const QString get_favourites_icon() const
    {
        return get_appData_path(favourites_icon_file_name);
    }

    const QString get_import_image() const
    {
        return get_appData_path(import_photo_file_name);
    }

    const QString get_login_info() const
    {
        return get_appData_path(login_info_file_name);
    }

    const QString get_user_info() const
    {
        return get_appData_path(user_info_file_name);
    }

    const QString get_images_info() const
    {
        return get_appData_path(images_file_name);
    }

    const QString get_fav_info() const
    {
        return get_appData_path(fav_info_file_name);
    }

    const QString get_user_interests() const
    {
        return get_appData_path(user_interests_file_name);
    }
};

#endif // FILENAMES_H
