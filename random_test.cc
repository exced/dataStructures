//
//  random_test.cc
//  random
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "random.h"

int main(int argc, const char *argv[])
{
    int arr[5] = {
        0, 1, 2, 3, 4,
    };
    // print array
    for (auto const &v : arr)
    {
        std::cout << v << ",";
    }
    std::cout << std::endl;
    // shuffle it
    random::shuffle(arr, 5);
    // print array
    for (auto const &v : arr)
    {
        std::cout << v << ",";
    }
    std::cout << std::endl;
    return 0;
}
