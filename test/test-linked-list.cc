#include <catch.hpp>

#include <linked-list.h>

TEST_CASE( "Empty list behavior" )
{
    const auto null_iterator = Linked::Iterator<int>(nullptr);
    Linked::List<int> list;

    // Test the functions which don't alter list state
    REQUIRE(list.empty()   == true);
    REQUIRE(list.size()    == 0UL);
    REQUIRE(list.begin()   == null_iterator);
    REQUIRE(list.end()     == null_iterator);

    SECTION("Test List::clear")
    {
        // Should do nothing
        list.clear();

        // Ensure that the list remains unchanged
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::push_back")
    {
        // Push back some data into the list
        auto it_0 = list.push_back(0UL);

        // Ensure the list changes as expected
        REQUIRE(list.empty() == false);
        REQUIRE(list.size()  == 1UL);
        REQUIRE(list.begin() == it_0);
        REQUIRE(list.end()   == null_iterator);
    }

    SECTION("Test List::pop_back")
    {
        // Ensure that the function does nothing
        REQUIRE(list.pop_back() == false);

        // Ensure that the list remains unchanged
        REQUIRE(list.empty()    == true);
        REQUIRE(list.size()     == 0UL);
        REQUIRE(list.begin()    == null_iterator);
        REQUIRE(list.end()      == null_iterator);
    }

    SECTION("Test List::enqueue")
    {
        // Enqueue some data into the list.
        auto it_0 = list.enqueue(0UL);

        // Ensure the list changes as expected
        REQUIRE(list.empty()    == false);
        REQUIRE(list.size()     == 1UL);
        REQUIRE(list.begin()    == it_0);
        REQUIRE(list.end()      == null_iterator);
    }

    SECTION("Test List::dequeue")
    {
        // Ensure that the function does not succeed
        REQUIRE(list.dequeue() == false);

        // Ensure that the list remains unchanged
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::remove")
    {
        // Ensure that the function does not succeed
        REQUIRE(list.remove(0UL) == false);

        // Ensure that the list remains unchanged
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::reverse")
    {
        // Reverse the list
        list.reverse();

        // Ensure that the list remains unchanged
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }
}


TEST_CASE( "Test the linked list with 1 element" )
{
    const auto null_iterator = Linked::Iterator<int>(nullptr);
    Linked::List<int> list;

    const auto it_0 = list.push_back(0UL);

    //Test the functions which don't alter list state
    REQUIRE(list.empty()   == false);
    REQUIRE(list.size()    == 1UL);
    REQUIRE(list.begin()   == it_0);
    REQUIRE(list.end()     == null_iterator);

    SECTION("Test List::clear")
    {
        list.clear();

        // Ensure that the list has been emptied
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::push_back")
    {
        // Push back some data into the list
        auto it_1 = list.push_back(1UL);
        auto it_sec = ++(list.begin());

        // Ensure the list changes as expected
        REQUIRE(list.empty() == false);
        REQUIRE(list.size()  == 2UL);
        REQUIRE(list.begin() == it_0);
        REQUIRE(it_sec       == it_1);
        REQUIRE(list.end()   == null_iterator);
    }

    SECTION("Test List::pop_back")
    {
        // Ensure that the function removes an element
        REQUIRE(list.pop_back() == true);

        // Ensure that the list is now empty
        REQUIRE(list.empty()    == true);
        REQUIRE(list.size()     == 0UL);
        REQUIRE(list.begin()    == null_iterator);
        REQUIRE(list.end()      == null_iterator);
    }

    SECTION("Test List::enqueue")
    {
        // Enqueue some data into the list.
        auto it_1 = list.enqueue(1UL);

        // Ensure the list changes as expected
        REQUIRE(list.empty()    == false);
        REQUIRE(list.size()     == 2UL);
        REQUIRE(list.begin()    == it_0);
        REQUIRE(list.end()      == null_iterator);
        REQUIRE(--it_1          == it_0);
    }

    SECTION("Test List::dequeue")
    {
        // Ensure that the function removes an element
        REQUIRE(list.dequeue() == true);

        // Ensure that the list is now empty
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::remove")
    {
        // Ensure that the function does not succeed
        REQUIRE(list.remove(0UL) == true);

        // Ensure that the list is now empty
        REQUIRE(list.empty()   == true);
        REQUIRE(list.size()    == 0UL);
        REQUIRE(list.begin()   == null_iterator);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::reverse")
    {
        list.reverse();

        // Ensure that the list is not empty
        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 1UL);
        REQUIRE(list.begin()   == it_0);
        REQUIRE(list.end()     == null_iterator);
    }
}


TEST_CASE( "Test the linked list with many elements" )
{
    const auto null_iterator = Linked::Iterator<int>(nullptr);
    Linked::List<int> list;

    const auto it_0 = list.push_back(0UL);
    const auto it_1 = list.push_back(1UL);
    const auto it_2 = list.push_back(2UL);

    // Test the functions which don't alter list state
    REQUIRE(list.empty()   == false);
    REQUIRE(list.size()    == 3UL);
    REQUIRE(list.begin()   == it_0);
    REQUIRE(list.end()     == null_iterator);

    SECTION("Test List::clear")
    {
        list.clear();

        REQUIRE(list.empty() == true);
        REQUIRE(list.size()  == 0UL);
        REQUIRE(list.begin() == null_iterator);
        REQUIRE(list.end()   == null_iterator);
    }

    SECTION("Test List::push_back")
    {
        // Push back some data into the list
        auto it_3    = list.push_back(3UL);

        // Ensure the list changes as expected
        REQUIRE(list.empty() == false);
        REQUIRE(list.size()  == 4UL);
        REQUIRE(list.begin() == it_0);
        REQUIRE(list.end()   == null_iterator);

        auto it = list.begin();
        while(it != it_3)
        {
            it++;
        }

        REQUIRE(++it == list.end());
    }

    SECTION("Test List::pop_back")
    {
        // Ensure that the function removes an element
        REQUIRE(list.pop_back() == true);

        // Ensure that the list is now empty
        REQUIRE(list.empty()    == false);
        REQUIRE(list.size()     == 2UL);
        REQUIRE(list.begin()    == it_0);
        REQUIRE(list.end()      == null_iterator);

        auto it = list.begin();
        while(it != it_1)
        {
            it++;
        }

        REQUIRE(++(it) == list.end());
    }

    SECTION("Test List::enqueue")
    {
        // Enqueue some data into the list.
        auto it_3 = list.enqueue(3UL);

        // Ensure the list changes as expected
        REQUIRE(list.empty()    == false);
        REQUIRE(list.size()     == 4UL);
        REQUIRE(list.begin()    == it_0);
        REQUIRE(list.end()      == null_iterator);
        REQUIRE(--it_3          == it_2);
    }

    SECTION("Test List::dequeue")
    {
        // Ensure that the function removes an element
        REQUIRE(list.dequeue() == true);

        // Ensure that the list is now empty
        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 2UL);
        REQUIRE(list.begin()   == it_1);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::remove")
    {
        // Ensure that the function does not succeed
        REQUIRE(list.remove(0UL) == true);

        // Ensure that the list is now empty
        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 2UL);
        REQUIRE(list.begin()   == it_1);
        REQUIRE(list.end()     == null_iterator);
    }

    SECTION("Test List::reverse")
    {
        list.reverse();

        REQUIRE(list.empty()   == false);
        REQUIRE(list.size()    == 3UL);
        REQUIRE(list.begin()   != it_0);
        REQUIRE(list.begin()   == it_2);
    }
}
