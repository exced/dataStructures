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
#include <vector>

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

        /**
        * Agglomerate all terminating words in given collector (lexicographic order).
        */
        void words(std::vector<std::string> &words_collector, std::vector<char> char_collector) const
        {
            char_collector.push_back(element_);
            if (terminates_)
            { // new word : collect and next
                words_collector.push_back(std::string(char_collector.begin(), char_collector.end()));
            }
            if (!children_.size())
            { // no child
                char_collector.pop_back();
                return;
            }
            for (std::pair<char, Node *> child : children_)
            {
                child.second->words(words_collector, char_collector);
            }
            return;
        }

        /**
        * Retrieves all terminating words.
        */
        inline std::vector<std::string> words() const
        {
            std::vector<std::string> words_collector;
            std::vector<char> char_collector;
            words(words_collector, char_collector);
            return words_collector;
        }

        /**
        * lexicographic order print
        */
        friend std::ostream &operator<<(std::ostream &os, const Node &node)
        {
            os << node.element_;
            return os;
        }
    };

  private:
    Node *root_;

  public:
    Trie(std::vector<std::string> &words)
    {
        root_ = new Node();
        std::string word;
        while (!words.empty())
        {
            word = words.back();
            root_->add(word);
            words.pop_back();
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
    * remove a given word from this trie.
    */
    void remove(std::string word)
    {

    }

    /**
    * complete gives the list of possible words given a prefix.
    */
    std::vector<std::string> complete(const std::string prefix) const
    {
        std::vector<std::string> words;
        // go to the last node matching this prefix
        Node *curr = root_;
        for (int i = 0; i < prefix.size(); i++)
        {
            curr = curr->children_[prefix[i]];
            if (!curr)
            { // not matching
                return words;
            }
        }
        return curr->words();
    }

    /**
    * lexicographic order print
    */
    friend std::ostream &operator<<(std::ostream &os, const Trie &trie)
    {
        for (auto word : trie.root_->words())
        {
            os << word << " ";
        }
        return os;
    }
};
}

#endif /* TRIE_H__ */
