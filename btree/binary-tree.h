#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <bi-node.h>
#include <iostream>
#include <stdexcept>

namespace Binary
{
    template<typename K, typename V>
    class Iterator
    {
        typedef K   key_type;
        typedef T   mapped_type;
        typedef std::pair<key_type, mapped_type> value_type;

        typedef       value_type*  pointer;
        typedef const value_type*  const_pointer;
        typedef       value_type&  reference;
        typedef const value_type&  const_reference;
        typedef size_t             size_type;
        typedef ptrdiff_t          difference_type;

        typedef std::shared_ptr<Node<value_type>> node_pointer;
        typedef Iterator<key_type, value_type>    self_type;

        public:

            /*------------------------------------------------------------------
            Function:    Iterator()
            Arguments:   None
            Returns:     Nothing
            Description: Initializes an iterator which points to null
            ------------------------------------------------------------------*/
            Iterator() :
                ptr(nullptr)
            {

            }

            /*------------------------------------------------------------------
            Function:    Iterator()
            Arguments:   Pointer to a node object
            Returns:     Nothing
            Description: Initializes an iterator which points to the object
                           pointed to by node.
            ------------------------------------------------------------------*/
            explicit
            Iterator(node_pointer node) :
                ptr(node)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~Iterator()
            Arguments:   None
            Returns:     Nothing
            Description: Empty destructor
            ------------------------------------------------------------------*/
            ~Iterator()
            {

            }


            /*------------------------------------------------------------------
            Function:    Operator*()
            Arguments:   Nothing
            Returns:     Returns a reference to a value_type pair.
            Description: Dereferences the iterator's pointer object and returns
                           the Node's value member.
            ------------------------------------------------------------------*/
            reference operator*()
            {
                return ptr->getValue();
            }


            /*------------------------------------------------------------------
            Function:    operator->()
            Arguments:   Nothing
            Returns:     Returns a pointer to a value_type pair.
            Description: Returns a pointer to the value member of the iterator's
                           node object.
            ------------------------------------------------------------------*/
            pointer operator->()
            {
                return &(operator*());
            }


            /*------------------------------------------------------------------
            Function:    operator==()
            Arguments:   const Iterator<T> reference
            Returns:     True if the pointers are the identical, otherwise false
            Description: Compares the current iterator's pointer against the
                           provided iterator.
            ------------------------------------------------------------------*/
            bool operator==(const self_type& other)
            {
                return (ptr == other.ptr)
            }


            /*------------------------------------------------------------------
            Function:    operator==()
            Arguments:   const Iterator<T> reference
            Returns:     True if the pointeres are different, otherwise false
            Description: Compares the current iterator's pointer against the
                           provided iterator.
            ------------------------------------------------------------------*/
            bool operator!=(const self_type& other)
            {
                return !(operator==());
            }

        private:
            node_pointer ptr;
    };

    template <typename K, typename V>
    class Tree
    {
        typedef K   key_type;
        typedef T   mapped_type;
        typedef std::pair<key_type, mapped_type> value_type;

        typedef       value_type*  pointer;
        typedef const value_type*  const_pointer;
        typedef       value_type&  reference;
        typedef const value_type&  const_reference;
        typedef size_t             size_type;
        typedef ptrdiff_t          difference_type;

        typedef std::shared_ptr<Node<value_type>> node_pointer;

        public:
            /*------------------------------------------------------------------
            Function:    Tree()
            Arguments:   None
            Returns:     Nothing
            Description: Basic constructor. Nulls out root.
            ------------------------------------------------------------------*/
            Tree() :
                root(nullptr)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~Tree()
            Arguments:   None
            Returns:     Nothing
            Description: Empty destructor
            ------------------------------------------------------------------*/
            ~Tree()
            {

            }


            /*------------------------------------------------------------------
            Function:    insert()
            Arguments:   Value type which contains the value to be inserted.
            Returns:     An iterator pointing to the inserted element.
            Description: Inserts the provided value into the binary tree.
            ------------------------------------------------------------------*/
            Iterator<value_type> insert(value_type value)
            {    /*
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
                return Iterator<value_type>(nullptr);
            }


            /*------------------------------------------------------------------
            Function:    clear()
            Arguments:   None
            Returns:     Nothing
            Description: Destroys the contents of the tree.
            ------------------------------------------------------------------*/
            void clear()
            {
                root = nullptr;
            }


            /*------------------------------------------------------------------
            Function:    erase()
            Arguments:   An iterator pointing to the element to be erased
            Returns:     Nothing
            Description: Removes the node with the key held in pos.
            ------------------------------------------------------------------*/
            void erase(Iterator<value_type> pos)
            {
                return;
            }


            /*------------------------------------------------------------------
            Function:    find()
            Arguments:   None
            Returns:     An iterator pointing to the value type with the
                           provided key
            Description: Empty destructor
            ------------------------------------------------------------------*/
            Iterator<value_type> find(key_type key)
            {
                node_pointer node = root;
                while(node != nullptr)
                {
                    if(key < node->getValue().second)
                    {
                        node = node.left;
                    }
                    else if(node->getValue().second > key)
                    {
                        node = node.right;
                    }
                    else
                    {
                        break;
                    }
                }

                return end();
            }


            /*------------------------------------------------------------------
            Function:    at()
            Arguments:   The key_type to be searched for
            Returns:     The mapped_type variable that corresponds to the key
            Description: Returns the value that is stored with the provided key
            ------------------------------------------------------------------*/
            mapped_type at(key_type key)
            {
                Iterator<value_type> it = find(key);
                if(it != end())
                {
                    return it.second();
                }
                else
                {
                    throw std::out_of_range;
                }
            }




            /*------------------------------------------------------------------
            Function:    size()
            Arguments:   None
            Returns:     The contents of the count member
            Description: Returns the contents of the count member
            ------------------------------------------------------------------*/
            size_type size()
            {
                return count;
            }


            /*------------------------------------------------------------------
            Function:    empty()
            Arguments:   None
            Returns:     True if the tree is empty, false if otherwise.
            Description: Checks if count is equal to zero.
            ------------------------------------------------------------------*/
            bool empty()
            {
                return count == 0UL;
            }


            /*------------------------------------------------------------------
            Function:    balance()
            Arguments:   None
            Returns:     Nothing
            Description: Dumps the tree to a list, then recreates the tree by
                           inserting the values of the list to the tree.
            ------------------------------------------------------------------*/
            void balance()
            {
                return;
            }


            /*------------------------------------------------------------------
            Function:    front()
            Arguments:   None
            Returns:     An iterator pointing to the left-most node.
            Description: Returns the front of the tree.
            ------------------------------------------------------------------*/
            Iterator<value_type> front()
            {
                return Iterator<value_type>(nullptr);
            }


            /*------------------------------------------------------------------
            Function:    end()
            Arguments:   None
            Returns:     An iterator pointing at past the end of the tree (NULL)
            Description: Returns an iterator to the past-the-end element
            ------------------------------------------------------------------*/
            Iterator<value_type> end()
            {
                return Iterator<value_type(nullptr);
            }

        private:
            node_pointer root;

            size_type count;

    };
};
#endif