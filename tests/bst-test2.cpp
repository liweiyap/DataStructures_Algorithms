#include <iostream>  // cerr
#include <memory>  // unique_ptr
#include <utility>  // move
#include <ostream>
#include <cassert>
#include <string>

template <typename T>
struct BSTNode{
    BSTNode(T v): value(v){
        ++n_nodes;
    }
    
    BSTNode(T v, std::unique_ptr<BSTNode<T>> l, std::unique_ptr<BSTNode<T>> r): value(v), left(std::move(l)), right(std::move(r)){
        ++n_nodes;
    }
    
    std::ostream& print_value(std::ostream& os){
        os << value << " ";
        return os;
    }
    
    static int n_nodes;
    
    ~BSTNode(){
        --n_nodes;
    }
    
    T value;
    std::unique_ptr<BSTNode<T>> left;
    std::unique_ptr<BSTNode<T>> right;
};

template <typename T>
int BSTNode<T>::n_nodes = 0;

template <typename T>
class BSTree{
public:
    BSTree(){}
    
    BSTree(const T v): root(std::make_unique<BSTNode<T>>(v)){}
    
    bool search(const T v){
        BSTNode<T>* node = root.get();
        while (node && v != node->value){  // while (node != 0)
            if (v < node->value){
                node = node->left.get();
            } else{
                node = node->right.get();
            }
        }
        if (node) return true;
        return false;
    }
    
    bool insert(const T v){
        int old_node_count = BSTNode<T>::n_nodes;
        std::unique_ptr<BSTNode<T>>* node = &root;
        while (*node){
            if (v == (*node)->value){
                return false;
            }
            if (v < (*node)->value){
                node = &(*node)->left;
            } else{
                node = &(*node)->right;
            }
        }
        *node = std::make_unique<BSTNode<T>>(v);
        int new_node_count = BSTNode<T>::n_nodes;
        assert(new_node_count == old_node_count + 1);
        return true;
    }
    
    std::unique_ptr<BSTNode<T>>* min_node(std::unique_ptr<BSTNode<T>>& node){
        std::unique_ptr<BSTNode<T>>* walk = &node;
        while ((*walk)->left){
            walk = &(*walk)->left;
        }
        return walk;
    }
    
    std::unique_ptr<BSTNode<T>>* symm_succ(std::unique_ptr<BSTNode<T>>& node){
        return min_node(node->right);
    }
    
    bool remove(const T v){
        int old_node_count = BSTNode<T>::n_nodes;
        int new_node_count;
        std::unique_ptr<BSTNode<T>>* node = &root;
        while (*node){
            if (v == (*node)->value){
                if (!(*node)->left){
                    *node = std::move((*node)->right);
                } else if (!(*node)->right){
                    *node = std::move((*node)->left);
                } else{
                    std::unique_ptr<BSTNode<T>>* ss = symm_succ(*node);
                    std::unique_ptr<BSTNode<T>>* ss_parent = getParent((*ss)->value);
                    (*node)->value = (*ss)->value;
                    if ((*ss_parent)->right && (*ss_parent)->right->value == (*ss)->value){
                        if ((*ss)->right){
                            (*ss_parent)->right = std::move((*ss)->right);
                        } else{
                            (*ss_parent)->right.reset();
                        }
                    } else{
                        if ((*ss)->right){
                            (*ss_parent)->left = std::move((*ss)->right);
                        } else{
                            (*ss_parent)->left.reset();
                        }
                    }
                }
                new_node_count = BSTNode<T>::n_nodes;
                assert(new_node_count == old_node_count - 1);
                return true;
            } else if (v < (*node)->value){
                node = &(*node)->left;
            } else{
                node = &(*node)->right;
            }
        }
        new_node_count = BSTNode<T>::n_nodes;
        assert(new_node_count == old_node_count);
        return false;
    }
    
    void traverse_in_order(std::unique_ptr<BSTNode<T>>& node){
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
    
    std::unique_ptr<BSTNode<T>>* getParent(const T v){
        std::unique_ptr<BSTNode<T>>* parent = &root;
        while (*parent){
            if ((*parent)->left && v == (*parent)->left->value){
                return parent;
            }
            if ((*parent)->right && v == (*parent)->right->value){
                return parent;
            }
            if (v < (*parent)->value){
                parent = &(*parent)->left;
            } else if (v > (*parent)->value){
                parent = &(*parent)->right;
            } else{
                return nullptr;
            }
        }
        return nullptr;
    }
    
    std::ostream& spaces(std::ostream& os, const int h){
        for (int i = 0; i < h; ++i){
            os << "--";
        }
        os << " ";
        return os;
    }
    
    std::ostream& print(std::ostream& os, std::unique_ptr<BSTNode<T>>& node, const int h){
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
    std::unique_ptr<BSTNode<T>> root;
};

int main(){
//    BSTree<int> test;
    BSTree<std::string> test;
//    test.insert(16);
//    test.insert(24);
//    test.insert(8);
//    test.insert(4);
//    test.insert(20);
//    test.insert(28);
//    test.insert(12);
//    test.insert(2);
//    test.insert(6);
//    test.insert(10);
//    test.insert(14);
//    test.insert(18);
//    test.insert(22);
//    test.insert(26);
//    test.insert(30);
//    test.insert(31);
//    test.insert(29);
//    test.insert(27);
//    test.insert(25);
//    test.insert(23);
//    test.insert(21);
//    test.insert(19);
//    test.insert(17);
//    test.insert(15);
//    test.insert(13);
//    test.insert(11);
//    test.insert(9);
//    test.insert(7);
//    test.insert(5);
//    test.insert(3);
//    test.insert(1);
    
//    test.insert(4);
//    test.insert(2);
//    test.insert(6);
//    test.insert(1);
//    test.insert(3);
//    test.insert(5);
//    test.insert(9);
//    test.insert(7);
//    test.insert(8);
//    test.insert(11);
//    test.insert(10);
    
    test.insert("epsilon");
    test.insert("gamma");
    test.insert("beta");
    test.insert("delta");
    test.insert("alpha");
    test.insert("mu");
    test.insert("kappa");
    
    test.traverse_in_order();
    std::cout << test.search("zeta") << "\n";
    std::cout << test.search("kappa") << "\n";
    test.traverse_in_order();
    test.print(std::cout);
    std::cout << BSTNode<std::string>::n_nodes << "\n";
//    for (int i = 0; i <= 12; ++i){
//        if (!test.getParent(i)){
//            std::cout << "parent of " << i << " is not found\n";
//        } else if (*test.getParent(i)){
//            std::cout << "parent of " << i << " is " << (*test.getParent(i))->value << "\n";
//        }
//    }
    std::cout << test.remove("beta") << "\n";
    test.traverse_in_order();
    test.print(std::cout);
    std::cout << BSTNode<std::string>::n_nodes << "\n";
    
    return 0;
}
