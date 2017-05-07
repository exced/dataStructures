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

#include <map>
#include <unordered_set>
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
        char element_;
        std::map<char, Node *> children_; // children of this node in the trie. Ordered to keep track of lexicographic order
        bool terminates_;

      public:
        Node()
        {
        }

        Node(const char element)
        {
            element_ = element;
        }

        ~Node()
        {
        }

        /**
        * Inserts the specified word in this trie, and recursively creates the child nodes.
        */
        void add(const std::string word)
        {
            if (word.empty()) // terminal case
            {
                return;
            }
            Node *child = children_[word[0]];
            if (!child) // not found
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

      private:
        /**
        * Agglomerate all terminating words in given collector (lexicographic order).
        */
        void words(datastructure::LinkedList<std::string> words_collector, datastructure::LinkedList<char> char_collector) const
        {
            char_collector.add(element_);
            if (terminates_)
            { // new word : collect and next
                std::vector<char> word = char_collector.asArray();
                words_collector.add(std::string(word.begin(), word.end()));
                char_collector.remove();
                return;
            }
            for (std::pair<char, Node *> child : children_)
            {
                child.second->words(words_collector, char_collector);
            }
            return;
        }

      public:
        /**
        * Retrieves all terminating words.
        */
        inline datastructure::LinkedList<std::string> words() const
        {
            datastructure::LinkedList<std::string> words_collector;
            datastructure::LinkedList<char> char_collector;
            words(words_collector, char_collector);
            return words_collector;
        }

        /**
        * lexicographic order print
        */
        friend std::ostream &operator<<(std::ostream &os, const Node &node)
        {
            os << node.words();
            return os;
        }
    };

  private:
    Node *root_;

  public:
    const uint8_t ALPHABET_SIZE = 26;

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
    void add(const std::string word)
    {
        root_->add(word);
        return;
    }

    /**
    * Retrieves true if this trie contains given word and false otherwise.
    */
    bool contains(const std::string word) const
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

    /**
    * complete gives the list of possible words given a prefix.
    */
    datastructure::LinkedList<std::string> complete(const std::string prefix) const
    {
        datastructure::LinkedList<std::string> words;
        //root_->complete(prefix, words);
        return words;
    }

    /**
    * lexicographic order print
    */
    friend std::ostream &operator<<(std::ostream &os, const Trie &trie)
    {
        os << *trie.root_;
        return os;
    }
};
}

#endif /* TRIE_H__ */
