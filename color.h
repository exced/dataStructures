//  Simple Color enum
//
//  color.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef COLOR_H__
#define COLOR_H__

#include <stdbool.h>
#include <stdint.h>
#include <exception>

namespace color
{

// Color enum. Warning: order matters. Red > Black
enum Color
{
    BLACK,
    RED,
    FLAG_NUMBER,
};

/**
* Retrieves random color
*/
Color random()
{
    return static_cast<Color>(rand() % FLAG_NUMBER);
}

std::ostream &operator<<(std::ostream &os, Color color)
{
    switch (color)
    {
    case BLACK:
        os << "black";
        break;
    case RED:
        os << "red";
        break;
    default:
        os.setstate(std::ios_base::failbit);
    }
    return os;
}
}

#endif /* COLOR_H__ */
