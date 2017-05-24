//
//  concurrent_linkedlist_test.cc
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "concurrentlinkedlist.h"

int main(int argc, const char * argv[]) {
    datastructure::ConcurrentLinkedList list;
    list.add(0);
    list.add(4);
    list.add(2);
    list.add(3);
    int s = list.sum();
    std::cout << "multi threaded sum: " << s << std::endl;
    std::cout << "list: " << list << std::endl;
    return 0;
}
