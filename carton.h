//  Simple Carton struct
//
//  carton.h
//  factory
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef CARTON_H__
#define CARTON_H__

#include "random.h"
#include "linkedlist.h"

namespace factory
{

const uint8_t PIECES_NUMBER = 100;

struct Piece
{
    uint8_t id_;         // piece identifier: {0: head, 1: skirt, 2: axe}
};

std::ostream &operator<<(std::ostream &os, Piece piece)
{
    switch (piece.id_)
    {
    case 0:
        os << "head";
        break;
    case 1:
        os << "skirt";
        break;
    case 2:
        os << "axe";
        break;
    default:
        os.setstate(std::ios_base::failbit);
    }
    return os;
}

struct Carton
{
    datastructure::LinkedList<Piece> pieces_; // fullfilled pieces array
};

/**
* Retrieves carton with random pieces inside.
*/
Carton randomCarton()
{
    Carton carton = Carton();
    // init pieces
    Piece piece;
    for (int i = 0; i < PIECES_NUMBER; i++)
    {
        piece = Piece();
        piece.id_ = rand() % 3;
        carton.pieces_.add(piece);
    }
    return carton;
}

std::ostream &operator<<(std::ostream &os, Carton carton)
{
    os << carton.pieces_;
    return os;
}
}

#endif /* CARTON_H__ */
