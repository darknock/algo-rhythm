#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <functional>
#include <iostream>

template<typename T>
class Tree {
public:
    enum TraverseOrder {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER,
        LEVEL_ORDER
    };

    class Node;

    void insert(Tree<T>::Node *node) {
        insert_internal(node, root_);
    }

    void remove(Tree<T>::Node *node) {
        remove_internal(node);
    }

    void traverse(const std::function <void(T)> &f, Tree<T>::TraverseOrder traverse_order) {
        #warning "treverse Not implemented"
    }

public:
    class Node {
    public:
        Node(T value) : value(value) {}
        operator T() { return value; }
        
        Node* left = 0;
        Node* right = 0;
        T value;
    };

protected:
    virtual bool insert_internal(Tree<T>::Node *node, Tree<T>::Node *parent) = 0; 
    virtual bool remove_internal(Tree<T>::Node *node) = 0;

    Node *root_ = 0;
};

#endif // _BINARY_TREE_
