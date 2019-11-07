/**
 * Test for BST implementation.
 */

#include "binary-search-tree.hpp"
#include <array>

int main(){
    // ////////////////////////////////////////////////////////////////////////////
    // Test 1
    // ////////////////////////////////////////////////////////////////////////////
    
    std::cout << "\n------------------------\n         Test 1         \n------------------------\n";
    std::cout << "\nCreating tree with nodes in the following order: \n";
    std::array<int, 11> intArray1 = {4,2,6,1,3,5,9,7,8,11,10};
    dsa::BSTree<int> intTree1(intArray1[0]);
    for (auto it = intArray1.begin()+1; it != intArray1.end(); ++it){
        std::cout << *it << ",";
        intTree1.insert(*it);
    }
    std::cout << "\n\nTree with " << intTree1.get_n_nodes() << " nodes and height " << intTree1.height() << " created.\n\n";
    std::cout << "In-order Traversal:\n";
    intTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree1.print(std::cout);
    std::cout << "\nSearching for value 12 in tree:\n";
    if (intTree1.search(12)){
        std::cout << "Value found.\n";
    } else{
        std::cout << "Value not found.\n";
    }
    std::cout << "\nSearching for value 9 in tree:\n";
    if (intTree1.search(9)){
        std::cout << "Value found.\n";
    } else{
        std::cout << "Value not found.\n";
    }
    std::cout << "\nRemoving value 4 from tree:\n";
    intTree1.remove(4);
    std::cout << "Tree now has " << intTree1.get_n_nodes() << " nodes and height " << intTree1.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree1.print(std::cout);
    std::cout << "\nRemoving value 9 from tree:\n";
    intTree1.remove(9);
    std::cout << "Tree now has " << intTree1.get_n_nodes() << " nodes and height " << intTree1.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree1.print(std::cout);
    std::cout << "\nRemoving value 1 from tree:\n";
    intTree1.remove(1);
    std::cout << "Tree now has " << intTree1.get_n_nodes() << " nodes and height " << intTree1.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree1.print(std::cout);
    std::cout << "\nInserting value 4 back into tree:\n";
    intTree1.insert(4);
    std::cout << "Tree now has " << intTree1.get_n_nodes() << " nodes and height " << intTree1.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree1.print(std::cout);
    std::cout << "\nInserting value 9 back into tree:\n";
    intTree1.insert(9);
    std::cout << "Tree now has " << intTree1.get_n_nodes() << " nodes and height " << intTree1.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree1.print(std::cout);
    
    // ////////////////////////////////////////////////////////////////////////////
    // Test 2
    // ////////////////////////////////////////////////////////////////////////////
    
    std::cout << "\n------------------------\n         Test 2         \n------------------------\n";
    std::cout << "\nCreating tree with nodes in the following order: \n";
    std::array<int, 31> intArray2 = {16,24,8,4,20,28,12,2,6,10,14,18,22,26,30,31,29,27,25,23,21,19,17,15,13,11,9,7,5,3,1};
    dsa::BSTree<int> intTree2;
    for (auto it = intArray2.begin(); it != intArray2.end(); ++it){
        std::cout << *it << ",";
        intTree2.insert(*it);
    }
    std::cout << "\n\nTree with " << intTree2.get_n_nodes() << " nodes and height " << intTree2.height() << " created.\n\n";
    std::cout << "In-order Traversal:\n";
    intTree2.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree2.print(std::cout);
    std::cout << "\nRemoving value 6 from tree:\n";
    intTree2.remove(6);
    std::cout << "Tree now has " << intTree2.get_n_nodes() << " nodes and height " << intTree2.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree2.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree2.print(std::cout);
    std::cout << "\nRemoving values 25,26,27 from tree:\n";
    intTree2.remove(25);
    intTree2.remove(26);
    intTree2.remove(27);
    std::cout << "Tree now has " << intTree2.get_n_nodes() << " nodes and height " << intTree2.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree2.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree2.print(std::cout);
    std::cout << "\nRemoving value 28 from tree:\n";
    intTree2.remove(28);
    std::cout << "Tree now has " << intTree2.get_n_nodes() << " nodes and height " << intTree2.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    intTree2.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    intTree2.print(std::cout);
    
    // ////////////////////////////////////////////////////////////////////////////
    // Test 3
    // ////////////////////////////////////////////////////////////////////////////
    
    std::cout << "\n------------------------\n         Test 3         \n------------------------\n";
    std::cout << "\nCreating tree with nodes in the following order: \n";
    std::array<std::string, 7> strArray1 = {"epsilon","gamma","beta","delta","alpha","mu","kappa"};
    dsa::BSTree<std::string> strTree1;
    for (auto it = strArray1.begin(); it != strArray1.end(); ++it){
        std::cout << *it << ",";
        strTree1.insert(*it);
    }
    std::cout << "\n\nTree with " << strTree1.get_n_nodes() << " nodes and height " << strTree1.height() << " created.\n\n";
    std::cout << "In-order Traversal:\n";
    strTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    strTree1.print(std::cout);
    std::cout << "\nSearching for value omega in tree:\n";
    if (strTree1.search("omega")){
        std::cout << "Value found.\n";
    } else{
        std::cout << "Value not found.\n";
    }
    std::cout << "\nSearching for value mu in tree:\n";
    if (strTree1.search("mu")){
        std::cout << "Value found.\n";
    } else{
        std::cout << "Value not found.\n";
    }
    std::cout << "\nRemoving value beta from tree:\n";
    strTree1.remove("beta");
    std::cout << "Tree now has " << strTree1.get_n_nodes() << " nodes and height " << strTree1.height() << ".\n\n";
    std::cout << "In-order Traversal:\n";
    strTree1.traverse_in_order();
    std::cout << "\nPrinting overall tree structure:\n";
    strTree1.print(std::cout);
    std::cout << "\nRemoving all values from tree:\n";
    strTree1.clear();
    std::cout << "Tree now has " << strTree1.get_n_nodes() << " nodes and height " << strTree1.height() << ".\n\n";
    std::cout << "In-order Traversal doesn't yield anything:\n";
    strTree1.traverse_in_order();
    std::cout << "Printing doesn't yield anything:\n\n";
    strTree1.print(std::cout);
    
    std::cout << "End of tests.\n";
    
    return 0;
}
