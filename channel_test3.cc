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
#include <chrono>

#include "channel.h"

static const int kQuit = 0;

Channel<int> _wait(0);

void send()
{
    std::this_thread::sleep_for (std::chrono::seconds(6));
    _wait << 1;
    int r;
    _wait >> r;
    std::cout << "rcv 2" << r << std::endl;
}

void rcv()
{
    int r;
    _wait >> r;
    std::cout << "rcv 1" << r << std::endl;
    _wait << 2;
}

int main(int argc, const char *argv[])
{
    std::thread t2(rcv);
    std::thread t1(send);

    t1.join();
    t2.join();

    return 0;
}
