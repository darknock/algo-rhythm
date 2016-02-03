#include "binarysearchtree.h"

int main(int argc, char** argv)
{
    BinarySearchTree<int> tree;
    BinarySearchTree<int>::Node *node = new BinarySearchTree<int>::Node(123);
    tree.insert(node);
    tree.traverse([](int i) { std::cout << "lambda: " << i << std::endl; }, Tree<int>::PRE_ORDER);
}

