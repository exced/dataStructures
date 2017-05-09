//  Simple Color enum
//
//  color.h
//  color
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef COLOR_H__
#define COLOR_H__

namespace color
{

// Color enum.
enum Color
{
    GREEN,
    BLUE,
    BROWN,
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
    case GREEN:
        os << "green";
        break;
    case BLUE:
        os << "blue";
        break;
    case BROWN:
        os << "brown";
        break;
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
