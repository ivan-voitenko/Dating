#include "PersonInterests.h"
#include <algorithm>

PersonInterests::PersonInterests() : interests() {}

PersonInterests::PersonInterests(const std::vector<QString>& interests_) : interests(interests_) {}

PersonInterests::PersonInterests(const PersonInterests& other) : interests(other.interests) {}

PersonInterests& PersonInterests::operator=(const PersonInterests& other)
{
    if (this != &other)
    {
        interests = other.interests;
    }
    return *this;
}

const std::vector<QString>& PersonInterests::get_interests() const
{
    return interests;
}

void PersonInterests::set_interests(const std::vector<QString>& interests_)
{
    interests = interests_;
}

void PersonInterests::add_interest(const QString& interest)
{
    interests.push_back(interest);
}

void PersonInterests::del_interest(const QString& interest)
{
    auto it = std::find(interests.begin(), interests.end(), interest);
    if (it != interests.end())
    {
        interests.erase(it);
    }
}
