#include <catch.hpp>

#include <stack.h>

TEST_CASE( "Empty stack behavior" )
{
    Linked::Stack<int> stack;

    // Test the functions which don't alter stack state
    REQUIRE(stack.empty()   == true);
    REQUIRE(stack.size()    == 0UL);

    SECTION("Test Stack::push")
    {
        // Push back some data into the stack
        REQUIRE(stack.push(0UL) == true);

        // Ensure the stack changes as expected
        REQUIRE(stack.empty() == false);
        REQUIRE(stack.size()  == 1UL);
    }

    SECTION("Test Stack::pop")
    {
        // Ensure that the function does nothing
        REQUIRE(stack.pop() == false);

        // Ensure that the stack remains unchanged
        REQUIRE(stack.empty()    == true);
        REQUIRE(stack.size()     == 0UL);
    }
}


TEST_CASE( "Test the linked stack with 1 element" )
{
    Linked::Stack<int> stack;

    // Push back some data into the stack
    REQUIRE(stack.push(0UL) == true);

    //Test the functions which don't alter stack state
    REQUIRE(stack.empty()   == false);
    REQUIRE(stack.size()    == 1UL);

    SECTION("Test Stack::push")
    {
        // Push back some data into the stack
        REQUIRE(stack.push(0UL) == true);

        // Ensure the stack changes as expected
        REQUIRE(stack.empty() == false);
        REQUIRE(stack.size()  == 2UL);
    }

    SECTION("Test Stack::pop")
    {
        // Ensure that the function does nothing
        REQUIRE(stack.pop() == true);

        // Ensure that the stack is now empty
        REQUIRE(stack.empty()    == true);
        REQUIRE(stack.size()     == 0UL);
    }
}


TEST_CASE( "Test the linked stack with many elements" )
{
    Linked::Stack<int> stack;

    // Push back some data into the stack
    REQUIRE(stack.push(1UL) == true);
    REQUIRE(stack.push(2UL) == true);
    REQUIRE(stack.push(3UL) == true);

    // Test the functions which don't alter stack state
    REQUIRE(stack.empty()   == false);
    REQUIRE(stack.size()    == 3UL);

    SECTION("Test Stack::push")
    {
        // Push back some data into the stack
        REQUIRE(stack.push(0UL) == true);

        // Ensure the stack changes as expected
        REQUIRE(stack.empty() == false);
        REQUIRE(stack.size()  == 4UL);
    }

    SECTION("Test Stack::pop")
    {
        // Ensure that the function removes an element
        REQUIRE(stack.pop() == true);

        // Ensure that the stack is now empty
        REQUIRE(stack.empty()    == false);
        REQUIRE(stack.size()     == 2UL);
    }
}
