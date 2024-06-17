#include "PersonEducation.h"
#include <exception>

PersonEducation::PersonEducation() : secondary_education(true),
    higher_education(false), getting_higher_ed(false), university_info(new UniversityInfo) {}

PersonEducation::PersonEducation(bool secondary_ed, bool higher_ed,
                                 bool getting_he, UniversityInfo* unInfo) : secondary_education(secondary_ed),
    higher_education(higher_ed), getting_higher_ed(getting_he), university_info(unInfo)
{
    if ((higher_ed == false || getting_higher_ed == false) &&
        university_info != nullptr)
    {
        throw std::exception("Unexpected error. Not student, but university information is complete");
    }
    else if ((higher_ed == true || getting_higher_ed == true) &&
             university_info == nullptr)
    {
        throw std::exception("Unexpected error. Student, but university info is incomplete");
    }
}

PersonEducation::PersonEducation(const PersonEducation& other) :
    secondary_education(other.secondary_education), higher_education(other.higher_education),
    getting_higher_ed(other.getting_higher_ed), university_info(other.university_info) {}

PersonEducation::~PersonEducation() noexcept
{
    delete university_info;
}

PersonEducation& PersonEducation::operator=(const PersonEducation& other)
{
    if (this != &other)
    {
        secondary_education = other.secondary_education;
        higher_education = other.higher_education;
        getting_higher_ed = other.getting_higher_ed;
        university_info = other.university_info;
    }
    return *this;
}

bool PersonEducation::get_secondary_education() const
{
    return secondary_education;
}

bool PersonEducation::get_higher_education() const
{
    return higher_education;
}

bool PersonEducation::get_is_getting_higher_ed() const
{
    return getting_higher_ed;
}

const QString& PersonEducation::get_university() const
{
    return university_info->get_university();
}

const QString& PersonEducation::get_degree() const
{
    return university_info->get_degree();
}

const QString& PersonEducation::get_speciality() const
{
    return university_info->get_speciality();
}

const QString& PersonEducation::get_faculty() const
{
    return university_info->get_faculty();
}

int PersonEducation::get_year_of_admission() const
{
    return university_info->get_year_of_admission();
}

int PersonEducation::get_year_of_graduation() const
{
    return university_info->get_year_of_graduation();
}

void PersonEducation::set_secondary_ed(bool secondary_ed)
{
    this->secondary_education = secondary_ed;
}

void PersonEducation::set_higher_ed(bool higher_ed)
{
    this->higher_education = higher_ed;
}

void PersonEducation::set_getting_higher_ed(bool getting_higher_ed)
{
    this->getting_higher_ed = getting_higher_ed;
}


void PersonEducation::set_university(const QString& university)
{
    if (!university_info) university_info = new UniversityInfo;
    this->university_info->set_university(university);
}

void PersonEducation::set_degree(const QString& degree)
{
    if (!university_info) university_info = new UniversityInfo;
    this->university_info->set_degree(degree);
}

void PersonEducation::set_speciality(const QString& speciality)
{
    if (!university_info) university_info = new UniversityInfo;
    this->university_info->set_speciality(speciality);
}

void PersonEducation::set_faculty(const QString& faculty)
{
    if (!university_info) university_info = new UniversityInfo;
    this->university_info->set_faculty(faculty);
}

void PersonEducation::set_admission(int year_of_admission)
{
    if (!university_info) university_info = new UniversityInfo;
    this->university_info->set_admission(year_of_admission);
}

void PersonEducation::set_graduation(int year_of_graduation)
{
    if (!university_info) university_info = new UniversityInfo;
    this->university_info->set_graduation(year_of_graduation);
}
