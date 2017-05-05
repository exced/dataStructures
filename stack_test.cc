//
//  stack_test.cc
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "stack.h"

int main(int argc, const char * argv[]) {
    const int capacity = 10;
    datastructure::Stack<int> stack(capacity);
    stack.push(1);
    std::cout << "size: " << stack.size() << std::endl;
    stack.push(2);
    std::cout << "size: " << stack.size() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    stack.push(1);
    stack.push(2);
    std::cout << stack << std::endl;
    return 0;
}
