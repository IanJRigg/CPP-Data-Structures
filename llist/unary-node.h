#ifndef _UNARY_NODE_H_
#define _UNARY_NODE_H_

// STL Includes
#include <memory>
#include <iostream>

namespace Linked
{
    template<typename T>
    class Node
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
            Function:    Node()
            Arguments:   None
            Returns:     Nothing
            Description: Default constructor, initializes both pointers to null,
                           and calls the default constructor on data.
            ------------------------------------------------------------------*/
            Node() :
                next(nullptr),
                prev(nullptr),
                data()
            {

            }


            /*------------------------------------------------------------------
            Function:    ~List()
            Arguments:   Value of type T.
            Returns:     Nothing
            Description: Single arument constructor, sets the pointers to null,
                           and sets data to the provided value.
            ------------------------------------------------------------------*/
            explicit
            Node(const value_type val) :
                next(nullptr),
                prev(nullptr),
                data(val)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~Node()
            Arguments:   None
            Returns:     Nothing
            Description: Destructor for the node class
            ------------------------------------------------------------------*/
            ~Node()
            {

            }


            /*------------------------------------------------------------------
            Function:    setData()
            Arguments:   A reference to a data variable of type T.
            Returns:     Nothing
            Description: Sets the data member to the provided data reference.
            ------------------------------------------------------------------*/
            void setData(reference newData)
            {
                data = newData;
            }


            /*------------------------------------------------------------------
            Function:    getData()
            Arguments:   None
            Returns:     A reference to the data member.
            Description: Returns a reference to this instance's data member.
            ------------------------------------------------------------------*/
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