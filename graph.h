//  Simple Graph implementation
//
//  graph.h
//  datastructure
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#ifndef GRAPH_H__
#define GRAPH_H__

#include <stdbool.h>

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "linkedlist.h"

namespace datastructure
{

template <typename T>
class Graph
{

  private:
    /**
    * Node of Graph
    */
    class Node
    {
      public:
        uint32_t id_;
        T element_;
        datastructure::LinkedList<Node *> adjacents_;

      public:
        Node(const uint32_t id)
        {
            id_ = id;
        }

        Node(const uint32_t id, T element)
        {
            id_ = id;
            element_ = element;
        }

        ~Node()
        {
        }

        friend std::ostream &operator<<(std::ostream &os, const Node &node)
        {
            return os;
        }
    };

  private:
    std::unordered_map<uint32_t, Node *> node_lookup_; // Nodes lookup

  public:
    Graph()
    {
    }

    ~Graph()
    {
    }

    /**
        * add Edge between two nodes.
        */
    void addEdge(const uint32_t source, const uint32_t destination)
    {
        node_lookup_[source].adjacents_.add(node_lookup_[destination]);
        return;
    }

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        return os;
    }
};
}

#endif /* GRAPH_H__ */
