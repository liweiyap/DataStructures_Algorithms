/**
 * Definition of Node object, which is a building block of Tree object, e.g. Binary Search Tree.
 */

#ifndef NODE_TREE_H
#define NODE_TREE_H
#pragma once

#include <memory>   // unique_ptr
#include <utility>  // move
#include <ostream>

namespace dsa{

    /**
     * Node object acts as building block for larger Tree object.
     * Each Node contains three attributes: its own value of datatype T
     * and two pointers to its left and right children in the same Tree.
     */
    template <typename T>
    struct BSTNode{
        // Constructor 1
        BSTNode(T v): value(v){}
        
        // Constructor 2
        BSTNode(T v, std::unique_ptr<BSTNode<T>> l, std::unique_ptr<BSTNode<T>> r): value(v), left(std::move(l)), right(std::move(r)){}
        
        // print value of this node
        std::ostream& print_value(std::ostream& os){
            os << value << " ";
            return os;
        }
        
        T value;
        std::unique_ptr<BSTNode<T>> left;
        std::unique_ptr<BSTNode<T>> right;
    };  // end of BSTNode struct definition

}  // end of namespace dsa

#endif
