//  Simple Stack implementation using array.
//
//  stack.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef STACK_H__
#define STACK_H__

#include <stdbool.h>
#include <stdint.h>
#include <exception>

namespace datastructure
{

template <typename T>
class Stack
{
  private:
    class StackEmptyException : public std::exception
    {
      public:
        virtual const char *toString() const throw()
        {
            return "Empty stack";
        }
    } stack_empty_exception;

  protected:
    uint32_t capacity_; // max capacity
    uint32_t size_;     // current size
    uint32_t head_;     // index of head (a.k.a top)
    T *elements_;

  public:
    Stack(uint32_t capacity)
    {
        capacity_ = capacity;
        size_ = 0;
        head_ = -1;
        elements_ = new T[capacity];
    };

    ~Stack()
    {
        delete[] elements_;
    };

    /**
         * Retrieves, but does not remove, the top of this stack, or returns null if this stack is empty.
         */
    inline const T &peek() const
    {
        return (size_ == 0) ? NULL : elements_[head_];
    }

    /**
         * Removes the object at the top of this stack and returns that object as the value of this function.
         */
    inline const T &pop()
    {
        if (size_ == 0)
        {
            throw stack_empty_exception;
        }
        size_--;
        return elements_[head_--];
    }

    /**
         * Pushes an item onto the top of this stack.
         */
    bool push(const T &element)
    {
        if (size_ == capacity_)
        {
            return false;
        }
        size_++;
        elements_[++head_] = element;
        return true;
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

    friend std::ostream &operator<<(std::ostream &os, const Stack &stack)
    {
        for (int i = stack.size() - 1; i >= 0; i--)
        {
            os << stack.elements_[i] << ", ";
        }
        return os;
    }
};
}

#endif /* STACK_H__ */
