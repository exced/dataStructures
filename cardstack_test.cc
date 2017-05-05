//
//  cardstack_test.cc
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "cardstack.h"

int main(int argc, const char * argv[]) {
    const int capacity = 10;
    card::CardStack cs1 = card::CardStack(capacity);
    cs1.fullfillRandom();
    card::CardStack cs2 = card::CardStack(capacity);
    std::cout << cs1.size() << std::endl;
    std::cout << cs1 << std::endl;
    cs1.shuffle();
    std::cout << "shuffled: " << cs1 << std::endl;
    std::cout << cs2 << std::endl;
    return 0;
}
