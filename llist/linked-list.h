#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

// STL Headers
#include <iostream>

// Project Headers
#include <unary-node.h>
#include <unary-iterator.h>

/*
    Doubly Linked List
    STL types and other notes adapted from:
        https://accu.org/index.php/journals/389
*/

namespace Linked
{
    template<typename T>
    class List
    {
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
                if(!empty())
                {
                    node_pointer node = head->next;

                    // Destroy the contents between head and tail.
                    while(node != nullptr)
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

                    count = 0UL;
                }
            }


            /*------------------------------------------------------------------
            Function:    push_back()
            Arguments:   The value to be inserted into the list
            Returns:     An iterator to the newly created node
            Description: Insert a new node at the end of the list with the
                           provided value type.
            ------------------------------------------------------------------*/
            Iterator<value_type> push_back(const value_type val)
            {
                node_pointer node(new Node<value_type>(val));

                if(head == nullptr)
                {
                    head = node;
                }
                else
                {
                    tail->next = node;
                    node->prev = tail;
                }

                tail = node;
                ++count;

                return Iterator<value_type>(node);
            }


            /*------------------------------------------------------------------
            Function:    pop_back()
            Arguments:   None
            Returns:     True if the list isn't empty and the operation could be
                           completed.
            Description: removes the node at the end of the list.
            ------------------------------------------------------------------*/
            bool pop_back()
            {
                bool successful = false;

                if(!empty())
                {
                    if(head == tail)
                    {
                        head = nullptr;
                        tail = nullptr;
                    }
                    else
                    {
                        tail = tail->prev;
                        tail->next = nullptr;
                    }

                    --count;
                    successful = true;
                }

                return successful;
            }


            /*------------------------------------------------------------------
            Function:    enqueue()
            Arguments:   Value to enter into the list.
            Returns:     Iterator with the pointer of the inserted element.
            Description: Creates a node with the provided value and appends it
                           to the back of the list.
            ------------------------------------------------------------------*/
            Iterator<value_type> enqueue(const value_type val)
            {
                node_pointer node(new Node<value_type>(val));

                if(head == nullptr)
                {
                    head = node;
                }
                else
                {
                    tail->next = node;
                    node->prev = tail;
                }

                tail = node;
                ++count;

                return Iterator<value_type>(node);
            }


            /*------------------------------------------------------------------
            Function:    dequeue()
            Arguments:   None
            Returns:     True if the list isn't empty and the operation could be
                           completed.
            Description: Removes the node at the back of the list.
            ------------------------------------------------------------------*/
            bool dequeue()
            {
                bool successful = false;

                if(!empty())
                {
                    if(head == tail)
                    {
                        head = nullptr;
                        tail = nullptr;
                    }
                    else
                    {
                        head = head->next;
                        head->prev = nullptr;
                    }

                    --count;
                    successful = true;
                }

                return successful;
            }


            /*------------------------------------------------------------------
            Function:    remove()
            Arguments:   None
            Returns:     Boolean true or false
            Description: Removes the node whose data matches val, returns true
                           if the value is found in the list an is successfully
                           removed, or false otherwise.
            ------------------------------------------------------------------*/
            bool remove(const value_type val)
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
            Function:    size()
            Arguments:   None
            Returns:     The contents of the count member
            Description: Returns the size of the list, as tracked by count.
            ------------------------------------------------------------------*/
            size_type size() const
            {
                return count;
            }


            /*------------------------------------------------------------------
            Function:    Empty()
            Arguments:   None
            Returns:     Boolean true or false
            Description: Returns true if the list is not empty, false otherwise
            ------------------------------------------------------------------*/
            bool empty() const
            {
                return count == 0UL;
            }


            /*------------------------------------------------------------------
            Function:    begin()
            Arguments:   None
            Returns:     Returns an iterator to the head node.
            Description: N/A
            ------------------------------------------------------------------*/
            Iterator<value_type> begin() const
            {
                return Iterator<value_type>(head);
            }


            /*------------------------------------------------------------------
            Function:    end()
            Arguments:   None
            Returns:     An iterator to a null node.
            Description: A null node is equivalent to the value of tail->next;
            ------------------------------------------------------------------*/
            Iterator<value_type> end() const
            {
                return Iterator<value_type>(nullptr);
            }


            /*------------------------------------------------------------------
            Function:    rbegin()
            Arguments:   None
            Returns:     Returns an iterator to the tails node.
            Description: N/A
            ------------------------------------------------------------------*/
            Iterator<value_type> rbegin() const
            {
                return Iterator<value_type>(tail);
            }


            /*------------------------------------------------------------------
            Function:    rend()
            Arguments:   None
            Returns:     An iterator to a null node.
            Description: A null node is equivalent to the value of head->prev;
            ------------------------------------------------------------------*/
            Iterator<value_type> rend() const
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