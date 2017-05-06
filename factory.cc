//  Simple simulation of factory with linked machines to create items.
//
//  factory.cc
//  factory
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "queue.h"
#include "carton.h"

int main(int argc, const char *argv[])
{
    const int capacity = 100;
    const int number_pieces = 3; // Number of pieces inside a carton. Pieces are unique in a carton.
    const int max_capacity = capacity * number_pieces;
    datastructure::Queue<factory::Carton> carton_queue(capacity);   // input queue
    datastructure::Queue<factory::Piece> head_queue(capacity);      // independent machine
    datastructure::Queue<factory::Piece> skirt_queue(capacity);     // independent machine
    datastructure::Queue<factory::Piece> axe_queue(capacity);       // independent machine
    datastructure::Queue<factory::Piece> assembler_queue(max_capacity); // output queue. dependent of head/skirt/axe

    // init input cartons
    for (int i = 0; i < capacity; i++)
    {
        carton_queue.add(factory::randomCarton(i));
    }
    // load balancer
    factory::Piece piece;
    while (!carton_queue.empty()) {
        
    }

    return 0;
}