#include "User.h"

User::User() : info(new PersonInfo), education(new PersonEducation) {}

User::User(PersonInfo* info_, PersonEducation* education_) : info(info_), education(education_) {}

User::User(const User& other) : info(new PersonInfo(*other.info)), education(new PersonEducation(*other.education)) {}

User::~User() noexcept
{
    delete info;
    delete education;
}


User& User::operator=(const User& other)
{
    if (this != &other)
    {
        delete info;
        delete education;
        info = new PersonInfo(*other.info);
        education = new PersonEducation(*other.education);
    }
    return *this;
}


const QString& User::surname() const
{
    return info->get_surname();
}

const QString& User::name() const
{
    return info->get_name();
}

const QString& User::lastname() const
{
    return info->get_lastname();
}

int User::age() const
{
    return info->get_age();
}

const QString& User::gender() const
{
    return info->get_gender();
}


bool User::secondary_education() const
{
    return education->get_secondary_education();
}

bool User::higher_education() const
{
    return education->get_higher_education();
}

bool User::is_getting_higher_ed() const
{
    return education->get_is_getting_higher_ed();
}


const QString& User::university() const
{
    return education->get_university();
}

const QString& User::degree() const
{
    return education->get_degree();
}

const QString& User::speciality() const
{
    return education->get_speciality();
}

const QString& User::faculty() const
{
    return education->get_faculty();
}

int User::year_of_admission() const
{
    return education->get_year_of_admission();
}

int User::year_of_graduation() const
{
    return education->get_year_of_graduation();
}


void User::set_surname(const QString& surname)
{
    info->set_surname(surname);
}

void User::set_name(const QString& name)
{
    info->set_name(name);
}

void User::set_lastname(const QString& lastname)
{
    info->set_lastname(lastname);
}

void User::set_age(int age)
{
    info->set_age(age);
}

void User::set_gender(const QString& gender)
{
    info->set_gender(gender);
}


void User::set_secondary_ed(bool secondary_ed)
{
    education->set_secondary_ed(secondary_ed);
}

void User::set_higher_ed(bool higher_ed)
{
    education->set_higher_ed(higher_ed);
}

void User::set_getting_higher_ed(bool getting_higher_ed)
{
    education->set_getting_higher_ed(getting_higher_ed);
}


void User::set_university(const QString& university)
{
    education->set_university(university);
}

void User::set_degree(const QString& degree)
{
    education->set_degree(degree);
}

void User::set_speciality(const QString& speciality)
{
    education->set_speciality(speciality);
}

void User::set_faculty(const QString& faculty)
{
    education->set_faculty(faculty);
}


void User::set_admission(int year_of_admission)
{
    education->set_admission(year_of_admission);
}

void User::set_graduation(int year_of_graduation)
{
    education->set_graduation(year_of_graduation);
}
