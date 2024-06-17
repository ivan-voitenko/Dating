#ifndef PERSONEDUCATION_H
#define PERSONEDUCATION_H

#include "UniversityInfo.h"

class PersonEducation
{
private:
    bool secondary_education;
    bool higher_education;
    bool getting_higher_ed;
    UniversityInfo* university_info;

public:
    PersonEducation();
    PersonEducation(bool secondary_ed, bool higher_ed, bool getting_he, UniversityInfo* unInfo);
    PersonEducation(const PersonEducation& other);
    ~PersonEducation() noexcept;

    PersonEducation& operator=(const PersonEducation& other);

    bool get_secondary_education() const;
    bool get_higher_education() const;
    bool get_is_getting_higher_ed() const;

    const QString& get_university() const;
    const QString& get_degree() const;
    const QString& get_speciality() const;
    const QString& get_faculty() const;
    int get_year_of_admission() const;
    int get_year_of_graduation() const;


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

#endif // PERSONEDUCATION_H
