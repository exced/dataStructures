//  Simple binary tree test
//  family_tree_test.cc
//  datastructure
//
//  ex src : https://en.wikipedia.org/wiki/Tree_traversal
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <string>

#include "btree.h"

std::ostream &
operator<<(std::ostream &os, const std::vector<char> &chars)
{
    for (auto element : chars)
    {
        os << element << " ";
    }
    return os;
}

int main(int argc, const char *argv[])
{
    char F = 'F';
    char B = 'B';
    char G = 'G';
    char A = 'A';
    char D = 'D';
    char C = 'C';
    char E = 'E';
    char I = 'I';
    char H = 'H';
    datastructure::BTree<char> tree(F); // root
    tree.setLeftChild(F, B);
    tree.setRightChild(F, G);
    tree.setLeftChild(B, A);
    tree.setRightChild(B, D);
    tree.setLeftChild(D, C);
    tree.setRightChild(D, E);
    tree.setRightChild(G, I);
    tree.setLeftChild(I, H);
    std::cout << "Tree height: " << tree.height() << std::endl;
    std::cout << "inOrder: " << tree.inOrder() << std::endl;
    std::cout << "preOrder: " << tree.preOrder() << std::endl;
    std::cout << "postOrder: " << tree.postOrder() << std::endl;
    return 0;
}
