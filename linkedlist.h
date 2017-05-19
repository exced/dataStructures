//  Simple doubly LinkedList implementation.
//
//  linkedlist.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

namespace datastructure
{

template <typename T>
class LinkedList
{

  private:
    struct Node
    {
        T element_;
        Node *previous_;
        Node *next_;
        Node()
        {
            previous_ = this;
            next_ = this;
        }
    };

  public:
    class Iterator
    {

        friend class LinkedList;

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
    LinkedList()
    {
        sentinal_ = new Node;
        size_ = 0;
    }

    /**
    * Copy constructor.
    */
    LinkedList(const LinkedList &other)
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

    Iterator insert(Iterator position, T element)
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

    inline const T &peek() const
    {
        return begin().node_->element_;
    }

    /**
    * Retrieves, but does not remove, the tail of this queue, or returns null if this queue is empty.
    */
    inline const T &peekLast() const
    {
        return end().node_->previous_->element_;
    }

    /**
    * Append given data to the end of the list (tail).
    */
    void add(const T &element)
    {
        insert(end(), element);
    }

    /**
    * Retrieves and removes the head of this queue.
    */
    inline const T &remove()
    {
        const T &element = begin().node_->element_;
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

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &queue)
    {
        for (auto i = queue.begin(); i != queue.end(); ++i)
        {
            os << *i << ' ';
        }
        return os;
    }
};
}

#endif /* LINKEDLIST_H__ */
