//  Simple family tree implementation with our Binary Tree class. Since everyone has a parent, Links represent parental relationship.
//  family_tree_test.cc
//  datastructure
//
//  family src http://fr.gameofthrones.wikia.com/wiki/Maison_Stark
//  http://awoiaf.westeros.org/index.php/Jon_Snow
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <string>

#include "btree.h"
#include "color.h"

struct Person
{
    uint32_t id_;
    std::string firstname_;
    std::string lastname_;
    uint32_t birthyear_;
    color::Color eyes_color_;
};

std::ostream &
operator<<(std::ostream &os, const Person &person)
{
    os << person.id_ << "," << person.firstname_ << "," << person.lastname_ << "," << person.birthyear_ << "," << person.eyes_color_;
    return os;
}

int main(int argc, const char *argv[])
{
    Person jon = {0, "Jon", "Snow", 284, color::Color::BROWN};
    Person eddard = {1, "Eddard", "Stark", 260, color::Color::BROWN};
    Person catelyn = {2, "Catelyn", "Tully", 262, color::Color::BLUE};
    Person rickard = {3, "Rickard", "Stark", 244, color::Color::BROWN};
    Person unknown = {3, "Unknown", "Unknown", 246, color::Color::BROWN};
    datastructure::BTree<Person> tree(jon); // root
    return 0;
}
