//  Simple simulation of factory with linked machines to create items (Production chain).
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

#include "linkedlist.h"

struct Piece
{
    uint8_t id_;       // piece identifier: {0: head, 1: skirt, 2: axe}
    float time_track_; // time tracking since the beginning of the chain
};

/**
* simulate a breakdown: add 5 to 10 minutes to repair, tenth precision
*/
float time_breakdown()
{
    return !(rand() % 4) ? static_cast<float>(50 + (rand() % 50)) / (10.f) : 0.f;
}

/**
* simulate a chained task job with a breakdown. Take 1 piece, enhances it and give it to the next worker. Returns time after producting this piece.
*/
float work(datastructure::LinkedList<Piece> &job, datastructure::LinkedList<Piece> &next, int quantity, int id_new, float time_production, float time_current)
{
    for (int i = 0; i < quantity; i++)
    {
        job.remove();
    }
    Piece piece = Piece();
    piece.id_ = id_new;                                                    // piece transformation
    piece.time_track_ = time_current + time_production + time_breakdown(); // timestamp tag
    next.add(piece);
    return piece.time_track_;
}

int main(int argc, const char *argv[])
{
    const int capacity = 100;     // number of input cartons.
    const int pieces_number = 4; // number of different pieces. (head/skirt/axe/piston)

    // random seed
    srand(time(NULL));

    datastructure::LinkedList<Piece> carton;          // -> head/skirt/axe
    datastructure::LinkedList<Piece> head_queue;      // head -> assembler
    datastructure::LinkedList<Piece> skirt_queue;     // skirt -> assembler
    datastructure::LinkedList<Piece> axe_queue;       // axe -> assembler
    datastructure::LinkedList<Piece> assembler_queue; // head/skirt/axe -> piston.
    datastructure::LinkedList<Piece> piston_queue;    // piston stack

    // init input cartons : initially randomed pieces.
    Piece piece;
    for (int i = 0; i < capacity; i++)
    {
        piece = Piece();
        piece.id_ = rand() % (pieces_number - 1);
        piece.time_track_ = 0.f;
        carton.add(piece);
    }

    // load balancer : we do not know the content of a carton
    while (!carton.empty())
    {
        piece = carton.remove();
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

    float time_head = 0.f;
    float time_skirt = 0.f;
    float time_axe = 0.f;
    float time_piston = 0.f;
    // scheduling simulation
    while (!head_queue.empty() && !skirt_queue.empty() && !axe_queue.empty())
    {
        // workflow simulation
        time_head = work(head_queue, assembler_queue, 1, 0, 2.f, time_head);
        time_skirt = work(skirt_queue, assembler_queue, 1, 1, 3.f, time_skirt);
        time_axe = work(axe_queue, assembler_queue, 1, 2, 2.5f, time_axe);
        // assembler depends on (head/skirt/axe)
        float times[] = {time_head, time_skirt, time_axe};
        time_piston = work(assembler_queue, piston_queue, 3, 4, 1.f, *std::max_element(times, times + pieces_number - 1));
    }

    // output of simulation
    std::cout << piston_queue.size() << " piston(s) assembled in " << piston_queue.elementLast().time_track_ << " minutes." << std::endl;

    return 0;
}