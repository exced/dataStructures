//  Simple Card class for war card game.
//
//  card.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef CARD_H__
#define CARD_H__

#include <stdbool.h>
#include <stdint.h>
#include <exception>

#include "color.h"

namespace card
{

class Card
{
  public:
    color::Color color_;
    uint32_t value_;
    uint32_t power_;

  public:
    /**
    * random card
    */
    Card()
    {
        color_ = color::random();
        value_ = rand() % 10 + 1;
        power_ = rand() % 4 + 1;
    }

    Card(color::Color color, uint32_t value, uint32_t power)
    {
        color_ = color;
        value_ = value;
        power_ = power;
    };

    ~Card(){

    };

    inline float score()
    {
        float score = value_;
        if (color_ == color::RED)
        {
            score *= 1.5;
        }
        return score * power_;
    }

    bool operator<(const Card &card)
    {
        if (value_ != card.value_)
        {
            return value_ < card.value_;
        }
        return color_ < card.color_;
    }

    bool operator==(const Card &card)
    {
        return value_ == card.value_ && color_ == card.color_;
    }

    friend std::ostream &operator<<(std::ostream &os, const Card &card)
    {
        os << card.color_ << " " << card.value_ << " " << card.power_;
        return os;
    }
};
}

#endif /* CARD_H__ */
