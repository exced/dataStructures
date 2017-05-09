//  Simple Binary Tree implementation
//
//  btree.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef BTREE_H__
#define BTREE_H__

#include <stdbool.h>

#include <unordered_set>
#include <string>
#include <vector>

namespace datastructure
{

template <typename T>
class BTree
{

  private:
    /**
    * Node of Tree
    */
    class Node
    {
      public:
        T element_;
        Node *left_;
        Node *right_;
        Node *parent_;

      public:
        Node(const T &element)
        {
            element_ = element;
            left_ = NULL;
            right_ = NULL;
            parent_ = NULL;
        }

        ~Node()
        {
        }

        void setLeftChild(const T &element)
        {
            left_ = new Node(element);
            left_->parent_ = this;
        }

        void setRightChild(const T &element)
        {
            right_ = new Node(element);
            right_->parent_ = this;
        }

        /**
        * Retrieves node of given element
        */
        Node *findNode(const T &element)
        {
            if (element_ == element)
            {
                return this;
            }
            Node *child;
            if (left_)
            {
                child = left_->findNode(element);
            }
            if (!child && right_)
            {
                child = right_->findNode(element);
            }
            return child;
        }

        /**
        * Agglomerate element of node in a queue.
        */
        void visit(std::vector<T> &queue) const
        {
            queue.push_back(element_);
        }

        void inOrder(std::vector<T> &queue) const
        {
            if (!this)
            {
                return;
            }
            left_->inOrder(queue);
            visit(queue);
            right_->inOrder(queue);
        }

        void preOrder(std::vector<T> &queue) const
        {
            if (!this)
            {
                return;
            }
            visit(queue);
            left_->preOrder(queue);
            right_->preOrder(queue);
        }

        void postOrder(std::vector<T> &queue) const
        {
            if (!this)
            {
                return;
            }
            left_->postOrder(queue);
            right_->postOrder(queue);
            visit(queue);
        }

        /**
        * Returns the height of the tree.
        */
        inline int height() const
        {
            int leftHeight = left_ ? left_->height() : 0;
            int rightHeight = right_ ? right_->height() : 0;
            return 1 + std::max(leftHeight, rightHeight);
        }

        /**
        * print
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
    BTree(const T &element)
    {
        root_ = new Node(element);
    }

    ~BTree()
    {
    }

    /**
    * set left child of parent node.
    */
    void setLeftChild(const T &parent_element, const T &element)
    {
        Node *node = findNode(parent_element);
        if (node)
        {
            node->setLeftChild(element);
        }
    }

    /**
    * set right child of parent node.
    */
    void setRightChild(const T &parent_element, const T &element)
    {
        Node *node = findNode(parent_element);
        if (node)
        {
            node->setRightChild(element);
        }
    }

  private:
    /**
    * Retrieves node of given element.
    */
    Node *findNode(const T &element)
    {
        return root_->findNode(element);
    }

  public:
    /**
    * in order traversal. Agglomerate visited node in queue.
    */
    inline const std::vector<T> inOrder() const
    {
        std::vector<T> queue;
        root_->inOrder(queue);
        return queue;
    }

    /**
    * pre order traversal. Agglomerate visited node in queue.
    */
    inline const std::vector<T> preOrder() const
    {
        std::vector<T> queue;
        root_->preOrder(queue);
        return queue;
    }

    /**
    * post order traversal. Agglomerate visited node in queue.
    */
    inline const std::vector<T> postOrder() const
    {
        std::vector<T> queue;
        root_->postOrder(queue);
        return queue;
    }

  public:
    /**
    * Returns the height of the tree.
    */
    inline int height() const
    {
        return root_->height();
    }

    /**
    * print
    */
    friend std::ostream &operator<<(std::ostream &os, const BTree &btree)
    {
        for (auto element : btree.inOrder())
        {
            os << element << " ";
        }
        return os;
    }
};
}

#endif /* BTREE_H__ */
