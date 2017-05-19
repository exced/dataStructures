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

static const int kQuit = 0;

Channel<int> out(1), in(1);

void sendInts()
{
    auto d = std::async(std::launch::async, [&] {
        for (int i = 1; i < 5; i++)
        {
            out << i;
            int rcvd;
            in >> rcvd;

        }
        out << kQuit;
    });
}

int sum()
{
    int res = 0;
    auto b = std::async(std::launch::async, [&] {
        while (true)
        {
            int reply;
            out >> reply;
            if (reply == kQuit)
                return res;
            res += reply;
            in << 1;
        }
    });
    return res;
}

int main(int argc, const char *argv[])
{

    std::thread t1(sendInts);
    int s = 0;
    std::thread t2([&] {
        s = sum();
    });

    t1.join();
    t2.join();
    std::cout << "sum: " << s << std::endl;

    return 0;
}
