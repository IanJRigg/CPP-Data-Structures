#ifndef _LLIST_H_
#define _LLIST_H_

#include <uni-node.h>

/*
    Doubly Linked List
*/

namespace Linked
{
    // TODO: Implement ++, -- operators
    template <typename T>
    class Iterator
    {
        public:
            Iterator() :
                element(nullptr)
            {

            }

            Iterator(Node<T> * node) :
                element(node)
            {

            }

            ~Iterator()
            {

            }

        private:
            Node<T> * element;
    };

    template<typename T>
    class List
    {
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

            Iterator<T> find(uint32_t pos)
            {
                if(pos > count)
                {
                    return Iterator<T>();
                }

                Node<T> * currNode = head;

                for(uint32_t i = 0UL; i < count; ++i)
                {
                    currNode = currNode->next;
                }

                return Iterator<T>(currNode);
            }

            size_t size()
            {
                return size;
            }

            bool empty()
            {
                return count == 0UL;
            }



        private:
            size_t count;

            Node<T> * head;
            Node<T> * tail;

    };
};

#endif