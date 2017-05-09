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

#include <unordered_map>
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

      public:
        Node(const T &element)
        {
            element_ = element;
            left_ = NULL;
            right_ = NULL;
        }

        ~Node()
        {
        }

        void setLeftChild(Node *left)
        {
            left_ = left;
        }

        void setRightChild(Node *right)
        {
            right_ = right;
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
    std::unordered_map<T, Node *> nodes_lookup_; // Nodes lookup

  public:
    BTree(const T &element)
    {
        root_ = new Node(element);
        nodes_lookup_[element] = root_;
    }

    ~BTree()
    {
    }

    /**
    * set left child of parent node.
    */
    void setLeftChild(const T &parent_element, const T &element)
    {
        Node *parent = findNode(parent_element);
        Node *child = new Node(element);
        if (parent)
        {
            parent->setLeftChild(child);
            nodes_lookup_[element] = child;
        }
    }

    /**
    * set right child of parent node.
    */
    void setRightChild(const T &parent_element, const T &element)
    {
        Node *parent = findNode(parent_element);
        Node *child = new Node(element);
        if (parent)
        {
            parent->setRightChild(child);
            nodes_lookup_[element] = child;
        }
    }

  private:
    /**
    * Retrieves node of given element.
    */
    Node *findNode(const T &element)
    {
        return nodes_lookup_[element];
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
