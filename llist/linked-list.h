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

            void push_back()
            {

            }

            void pop_back()
            {

            }

            void remove()
            {

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



        private:
            size_type count;

            Node<value_type> * head;
            Node<value_type> * tail;

    };
};

#endif