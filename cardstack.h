//  Simple Stack Card class for war card game.
//
//  cardstack.h
//  card
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef CARDSTACK_H__
#define CARDSTACK_H__

#include "stack.h"
#include "card.h"
#include "random.h"

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
        random::shuffle(elements_, size_);
    }

    /**
    * Fullfill the stack of cards with random cards
    */
    inline void fullfillRandom()
    {
        card::Card card;
        do
        {
            card.setRandom();
        } while (push(card));
    }
};
}

#endif /* CARDSTACK_H__ */
