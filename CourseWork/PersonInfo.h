#ifndef PERSONINFO_H
#define PERSONINFO_H

#include <QString>

class PersonInfo
{
private:
    QString surname;
    QString name;
    QString lastname;
    int age;
    QString gender;

public:
    PersonInfo();
    PersonInfo(const QString& surname, const QString& name, const QString& lastname,
               int age, const QString& gender);
    PersonInfo(const PersonInfo& other);
    ~PersonInfo() noexcept = default;

    PersonInfo& operator=(const PersonInfo& other);

    const QString& get_surname() const;
    const QString& get_name() const;
    const QString& get_lastname() const;
    int get_age() const;
    const QString& get_gender() const;


    void set_surname(const QString& surname);
    void set_name(const QString& name);
    void set_lastname(const QString& lastname);
    void set_age(int age);
    void set_gender(const QString& gender);
};

#endif // PERSONINFO_H
