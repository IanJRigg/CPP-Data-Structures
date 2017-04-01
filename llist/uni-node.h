#ifndef _NODE_H_
#define _NODE_H_

// STL Includes
#include <memory>
#include <iostream>

namespace Linked
{
    template<typename T>
    class Node
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
            Node() :
                next(nullptr),
                prev(nullptr),
                data()
            {

            }

            explicit
            Node(value_type val) :
                next(nullptr),
                prev(nullptr),
                data(val)
            {

            }

            ~Node()
            {
                std::cout << "Destroying node with data: " << data << std::endl;
            }

            void setData(reference newData)
            {
                data = newData;
            }

            reference getData()
            {
                return data;
            }

            node_pointer next;
            node_pointer prev;

        private:
            value_type data;
    };
};

#endif