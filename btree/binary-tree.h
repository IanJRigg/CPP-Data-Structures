#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <bi-node.h>
#include <iostream>

/*
   Implementation Notes:
       Duplicate Keys are not allowed.
       The supported keys must implement the comparison operators,
           otherwise the build will fail.


*/

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
                delete root;
            }

            // insert()
                /*
                    retval = false
                    if curr_node
                        if curr_node->key > key
                            if rnode
                                retval = insert(rnode, key, val)
                            else
                                rnode = new Node(key, val)
                        else if curr_node->key < key
                            if lnode
                                retval = insert(lnode, key, val)
                            else
                                lnode = new node(key, val)
                        else
                            // Duplicate!!!
                            retval = failure
                    else
                        retval = false

                    return retval
                */

            // erase()
                /*

                */

            // find()
                /*
                    if val == currnode
                        return node
                    else if rnode && val > currnode->val
                        return find(rnode)
                    else if lnode && val < currnode->val
                        return find(lnode)
                    else
                        return nullptr
                */

            // Valuest
                /*
                    In-order traversal
                        retrieve the values
                */
            // Keys
                /*
                    In-order traversal
                        retrieve the keys
                */

            // size_t size()
                /*
                    return size;
                */

            // bool empty()
                /*
                    return size == 0UL;
                */
            //

        private:

            // Balance




            Node<K, V> * root;
            size_t size;

    };
};
#endif