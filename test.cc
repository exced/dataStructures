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

float time_breakdown()
{
    return !(rand() % 4) ? static_cast<float>(50 + (rand() % 50)) / (10.f) : 0.f;
}

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    float times[] = {1.f, 2.5f, 3.f};
    std::cout << (*std::max_element(times, times + 3)) << std::endl;
    return 0;
}
