#include <iostream>
#include <memory>  // unique_ptr
#include <utility>  // move
#include <ostream>

struct BSTNode{
    BSTNode(int v): value(v){}
    
    BSTNode(int v, std::unique_ptr<BSTNode> l, std::unique_ptr<BSTNode> r): value(v), left(std::move(l)), right(std::move(r)){}
    
    std::ostream& print_value(std::ostream& os){
        os << value << " ";
        return os;
    }
    
    ~BSTNode(){}
    
    int value;
    std::unique_ptr<BSTNode> left;
    std::unique_ptr<BSTNode> right;
};

class BSTree{
public:
    BSTree(): n_nodes(0){}
    
    BSTree(int v): root(std::make_unique<BSTNode>(v)), n_nodes(1){}
    
    BSTNode* search(int v){
        BSTNode* node = root.get();
        while (node && v != node->value){  // while (node != 0)
            if (v < node->value){
                node = node->left.get();
            } else{
                node = node->right.get();
            }
        }
        return node;
    }
    
    void insert(int v){
        std::unique_ptr<BSTNode>* node = &root;
        while (*node){
            if (v < (*node)->value){
                node = &(*node)->left;
            } else{
                node = &(*node)->right;
            }
        }
        *node = std::make_unique<BSTNode>(v);
    }
    
    void traverse_in_order(std::unique_ptr<BSTNode>& node){
        if (node){
            traverse_in_order(node->left);
            node->print_value(std::cout);
            traverse_in_order(node->right);
        }
    }
    
    void traverse_in_order(){
        traverse_in_order(root);
        std::cout << "\n";
    }
    
    std::ostream& spaces(std::ostream& os, int h){
        for (int i = 0; i < h; ++i){
            os << "--";
        }
        os << " ";
        return os;
    }
    
    std::ostream& print(std::ostream& os, std::unique_ptr<BSTNode>& node, int h){
        if (node){
            print(os, node->right, h+1);
            spaces(os, h);
            os << node->value << "\n";
            print(os, node->left, h+1);
        }
        return os;
    }
    
    std::ostream& print(std::ostream& os){
        return print(os, root, 0);
    }
    
private:
    std::unique_ptr<BSTNode> root;
    unsigned int n_nodes;
};

int main(){
    
    BSTree test;
    test.insert(5);
    test.insert(6);
    test.insert(4);
    test.traverse_in_order();
    auto node = test.search(6);
    node->print_value(std::cout);
    std::cout << "\n";
    test.traverse_in_order();
    test.print(std::cout);
    
    
    return 0;
}
