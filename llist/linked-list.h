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
            Iterator() :
                ptr(nullptr)
            {

            }

            explicit
            Iterator(node_pointer node) :
                ptr(node)
            {

            }

            ~Iterator()
            {

            }

            reference operator*()
            {
                return ptr->getData();
            }

            pointer operator->()
            {
                return &(operator*());
            }

            bool operator==(const self_type& other)
            {
                return (ptr == other.ptr);
            }

            bool operator!=(const self_type& other)
            {
                return (ptr != other.ptr);
            }

            self_type& operator++()
            {
                ptr = ptr->next;
                return *this;
            }

            self_type  operator++(int)
            {
                self_type temp(ptr);
                ++(*this);
                return temp;
            }

            self_type& operator--()
            {
                ptr = ptr->prev;
            }

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
            Description: Basic destructor, currently empty.
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
                    tail = newNode;
                    count++;
                }
                else
                {
                    tail.get()->next = newNode;
                    newNode.get()->prev = tail;
                    tail = newNode;
                    count++;
                }

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
                node_pointer newNode(new Node<value_type>);
                tail = tail->prev;
                tail->next = nullptr;
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

                for(auto it = begin(); it != end(); it++)
                {
                    if(val == *it)
                    {
                        successful = true;

                        //it->prev->next = it->next;

                        break;
                    }
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

                node_pointer currNode = head;

                for(uint32_t i = 0UL; i < count; ++i)
                {
                    currNode = currNode->next;
                }

                return Iterator<value_type>(currNode);
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