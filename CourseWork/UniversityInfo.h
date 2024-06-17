#ifndef UNIVERSITYINFO_H
#define UNIVERSITYINFO_H

#include <QString>

class UniversityInfo
{
private:
    QString university;
    QString degree;
    QString speciality;
    QString faculty;
    int year_of_admission;
    int year_of_graduation;

public:
    UniversityInfo();
    UniversityInfo(const QString& university, const QString& degree, const QString& speciality,
                   const QString& faculty, int admission, int graduation, bool still_learning);
    UniversityInfo(const UniversityInfo& other);
    ~UniversityInfo() noexcept = default;

    UniversityInfo& operator=(const UniversityInfo& other);

    const QString& get_university() const;
    const QString& get_degree() const;
    const QString& get_speciality() const;
    const QString& get_faculty() const;
    int get_year_of_admission() const;
    int get_year_of_graduation() const;

    void set_university(const QString& university);
    void set_degree(const QString& degree);
    void set_speciality(const QString& speciality);
    void set_faculty(const QString& faculty);
    void set_admission(int year_of_admission);
    void set_graduation(int year_of_graduation);
};

#endif // UNIVERSITYINFO_H
