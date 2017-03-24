#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

namespace Binary
{
    template<class T>
    class Node
    {
        public:
            Node()
            {
                std::cout << "In the Node constructor" << std::endl;
            }

            ~Node()
            {
                std::cout << "In the Node destructor" << std::endl;
            }

        private:

    };
};


#endif