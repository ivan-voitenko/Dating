#include "PersonInfo.h"
#include <exception>

PersonInfo::PersonInfo() : surname(), name(), lastname(),
    age(0), gender() {}

PersonInfo::PersonInfo(const QString& surname, const QString& name, const QString& lastname,
                       int age, const QString& gender) : surname(surname), name(name), lastname(lastname),
    age(age), gender(gender)
{
    if (age <= 0)
    {
        throw std::exception("Invalid age");
    }
    else if (age < 16)
    {
        throw std::exception("Insufficient age");
    }
}

PersonInfo::PersonInfo(const PersonInfo& other) : surname(other.surname), name(other.name),
    lastname(other.lastname), age(other.age), gender(other.gender) {}

PersonInfo& PersonInfo::operator=(const PersonInfo& other)
{
    if (this != &other)
    {
        surname = other.surname;
        name = other.name;
        lastname = other.lastname;
        age = other.age;
        gender = other.gender;
    }
    return *this;
}

const QString& PersonInfo::get_surname() const
{
    return surname;
}

const QString& PersonInfo::get_name() const
{
    return name;
}

const QString& PersonInfo::get_lastname() const
{
    return lastname;
}

int PersonInfo::get_age() const
{
    return age;
}

const QString& PersonInfo::get_gender() const
{
    return gender;
}

void PersonInfo::set_surname(const QString& surname)
{
    this->surname = surname;
}

void PersonInfo::set_name(const QString& name)
{
    this->name = name;
}

void PersonInfo::set_lastname(const QString& lastname)
{
    this->lastname = lastname;
}

void PersonInfo::set_age(int age)
{
    this->age = age;
}

void PersonInfo::set_gender(const QString& gender)
{
    this->gender = gender;
}
