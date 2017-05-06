//  Simple Trie implementation
//
//  trie.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef TRIE_H__
#define TRIE_H__

#include <stdbool.h>

#include <unordered_map>
#include <string>

#include "linkedlist.h"

namespace datastructure
{

class Trie
{

  private:
    /**
    * Node of Trie
    */
    class Node
    {
      public:
        char data_;
        std::unordered_map<char, Node *> children_; // children of this node in the trie
        bool terminates_;

      public:
        Node()
        {
        }

        Node(char data)
        {
            data_ = data;
        }

        ~Node()
        {
        }

        /**
        * Inserts the specified word in this trie, and recursively creates the child nodes.
        */
        void add(const std::string &word)
        {
            if (word.empty())
            {
                return;
            }
            Node *child = children_[word[0]];
            if (!child)
            {
                child = new Node(word[0]);
                children_[word[0]] = child;
            }
            if (word.size() > 1)
            {
                child->add(word.substr(1));
            }
            else
            {
                child->terminates_ = true;
            }
            return;
        }
    };

  private:
    Node *root_;

  public:
    Trie(datastructure::LinkedList<std::string> words)
    {
        root_ = new Node();
        while (!words.empty())
        {
            root_->add(words.remove());
        }
    }

    ~Trie()
    {
    }

    /**
        * Inserts the specified word in this trie, and recursively creates the child nodes.
        */
    void add(const std::string &word)
    {
        root_->add(word);
        return;
    }

    /**
    * Retrieves true if this trie contains given word and false otherwise.
    */
    bool contains(const std::string &word) const
    {
        Node *curr = root_;
        for (int i = 0; i < word.size(); i++)
        {
            curr = curr->children_[word[i]];
            if (!curr)
            {
                return false;
            }
        }
        return curr->terminates_;
    }
};
}

#endif /* TRIE_H__ */
