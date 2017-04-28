#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

#include <binary-tree.h>
#include <red-black-node.h>

namespace Binary
{
    template<typename K, typename V>
    class Red_Black_Tree : public Tree<K, V>
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

        typedef std::shared_ptr<Red_Black_Node<key_type, mapped_type >> node_pointer;

        public:
            /*------------------------------------------------------------------
            Function:    Tree()
            Arguments:   None
            Returns:     Nothing
            Description: Basic constructor. Nulls out root.
            ------------------------------------------------------------------*/
            Red_Black_Tree()
            {

            }


            /*------------------------------------------------------------------
            Function:    ~Tree()
            Arguments:   None
            Returns:     Nothing
            Description: Destructor, clears the contents of the tree.
            ------------------------------------------------------------------*/
            ~Red_Black_Tree()
            {
                
            }

            /*------------------------------------------------------------------
            Function:    insert()
            Arguments:   Value type which contains the value to be inserted.
            Returns:     An iterator pointing to the inserted element.
            Description: Inserts the provided value into the binary tree.
            ------------------------------------------------------------------*/
            std::pair<Iterator<key_type, mapped_type>, bool>
            insert(const value_type entry)
            {
                this->root = node_pointer(new Red_Black_Node<key_type, mapped_type>(entry, BLACK));
                return std::make_pair(Iterator<key_type, mapped_type>(nullptr), false);
            }


            /*------------------------------------------------------------------
            Function:    erase()
            Arguments:   An iterator pointing to the element to be erased
            Returns:     Nothing
            Description: Removes the node with the key held in pos.
            ------------------------------------------------------------------*/
            void erase(Iterator<key_type, mapped_type> entry)
            {
                Iterator<key_type, mapped_type> blah(nullptr);
                if(blah == entry)
                {
                    std::cout << "I just want to pass the compiler...." << std::endl;
                }
            }

        private:
    };
};



#endif