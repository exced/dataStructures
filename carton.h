//  Simple Carton struct
//
//  carton.h
//  carton
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef CARTON_H__
#define CARTON_H__

#include "random.h"

namespace carton
{

const uint8_t PIECE_NUMBER = 3;

struct Piece
{
    uint8_t id_;         // piece identifier: {0: head, 1: skirt, 2: axe}
    uint32_t carton_id_; // id of the carton where the piece comes from
};

struct Carton
{
    Piece *pieces_; // pieces array fullfilled
    uint32_t pieces_number_; // number of pieces_
    uint32_t id_;
};

/**
* Retrieves random carton with given id_
*/
Carton random(uint32_t id)
{
    Carton carton = Carton();
    // random pieces_id
    int pieces_id[3] = {
        0, 1, 2,
    };
    random::shuffle(pieces_id, PIECE_NUMBER);
    // init pieces
    Piece pieces[3];
    for (int i = 0; i < PIECE_NUMBER; i++)
    {
        pieces[i] = Piece();
        pieces[i].id_ = pieces_id[i];
        pieces[i].carton_id_ = id;
    }
    carton.pieces_ = pieces;
    carton.id_ = id;
    return carton;
}
}

#endif /* CARTON_H__ */
