#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <binary-node.h>
#include <iostream>
#include <stdexcept>
#include <queue.h>
#include <binary-iterator.h>

namespace Binary
{
    template <typename K, typename V>
    class Tree
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

        typedef std::shared_ptr<Node<key_type, mapped_type>> node_pointer;

        public:
            /*------------------------------------------------------------------
            Function:    Tree()
            Arguments:   None
            Returns:     Nothing
            Description: Basic constructor. Nulls out root.
            ------------------------------------------------------------------*/
            Tree() :
                root(nullptr),
                count(0UL)
            {

            }


            /*------------------------------------------------------------------
            Function:    ~Tree()
            Arguments:   None
            Returns:     Nothing
            Description: Destructor, clears the contents of the tree.
            ------------------------------------------------------------------*/
            ~Tree()
            {
                clear();
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
                node_pointer node = root;
                bool successful = true;

                if(empty())
                {
                    root = node_pointer(new Node<key_type, mapped_type>(entry));
                    ++count;
                    return std::make_pair(Iterator<key_type, mapped_type>(root), successful);
                }

                while(node != nullptr)
                {
                    if(node->getValue().first > entry.first)
                    {
                        if(node->left == nullptr)
                        {
                            node->left = node_pointer(new Node<key_type, mapped_type>(node, entry));
                            node = node->left;
                            ++count;
                            break;
                        }
                        else
                        {
                            node = node->left;
                        }
                    }
                    else if(node->getValue().first < entry.first)
                    {
                        if(node->right == nullptr)
                        {
                            node->right = node_pointer(new Node<key_type, mapped_type>(node, entry));
                            node = node->right;
                            ++count;
                            break;
                        }
                        else
                        {
                            node = node->right;
                        }
                    }
                    else
                    {
                        successful = false;
                        break;
                    }
                }

                return std::make_pair(Iterator<key_type, mapped_type>(node), successful);
            }


            /*------------------------------------------------------------------
            Function:    clear()
            Arguments:   None
            Returns:     Nothing
            Description: Destroys the contents of the tree.
            ------------------------------------------------------------------*/
            void clear()
            {
                if(empty())
                {
                    return;
                }

                // Breadth first search the tree
                node_pointer node;
                Linked::Queue<node_pointer> queue;
                queue.enqueue(root);

                while(!queue.empty())
                {
                    node = queue.front();
                    node->head = nullptr;

                    if(node->left != nullptr)
                    {
                        queue.enqueue(node->left);
                    }

                    if(node->right != nullptr)
                    {
                        queue.enqueue(node->right);
                    }

                    if(!queue.dequeue())
                    {
                        std::cout << "THROW AN EXCEPTION HERE!!!" << std::endl;
                    }
                }

                // Nulling the root should then trigger a chain of deletions
                root  = nullptr;
                count = 0UL;
            }


            /*------------------------------------------------------------------
            Function:    erase()
            Arguments:   An iterator pointing to the element to be erased
            Returns:     Nothing
            Description: Removes the node with the key held in pos.
            ------------------------------------------------------------------*/
            void erase(Iterator<key_type, mapped_type> entry)
            {
                if(entry == Iterator<int, int>(nullptr))
                {
                    return;
                }

                node_pointer node = root;
                while(node != nullptr)
                {
                    if(node->getValue().first == (*entry).first)
                    {
                        break;
                    }
                    else if(node->getValue().first < (*entry).first)
                    {
                        node = node->right;
                    }
                    else
                    {
                        node = node->left;
                    }
                }

                if(node == nullptr)
                {
                    return;
                }

                // Node with a left child only: replace current node with child
                if((node->left != nullptr) && (node->right == nullptr))
                {
                    node->left->head = node->head;

                    // if parent's left child is equal to the current node
                    if(node->head->left == node)
                    {
                        node->head->left = node->left;
                    }
                    else
                    {
                        node->head->right = node->left;
                    }

                    node->head = nullptr;
                }
                // Node with a right child only: replace current node with child
                else if((node->left == nullptr) && (node->right != nullptr))
                {
                    node->right->head = node->head;

                    // if parent's left child is equal to the current node
                    if(node->head->left == node)
                    {
                        node->head->left = node->right;
                    }
                    else
                    {
                        node->head->right = node->right;
                    }
                    node->head = nullptr;
                }
                // Node with both children
                else if((node->left != nullptr) && (node->right != nullptr))
                {
                    // Find the lowest valued element in the right subtree,
                    //   replace the node to be destroye with said node
                    node_pointer swap = node->right;

                    while(swap->left != nullptr)
                    {
                        swap = swap->left;
                    }

                    //replace node with swap
                    if(node->left != nullptr)
                    {
                        node->left->head = swap;
                    }

                    if(node->right != nullptr)
                    {
                        node->right->head = swap;
                    }

                    // Handle the root here
                    if(node->head != nullptr)
                    {
                        if(node->head->left == node)
                        {
                            node->head->left = swap;
                        }
                        else
                        {
                            node->head->right = swap;
                        }
                    }
                }
                // Node with no cildren: Remove the node outright
                else
                {
                    // Handle the root here
                    if(node->head != nullptr)
                    {
                        if(node->head->left == node)
                        {
                            node->head->left = nullptr;
                        }
                        else
                        {
                            node->head->right = nullptr;
                        }
                    }
                    else
                    {
                        // If the node has no head pointer, it must be root.
                        root = nullptr;
                    }
                }

                --count;
                return;
            }


            /*------------------------------------------------------------------
            Function:    find()
            Arguments:   None
            Returns:     An iterator pointing to the value type with the
                           provided key
            Description: Empty destructor
            ------------------------------------------------------------------*/
            Iterator<key_type, mapped_type> find(const key_type key) const
            {
                node_pointer node = root;
                while(node != nullptr)
                {
                    if(key == node->getValue().first)
                    {
                        break;
                    }
                    if(key < node->getValue().first)
                    {
                        node = node->left;
                    }
                    else
                    {
                        node = node->right;
                    }
                }

                return Iterator<key_type, mapped_type>(node);
            }


            /*------------------------------------------------------------------
            Function:    at()
            Arguments:   The key_type to be searched for
            Returns:     The mapped_type variable that corresponds to the key
            Description: Returns the value that is stored with the provided key
            ------------------------------------------------------------------*/
            mapped_type at(const key_type key) const
            {
                Iterator<key_type, mapped_type> it = find(key);
                if(it != end())
                {
                    return (*it).second;
                }
                else
                {
                    throw std::out_of_range("Key is out of range");
                }
            }


            /*------------------------------------------------------------------
            Function:    size()
            Arguments:   None
            Returns:     The contents of the count member
            Description: Returns the contents of the count member
            ------------------------------------------------------------------*/
            size_type size() const
            {
                return count;
            }


            /*------------------------------------------------------------------
            Function:    empty()
            Arguments:   None
            Returns:     True if the tree is empty, false if otherwise.
            Description: Checks if count is equal to zero.
            ------------------------------------------------------------------*/
            bool empty() const
            {
                return count == 0UL;
            }


            /*------------------------------------------------------------------
            Function:    front()
            Arguments:   None
            Returns:     An iterator pointing to the left-most node.
            Description: Returns the front of the tree.
            ------------------------------------------------------------------*/
            Iterator<key_type, mapped_type> front() const
            {
                if(root == nullptr)
                {
                    return Iterator<key_type, mapped_type>(nullptr);
                }

                node_pointer ptr = root;
                while(ptr->left != nullptr)
                {
                    ptr = ptr->left;
                }

                return Iterator<key_type, mapped_type>(ptr);
            }


            /*------------------------------------------------------------------
            Function:    end()
            Arguments:   None
            Returns:     An iterator pointing at past the end of the tree (NULL)
            Description: Returns an iterator to the past-the-end element
            ------------------------------------------------------------------*/
            Iterator<key_type, mapped_type> end() const
            {
                return Iterator<key_type, mapped_type>(nullptr);
            }

            /*------------------------------------------------------------------
            Function:    back()
            Arguments:   None
            Returns:     An iterator pointing to the right-most node.
            Description: Returns the back of the tree.
            ------------------------------------------------------------------*/
            Iterator<key_type, mapped_type> back() const
            {
                if(root == nullptr)
                {
                    return Iterator<key_type, mapped_type>(nullptr);
                }

                node_pointer ptr = root;
                while(ptr->right != nullptr)
                {
                    ptr = ptr->right;
                }

                return Iterator<key_type, mapped_type>(ptr);
            }


            /*------------------------------------------------------------------
            Function:    rend()
            Arguments:   None
            Returns:     An iterator pointing at past the end of the tree (NULL)
            Description: Returns an iterator to the past-the-end element
            ------------------------------------------------------------------*/
            Iterator<key_type, mapped_type> rend() const
            {
                return Iterator<key_type, mapped_type>(nullptr);
            }

        private:
            node_pointer root;

            size_type count;
    };
};
#endif