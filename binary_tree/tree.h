#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <functional>

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

    Tree<T>& operator<<(T value) { insert(value); return *this; }

    void insert(T value) {
        insert_internal(node(value), root_);
    }

    void remove(Node *node) {
        remove_internal(node);
    }

    void traverse(const std::function <void(T)> &f, TraverseOrder traverse_order) {
        switch (traverse_order) {
        case PRE_ORDER:
            traverse_pre_order(root_, f);
            break;
        case IN_ORDER:
            traverse_in_order(root_, f);
            break;
        case POST_ORDER:
            traverse_post_order(root_, f);
            break;
        case LEVEL_ORDER:
            traverse_level_order(root_, f);
            break;
        default:
            break;
        }
    }

    void paint() {

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
    virtual Node* node(T value) { return new Node(value); }
    virtual bool insert_internal(Node *node, Node *parent) = 0;
    virtual bool remove_internal(Node *node) = 0;

    void traverse_pre_order(Node *current, const std::function <void(T)> &f) {
        if (0 != current) {
            f(*current);
            traverse_pre_order(current->left, f);
            traverse_pre_order(current->right, f);
        }
    }

    void traverse_in_order(Node *current, const std::function <void(T)> &f) {
        if (0 != current) {
            traverse_in_order(current->left, f);
            f(*current);
            traverse_in_order(current->right, f);
        }
    }

    void traverse_post_order(Node *current, const std::function <void(T)> &f) {
        if (0 != current) {
            traverse_post_order(current->left, f);
            traverse_post_order(current->right, f);
            f(*current);
        }
    }

    void traverse_level_order(Node *current, const std::function <void(T)> &f) {
        int level = 0;
        std::queue<Node *> queue;
    }

    Node *root_ = 0;
};

#endif // _BINARY_TREE_
