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
        }

        ~Node()
        {
        }

        void setLeftChild(Node &left)
        {
            left_ = left;
            if (left)
            {
                left.parent_ = this;
            }
        }

        void setRightChild(Node &right)
        {
            right_ = right;
            if (right)
            {
                right.parent_ = this;
            }
        }

        /**
        * Retrieves node of given id
        */
        Node *findNode(uint32_t id)
        {
            if (id_ == id)
            {
                return this;
            }
            Node *child;
            if (left_)
            {
                child = left_.find(id);
            }
            if (!child && right_)
            {
                child = right_.find(id);
            }
            return child;
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

    void visit(Node &root)
    {
        std::cout << "visit: " << root << std::endl;
    }

    /**
    * set left child of node of given id
    */
    void setLeft(uint32_t id, const T &element)
    {
    }

  private:
    /**
    * Retrieves node of given id
    */
    Node *findNode(uint32_t id)
    {
        return root_.findNode(id);
    }

  public:
    /**
    * Retrieves element of node of given id
    */
    const T &find(uint32_t id)
    {
        return findNode(id).element_;
    }

    void inOrder(Node &root)
    {
        if (!root)
        {
            return;
        }
        inOrder(root.left_);
        visit(root);
        inOrder(root.right_);
    }

    void preOrder(Node &root)
    {
        if (!root)
        {
            return;
        }
        visit(root);
        preOrder(root.left_);
        preOrder(root.right_);
    }

    void postOrder(Node &root)
    {
        if (!root)
        {
            return;
        }
        postOrder(root.left_);
        postOrder(root.right_);
        visit(root);
    }

  private:
    /**
    * Returns the height of the tree.
    */
    inline int height()
    {
        return (height(root_));
    }

  public:
    /**
    * Returns the height of the tree.
    */
    int height(Node &node)
    {
        if (!node)
        {
            return -1;
        }
        return std::max(height(node->left_), height(node->right_)) + 1;
    }

    /**
    * print
    */
    friend std::ostream &operator<<(std::ostream &os, const BTree &btree)
    {
        return os;
    }
};
}

#endif /* BTREE_H__ */
