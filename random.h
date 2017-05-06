//  Simple Random nested utility class
//
//  random.h
//  random
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef RANDOM_H__
#define RANDOM_H__

namespace
{
namespace random
{

/**
* Shuffle given array and its size
*/
template <typename T>
void shuffle(T array[], int size)
{
    int r;
    T t;
    for (int i = 0; i < size; i++)
    {
        r = rand() % (i + 1);
        t = array[r];
        array[r] = array[i];
        array[i] = t;
    }
    return;
}
}
}

#endif /* RANDOM_H__ */
