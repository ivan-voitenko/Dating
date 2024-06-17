#include "UniversityInfo.h"
#include <exception>

UniversityInfo::UniversityInfo() : university(), degree(), faculty(),
    speciality(), year_of_admission(1950), year_of_graduation(1954) {}

UniversityInfo::UniversityInfo(const QString& university, const QString& degree, const QString& speciality,
                               const QString& faculty, int admission, int graduation, bool still_learning) :
    university(university), degree(degree), speciality(speciality),
    faculty(faculty), year_of_admission(admission), year_of_graduation(graduation)
{
    if (admission < 1950 || admission > 2024)
    {
        throw std::exception("Invalid year of admission");
    }
    else if (graduation < 1950 || graduation > 2024)
    {
        throw std::exception("Invalid year of graduation");
    }
    else if (!still_learning && (graduation <= admission || graduation - admission < 4))
    {
        throw std::exception("Training cannot be less than 4 years");
    }
}

UniversityInfo::UniversityInfo(const UniversityInfo& other) : university(other.university),
    degree(other.degree), faculty(other.faculty), speciality(other.speciality),
    year_of_admission(other.year_of_admission), year_of_graduation(other.year_of_graduation) {}

UniversityInfo& UniversityInfo::operator=(const UniversityInfo& other)
{
    if (this != &other)
    {
        university = other.university;
        faculty = other.faculty;
        speciality = other.speciality;
        degree = other.degree;
        year_of_admission = other.year_of_admission;
        year_of_graduation = other.year_of_graduation;
    }
    return *this;
}

const QString& UniversityInfo::get_university() const
{
    return university;
}

const QString& UniversityInfo::get_degree() const
{
    return degree;
}

const QString& UniversityInfo::get_speciality() const
{
    return speciality;
}

const QString& UniversityInfo::get_faculty() const
{
    return faculty;
}

int UniversityInfo::get_year_of_admission() const
{
    return year_of_admission;
}

int UniversityInfo::get_year_of_graduation() const
{
    return year_of_graduation;
}

void UniversityInfo::set_university(const QString& university)
{
    this->university = university;
}

void UniversityInfo::set_degree(const QString& degree)
{
    this->degree = degree;
}

void UniversityInfo::set_speciality(const QString& speciality)
{
    this->speciality = speciality;
}

void UniversityInfo::set_faculty(const QString& faculty)
{
    this->faculty = faculty;
}

void UniversityInfo::set_admission(int year_of_admission)
{
    this->year_of_admission = year_of_admission;
}

void UniversityInfo::set_graduation(int year_of_graduation)
{
    this->year_of_graduation = year_of_graduation;
}
