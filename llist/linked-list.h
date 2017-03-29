#ifndef _LLIST_H_
#define _LLIST_H_

// STL Headers

// Project Headers
#include <uni-node.h>

/*
    Doubly Linked List
    STL types and other notes adapted from:
        https://accu.org/index.php/journals/389
*/

namespace Linked
{
    // TODO: Implement ++, --, [] operators
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
                element(nullptr)
            {

            }

            explicit
            Iterator(node_pointer node) :
                element(node)
            {

            }

            ~Iterator()
            {

            }

            reference operator*()
            {
                return element.getData();
            }

            pointer operator->()
            {
                return &(operator*());
            }

            bool operator==(const self_type& other)
            {
                return operator*() == *other;
            }

            bool operator!=(const self_type& other)
            {
                return operator*() != *other;
            }

            self_type& operator++()
            {
                element = element.next;
            }

            self_type  operator++(int)
            {
                value_type temp = *this;
                ++(*this);
                return temp;
            }

            self_type& operator--()
            {
                element = element.prev;
            }

            self_type  operator--(int)
            {
                value_type temp = *this;
                --(*this);
                return temp;
            }



        private:
            node_pointer element;
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
            List() :
                count(0UL),
                head(nullptr),
                tail(nullptr)
            {

            }

            ~List()
            {
                clear();
            }

            void clear()
            {

            }

            Iterator<value_type> push_back(value_type val)
            {
                node_pointer newNode = new Node<value_type>();
                newNode.setData(val);

                tail->next = newNode;
                tail = newNode;

                return Iterator<value_type>(newNode);
            }

            void pop_back()
            {
                node_pointer newNode = new Node<value_type>();
                tail = tail->prev;
                tail->next = nullptr;
            }

            bool remove(value_type val)
            {
                bool retval = false;

                for(auto it = begin(); it != end(); it++)
                {
                    if(val == *it)
                    {
                        retval = true;

                        break;
                    }
                }

                return retval;
            }

            void reverse()
            {

            }

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

            size_type size()
            {
                return size;
            }

            bool empty()
            {
                return count == 0UL;
            }

            Iterator<value_type> begin()
            {
                return Iterator<value_type>(head);
            }

            Iterator<value_type> end()
            {
                return Iterator<value_type>(head);
            }



        private:
            size_type count;

            Node<value_type> * head;
            Node<value_type> * tail;

    };
};

#endif