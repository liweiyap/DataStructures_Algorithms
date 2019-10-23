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
dsa::Queue::Queue(): first(0), last(0), n_nodes(0){}


/**
 * Constructor for Queue containing a single Node to be created for storing integer value
 *
 * @param v integer value for creating new Node object at back of Queue that is to be created
 * @return Queue with a single Node
 */
dsa::Queue::Queue(int v): first(std::make_shared<Node>(v)), n_nodes(1){
    last = first;
}

/**
 * Create new Node storing integer value.
 * Add said Node to Queue.
 *
 * @param v integer value for creating new Node to be pushed onto Queue
 */
void dsa::Queue::enqueue(int v){
    std::shared_ptr<Node> node = std::make_shared<Node>(v);
    
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
void dsa::Queue::dequeue(){
    assert(!isEmpty() && "Error: dequeue() failed because queue is empty.");
    std::shared_ptr<Node> node = first;
    first = first->next;
    if (first == 0) last = 0;
    --n_nodes;
}  // end of dequeue function


/**
 * Return int value stored in Node at the front without removing it from the Queue.
 *
 * @return integer value stored in front Node of Queue
 */
int dsa::Queue::peek(){
    assert(!isEmpty() && "Error: peek() failed because queue is empty.");
    return first->value;
}  // end of peek function


/**
 * Return total number of Nodes in Queue.
 *
 * @return number of Nodes in Queue
 */
int dsa::Queue::size(){
    return n_nodes;
}  // end of size function


/**
 * If true, Queue  contains 0 Nodes. If false, Queue contains Nodes.
 *
 * @return boolean value for whether queue is empty
 */
bool dsa::Queue::isEmpty(){
    return !first && !last;  // return first == 0 && last == 0
}  // end of isEmpty function


/**
 * Print the value stored in all Nodes to standard output in the correct order.
 */
void dsa::Queue::print(){
    std::cout << "[ ";
    std::shared_ptr<Node> node = first;
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
void dsa::Queue::clear(){
    while (!isEmpty()){
        dequeue();
    }
}  // end of clear function


/**
 * Destructor
 */
dsa::Queue::~Queue(){
    clear();
}  // end of destructor
