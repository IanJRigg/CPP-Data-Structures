#include <binary-tree.h>
#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
    if(argc != 1UL)
    {
        std::cout << "Invalid argument provided: "
                  << argv[1]
                  << std::endl;

        return 0UL;
    }

    Binary::Tree<int> tree;
    return 0;
}