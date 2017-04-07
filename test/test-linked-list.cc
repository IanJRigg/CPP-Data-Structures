#include <catch.hpp>

#include <linked-list.h>

TEST_CASE( "Test the linked list with 0, 1, and many elements" )
{
    const auto null_iterator = Linked::Iterator<int>(nullptr);
    Linked::List<int> list;


    SECTION("Empty list behavior")
    {
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);

        list.reverse();

        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("List with one element")
    {
        const auto it = list.push_back(1UL);

        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 1UL);
        REQUIRE(list.begin()   == it);
        REQUIRE(list.end()     == null_iterator);

        list.reverse();

        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 1UL);
        REQUIRE(list.begin()   == it);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("List withi many elements")
    {
        const auto it_0 = list.push_back(0UL);
        const auto it_1 = list.push_back(1UL);
        const auto it_2 = list.push_back(2UL);

        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 3UL);
        REQUIRE(list.begin()   == it_0);

        list.reverse();

        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 3UL);
        REQUIRE(list.begin()   != it_0);
        REQUIRE(list.begin()   == it_2);

        list.clear();

        REQUIRE(list.empty() == true);
        REQUIRE(list.size()  == 0UL);
        REQUIRE(list.begin() == null_iterator);
    }



}
