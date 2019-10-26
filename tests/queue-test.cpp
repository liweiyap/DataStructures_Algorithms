/**
 * Test for queue implementation.
 */

#include "queue.hpp"

int main(){
    std::cout << "\nTesting implementation of queue...\n\n";
    
    std::cout << "Initialisation of queue q1 with single node...\n";
    dsa::Queue<int> q1(6);
    assert(q1.peek() == 6 && q1.size() == 1 && !q1.isEmpty() && "Error during initialisation with single node.");
    
    std::cout << "Enqueuing 3 nodes onto queue q1...\n";
    q1.enqueue(1); q1.enqueue(2); q1.enqueue(3);
    assert(q1.peek() == 6 && q1.size() == 4 && !q1.isEmpty() && "Error during enqueue.");
    
    std::cout << "q1 is now: "; q1.print();
    std::cout << "\n";
    
    std::cout << "Initialisation of empty queue q2...\n";
    dsa::Queue<int> q2;
    assert(q2.size() == 0 && q2.isEmpty() && "Error during initialisation of empty queue.");
    
    std::cout << "Enqueuing 2 nodes onto queue q2...\n";
    q2.enqueue(5); q2.enqueue(4);
    assert(q2.peek() == 5 && q2.size() == 2 && !q2.isEmpty() && "Error during enqueue.");
    
    std::cout << "Assigning queue q1 to queue q2...\n";
    q2 = q1;
    
    std::cout << "Dequeuing front node from queue q1...\n";
    q1.dequeue();
    assert(q1.peek() == 1 && q1.size() == 3 && !q1.isEmpty() && "Error during dequeue.");
    assert(q2.peek() == 6 && q2.size() == 4 && !q2.isEmpty() && "Error with assignment operator.");
    
    std::cout << "q1 is now: "; q1.print();
    std::cout << "\n";
    
    std::cout << "Dequeuing top node from queue q2...\n";
    q2.dequeue();
    assert(q2.peek() == 1 && q2.size() == 3 && !q2.isEmpty() && "Error during dequeue.");
    
    std::cout << "q2 is now: "; q2.print();
    std::cout << "\n";
    
    std::cout << "End of test.\n";
    
    return 0;
}  // end of main() function
