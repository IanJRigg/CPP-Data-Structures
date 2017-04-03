#define CATCH_CONFIG_MAIN
#include <catch.hpp>


#include <binary-tree.h>
#include <linked-list.h>
#include <stack.h>
#include <queue.h>
#include <iostream>
#include <string>

#include <vector>

/* TEMPLATE FOR SCOFFOLDING OUT UNIT TESTS
TEST_CASE( "vectors can be sized and resized", "[vector]" ) {

    std::vector<int> v( 5 );

    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );

    SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );

        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) {
        v.resize( 0 );

        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() >= 5 );
    }
    SECTION( "reserving bigger changes capacity but not size" ) {
        v.reserve( 10 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );
    }
}
*/

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

bool test_linked_list()
{
    bool successful = false;

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

    return successful;
}

bool test_stack()
{
    bool successful = false;
    Linked::Stack<int> stack;
    return successful;
}

bool test_queue()
{
    bool successful = false;
    Linked::Queue<int> queue;
    return successful;
}

bool test_binary_tree()
{
    bool successful = false;
    Binary::Tree<int, int> tree;
    return successful;
}

/*
int main(int argc, char ** argv)
{
    if(argc != 1UL)
    {
        std::cout << "Invalid argument provided: "
                  << argv[1]
                  << std::endl;

        return 0UL;
    }

    return 0;
}*/