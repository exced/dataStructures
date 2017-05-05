//
//  linkedlist_test.cc
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "linkedlist.h"

int main(int argc, const char *argv[])
{
    datastructure::LinkedList<int> queue;
    queue.add(1);
    queue.add(2);
    queue.add(3);
    std::cout << "size: " << queue.size() << std::endl;
    std::cout << "queue: " << queue << std::endl;
    std::cout << queue.remove() << std::endl;
    std::cout << "size: " << queue.size() << std::endl;
    std::cout << queue.remove() << std::endl;
    std::cout << "size: " << queue.size() << std::endl;
    std::cout << queue.remove() << std::endl;
    std::cout << "size: " << queue.size() << std::endl;    
    return 0;
}
