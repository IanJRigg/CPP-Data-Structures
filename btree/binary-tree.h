#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <node.h>
#include <iostream>

namespace Binary
{
    template <typename T>
    class Tree
    {
        public:
            Tree()
            {
                std::cout << "Hello from the Binary Tree Constructor!" << std::endl;
            }

            ~Tree()
            {
                std::cout << "Hello from the Binary Tree Destructor!"  << std::endl;
            }

        private:
            Node<T> root;

    };
};
#endif