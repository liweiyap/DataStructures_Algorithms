/**
 * Declaration of Stack object.
 */

#ifndef STACK_H
#define STACK_H
#pragma once

#ifndef NODE_SQ_H
#include "node-sq.hpp"
#endif

#include <cassert>


namespace dsa{
    
    /**
     * LIFO object used to simulate a virtual CPU.
     */
    template<typename T>
    class Stack{
    public:
        // Default constructor for empty Stack
        Stack();
        
        
        // Constructor for Stack containing a single Node to be created for storing value of datatype T
        Stack(T v);
        
        
        // Create new Node storing value of datatype T.
        // Add said Node to top of Stack.
        void push(T v);
        
        
        // Remove Node from top of Stack. Delete Node.
        void pop();
        
        
        // Return value of datatype T stored in Node at the top without removing it from the Stack
        T peek();
        
        
        // Return total number of Nodes in Stack
        unsigned int size();
        
        
        // If true, Stack contains 0 Nodes. If false, Stack contains Nodes.
        bool isEmpty();
        
        
        // Print the value stored in all Nodes to standard output in the correct order.
        void print();
        
        
        // Remove all Nodes from Stack. Delete all Nodes.
        void clear();
        
        
        // Destructor
        ~Stack();
        
        
    private:
        std::shared_ptr<Node<T>> top;
        
        unsigned int n_nodes;
    };  // end of Stack class definition


}  // end of namespace dsa

#endif
