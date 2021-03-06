#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_
 
#include "tree.h"

#include <iostream>

template<typename T>
class BinarySearchTree : public Tree<T>
{
protected:
   bool insert_internal(typename Tree<T>::Node *node, typename Tree<T>::Node *parent) override {
       if (0 == parent) {
           if (0 == this->root_) {
               this->root_ = node;
               //std::cout << "Inserting as root\n";
               return true;
           } else {
               std::cerr << "Improper use of " << __func__ << std::endl;
               return false;
           }
       }
       typename Tree<T>::Node *new_parent = 0;
       if (*node < *parent)
           if (0 == parent->left()) {
               parent->set_left(node);
               //std::cout << *node << " Inserting as left child of " << *parent << std::endl;
               return true;
           } else
               new_parent = parent->left();
       else if (*node > *parent)
           if (0 == parent->right()) {
               parent->set_right(node);
               //std::cout << *node << " Inserting as right child of " << *parent << std::endl;
               return true;
           } else
               new_parent = parent->right();
       else {
           std::cerr << "This implementation does not allow duplicate keys\n";
           return false;
       }

       return insert_internal(node, new_parent);
   }

   bool remove_internal(typename Tree<T>::Node */*node*/) override  {
       #warning "remove_internal Not implemented"
       return false;
   }
};

#endif // _BINARY_SEARCH_TREE_H_

