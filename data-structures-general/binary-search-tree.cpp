/**
 * Definition of Binary Search Tree object.
 */

#ifndef BST_H
#include "binary-search-tree.hpp"
#endif


/**
 * Default constructor for empty BST.
 *
 * @return empty BST
 */
template <typename T>
dsa::BSTree<T>::BSTree(){}


/**
 * Constructor for BST class with value of datatype T stored at root
 *
 * @param v value of datatype T to be stored at root
 */
template <typename T>
dsa::BSTree<T>::BSTree(const T v): root(std::make_unique<dsa::BSTNode<T>>(v)), n_nodes(1) {}


/**
 * Search for node storing value of datatype T in BST. If present, return true; else, return false.
 *
 * @param v value of datatype T to be searched for in BST
 * @return boolean for whether value is present in BST
 */
template <typename T>
bool dsa::BSTree<T>::search(const T v){
    // start walking at root of BST
    dsa::BSTNode<T>* node = root.get();
    
    // whilst current node exists but value has not been found
    while (node && v != node->value){
        // if value to be searched is smaller than the value of the current node, go left
        if (v < node->value){
            node = node->left.get();
            
        // if value to be searched is greater than the value of the current node, go right
        } else{
            node = node->right.get();
        }  // end IF
    }  // end WHILE for walking down BST
    
    // if node with value to be searched is present, return TRUE
    if (node) return true;
    
    // otherwise, if node is nullptr, then value cannot be found in BST. Return FALSE.
    return false;
    
}  // end of search function


/**
 * Insert node with value of datatype T into BST, and then return true.
 * If node already present in BST, then don't insert any node. Return false.
 *
 * @param v value of datatype T to be inserted into BST
 * @return boolean for whether insertion is successful
 */
template <typename T>
bool dsa::BSTree<T>::insert(const T v){
    // start walking at root of BST
    std::unique_ptr<dsa::BSTNode<T>>* node = &root;
    
    // whilst current node exists
    while (*node){
        // if node already present
        if (v == (*node)->value){
            // don't insert any node. Return FALSE.
            return false;
            
        /*
         otherwise if node is not already present,
         continue searching for it by walking down left or right
         */
        } else if (v < (*node)->value){
            node = &(*node)->left;
        } else{
            node = &(*node)->right;
        }  // end IF
    }  // end WHILE
    
    // insert node either at the left or right branch of parent
    *node = std::make_unique<dsa::BSTNode<T>>(v);
    
    // increment number of nodes and return true
    ++n_nodes;
    return true;
    
}  // end of insert function


/**
 * Remove node with value of datatype T from BST, and then return true.
 * If node not already present in BST, then don't remove any node. Return false.
 *
 * @param v value of datatype T to be inserted into BST
 * @return boolean for whether deletion is successful
 */
template <typename T>
bool dsa::BSTree<T>::remove(const T v){
    // start walking at root of BST
    std::unique_ptr<dsa::BSTNode<T>>* node = &root;
    
    // whilst current node exists
    while (*node){
        // if node with correct value is found
        if (v == (*node)->value){
            /*
             The first two statements together take care of the following 2 cases simultaneously:
             1) if node has no children, then it is a leaf. Simply delete it from the BST.
             2) if node has only one child, replace that node with its child and delete it.
             */
            if (!(*node)->left){
                *node = std::move((*node)->right);
            } else if (!(*node)->right){
                *node = std::move((*node)->left);
                
            /*
             The last statement takes care of the much more complicated case:
             if node has 2 children.
             */
            } else{
                /*
                 find the symmetric successor (i.e. node with minimum value in sub-tree
                 rooted at right child of input node), as well as the parent of the
                 symmetric successor
                 */
                std::unique_ptr<dsa::BSTNode<T>>* ss = symm_succ(*node);
                std::unique_ptr<dsa::BSTNode<T>>* ss_parent = getParent((*ss)->value);
                
                // delete value from node by replacing it with the value of the symmetric successor
                (*node)->value = (*ss)->value;
                
                /*
                 if the symmetric successor is the right child of its parent,
                 then the parent of the symmetric successor is the one that is being removed
                 */
                if ((*ss_parent)->right && (*ss_parent)->right->value == (*ss)->value){
                    
                    // if the symmetric successor itself has a right child
                    if ((*ss)->right){
                        // replace parent of symmetric successor with symmetric successor
                        (*ss_parent)->right = std::move((*ss)->right);
                    // otherwise, if the symmetric successor itself has no right child
                    } else{
                        /*
                         then simply remove symmetric successor, since its value has already
                         been copied into its parent
                         */
                        (*ss_parent)->right.reset();
                    }  // end inner IF
                
                // otherwise, if the symmetric successor is the left child of its parent
                } else{
                    
                    // if the symmetric successor itself has a right child
                    if ((*ss)->right){
                        /*
                         replace symmetric successor with its own right child. Its value has
                         already been copied into the node that it is actually replacing.
                         */
                        (*ss_parent)->left = std::move((*ss)->right);
                    // otherwise, if the symmetric successor itself has no right child
                    } else{
                        /*
                        then simply remove symmetric successor, since its value has already
                        been copied into its parent
                        */
                        (*ss_parent)->left.reset();
                    }  // end inner IF
                    
                }  // end outer IF
            }  // end outermost IF for all 3 cases
            
            // decrement number of nodes and return true
            --n_nodes;
            return true;
            
        /*
         otherwise, if node with correct value has not been found,
         continue searching for it by walking down left or right
         */
        } else if (v < (*node)->value){
            node = &(*node)->left;
        } else{
            node = &(*node)->right;
        }  // end IF for comparing with values of nodes
        
    } // end WHILE
    
    /*
     if we reach a leaf and the correct value has not been found,
     then it does not exist in the BST. Don't remove any node. Instead, return false.
     */
    return false;
    
}  // end of remove function


/**
 * Recursive function to traverse sub-tree rooted at input node in order
 *
 * @param node reference of pointer to input node
 */
template <typename T>
void dsa::BSTree<T>::traverse_in_order(std::unique_ptr<dsa::BSTNode<T>>& node){
    if (node){
        traverse_in_order(node->left);
        node->print_value(std::cout);
        traverse_in_order(node->right);
    }
}  // end of traverse_in_order function


/**
 * Recursive function to traverse whole BST in order
 */
template <typename T>
void dsa::BSTree<T>::traverse_in_order(){
    traverse_in_order(root);
    std::cout << "\n";
}  // end of overloaded traverse_in_order function


/**
 * Return pointer to pointer of node with minimum value in sub-tree rooted at input node
 *
 * @param node reference of pointer to input node
 * @return pointer to pointer of minimum node in sub-tree
 */
template <typename T>
std::unique_ptr<dsa::BSTNode<T>>* dsa::BSTree<T>::min_node(std::unique_ptr<dsa::BSTNode<T>>& node){
    // start at input node
    std::unique_ptr<dsa::BSTNode<T>>* walk = &node;
    
    // whilst current node has a left child, keep walking left
    while ((*walk)->left){
        walk = &(*walk)->left;
    }
    return walk;
}  // end of min_node function


/**
 * Return pointer to pointer of symmetric successor of input node
 * (i.e. node with minimum value in sub-tree rooted at right child of input node)
 *
 * @param node reference of pointer to input node
 * @return pointer to pointer of symmetric successor
 */
template <typename T>
std::unique_ptr<dsa::BSTNode<T>>* dsa::BSTree<T>::symm_succ(std::unique_ptr<dsa::BSTNode<T>>& node){
    return min_node(node->right);
}  // end of symm_succ function


/**
 * Return pointer to pointer of parent of node with given value
 *
 * @param v value of datatype T
 * @return pointer to pointer of parent
 */
template <typename T>
std::unique_ptr<dsa::BSTNode<T>>* dsa::BSTree<T>::getParent(const T v){
    // start walking at root
    std::unique_ptr<dsa::BSTNode<T>>* parent = &root;
    
    // while parent exists
    while (*parent){
        // if value is found, return its parent
        if ((*parent)->left && v == (*parent)->left->value){
            return parent;
        }
        if ((*parent)->right && v == (*parent)->right->value){
            return parent;
        }
        
        // otherwise, continue searching for value by walking down left or right
        if (v < (*parent)->value){
            parent = &(*parent)->left;
        } else if (v > (*parent)->value){
            parent = &(*parent)->right;
        
        // if value cannot be found, return nullptr
        } else{
            return nullptr;
        }
    }
    
    // if value cannot be found, return nullptr
    return nullptr;
    
}  // end of getParent function


/**
 * helper function for indicating level of nodes when printing
 *
 * @param os output stream
 * @param h height of current node
 * @return output stream
 */
template <typename T>
std::ostream& dsa::BSTree<T>::spaces(std::ostream& os, const int h){
    for (int i = 0; i < h; ++i){
        os << "--";
    }
    os << " ";
    return os;
}  // end of spaces function


/**
 * Vertically print sub-tree rooted at given node
 *
 * @param os output stream
 * @param node reference of pointer to input node
 * @param h height of current node
 * @return output stream
 */
template <typename T>
std::ostream& dsa::BSTree<T>::print(std::ostream& os, std::unique_ptr<dsa::BSTNode<T>>& node, const int h){
    if (node){
        print(os, node->right, h+1);
        spaces(os, h);
        os << node->value << "\n";
        print(os, node->left, h+1);
    }
    return os;
}  // end of print function


/**
 * Vertically print entire BST
 *
 * @param os output stream
 * @return output stream
 */
template <typename T>
std::ostream& dsa::BSTree<T>::print(std::ostream& os){
    return print(os, root, 0);
}


/**
 * Return total number of nodes in BST
 *
 * @return number of nodes
 */
template <typename T>
int dsa::BSTree<T>::get_n_nodes(){
    assert(n_nodes >= 0);
    return n_nodes;
}


/**
 * Simple removal of all nodes from BST
 */
template <typename T>
void dsa::BSTree<T>::clear(){
    root.reset();
    n_nodes = 0;
}


// explicit template instantiations
template class dsa::BSTree<int>;
template class dsa::BSTree<short>;
template class dsa::BSTree<long>;
template class dsa::BSTree<long long>;
template class dsa::BSTree<float>;
template class dsa::BSTree<double>;
template class dsa::BSTree<std::string>;
template class dsa::BSTree<char>;
