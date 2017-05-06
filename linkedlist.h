//  Simple singly LinkedList implementation.
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
    class QueueEmptyException : public std::exception
    {
      public:
        virtual const char *toString() const throw()
        {
            return "Empty queue";
        }
    } queue_empty_exception;

  private:
    struct Node
    {
        T element_;
        Node *next_;
    };

  private:
    Node *head_;
    Node *tail_;
    uint32_t size_;

  public:
    LinkedList()
    {
        size_ = 0;
    }

    /**
    * Retrieves, but does not remove, the head of this queue, or returns null if this queue is empty.
    */
    inline const T &peek() const
    {
        return (size_ == 0) ? NULL : head_->element_;
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
        return head_->element_;
    }

    /**
    * Inserts the specified element at the end of this queue.
    */
    void add(const T &element)
    {
        // new Node
        Node *node = new Node();
        node->element_ = element;
        if (size_ == 0)
        {
            head_ = node;
            tail_ = head_;
            size_++;
            return;
        }
        // append
        tail_->next_ = node;
        tail_ = tail_->next_;        
        size_++;
        return;
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
        Node *head = head_; // delete purpose
        const T &element = head_->element_;
        size_--;
        head_ = head_->next_;
        delete head;
        return element;
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
        Node *curr = queue.head_;
        while (curr)
        {
            os << curr->element_ << ", ";
            curr = curr->next_;
        }
        return os;
    }
};
}

#endif /* LINKEDLIST_H__ */
