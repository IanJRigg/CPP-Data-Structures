#ifndef _RED_BLACK_NODE_H_
#define _RED_BLACK_NODE_H_

#include <iostream>
#include <binary-node.h>

namespace Binary
{
    //enum Color_t
    //{
    //    BLACK = 1UL,
    //    RED   = 2UL
    //};
//
    //template<typename K, typename V>
    //class Red_Black_Node : public Node<K,V>
    //{
    //    typedef K   key_type;
    //    typedef V   mapped_type;
    //    typedef std::pair<key_type, mapped_type> value_type;
//
    //    typedef       value_type*  pointer;
    //    typedef const value_type*  const_pointer;
    //    typedef       value_type&  reference;
    //    typedef const value_type&  const_reference;
    //    typedef size_t             size_type;
    //    typedef ptrdiff_t          difference_type;
//
    //    typedef std::shared_ptr<Node<key_type, mapped_type >> node_pointer;
//
    //    public:
    //        /*------------------------------------------------------------------
    //        Function:    Red_Black_Node()
    //        Arguments:   A std::pair containing the key and value for the entry
    //                     The color of the node
    //        Returns:     Nothing
    //        Description: Default constructor, initializes both pointers to null,
    //                       and sets the value memeber to the provided value.
    //        ------------------------------------------------------------------*/
    //        Red_Black_Node(const value_type value, Color_t color) :
    //            Node<K,V>(value),
    //            color(color)
    //        {
//
    //        }
//
//
    //        /*------------------------------------------------------------------
    //        Function:    Red_Black_Node()
    //        Arguments:   A pointer to the entry's head node.
    //                     A std::pair containing the key and value for the entry
    //                     The color of the node
    //        Returns:     Nothing
    //        Description: Default constructor, initializes both pointers to null,
    //                       and sets the value memeber to the provided value.
    //        ------------------------------------------------------------------*/
    //        Red_Black_Node(const node_pointer head,
    //                       const value_type value,
    //                       Color_t color) :
    //            Node<key_type, mapped_type>(head, value),
    //            color(color)
    //        {
//
    //        }
//
//
    //        /*------------------------------------------------------------------
    //        Function:    ~RB_Node()
    //        Arguments:   None
    //        Returns:     Nothing
    //        Description: Destructor.
    //        ------------------------------------------------------------------*/
    //        ~Red_Black_Node()
    //        {
//
    //        }
//
//
    //        /*------------------------------------------------------------------
    //        Function:    setColor()
    //        Arguments:   None
    //        Returns:     Nothing
    //        Description: Set's the provided color, if it's RED or BLACK
    //        ------------------------------------------------------------------*/
    //        void setColor(const Color_t color)
    //        {
    //            switch(color)
    //            {
    //                case RED:
    //                case BLACK:
    //                    this->color = color;
    //                    break;
    //                default:
    //                    break;
    //            }
    //        }
//
//
    //        /*------------------------------------------------------------------
    //        Function:    isBlack()
    //        Arguments:   None
    //        Returns:     Boolean indicating if the node is a black node
    //        Description: True if color is equal to BLACK
    //        ------------------------------------------------------------------*/
    //        bool isBlack() const
    //        {
    //            return (color == BLACK);
    //        }
//
//
    //        /*------------------------------------------------------------------
    //        Function:    isRed()
    //        Arguments:   None
    //        Returns:     Boolean indicating if the node is a red node
    //        Description: True if color is equal to RED
    //        ------------------------------------------------------------------*/
    //        bool isRed() const
    //        {
    //            return (color == RED);
    //        }
//
//
    //    protected:
    //        Color_t color;
//
//
    //    private:
    //        /*------------------------------------------------------------------
    //        Function:    RB_Node()
    //        Arguments:   None
    //        Returns:     Nothing
    //        Description: Basic argumentless constructor. Nulls out the pointers,
    //                       sets the pair to be empty, and sets color to black.
    //                       This constructor should not ever be used.
    //        ------------------------------------------------------------------*/
    //        Red_Black_Node() : color(BLACK)
    //        {
//
    //        }
    //};
};


#endif