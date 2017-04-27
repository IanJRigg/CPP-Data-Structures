#ifndef _BINARY_ITERATOR_H_
#define _BINARY_ITERATOR_H_

namespace Binary
{
    template<typename K, typename V>
    class Iterator
    {
        typedef K   key_type;
        typedef V   mapped_type;
        typedef std::pair<key_type, mapped_type> value_type;

        typedef       value_type*  pointer;
        typedef const value_type*  const_pointer;
        typedef       value_type&  reference;
        typedef const value_type&  const_reference;
        typedef size_t             size_type;
        typedef ptrdiff_t          difference_type;

        typedef std::shared_ptr<Node<key_type, mapped_type>> node_pointer;
        typedef Iterator<key_type, mapped_type>    self_type;

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
            Iterator(const node_pointer node) :
                ptr(node)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~Iterator()
            Arguments:   None
            Returns:     Nothing
            Description: Destructor
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
            Arguments:   const Iterator<K,V> reference
            Returns:     True if the pointers are the identical, otherwise false
            Description: Compares the current iterator's pointer against the
                           provided iterator.
            ------------------------------------------------------------------*/
            bool operator==(const self_type& other)
            {
                return (ptr == other.ptr);
            }


            /*------------------------------------------------------------------
            Function:    operator==()
            Arguments:   const Iterator<K,V> reference
            Returns:     True if the pointeres are different, otherwise false
            Description: Compares the current iterator's pointer against the
                           provided iterator.
            ------------------------------------------------------------------*/
            bool operator!=(const self_type& other)
            {
                return !(operator==(other));
            }

            /*------------------------------------------------------------------
            Function:    operator++()
            Arguments:   None
            Returns:     Reference to the this object
            Description: Pre-increment operator. Iterates over the tree via an
                           in-order traversal.
            ------------------------------------------------------------------*/
            self_type& operator++()
            {
                if(ptr == nullptr)
                {
                    return *this;
                }

                node_pointer node = ptr;

                if(node->right == nullptr)
                {
                    // Advance to the parent of the first left child
                    node_pointer prev = node;

                    while(node->left != prev)
                    {
                        prev = node;
                        node = node->head;

                        if(node == nullptr)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    // Advance to the right child
                    node = node->right;

                    // Follow the left node until there are none
                    while(node->left != nullptr)
                    {
                        node = node->left;
                    }
                }

                ptr = node;
                return *this;
            }


            /*------------------------------------------------------------------
            Function:    operator++()
            Arguments:   Integer
            Returns:     A reference to the current state of the iterator.
            Description: Post-increment operator. Iterates over the tree via an
                           in-order traversal.
            ------------------------------------------------------------------*/
            self_type operator++(int)
            {
                self_type temp(ptr);
                operator++();
                return temp;
            }


            /*------------------------------------------------------------------
            Function:    operator++()
            Arguments:   None
            Returns:     Reference to the current object
            Description: Pre-decrement operator. Iterates over the tree via a
                           reverse in-order traversal
            ------------------------------------------------------------------*/
            self_type& operator--()
            {
                if(ptr == nullptr)
                {
                    return *this;
                }

                node_pointer curr_pointer = ptr;

                if(curr_pointer->left == nullptr)
                {
                    node_pointer prev = curr_pointer;

                    // Advance to the parent of the first right child
                    while(curr_pointer->head != nullptr)
                    {
                        prev         = curr_pointer;
                        curr_pointer = curr_pointer->head;

                        if(curr_pointer->right == prev)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    // Advance to the left child
                    curr_pointer = curr_pointer->left;

                    // Follow the right nodes until there are none
                    while(curr_pointer->left != nullptr)
                    {
                        curr_pointer = curr_pointer->right;
                    }
                }

                ptr = curr_pointer;
                return *this;
            }


            /*------------------------------------------------------------------
            Function:    operator++()
            Arguments:   None
            Returns:     Reference to the current object
            Description: Post-decrement operator. Iterates over the tree via a
                           reverse in-order traversal
            ------------------------------------------------------------------*/
            self_type operator--(int)
            {
                self_type temp(ptr);
                operator--();
                return temp;
            }

        private:
            node_pointer ptr;
    };
};

#endif