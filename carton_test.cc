//
//  carton_test.cc
//  carton
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "carton.h"

int main(int argc, const char * argv[]) {
    const factory::Carton c1 = factory::randomCarton(1);
    const factory::Carton c2 = factory::randomCarton(2);
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    return 0;
}
