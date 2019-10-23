/**
 * Declaration of Stack object.
 */

#ifndef STACK_H
#define STACK_H
#pragma once

#ifndef NODE_SQ
#include "node-sq.hpp"
#endif

#include <iostream>
#include <cassert>


namespace dsa{
    
    /**
     * LIFO object used to simulate a virtual CPU.
     */
    class Stack{
    public:
        // Default constructor for empty Stack
        Stack();
        
        
        // Constructor for Stack containing a single Node to be created for storing integer value
        Stack(int v);
        
        
        // Create new Node storing integer value.
        // Add said Node to top of Stack.
        void push(int v);
        
        
        // Remove Node from top of Stack. Delete Node.
        void pop();
        
        
        // Return int value stored in Node at the top without removing it from the Stack
        int peek();
        
        
        // Return total number of Nodes in Stack
        int size();
        
        
        // If true, Stack contains 0 Nodes. If false, Stack contains Nodes.
        bool isEmpty();
        
        
        // Print the value stored in all Nodes to standard output in the correct order.
        void print();
        
        
        // Remove all Nodes from Stack. Delete all Nodes.
        void clear();
        
        
        // Destructor
        ~Stack();
        
        
    private:
        std::shared_ptr<Node> top;
        
        int n_nodes;
    };  // end of Stack class definition


}  // end of namespace dsa

#endif
