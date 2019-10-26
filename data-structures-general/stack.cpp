/**
 * Definition of Stack object.
 */

#ifndef STACK_H
#include "stack.hpp"
#endif


/**
 * Default constructor for empty Stack.
 *
 * @return empty Stack
 */
template<typename T>
dsa::Stack<T>::Stack(): top(0), n_nodes(0){}


/**
 * Constructor for Stack containing a single Node to be created for storing value of datatype T
 *
 * @param v value of datatype T for creating new Node object at top of Stack to be created
 * @return Stack with a single Node
 */
template<typename T>
dsa::Stack<T>::Stack(T v): top(std::make_shared<Node<T>>(v)), n_nodes(1){}


/**
 * Create new Node storing value of datatype T.
 * Add said Node to top of Stack.
 *
 * @param v ivalue of datatype T for creating new Node to be pushed onto Stack
 */
template<typename T>
void dsa::Stack<T>::push(T v){
    std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(v, top);
    top = node;
    ++n_nodes;
}  // end of push function


/**
 * Remove Node from top of Stack. Delete Node.
 */
template<typename T>
void dsa::Stack<T>::pop(){
    assert(!isEmpty() && "Error: pop() failed because stack is empty.");
    std::shared_ptr<Node<T>> node = top;
    top = top->next;
    --n_nodes;
}  // end of pop function


/**
 * Return value of datatype T stored in Node at the top without removing it from the Stack.
 *
 * @return value of datatype T stored in top Node of Stack
 */
template<typename T>
T dsa::Stack<T>::peek(){
    assert(!isEmpty() && "Error: peek() failed because stack is empty.");
    return top->value;
}  // end of peek function


/**
 * Return total number of Nodes in Stack.
 *
 * @return number of Nodes in Stack
 */
template<typename T>
unsigned int dsa::Stack<T>::size(){
    return n_nodes;
}  // end of size function


/**
 * If true, Stack contains 0 Nodes. If false, Stack contains Nodes.
 *
 * @return boolean value for whether stack is empty
 */
template<typename T>
bool dsa::Stack<T>::isEmpty(){
    return !top;  // return top == 0
}  // end of isEmpty function


/**
 * Print the value stored in all Nodes to standard output in the correct order.
 */
template<typename T>
void dsa::Stack<T>::print(){
    std::cout << "[ ";
    std::shared_ptr<Node<T>> node = top;
    while (node){                             // while node != 0
        std::cout << node->value;
        if (node->next) std::cout << " -> ";  // if node->next != 0
        node = node->next;
    }
    std::cout << " ]\n";
}  // end of print function


/**
 * Remove all Nodes from Stack. Delete all Nodes.
 */
template<typename T>
void dsa::Stack<T>::clear(){
    while (!isEmpty()){
        pop();
    }
}  // end of clear function


/**
 * Destructor
 */
template<typename T>
dsa::Stack<T>::~Stack(){
    clear();
}  // end of destructor


// explicit template instantiations
template class dsa::Stack<int>;
