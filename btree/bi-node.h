#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

namespace Binary
{
    template<typename K, typename V>
    class Node
    {
        typedef K   key_type;
        typedef V   mapped_type;
        typedef std::pair<key_type, mapped_type> value_type;

        typedef       value_type*  pointer;
        typedef const value_type*  const_pointer;
        typedef       value_type&  reference;
        typedef const value_type&  const_reference;
        typedef size_t             size_type;
        typedef ptrdiff_t          difference_type;

        typedef std::shared_ptr<Node<key_type, mapped_type >> node_pointer;

        public:

            /*------------------------------------------------------------------
            Function:    Node()
            Arguments:   None
            Returns:     Nothing
            Description: Basic argumentless constructor. Nulls out the pointers
                           and sets the pair to be empty.
            ------------------------------------------------------------------*/
            Node() :
                value(),
                head(nullptr),
                left(nullptr),
                right(nullptr)
            {

            }


            /*------------------------------------------------------------------
            Function:    Node()
            Arguments:   None
            Returns:     Nothing
            Description: Default constructor, initializes both pointers to null,
                           and sets the value memeber to the provided value.
            ------------------------------------------------------------------*/
            explicit
            Node(value_type value) :
                value(value),
                head(nullptr),
                left(nullptr),
                right(nullptr)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~Node()
            Arguments:   None
            Returns:     Nothing
            Description: Default destructor.
            ------------------------------------------------------------------*/
            ~Node()
            {
                std::cout << "In the Node destructor" << std::endl;
            }


            /*------------------------------------------------------------------
            Function:    setValue()
            Arguments:   Reference to a value_type
            Returns:     Nothing
            Description: Sets the member node left to the provided node.
            ------------------------------------------------------------------*/
            void setValue(reference data)
            {
                value = data;
            }


            /*------------------------------------------------------------------
            Function:    getValue()
            Arguments:   None
            Returns:     Nothing
            Description: Returns a reference to the value member
            ------------------------------------------------------------------*/
            reference getValue()
            {
                return value;
            }

            node_pointer head;


            node_pointer left;
            node_pointer right;

        private:
            value_type value;
    };
};


#endif