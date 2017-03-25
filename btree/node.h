#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

namespace Binary
{
    template<typename K, typename V>
    class Node
    {
        public:
            Node(K _k, V _v) :
                key(_k),
                value(_v),
                lNode(),
                rNode()
            {
                std::cout << "In the Node constructor" << std::endl;
            }

            ~Node()
            {
                std::cout << "In the Node destructor" << std::endl;

                delete lNode;
                delete rNode;
            }

            void setLeftNode(Node<K, V> node)
            {
                delete lNode;
                lNode = node;
            }

            void setRightNode(Node<K, V> node)
            {
                delete rNode;
                rNode = node;
            }

        private:
            K key;
            V value;

            Node<K, V> * lNode;
            Node<K, V> * rNode;

    };
};


#endif