//  Simple doubly thread save LinkedList implementation.
//
//  concurrentlinkedlist.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef CONCURRENTLINKEDLIST_H__
#define CONCURRENTLINKEDLIST_H__

namespace datastructure
{

template <typename T>
class ConcurrentLinkedList
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
    class iterator
    {

        friend class ConcurrentLinkedList;

      private:
        Node *node_;

      private:
        iterator(Node *node)
        {
            node_ = node;
        }

      public:
        iterator()
        {
        }

        iterator &operator++()
        {
            node_ = node_->next_;
            return *this;
        }

        iterator &operator--()
        {
            node_ = node_->previous_;
            return *this;
        }

        bool operator==(const iterator &other)
        {
            return node_ == other.node_;
        }

        bool operator!=(const iterator &other)
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
    ConcurrentLinkedList(const LinkedList &other)
    {
    }

    ~ConcurrentLinkedList()
    {
        
    }

    iterator begin() const
    {
        return iterator(sentinal_->next_);
    }

    iterator end() const
    {
        return iterator(sentinal_);
    }

    iterator insert(iterator position, T element)
    {
        size_++;
        Node *node = new Node;
        node->element_ = element;
        Node *current = position.node_;
        node->next_ = current;
        node->previous_ = current->previous_;
        current->previous_->next_ = node;
        current->previous_ = node;
        return iterator(current);
    }

    void erase(iterator position)
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

    /**
    * Free the list. It differs from delete that it keeps the root pointer so you can fulfill it later.
    */
    inline void free()
    {
        while (!empty())
        {
            remove();
        }
        return;
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

#endif /* CONCURRENTLINKEDLIST_H__ */
