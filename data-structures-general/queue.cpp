/**
 * Definition of Queue object.
 */

#ifndef QUEUE_H
#include "queue.hpp"
#endif


/**
 * Default constructor for empty Queue.
 *
 * @return empty Queue
 */
template <typename T>
dsa::Queue<T>::Queue(): first(0), last(0), n_nodes(0){}


/**
 * Constructor for Queue containing a single Node to be created for storing value of datatype T
 *
 * @param v value of datatype T for creating new Node object at back of Queue that is to be created
 * @return Queue with a single Node
 */
template<typename T>
dsa::Queue<T>::Queue(T v): first(std::make_shared<Node<T>>(v)), n_nodes(1){
    last = first;
}  // end of constructor

/**
 * Create new Node storing value of datatype T.
 * Add said Node to Queue.
 *
 * @param v value of datatype T for creating new Node to be pushed onto Queue
 */
template<typename T>
void dsa::Queue<T>::enqueue(T v){
    std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(v);
    
    if (isEmpty()){
        first = node;
        last = node;
    } else{
        last->next = node;
        last = node;
    }
    
    ++n_nodes;
}  // end of enqueue function


/**
 * Remove Node from front of Queue. Delete Node.
 */
template<typename T>
void dsa::Queue<T>::dequeue(){
    assert(!isEmpty() && "Error: dequeue() failed because queue is empty.");
    std::shared_ptr<Node<T>> node = first;
    first = first->next;
    if (first == 0) last = 0;
    --n_nodes;
}  // end of dequeue function


/**
 * Return value of datatype T stored in Node at the front without removing it from the Queue.
 *
 * @return value of datatype T stored in front Node of Queue
 */
template<typename T>
T dsa::Queue<T>::peek(){
    assert(!isEmpty() && "Error: peek() failed because queue is empty.");
    return first->value;
}  // end of peek function


/**
 * Return total number of Nodes in Queue.
 *
 * @return number of Nodes in Queue
 */
template<typename T>
unsigned int dsa::Queue<T>::size(){
    return n_nodes;
}  // end of size function


/**
 * If true, Queue  contains 0 Nodes. If false, Queue contains Nodes.
 *
 * @return boolean value for whether queue is empty
 */
template<typename T>
bool dsa::Queue<T>::isEmpty(){
    return !first && !last;  // return first == 0 && last == 0
}  // end of isEmpty function


/**
 * Print the value stored in all Nodes to standard output in the correct order.
 */
template<typename T>
void dsa::Queue<T>::print(){
    std::cout << "[ ";
    std::shared_ptr<Node<T>> node = first;
    while (node){                             // while node != 0
        std::cout << node->value;
        if (node->next) std::cout << " -> ";  // if node->next != 0
        node = node->next;
    }
    std::cout << " ]\n";
}  // end of print function


/**
 * Remove all Nodes from Queue. Delete all Nodes.
 */
template<typename T>
void dsa::Queue<T>::clear(){
    while (!isEmpty()){
        dequeue();
    }
}  // end of clear function


/**
 * Destructor
 */
template<typename T>
dsa::Queue<T>::~Queue(){
    clear();
}  // end of destructor


// explicit template instantiations
template class dsa::Queue<int>;
template class dsa::Queue<unsigned int>;
