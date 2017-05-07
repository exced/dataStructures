//
//  trie_test.cc
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <string>

#include "trie.h"

int main(int argc, const char *argv[])
{
    datastructure::LinkedList<std::string> words;
    words.add("hello");
    words.add("world");
    datastructure::Trie trie(words);
    std::cout << trie << std::endl;
    std::cout << trie.contains("h") << std::endl;
    std::cout << trie.contains("hello") << std::endl;
    std::cout << trie.contains("world") << std::endl;
    return 0;
}
