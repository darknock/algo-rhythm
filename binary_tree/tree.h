#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <functional>
#include <queue>

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

    ~Tree<T>()
    {
        delete root_;
    }

    class Node;

    Tree<T>& operator<<(T value) { insert(value); return *this; }

    bool insert(T value) {
        return insert(node(value));
    }

    bool insert(Node *node) {
        return insert_internal(node, root_);
    }

    bool remove(Node *node) {
        return remove_internal(node);
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
        Node(T value) : value_(value) {}
        virtual ~Node() { delete left_; delete right_; }
        operator T()                        { return value_; }
        virtual Node* left() const          { return left_; }
        virtual void set_left(Node *node)   { left_ = node; }
        virtual Node* right() const         { return right_; }
        virtual void set_right(Node *node)  { right_ = node; }

    protected:
        Node* left_ = 0;
        Node* right_ = 0;
        T value_;
    };

private:
    Node* node(T value) { return new Node(value); }

protected:
    virtual bool insert_internal(Node *node, Node *parent) = 0;
    virtual bool remove_internal(Node *node) = 0;

    void traverse_pre_order(Node *current, const std::function <void(T)> &f) {
        if (0 != current) {
            f(*current);
            traverse_pre_order(current->left(), f);
            traverse_pre_order(current->right(), f);
        }
    }

    void traverse_in_order(Node *current, const std::function <void(T)> &f) {
        if (0 != current) {
            traverse_in_order(current->left(), f);
            f(*current);
            traverse_in_order(current->right(), f);
        }
    }

    void traverse_post_order(Node *current, const std::function <void(T)> &f) {
        if (0 != current) {
            traverse_post_order(current->left(), f);
            traverse_post_order(current->right(), f);
            f(*current);
        }
    }

    void traverse_level_order(Node *current, const std::function <void(T)> &f) {
        std::queue<Node *> queue;
        queue.push(current);
        while (!queue.empty()) {
            Node *node = queue.front();
            queue.pop();
            f(*node);
            if (0 != node->left())
                queue.push(node->left());
            if (0 != node->right())
                queue.push(node->right());
        }
    }

    Node *root_ = 0;
};

#endif // _BINARY_TREE_
