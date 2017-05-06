//  Simple simulation of factory with linked machines to create items.
//
//  factory.cc
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
#include "carton.h"

int main(int argc, const char *argv[])
{
    const int capacity = 100;
    const int number_pieces = 3; // Number of pieces inside a carton. Pieces are unique in a carton.
    const int max_capacity = capacity * number_pieces;
    datastructure::Queue<carton::Carton> carton_queue(capacity);   // input queue
    datastructure::Queue<carton::Piece> head_queue(capacity);      // independent machine
    datastructure::Queue<carton::Piece> skirt_queue(capacity);     // independent machine
    datastructure::Queue<carton::Piece> axe_queue(capacity);       // independent machine
    datastructure::Queue<carton::Piece> assembler_queue(max_capacity); // output queue. dependent of head/skirt/axe

    // init input cartons
    for (int i = 0; i < capacity; i++)
    {
        carton_queue.add(carton::random());
    }

    return 0;
}