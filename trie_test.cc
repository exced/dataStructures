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
    std::vector<std::string> words;
    words.push_back("hello");
    words.push_back("hell");
    words.push_back("helloworld");
    words.push_back("world");
    datastructure::Trie trie(words);
    std::cout << "trie: " << trie << std::endl;
    std::cout << trie.contains("h") << std::endl;
    std::cout << trie.contains("hell") << std::endl;
    std::cout << trie.contains("hello") << std::endl;
    std::cout << trie.contains("helloworld") << std::endl;
    std::cout << trie.contains("world") << std::endl;
    std::cout << "autocomplete: " << trie << std::endl;
    std::vector<std::string> complete = trie.complete("hel");
    for (auto completed : complete)
    {
        std::cout << completed << ", ";
    }
    return 0;
}
