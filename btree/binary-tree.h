#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <node.h>
#include <iostream>

namespace Binary
{
    template <typename K, typename V>
    class Tree
    {
        public:
            Tree() :
                root(NULL)
            {
                std::cout << "Hello from the Binary Tree Constructor!" << std::endl;
            }

            ~Tree()
            {
                std::cout << "Hello from the Binary Tree Destructor!"  << std::endl;
            }

            // Insert
            // Remove
            // Find
            // Balance
            // Values
            // Keys

        private:
            Node<K, V> * root;

    };
};
#endif