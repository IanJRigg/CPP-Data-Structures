#include <linked-list.h>

namespace Linked
{
    template<typename T>
    class Queue
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
            Function:    Queue()
            Arguments:   None
            Returns:     Nothing
            Description: Constructs an instance of the Linked List Queue.
            ------------------------------------------------------------------*/
            Queue() :
                list(),
                count(0UL)
            {

            }

            /*------------------------------------------------------------------
            Function:    ~Queue()
            Arguments:   None
            Returns:     Nothing
            Description: Destructs an instance of the Linked List Queue
            ------------------------------------------------------------------*/
            ~Queue()
            {

            }


            /*------------------------------------------------------------------
            Function:    dequeue()
            Arguments:   None
            Returns:     True if the first element was dequeued.
            Description: Removes the element at the front of the queue.
            ------------------------------------------------------------------*/
            bool dequeue()
            {
                return list.dequeue();
            }


            /*------------------------------------------------------------------
            Function:    enqueue()
            Arguments:   Value to be inserted in the table.
            Returns:     True if the inserted value is equal to provided value.
            Description: Inserts the provided value at the front of the list
            ------------------------------------------------------------------*/
            bool enqueue(value_type val)
            {
                Iterator<value_type> it = list.enqueue(val);
                Iterator<value_type> null_iterator(nullptr);

                return (it != null_iterator);
            }


            /*------------------------------------------------------------------
            Function:    size()
            Arguments:   None
            Returns:     The value contained in the count memeber variable
            Description: Returns the number of elements in the queue
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
                return count == 0UL;
            }

        private:
            List<T> list;
            size_type count;
    };
};