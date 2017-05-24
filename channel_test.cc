//
//  channel_test.cc
//  channel
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <string>
#include <future>
#include <thread>

#include "channel.h"

static const int kGo = 0;
static const int kQuit = -1;

Channel<int> sayHello(0), sayWorld(0);

void hello()
{
    for (int i = 0; i < 5; ++i)
    {
        sayWorld << i;
        int a;
        sayHello >> a;
    }
    sayWorld << kQuit;
}

void world()
{
    while (true)
    {
        int reply;
        sayWorld >> reply;
        if (reply == kQuit)
        {
            break;
        }
        std::cout << reply;
        sayHello << kGo;
    }
}

int main(int argc, const char *argv[])
{
    std::thread t1(hello);
    std::thread t2(world);

    t1.join();
    t2.join();

    return 0;
}
