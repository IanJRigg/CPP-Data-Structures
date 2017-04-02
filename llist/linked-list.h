#ifndef _LLIST_H_
#define _LLIST_H_

// STL Headers
#include <iostream>

// Project Headers
#include <uni-node.h>

/*
    Doubly Linked List
    STL types and other notes adapted from:
        https://accu.org/index.php/journals/389
*/

namespace Linked
{
    // TODO: Implement a const iterator
    template <typename T>
    class Iterator
    {
        protected:
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
            Description: Initializes an iterator which points to the node object
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
                return (ptr != other.ptr);
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
                ++(*this);
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
                --(*this);
                return temp;
            }

        private:
            node_pointer ptr;
    };

    template<typename T>
    class List
    {
        protected:
            typedef       T   value_type;
            typedef       T*  pointer;
            typedef const T*  const_pointer;
            typedef       T&  reference;
            typedef const T&  const_reference;
            typedef size_t    size_type;
            typedef ptrdiff_t difference_type;

            typedef std::shared_ptr<Node<value_type>> node_pointer;

        public:

            /*------------------------------------------------------------------
            Function:    List()
            Arguments:   None
            Returns:     Nothing
            Description: Constructs an instance of the linked list with the
                           class members zero'd out.
            ------------------------------------------------------------------*/
            List() :
                count(0UL),
                head(nullptr),
                tail(nullptr)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~List()
            Arguments:   None
            Returns:     Nothing
            Description: Destructor, currently empty.
            ------------------------------------------------------------------*/
            ~List()
            {

            }


            /*------------------------------------------------------------------
            Function:    clear()
            Arguments:   None
            Returns:     Nothing
            Description: Empties the contents of the list. De-allocation must
                           happen as result of this function ending.
            ------------------------------------------------------------------*/
            void clear()
            {
                node_pointer node = head->next;

                // Destroy the contents between head and tail.
                while(node != tail)
                {
                    node->prev->next = nullptr;
                    node->prev = nullptr;
                    node = node->next;
                }

                // Destroy head and tail.
                head->next = nullptr;
                tail->prev = nullptr;
                head = nullptr;
                tail = nullptr;
            }


            /*------------------------------------------------------------------
            Function:    push_back()
            Arguments:   The value to be inserted into the list
            Returns:     An iterator to the newly created node
            Description: Insert a new node at the end of the list with the
                           provided value type.
            ------------------------------------------------------------------*/
            Iterator<value_type> push_back(value_type val)
            {
                node_pointer newNode(new Node<value_type>(val));

                if(head.get() == nullptr)
                {
                    head = newNode;
                }
                else
                {
                    tail->next    = newNode;
                    newNode->prev = tail;
                }

                tail = newNode;
                count++;

                return Iterator<value_type>(newNode);
            }


            /*------------------------------------------------------------------
            Function:    pop_back()
            Arguments:   None
            Returns:     Nothing
            Description: removes the node at the end of the list.
            ------------------------------------------------------------------*/
            void pop_back()
            {
                tail = tail->prev;
                tail->next = nullptr;
                --count;
            }


            /*------------------------------------------------------------------
            Function:    pop_back()
            Arguments:   None
            Returns:     Nothing
            Description: Creates a node with the provided value and appends it
                           to the front of the list.
            ------------------------------------------------------------------*/
            Iterator<value_type> enqueue(value_type val)
            {
                node_pointer node(new Node<value_type>(val));
                node->next = head;
                head = node;
                ++count;
            }


            /*------------------------------------------------------------------
            Function:    pop_back()
            Arguments:   None
            Returns:     Nothing
            Description: Removes the node at the front of the list.
            ------------------------------------------------------------------*/
            void dequeue()
            {
                head = head->next;
                head->prev = nullptr;
                --count;
            }


            /*------------------------------------------------------------------
            Function:    remove()
            Arguments:   None
            Returns:     Boolean true or false
            Description: Removes the node whose data matches val, returns true
                           if the value is found in the list an is successfully
                           removed, or false otherwise.
            ------------------------------------------------------------------*/
            bool remove(value_type val)
            {
                bool successful = false;

                node_pointer node = head;

                while(node.get() != nullptr)
                {
                    if(node->getData() == val)
                    {
                        if((node == head) &&
                           (node == tail))
                        {
                            head = nullptr;
                            tail = nullptr;
                        }
                        else if(node == head)
                        {
                            head = head->next;
                            if(head != nullptr)
                            {
                                head->prev = nullptr;
                            }
                        }
                        else if(node == tail)
                        {
                            tail = tail->prev;
                            tail->next = nullptr;
                        }
                        else
                        {
                            node->prev->next = node->next;
                        }

                        --count;
                        successful = true;
                        break;
                    }

                    node = node->next;
                }

                return successful;
            }


            /*------------------------------------------------------------------
            Function:    reverse()
            Arguments:   None
            Returns:     Nothing
            Description: Reverses the list
            ------------------------------------------------------------------*/
            void reverse()
            {
                node_pointer node = head;
                node_pointer temp = nullptr;

                while(node != nullptr)
                {
                    temp = node->next;
                    node->next = node->prev;
                    node->prev = temp;

                    node = temp;
                }

                node = tail;
                tail = head;
                head = node;
            }


            /*------------------------------------------------------------------
            Function:    find()
            Arguments:   An integer represent the position of the requested data
            Returns:     Returns an iterator pointing to the node if one exists.
            Description: Finds the element at the numeric position held by pos.
            ------------------------------------------------------------------*/
            Iterator<value_type> find(uint32_t pos)
            {
                if(pos > count)
                {
                    return Iterator<value_type>();
                }

                node_pointer node = head;

                for(uint32_t i = 0UL; i < count; ++i)
                {
                    node = node->next;
                }

                return Iterator<value_type>(node);
            }


            /*------------------------------------------------------------------
            Function:    size()
            Arguments:   None
            Returns:     The contents of the count member
            Description: Returns the size of the list, as tracked by count.
            ------------------------------------------------------------------*/
            size_type size()
            {
                return count;
            }


            /*------------------------------------------------------------------
            Function:    Empty()
            Arguments:   None
            Returns:     Boolean true or false
            Description: Returns true if the list is not empty, false otherwise
            ------------------------------------------------------------------*/
            bool empty()
            {
                return count == 0UL;
            }


            /*------------------------------------------------------------------
            Function:    begin()
            Arguments:   None
            Returns:     Returns an iterator to the head node.
            Description: N/A
            ------------------------------------------------------------------*/
            Iterator<value_type> begin()
            {
                return Iterator<value_type>(head);
            }


            /*------------------------------------------------------------------
            Function:    end()
            Arguments:   None
            Returns:     An iterator to a null node.
            Description: A null node is equivalent to the value of tail->next;
            ------------------------------------------------------------------*/
            Iterator<value_type> end()
            {
                return Iterator<value_type>(nullptr);
            }

        private:
            size_type count;

            node_pointer head;
            node_pointer tail;

    };
};

#endif