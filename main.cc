#include <binary-tree.h>
#include <linked-list.h>
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

    Binary::Tree<int, int> tree;

    Linked::List<int> list;

    list.push_back(0UL);
    list.push_back(1UL);
    list.push_back(2UL);
    list.push_back(3UL);
    list.push_back(4UL);

    /*
    for(auto it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }*/


    return 0;
}