#ifndef RANDOMUSER_H
#define RANDOMUSER_H

#include "User.h"
#include "TypeRelationship.h"
#include "PersonInterests.h"
#include <QString>
#include <QDir>

class RandomUser : public User
{
private:
    PersonInterests* interest;

    const QString file_name_fio = QDir::currentPath() + "/randomGenerator/SurnameNameLastname.txt";
    const QString file_name_degrees = QDir::currentPath() + "/randomGenerator/degrees.txt";
    const QString file_name_specialities = QDir::currentPath() + "/randomGenerator/specialities.txt";
    const QString file_name_faculties = QDir::currentPath() + "/randomGenerator/faculties.txt";
    const QString file_name_universities = QDir::currentPath() + "/randomGenerator/universities.txt";
    const QString file_name_interests = QDir::currentPath() + "/randomGenerator/interests.txt";

    void random_information(int min_age, int max_age, bool male, bool female);
    void random_university();
    void random_faculties();
    void random_specialities();
    void random_degrees();
    void random_interests();

public:
    RandomUser();
    RandomUser(PersonInfo* info_, PersonEducation* education_, PersonInterests* interest_);
    RandomUser(const RandomUser& other);
    ~RandomUser() noexcept;

    RandomUser& operator=(const RandomUser& other);

    void random_user(const TypeRelationship& types, bool secondary_ed, bool higher_ed,
                     bool student, int min_age, int max_age, bool male, bool female);
    const std::vector<QString>& get_interests() const;
};

#endif // RANDOMUSER_H
