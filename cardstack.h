//  Simple Stack Card class for war card game.
//
//  cardstack.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef CARDSTACK_H__
#define CARDSTACK_H__

#include "stack.h"
#include "card.h"

namespace card
{

class CardStack : public datastructure::Stack<card::Card>
{
  public:
    CardStack(uint32_t capacity) : datastructure::Stack<card::Card>(capacity){};

    ~CardStack(){};

    /**
    * shuffle this card stack.
    */
    inline void shuffle()
    {
        int r;
        card::Card card;
        for (int i = 0; i < size_; i++)
        {
            r = rand() % (i + 1);
            card = elements_[r];
            elements_[r] = elements_[i];
            elements_[i] = card;
        }
    }

    /**
    * Fullfill the stack of cards with random cards
    */
    inline void fullfillRandom()
    {
        while (push(card::Card()))
        {
        }
    }
};
}

#endif /* CARDSTACK_H__ */
