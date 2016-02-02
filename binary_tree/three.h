#ifndef _BINARY_TREE_
#define _BINARY_TREE_

class Node {
public:
    bool is_child_of(const Node *const node) const { return node == parent; }
    bool is_root() const { return 0 == parent; }
    bool is_leaf() const { return 0 == left && 0 == right; }

    Node *parent = 0;
    Node *left   = 0;
    Node *right  = 0;
};

class Tree {
public:
    void insert(Node *node, Node *parent) {
        if (node->is_leaf
    }

private:
    Node *root;
};

#endif // _BINARY_TREE_

