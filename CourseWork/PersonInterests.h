#ifndef PERSONINTERESTS_H
#define PERSONINTERESTS_H

#include <vector>
#include <QString>

class PersonInterests
{
private:
    std::vector<QString> interests;

public:
    PersonInterests();
    PersonInterests(const std::vector<QString>& interests_);
    PersonInterests(const PersonInterests& other);
    ~PersonInterests() noexcept = default;

    PersonInterests& operator=(const PersonInterests& other);

    const std::vector<QString>& get_interests() const;
    void set_interests(const std::vector<QString>& interests_);

    void add_interest(const QString& interest);
    void del_interest(const QString& interest);

};

#endif // PERSONINTERESTS_H
