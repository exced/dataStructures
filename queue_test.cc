//
//  queue_test.cc
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "queue.h"

int main(int argc, const char *argv[])
{
    const int capacity = 10;
    datastructure::Queue<int> queue(capacity);
    queue.add(1);
    std::cout << "size: " << queue.size() << std::endl;
    queue.add(2);
    std::cout << "size: " << queue.size() << std::endl;
    std::cout << queue.remove() << std::endl;
    std::cout << queue.remove() << std::endl;
    queue.add(1);
    queue.add(2);
    queue.add(3);
    std::cout << queue << std::endl;
    return 0;
}
