/**
 * Declaration of Queue object.
 */

#ifndef QUEUE_H
#define QUEUE_H
#pragma once

#ifndef NODE_SQ_H
#include "node-sq.hpp"
#endif

#include <cassert>


namespace dsa{
    
    /**
     * FIFO object used to simulate a virtual CPU.
     */
    template<typename T>
    class Queue{
    public:
        // Default constructor for empty Queue
        Queue();
        
        
        // Constructor for Queue containing a single Node to be created for storing value of datatype T
        Queue(T v);
        
        
        // Create new Node storing value of datatype T.
        // Add said Node to end of Queue.
        void enqueue(T v);
        
        
        // Remove Node from front of Queue. Delete Node.
        void dequeue();
        
        
        // Return value of datatype T stored in Node at the top without removing it from the Queue
        T peek();
        
        
        // Return total number of Nodes in Queue
        unsigned int size();
        
        
        // If true, Queue contains 0 Nodes. If false, Queue contains Nodes.
        bool isEmpty();
        
        
        // Print the value stored in all Nodes to standard output in the correct order.
        void print();
        
        
        // Remove all Nodes from Queue. Delete all Nodes.
        void clear();
        
        
        // Destructor
        ~Queue();
        
        
    private:
        std::shared_ptr<Node<T>> first;
        std::shared_ptr<Node<T>> last;
        
        unsigned int n_nodes;
    };  // end of Queue class definition


}  // end of namespace dsa

#endif
