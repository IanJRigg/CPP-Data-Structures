#include <binary-tree.h>
#include <linked-list.h>
#include <iostream>
#include <string>


void iterate(Linked::List<int> & list)
{
    std::cout << "List contents: " << std::endl;
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
}

void populate(Linked::List<int> & list)
{
    list.push_back(0UL);
    list.push_back(1UL);
    list.push_back(2UL);
    list.push_back(3UL);
    list.push_back(4UL);
}

int main(int argc, char ** argv)
{
    if(argc != 1UL)
    {
        std::cout << "Invalid argument provided: "
                  << argv[1]
                  << std::endl;

        return 0UL;
    }

    //Binary::Tree<int, int> tree;

    Linked::List<int> list;
    populate(list);
    list.clear();
    populate(list);

    iterate(list);
    list.reverse();
    iterate(list);
    list.reverse();
    iterate(list);

    list.remove(4UL);

    iterate(list);

    list.remove(3UL);

    iterate(list);

    list.remove(2UL);

    iterate(list);

    list.remove(1UL);

    iterate(list);

    list.remove(0UL);

    return 0;
}