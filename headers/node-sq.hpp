/**
 * Definition of Node object, which is a building block of Stack and Queue objects.
 */

// uncomment this block if wishing to debug
/*
#ifndef DEBUG_NODE
#define DEBUG_NODE
#endif
 */

#ifndef NODE_SQ_H
#define NODE_SQ_H
#pragma once

#include <memory>     // shared_ptr
#include <iostream>


namespace dsa{

    /**
     * Node object acts as building block for larger Stack or Queue object.
     * Each Node contains two attributes: its own value of datatype T and a pointer
     * that points either to NULL or the next Node in the same Stack or Queue.
     */
    template<typename T>
    struct Node{
        // Inline constructor for stand-alone Node
        Node(T v): value(v), next(0){}
        
        // Inline constructor for Node object that points to another Node
        Node(T v, std::shared_ptr<Node<T>> n): value(v), next(n){}

        T value;
        std::shared_ptr<Node<T>> next;
        
#ifdef DEBUG_NODE
        ~Node(){std::cout << "Node " << value << " destroyed.\n";}
#endif
    };  // end of Node struct definition

}  // end of namespace dsa

#endif
