#ifndef _NODE_H_
#define _NODE_H_

namespace Linked
{
    template<typename T>
    class Node
    {
        public:
            Node() :
                data(),
                next(nullptr),
                prev(nullptr)
            {

            }

            ~Node()
            {
                // In case something went wrong previously.
                if(prev)
                {
                    delete prev;
                }
            }

            void setData(T newData)
            {
                data = newData;
            }

            T getData()
            {
                return data;
            }

            Node<T> * next;
            Node<T> * prev;

        private:
            T data;
    };
};

#endif