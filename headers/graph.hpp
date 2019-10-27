/**
 * Declaration of Graph base and derived classes..
 */

#ifndef GRAPH_H
#define GRAPH_H
#pragma once

#ifndef EXCEPTIONS_H
#include "exceptions.hpp"
#endif

#include <vector>
#include <iostream>
#include <cassert>



namespace dsa{
    
    // abstract class: cannot be instantiated
    class Graph{
        
    public:
        
        // Constructor for base class Graph, given the number of vertices
        Graph(unsigned int n);
        
        // must be overwritten
        virtual void add_edge(unsigned int v1, unsigned int v2) = 0;
        
        // print adjacency list to standard output
        void print_adj_list();
        
        // access number of vertices
        unsigned int get_n_vertices();
        
        // access adjacency list
        std::vector<std::vector<unsigned int>> get_adj_list();
        
    protected:
        
        unsigned int n_vertices;
        
        std::vector<std::vector<unsigned int>> adj_list;
        
    };  // end of Graph base class declaration
    
    
    // derived class for undirected graph
    class Graph_Undirected : public Graph{
        
    public:
        
        // Constructor for derived class, given the number of vertices
        Graph_Undirected(unsigned int n);
        
        // add edge between two vertices by updating adjacency list
        void add_edge(unsigned int v1, unsigned int v2);
        
    };  // end of Graph_Undirected derived class declaration
    
    
    // dervied class for directed graph
    class Graph_Directed : public Graph{
        
    public:
        
        // Constructor for derived class, given the number of vertices
        Graph_Directed(unsigned int n);
        
        // add edge between two vertices by updating adjacency list
        void add_edge(unsigned int v1, unsigned int v2);
        
    };  // end of Graph_Directed derived class declaration
    
    
}  // end of namespace dsa

#endif
