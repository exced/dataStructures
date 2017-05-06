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
    const int piece_number = 3; // Number of pieces inside a carton. Pieces are unique in a carton.
    const int max_capacity = capacity * piece_number;

    datastructure::LinkedList<factory::Carton> carton_queue;   // input queue
    datastructure::LinkedList<factory::Piece> head_queue;      // independent machine
    datastructure::LinkedList<factory::Piece> skirt_queue;     // independent machine
    datastructure::LinkedList<factory::Piece> axe_queue;       // independent machine
    datastructure::LinkedList<factory::Piece> assembler_queue; // output queue. dependent of head/skirt/axe

    // init input cartons
    for (int i = 0; i < capacity; i++)
    {
        carton_queue.add(factory::randomCarton(i));
    }
    // load balancer
    datastructure::LinkedList<factory::Piece> pieces;
    factory::Piece piece;
    while (!carton_queue.empty())
    {
        pieces = carton_queue.remove().pieces_;
        while (!pieces.empty())
        {
            piece = pieces.remove();
            switch (piece.id_)
            {
            case 0: // head
                head_queue.add(piece);
                break;
            case 1: // skirt
                skirt_queue.add(piece);
                break;
            case 2: // axe
                axe_queue.add(piece);
                break;
            default:
                throw std::out_of_range("piece id out of range [0,1,2]");
            }
        }
    }

    return 0;
}