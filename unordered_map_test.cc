//
//  unordered_map_test.cc
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
#include <unordered_map>

int main(int argc, const char *argv[])
{
    std::unordered_map <std::string, int> m;
    m["foo"] = 42;
    std::string t = "foo";
    std::cout << m[t] << std::endl;
    std::cout << m.at(t) << std::endl;
    return 0;
}
