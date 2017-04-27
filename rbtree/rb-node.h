#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

namespace Binary
{
    enum Color_t
    {
        BLACK = 1UL,
        RED   = 2UL
    };

    template<typename K, typename V>
    class RB_Node : public Node
    {
        public:

            /*------------------------------------------------------------------
            Function:    RB_Node()
            Arguments:   None
            Returns:     Nothing
            Description: Basic argumentless constructor. Nulls out the pointers
                           and sets the pair to be empty.
            ------------------------------------------------------------------*/
            RB_Node() :
                head(nullptr),
                left(nullptr),
                right(nullptr),
                value()
            {

            }


            /*------------------------------------------------------------------
            Function:    RB_Node()
            Arguments:   A std::pair containing the key and value for the entry.
            Returns:     Nothing
            Description: Default constructor, initializes both pointers to null,
                           and sets the value memeber to the provided value.
            ------------------------------------------------------------------*/
            explicit
            RB_Node(const value_type value) :
                head(nullptr),
                left(nullptr),
                right(nullptr),
                value(value)
            {

            }


            /*------------------------------------------------------------------
            Function:    RB_Node()
            Arguments:   A pointer to the entry's head node. A std::pair
                           containing the key and value for the entry.
            Returns:     Nothing
            Description: Default constructor, initializes both pointers to null,
                           and sets the value memeber to the provided value.
            ------------------------------------------------------------------*/
            explicit
            RB_Node(const node_pointer head, const value_type value) :
                head(head),
                left(nullptr),
                right(nullptr),
                value(value)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~RB_Node()
            Arguments:   None
            Returns:     Nothing
            Description: Destructor.
            ------------------------------------------------------------------*/
            ~RB_Node()
            {

            }


            /*------------------------------------------------------------------
            Function:    setColor()
            Arguments:   None
            Returns:     Nothing
            Description: Set's the provided color, if it's RED or BLACK
            ------------------------------------------------------------------*/
            void setColor(const Color_t color)
            {
                switch(color)
                {
                    case RED:
                    case BLACK:
                        this->color = color;
                        break;
                    default:
                        break;
                }
            }


            /*------------------------------------------------------------------
            Function:    isBlack()
            Arguments:   None
            Returns:     Boolean indicating if the node is a black node
            Description: True if color is equal to BLACK
            ------------------------------------------------------------------*/
            bool isBlack() const
            {
                return (color == BLACK);
            }


            /*------------------------------------------------------------------
            Function:    isRed()
            Arguments:   None
            Returns:     Boolean indicating if the node is a red node
            Description: True if color is equal to RED
            ------------------------------------------------------------------*/
            bool isRed() const
            {
                return (color == RED);
            }

        protected:
            Color_t color;
    };
};


#endif