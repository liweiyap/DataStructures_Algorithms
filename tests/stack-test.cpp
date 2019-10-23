/**
 * Test for stack implementation.
 */

#include "stack.hpp"

int main(){
    std::cout << "\nTesting implementation of stack...\n\n";
    
    std::cout << "Initialisation of stack s1 with single node...\n";
    Stack s1(6);
    assert(s1.peek() == 6 && s1.size() == 1 && !s1.isEmpty() && "Error during initialisation with single node.");
    
    std::cout << "Pushing 3 nodes onto stack s1...\n";
    s1.push(1); s1.push(2); s1.push(3);
    assert(s1.peek() == 3 && s1.size() == 4 && !s1.isEmpty() && "Error during push.");
    
    std::cout << "s1 is now: "; s1.print();
    std::cout << "\n";
    
    std::cout << "Initialisation of empty stack s2...\n";
    Stack s2;
    assert(s2.size() == 0 && s2.isEmpty() && "Error during initialisation of empty stack.");
    
    std::cout << "Pushing 2 nodes onto stack s2...\n";
    s2.push(5); s2.push(4);
    assert(s2.peek() == 4 && s2.size() == 2 && !s2.isEmpty() && "Error during push.");
    
    std::cout << "Assigning stack s1 to stack s2...\n";
    s2 = s1;
    
    std::cout << "Popping top node from stack s1...\n";
    s1.pop();
    assert(s1.peek() == 2 && s1.size() == 3 && !s1.isEmpty() && "Error during pop.");
    assert(s2.peek() == 3 && s2.size() == 4 && !s2.isEmpty() && "Error with assignment operator.");
    
    std::cout << "s1 is now: "; s1.print();
    std::cout << "\n";
    
    std::cout << "Popping top node from stack s2...\n";
    s2.pop();
    assert(s2.peek() == 2 && s1.size() == 3 && !s1.isEmpty() && "Error during pop.");
    
    std::cout << "s2 is now: "; s2.print();
    std::cout << "\n";
    
    return 0;
}  // end of main() function
