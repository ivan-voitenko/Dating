#ifndef USER_H
#define USER_H

#include "PersonInfo.h"
#include "PersonEducation.h"

class User
{
protected:
    PersonInfo* info;
    PersonEducation* education;

public:
    User();
    User(PersonInfo* info_, PersonEducation* education_);
    User(const User& other);
    ~User() noexcept;

    User& operator=(const User& other);

    const QString& surname() const;
    const QString& name() const;
    const QString& lastname() const;
    int age() const;
    const QString& gender() const;

    bool secondary_education() const;
    bool higher_education() const;
    bool is_getting_higher_ed() const;

    const QString& university() const;
    const QString& degree() const;
    const QString& speciality() const;
    const QString& faculty() const;
    int year_of_admission() const;
    int year_of_graduation() const;

    void set_surname(const QString& surname);
    void set_name(const QString& name);
    void set_lastname(const QString& lastname);
    void set_age(int age);
    void set_gender(const QString& gender);

    void set_secondary_ed(bool secondary_ed);
    void set_higher_ed(bool higher_ed);
    void set_getting_higher_ed(bool getting_higher_ed);

    void set_university(const QString& university);
    void set_degree(const QString& degree);
    void set_speciality(const QString& speciality);
    void set_faculty(const QString& faculty);

    void set_admission(int year_of_admission);
    void set_graduation(int year_of_graduation);
};

#endif // USER_H
