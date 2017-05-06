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

const uint8_t PIECE_NUMBER = 3;

struct Piece
{
    uint8_t id_;         // piece identifier: {0: head, 1: skirt, 2: axe}
    uint32_t carton_id_; // id of the carton where the piece comes from. Tracking purpose
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
    uint32_t pieces_number_;             // number of pieces_
    uint32_t id_;
};

/**
* Retrieves random carton with given id_
*/
Carton randomCarton(uint32_t id)
{
    Carton carton = Carton();
    // init pieces
    datastructure::LinkedList<Piece> pieces;
    Piece piece;
    for (int i = 0; i < PIECE_NUMBER; i++)
    {
        piece = Piece();
        piece.id_ = rand() % PIECE_NUMBER;
        piece.carton_id_ = id;
        pieces.add(piece);
    }
    carton.id_ = id;
    return carton;
}

std::ostream &operator<<(std::ostream &os, Carton carton)
{
    os << "id: " << carton.id_ << ", pieces: [ " << carton.pieces_ << " ]" << std::endl;
    return os;
}
}

#endif /* CARTON_H__ */
