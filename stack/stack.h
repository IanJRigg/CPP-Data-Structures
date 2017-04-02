#include <linked-list.h>



namespace Linked
{
    template<typename T>
    class Stack
    {
        typedef       T   value_type;
        typedef       T*  pointer;
        typedef const T*  const_pointer;
        typedef       T&  reference;
        typedef const T&  const_reference;
        typedef size_t    size_type;
        typedef ptrdiff_t difference_type;

        public:
            /*------------------------------------------------------------------
            Function:    Stack()
            Arguments:   None
            Returns:     Nothing
            Description: Constructs an instance of the linked list stack.
            ------------------------------------------------------------------*/
            Stack() :
                list(),
                count(0UL)
            {

            }


            /*------------------------------------------------------------------
            Function:    Stack()
            Arguments:   None
            Returns:     Nothing
            Description: Constructs an instance of the linked list stack.
            ------------------------------------------------------------------*/
            ~Stack()
            {

            }


            /*------------------------------------------------------------------
            Function:    pop()
            Arguments:   None
            Returns:     Returns true if the last element was popped, otherwise
                           false.
            Description: Removes the element at the end of the list.
            ------------------------------------------------------------------*/
            bool pop()
            {
                return list.pop_back();
            }


            /*------------------------------------------------------------------
            Function:    push()
            Arguments:   None
            Returns:     True if the iterator returned from List::push_back()
                           does not contain the null pointer.
            Description: Constructs an instance of the linked list stack.
            ------------------------------------------------------------------*/
            bool push(value_type val)
            {
                Iterator<value_type> it = list.push_back(val);
                Iterator<value_type> null_iterator(nullptr);

                return (it != null_iterator);
            }


            /*------------------------------------------------------------------
            Function:    size()
            Arguments:   None
            Returns:     The value contained in the count memeber variable
            Description: Returns the number of elements in the stack
            ------------------------------------------------------------------*/
            size_type size()
            {
                return count;
            }


            /*------------------------------------------------------------------
            Function:    empty()
            Arguments:   None
            Returns:     True if the list is empty, otherwise false.
            Description: Checks if the size member variable is equal to 0.
            ------------------------------------------------------------------*/
            bool empty()
            {
                return (count == 0UL);
            }

        private:
            List<T> list;
            size_type count;
    };
};