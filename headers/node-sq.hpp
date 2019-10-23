/**
 * Definition of Node object, which is a building block of Stack object.
 */

#ifndef NODE_SQ
#define NODE_SQ
#pragma once

#include <memory>     // shared_ptr


namespace dsa{

    /**
     * Node object acts as building block for larger Stack object.
     * Each Node contains two attributes: its own value [int] and a pointer
     * that points either to NULL or the next Node in the same Stack.
     */
    struct Node{
        // Inline constructor for stand-alone Node
        Node(int v): value(v), next(0){}
        
        // Inline constructor for Node object that points to another Node
        Node(int v, std::shared_ptr<Node> n): value(v), next(n){}

        int value;
        std::shared_ptr<Node> next;
    };  // end of Node struct definition

}  // end of namespace dsa

#endif
