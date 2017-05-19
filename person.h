//  Simple Person struct. Used for Family Tree. Field id_ should be unique.
//
//  person.h
//  person
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef PERSON_H__
#define PERSON_H__

struct Person
{
    uint32_t id_;
    std::string firstname_;
    std::string lastname_;
    uint32_t birthyear_;
    color::Color eyes_color_;
};

bool operator==(const Person &lvalue, const Person &rvalue)
{
    return lvalue.id_ == rvalue.id_;
}

bool operator<(const Person &lvalue, const Person &rvalue)
{
    return lvalue.id_ < rvalue.id_;
}

std::ostream &
operator<<(std::ostream &os, const Person &person)
{
    os << '{' << person.id_ << "," << person.firstname_ << "," << person.lastname_ << "," << person.birthyear_ << "," << person.eyes_color_ << '}';
    return os;
}

std::ostream &
operator<<(std::ostream &os, const std::vector<Person> &persons)
{
    for (auto element : persons)
    {
        os << element << " ";
    }
    return os;
}

namespace std
{
template <>
struct hash<Person>
{
    size_t operator()(const Person &p) const
    {
        return std::hash<int>()(p.id_);
    }
};
}

#endif /* PERSON_H__ */
