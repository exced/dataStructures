//
//  concurrent_linkedlist_test.cc
//  color
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <thread>

#include "concurrentlinkedlist.h"

int main(int argc, const char * argv[]) {
    datastructure::ConcurrentLinkedList<int> list;
    list.add(1);
    list.add(1);
    list.add(1);
    list.add(1);
    std::cout << "mono threaded sum: " << list.sum() << std::endl;
    return 0;
}
