//  Simple family tree implementation with our Binary Tree class. Since everyone has a parent, Links represent parental relationship.
//  family_tree_test.cc
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <string>

#include "btree.h"

struct Person 
{
    uint32_t id_;
    std::string firstname_;
    std::string lastname_;
    std::string birthdate_;
    std::string eyes_color_;
}

int main(int argc, const char *argv[])
{
    datastructure::Graph graph;
    graph.addEdge();
    return 0;
}
