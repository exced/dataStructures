//
//  card_test.cc
//  card
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "card.h"

int main(int argc, const char *argv[])
{
    card::Card c1;
    card::Card c2;
    c1.setRandom();
    c2.setRandom();
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    card::Card c3 = card::Card(color::BLACK, 5, 1);
    card::Card c4 = card::Card(color::RED, 5, 1);
    std::cout << c3 << std::endl;
    std::cout << "score: " << c3.score() << std::endl;
    std::cout << c4 << std::endl;
    std::cout << "score: " << c4.score() << std::endl;
    std::cout << (c3 < c4) << std::endl;
    return 0;
}
