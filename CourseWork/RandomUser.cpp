#include "RandomUser.h"
#include <QFile>
#include <QTextStream>
#include <QDir>

RandomUser::RandomUser() : User(), interest(nullptr) {}

RandomUser::RandomUser(PersonInfo* info_, PersonEducation* education_, PersonInterests* interest_) : User(info_, education_), interest(interest_) {}

RandomUser::RandomUser(const RandomUser& other) : User(other), interest(new PersonInterests(*other.interest)) {}

RandomUser::~RandomUser() noexcept
{
    delete interest;
}

RandomUser& RandomUser::operator=(const RandomUser& other)
{
    if (this != &other)
    {
        delete interest;
        delete info;
        delete education;
        info = new PersonInfo(*other.info);
        education = new PersonEducation(*other.education);
        interest = new PersonInterests(*other.interest);
    }
    return *this;
}

void RandomUser::random_information(int min_age, int max_age, bool male, bool female)
{
    info->set_age(min_age + rand() % ((max_age + 1) - min_age));
    QFile FIO(file_name_fio);
    if (!FIO.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&FIO);
    QString allData = in.readAll();
    QStringList pieces = allData.split("\n");
    FIO.close();

    int fio_ind = rand() % 100;
    QStringList line = pieces.at(fio_ind).split(" ");
    while (true)
    {
        if (line.value(0) == 'F' && (female || (!male && !female)))
        {
            info->set_gender("female");
            break;
        }
        else if (line.value(0) == 'M' && (male|| (!male && !female)))
        {
            info->set_gender("male");
            break;
        }
        fio_ind = rand() % 100;
        line = pieces.at(fio_ind).split(" ");
    }
    info->set_surname(line.value(1));
    info->set_name(line.value(2));
    info->set_lastname(line.value(3));
}

void RandomUser::random_university()
{
    QFile un(file_name_universities);
    if (!un.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&un);
    int un_ind = rand() % 40;
    int i = 0;
    while (!in.atEnd() && i != un_ind)
    {
        ++i;
        in.readLine();
    }
    QString line = in.readLine();
    un.close();
    education->set_university(line);
}

void RandomUser::random_faculties()
{
    QFile faculties(file_name_faculties);
    if (!faculties.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&faculties);
    int fclt_ind = rand() % 40;
    int i = 0;
    while (!in.atEnd() && i != fclt_ind)
    {
        ++i;
        in.readLine();
    }
    QString line = in.readLine();
    faculties.close();
    education->set_faculty(line);
}

void RandomUser::random_specialities()
{
    QFile spec(file_name_specialities);
    if (!spec.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&spec);
    int spec_ind = rand() % 50;
    int i = 0;
    while (!in.atEnd() && i != spec_ind)
    {
        ++i;
        in.readLine();
    }
    QString line = in.readLine();
    spec.close();
    education->set_speciality(line);
}

void RandomUser::random_degrees()
{
    QFile degree(file_name_degrees);
    if (!degree.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&degree);
    int degree_ind = rand() % 20;
    int i = 0;
    while (!in.atEnd() && i != degree_ind)
    {
        ++i;
        in.readLine();
    }
    QString line = in.readLine();
    degree.close();
    education->set_degree(line);
}

void RandomUser::random_interests()
{
    QFile interests(file_name_interests);
    if (!interests.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&interests);
    int start_ind = rand() % 70;
    int size = 5 + rand() % 20;
    int i = 0;

    while (!in.atEnd() && i != start_ind)
    {
        ++i;
        in.readLine();
    }
    PersonInterests* pi = new PersonInterests;
    while (size)
    {
        --size;
        pi->add_interest(in.readLine());
    }
    interests.close();

    interest = pi;
}

void RandomUser::random_user(const TypeRelationship& types, bool secondary_ed, bool higher_ed,
                            bool student, int min_age, int max_age, bool male, bool female)
{
    education->set_secondary_ed(secondary_ed);
    education->set_higher_ed(higher_ed);
    education->set_getting_higher_ed(student);

    int admission = 1950 + rand() % 75;
    int graduation = admission + (4 + rand() % 2);
    education->set_admission(admission);
    education->set_graduation(graduation);

    random_information(min_age, max_age, male, female);
    random_university();
    random_faculties();
    random_specialities();
    random_degrees();
    random_interests();
}

const std::vector<QString>& RandomUser::get_interests() const
{
    return interest->get_interests();
}
