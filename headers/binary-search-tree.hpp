/**
 * Declaration of Binary Search Tree object.
 */

#ifndef BST_H
#define BST_H
#pragma once

#ifndef NODE_TREE_H
#include "node-tree.hpp"
#endif

#include <cassert>
#include <iostream>
#include <string>


namespace dsa{
    
    /**
     * BST object
     */
    template<typename T>
    class BSTree{
    public:
        // Default constructor for empty BST
        BSTree();
        
        
        // Constructor for BST with value of datatype T stored at root
        BSTree(const T v);
        
        
        // Search for node storing value of datatype T in BST.
        // If present, return true; else, return false.
        bool search(const T v);
        
        
        // Insert node with value of datatype T into BST, and then return true.
        // If node already present in BST, then don't insert any node. Return false.
        bool insert(const T v);
        
        
        // Remove node with value of datatype T from BST, and then return true.
        // If node not already present in BST, then don't remove any node. Return false.
        bool remove(const T v);
        
        
        // Traverse sub-tree rooted at input node in order
        void traverse_in_order(std::unique_ptr<dsa::BSTNode<T>>& node);
        
        
        // Traverse the whole tree in order
        void traverse_in_order();
        
        
        // Return pointer to pointer of node with minimum value in sub-tree rooted at input node
        std::unique_ptr<dsa::BSTNode<T>>* min_node(std::unique_ptr<dsa::BSTNode<T>>& node);
        
        
        // Return pointer to pointer of symmetric successor of input node
        // (i.e. node with minimum value in sub-tree rooted at right child of input node)
        std::unique_ptr<dsa::BSTNode<T>>* symm_succ(std::unique_ptr<dsa::BSTNode<T>>& node);
        
        
        // Return pointer to pointer of parent of node with given value
        std::unique_ptr<dsa::BSTNode<T>>* getParent(const T v);
        
        
        // helper function for indicating level of nodes when printing
        std::ostream& spaces(std::ostream& os, const int h);
        
        
        // Vertically print sub-tree rooted at given node
        std::ostream& print(std::ostream& os, std::unique_ptr<dsa::BSTNode<T>>& node, const int h);
        
        
        // Vertically print entire BST
        std::ostream& print(std::ostream& os);
        
        
        // Return number of nodes in BST
        int get_n_nodes();
        
        
        // Simple removal of all nodes from BST
        void clear();
        
        
    private:
        std::unique_ptr<dsa::BSTNode<T>> root;
        int n_nodes = 0;
        
    };  // end of BSTree class definition


}  // end of namespace dsa

#endif
