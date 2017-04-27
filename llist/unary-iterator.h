#ifndef __UNARY_ITERATOR_H__
#define __UNARY_ITERATOR_H__

namespace Linked
{
    template <typename T>
    class Iterator
    {
        typedef       T   value_type;
        typedef       T*  pointer;
        typedef const T*  const_pointer;
        typedef       T&  reference;
        typedef const T&  const_reference;
        typedef size_t    size_type;
        typedef ptrdiff_t difference_type;

        typedef std::shared_ptr<Node<value_type>> node_pointer;
        typedef Iterator<value_type>              self_type;


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
            Description: Empty destructor
            ------------------------------------------------------------------*/
            ~Iterator()
            {

            }


            /*------------------------------------------------------------------
            Function:    Operator*()
            Arguments:   Nothing
            Returns:     Returns a reference to a T object.
            Description: Dereferences the iterator's pointer object and returns
                           the Node's data member.
            ------------------------------------------------------------------*/
            reference operator*()
            {
                return ptr->getData();
            }


            /*------------------------------------------------------------------
            Function:    operator->()
            Arguments:   Nothing
            Returns:     Returns a pointer to a T object.
            Description: Returns a pointer to the data member of the iterator's
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
                return (ptr == other.ptr);
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
                return !(operator==(other));
            }


            /*------------------------------------------------------------------
            Function:    operator++()
            Arguments:   None
            Returns:     Returns a reference to an Iterator object.
            Description: Pre-increment. Advances the current pointer to the node
                           pointer which is stored in the current node's next
                           member.
            ------------------------------------------------------------------*/
            self_type& operator++()
            {
                ptr = ptr->next;
                return *this;
            }


            /*------------------------------------------------------------------
            Function:    operator++()
            Arguments:   None
            Returns:     Returns a reference to an Iterator object.
            Description: Post-increment. Advances the member pointer to the
                           node pointer which is stored in the current node's
                           next member.
            ------------------------------------------------------------------*/
            self_type  operator++(int)
            {
                self_type temp(ptr);
                operator++();
                return temp;
            }


            /*------------------------------------------------------------------
            Function:    operator--()
            Arguments:   None
            Returns:     Returns a reference to an Iterator object.
            Description: Pre-decrement. Retreats the member pointer to the
                           node pointer which is stored in the current node's
                           prev member.
            ------------------------------------------------------------------*/
            self_type& operator--()
            {
                ptr = ptr->prev;
                return *this;
            }


            /*------------------------------------------------------------------
            Function:    operator--()
            Arguments:   None
            Returns:     Returns a reference to an Iterator object.
            Description: Post-decrement. Retreats the member pointer to the
                           node pointer which is stored in the current node's
                           prev member.
            ------------------------------------------------------------------*/
            self_type  operator--(int)
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