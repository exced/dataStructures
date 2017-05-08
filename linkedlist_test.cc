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
#include <vector>

#include "linkedlist.h"

int main(int argc, const char *argv[])
{
    datastructure::LinkedList<int> queue;
    queue.add(1);
    std::cout << "queue: " << queue << std::endl;
    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "queue: " << queue.remove() << std::endl;
    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "queue: " << queue.remove() << std::endl;
    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "queue: " << queue.remove() << std::endl;
    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "queue: " << queue << std::endl;
    queue.pop_back();
    std::cout << "queue: " << queue << std::endl;
    queue.add(2);
    std::cout << "queue: " << queue << std::endl;
    queue.add(3);
    queue.add(4);
    std::cout << "queue remove: " << queue.remove() << std::endl;
    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "queue peek: " << queue.peek() << std::endl;
    std::cout << "queue peek last: " << queue.peekLast() << std::endl;
    std::cout << "queue: " << queue << std::endl;
    queue.add(5);
    std::cout << "queue: " << queue << std::endl;
    queue.add(6);
    std::cout << "queue: " << queue << std::endl;
    queue.add(7);
    queue.free();
    std::cout << "free: " << queue << std::endl;
    std::cout << "free size: " << queue.size() << std::endl;
    return 0;
}
