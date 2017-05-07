//
//  string_test.cc
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

int main(int argc, const char *argv[])
{
    std::string foo = "foo";
    char chars[10] = {'b', 'a', 'r'};
    std::string bar(chars);
    std::cout << foo << std::endl;
    std::cout << bar << std::endl;
    return 0;
}
