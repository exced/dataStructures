//  Simple Queue implementation using array. Warning: Limited size.
//
//  queue.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef QUEUE_H__
#define QUEUE_H__

#include <stdbool.h>
#include <stdint.h>
#include <exception>

namespace datastructure
{

template <typename T>
class Queue
{
  private:
    class QueueEmptyException : public std::exception
    {
      public:
        virtual const char *toString() const throw()
        {
            return "Empty queue";
        }
    } queue_empty_exception;

  private:
    uint32_t capacity_; // max capacity
    uint32_t size_;     // current size
    uint32_t head_;     // index of head
    uint32_t tail_;     // index of tail
    T *elements_;

  public:
    Queue(uint32_t capacity)
    {
        capacity_ = capacity;
        size_ = 0;
        head_ = 0;
        tail_ = -1;
        elements_ = new T[capacity];
    };

    ~Queue()
    {
        delete[] elements_;
    };

    /**
         * Retrieves, but does not remove, the head of this queue, or returns null if this queue is empty.
         */
    inline const T &peek() const
    {
        return (size_ == 0) ? NULL : elements_[head_];
    }

    /**
         * Retrieves, but does not remove, the head of this queue. This method differs from peek only in that it throws an exception if this queue is empty.
         */
    inline const T &element() const
    {
        if (size_ == 0)
        {
            throw queue_empty_exception;
        }
        return elements_[head_];
    }

    /**
         * Inserts the specified element into this queue if it is possible to do so immediately without violating capacity restrictions, returning true upon success and false if no space is currently available.
         */
    bool add(const T &element)
    {
        if (size_ == capacity_)
        {
            return false;
        }
        size_++;
        tail_++;
        /* handling circular */
        if (tail_ == capacity_)
        {
            tail_ = 0;
        }
        elements_[tail_] = element;
        return true;
    }

    /**
         * Retrieves and removes the head of this queue.
         */
    inline const T &remove()
    {
        if (size_ == 0)
        {
            throw queue_empty_exception;
        }
        size_--;
        const T &head = elements_[head_];
        head_++;
        /* handling circular */
        if (head_ == capacity_)
        {
            head_ = 0;
        }
        return head;
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

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue)
    {
        for (int i = 0; i < queue.size(); i++)
        {
            os << queue.elements_[queue.head_ + i] << ", ";
        }
        return os;
    }
};
}

#endif /* QUEUE_H__ */
