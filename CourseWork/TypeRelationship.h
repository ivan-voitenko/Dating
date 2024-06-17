#ifndef TYPERELATIONSHIP_H
#define TYPERELATIONSHIP_H

class TypeRelationship
{
private:
    bool relationship;
    bool friendship;
    bool flirting;
    bool companionship;
    bool not_decide;

public:
    TypeRelationship();
    TypeRelationship(bool relationship_, bool friendship_, bool flirting_, bool companionship_, bool not_decide_);
    TypeRelationship(const TypeRelationship& other);
    ~TypeRelationship() noexcept = default;

    TypeRelationship& operator=(const TypeRelationship& other);

    bool get_relationship() const;
    bool get_friendship() const;
    bool get_flirting() const;
    bool get_companionship() const;
    bool get_not_decide() const;

    void set_relationship(bool relationship_);
    void set_friendship(bool friendship_);
    void set_flirting(bool flirting_);
    void set_companionship(bool companionship_);
    void set_not_decide(bool not_decide_);
};

#endif // TYPERELATIONSHIP_H
