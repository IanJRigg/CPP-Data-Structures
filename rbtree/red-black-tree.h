#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

template<typename K, typename V>
class Red_Black_Tree
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
        Red_Black_Tree()
        {

        }

        ~Red_Black_Tree()
        {
            
        }

    private:
};

#endif