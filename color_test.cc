//
//  color_test.cc
//  color
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "color.h"

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    const color::Color r = color::RED;
    const color::Color b = color::BLACK;
    const color::Color random = color::random();
    std::cout << r << std::endl;
    std::cout << b << std::endl;
    std::cout << random << std::endl;
    return 0;
}
