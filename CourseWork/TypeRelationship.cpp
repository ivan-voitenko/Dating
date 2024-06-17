#include "TypeRelationship.h"

TypeRelationship::TypeRelationship() : relationship(false), friendship(false),
    flirting(false), companionship(false), not_decide(false) {}

TypeRelationship::TypeRelationship(bool relationship_, bool friendship_, bool flirting_, bool companionship_, bool not_decide_) :
    relationship(relationship_), friendship(friendship_), flirting(flirting_), companionship(companionship_), not_decide(not_decide_) {}

TypeRelationship::TypeRelationship(const TypeRelationship& other) : relationship(other.relationship), friendship(other.friendship),
    flirting(other.flirting), companionship(other.companionship), not_decide(other.not_decide) {}

TypeRelationship& TypeRelationship::operator=(const TypeRelationship& other)
{
    if (this != &other)
    {
        relationship = other.relationship;
        friendship = other.friendship;
        flirting = other.flirting;
        companionship = other.companionship;
        not_decide = other.not_decide;
    }
    return *this;
}

bool TypeRelationship::get_relationship() const
{
    return relationship;
}

bool TypeRelationship::get_friendship() const
{
    return friendship;
}

bool TypeRelationship::get_flirting() const
{
    return flirting;
}

bool TypeRelationship::get_companionship() const
{
    return companionship;
}

bool TypeRelationship::get_not_decide() const
{
    return not_decide;
}

void TypeRelationship::set_relationship(bool relationship_)
{
    relationship = relationship_;
}

void TypeRelationship::set_friendship(bool friendship_)
{
    friendship = friendship_;
}

void TypeRelationship::set_flirting(bool flirting_)
{
    flirting = flirting_;
}

void TypeRelationship::set_companionship(bool companionship_)
{
    companionship = companionship_;
}

void TypeRelationship::set_not_decide(bool not_decide_)
{
    not_decide = not_decide_;
}
