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

/**
* worker empties a queue in another -> chain of tasks. Returns the time taken.
*/
float worker(datastructure::LinkedList<factory::Piece> &job, datastructure::LinkedList<factory::Piece> &next, float working_time)
{
    float time_taken = 0.f;
    
}

int main(int argc, const char *argv[])
{
    const int capacity = 100; // number of input cartons.

    factory::Carton carton = factory::randomCarton();          // init input cartons : initially randomed. -> head/skirt/axe
    datastructure::LinkedList<factory::Piece> head_queue;      // head -> assembler
    datastructure::LinkedList<factory::Piece> skirt_queue;     // skirt -> assembler
    datastructure::LinkedList<factory::Piece> axe_queue;       // axe -> assembler
    datastructure::LinkedList<factory::Piece> assembler_queue; // head/skirt/axe -> assembled.
    datastructure::LinkedList<factory::Piece> assembled_queue; // assembled -> done.

    // load balancer
    factory::Piece piece;
    while (!carton.pieces_.empty())
    {
        piece = carton.pieces_.remove();
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

    // scheduling simulation

    return 0;
}