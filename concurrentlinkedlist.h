//  Simple doubly LinkedList implementation with all nodes running a different thread.
//
//  concurrentlinkedlist.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef CONCURRENTLINKEDLIST_H__
#define CONCURRENTLINKEDLIST_H__

#include <vector>
#include <thread>

#include "channel.h"

namespace datastructure
{

class ConcurrentLinkedList
{

  private:
    struct Node
    {
        int element_;
        int sum_ = 0;
        Channel<int> channel_;
        Node *previous_;
        Node *next_;
        Node()
        {
            previous_ = this;
            next_ = this;
        }
        /**
        * run do a round trip to sum nodes. 
        * Wait call from previous_ , then send to its next_ node until end.
        * Wait call from next_ (except for tail), then update sum_ and send to its previous_ node until begin.
        */
        void run(Node *begin, Node *sentinal)
        {
            int r;
            // receive from previous_ and send next_
            channel_ >> r;
            if (this->next_ == sentinal)
            { // tail
                sum_ = element_ + r;
                previous_->send(sum_);
            }
            else
            {
                next_->send(element_ + r);
                // receive from next_ and send previous_
                channel_ >> r;
                sum_ = r;
                if (this != begin)
                {
                    previous_->send(sum_);
                }
            }
        }
        /**
        * send put given input into channel_
        */
        void send(int element)
        {
            channel_ << element;
        }
    };

  public:
    class Iterator
    {

        friend class ConcurrentLinkedList;

      private:
        Node *node_;

      private:
        Iterator(Node *node)
        {
            node_ = node;
        }

      public:
        Iterator()
        {
        }

        Iterator &operator++()
        {
            node_ = node_->next_;
            return *this;
        }

        Iterator &operator--()
        {
            node_ = node_->previous_;
            return *this;
        }

        bool operator==(const Iterator &other)
        {
            return node_ == other.node_;
        }

        bool operator!=(const Iterator &other)
        {
            return !(node_ == other.node_);
        }

        int &operator*()
        {
            return node_->element_;
        }
    };

  private:
    Node *sentinal_;
    uint32_t size_;

  public:
    ConcurrentLinkedList()
    {
        sentinal_ = new Node;
        size_ = 0;
    }

    /**
    * Copy constructor.
    */
    ConcurrentLinkedList(const ConcurrentLinkedList &other)
    {
    }

    ~ConcurrentLinkedList()
    {
    }

    Iterator begin() const
    {
        return Iterator(sentinal_->next_);
    }

    Iterator end() const
    {
        return Iterator(sentinal_);
    }

    Iterator insert(Iterator position, int element)
    {
        size_++;
        Node *node = new Node;
        node->element_ = element;
        Node *current = position.node_;
        node->next_ = current;
        node->previous_ = current->previous_;
        current->previous_->next_ = node;
        current->previous_ = node;
        return Iterator(current);
    }

    void erase(Iterator position)
    {
        Node *current = position.node_;
        current->previous_->next_ = current->next_;
        if (size_ != 0)
        {
            current->next_->previous_ = current->previous_;
            delete current;
            size_--;
        }
        return;
    }

    inline const int &peek() const
    {
        return begin().node_->element_;
    }

    /**
    * Retrieves, but does not remove, the tail of this queue, or returns null if this queue is empty.
    */
    inline const int &peekLast() const
    {
        return end().node_->previous_->element_;
    }

    /**
    * Append given data to the end of the list (tail).
    */
    void add(const int &element)
    {
        insert(end(), element);
    }

    /**
    * Retrieves and removes the head of this queue.
    */
    inline const int &remove()
    {
        const int &element = begin().node_->element_;
        erase(begin());
        return element;
    }

    /**
    * Remove the last element
    */
    inline void pop_back()
    {
        erase(end().node_->previous_);
        return;
    }

    /**
    * Retrieves true if this queue is empty and false if not.
    */
    inline bool empty() const
    {
        return (size_ == 0);
    }

    /**
    * Retrieves the current size of this queue.
    */
    inline uint32_t size() const
    {
        return size_;
    }

    /**
    * Sum of all threaded nodes.
    */
    int sum()
    {
        std::vector<std::thread> workers;
        for (auto i = begin(); i != end(); ++i)
        {
            workers.emplace_back(&Node::run, i.node_, begin().node_, end().node_);
        }
        // start head
        begin().node_->channel_ << 0;
        for (auto &t : workers)
        {
            t.join();
        }
        return begin().node_->sum_;
    }

    friend std::ostream &operator<<(std::ostream &os, const ConcurrentLinkedList &queue)
    {
        for (auto i = queue.begin(); i != queue.end(); ++i)
        {
            os << *i << ' ';
        }
        return os;
    }
};
}

#endif /* CONCURRENTLINKEDLIST_H__ */
