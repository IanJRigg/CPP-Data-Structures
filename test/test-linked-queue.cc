#include <catch.hpp>

#include <queue.h>

TEST_CASE( "Empty queue behavior" )
{
    Linked::Queue<int> queue;

    // Test the functions which don't alter queue state
    REQUIRE(queue.empty()   == true);
    REQUIRE(queue.size()    == 0UL);

    SECTION("Test Queue::enqueue")
    {
        // Enqueue some data into the queue
        REQUIRE(queue.enqueue(0UL)  == true);

        // Ensure the queue changes as expected
        REQUIRE(queue.empty()    == false);
        REQUIRE(queue.size()     == 1UL);
    }

    SECTION("Test Queue::dequeue")
    {
        // Ensure that the function does not succeed
        REQUIRE(queue.dequeue() == false);

        // Ensure that the queue remains unchanged
        REQUIRE(queue.empty()   == true);
        REQUIRE(queue.size()    == 0UL);
    }
}


TEST_CASE( "Test the linked queue with 1 element" )
{
    Linked::Queue<int> queue;

    REQUIRE(queue.enqueue(1UL)  == true);

    //Test the functions which don't alter queue state
    REQUIRE(queue.empty()   == false);
    REQUIRE(queue.size()    == 1UL);

    SECTION("Test Queue::enqueue")
    {
        // Enqueue some data into the queue
        REQUIRE(queue.enqueue(0UL)  == true);

        // Ensure the queue changes as expected
        REQUIRE(queue.empty()    == false);
        REQUIRE(queue.size()     == 2UL);
    }

    SECTION("Test Queue::dequeue")
    {
        // Ensure that the function removes an element
        REQUIRE(queue.dequeue() == true);

        // Ensure that the queue is now empty
        REQUIRE(queue.empty()   == true);
        REQUIRE(queue.size()    == 0UL);
    }
}


TEST_CASE( "Test the linked queue with many elements" )
{
    Linked::Queue<int> queue;

    REQUIRE(queue.enqueue(1UL)  == true);
    REQUIRE(queue.enqueue(2UL)  == true);
    REQUIRE(queue.enqueue(3UL)  == true);

    // Test the functions which don't alter queue state
    REQUIRE(queue.empty()   == false);
    REQUIRE(queue.size()    == 3UL);

    SECTION("Test Queue::enqueue")
    {
        // Enqueue some data into the queue.
        REQUIRE(queue.enqueue(3UL) == true);

        // Ensure the queue changes as expected
        REQUIRE(queue.empty()    == false);
        REQUIRE(queue.size()     == 4UL);
    }

    SECTION("Test Queue::dequeue")
    {
        // Ensure that the function removes an element
        REQUIRE(queue.dequeue() == true);

        // Ensure that the queue is now empty
        REQUIRE(queue.empty()   == false);
        REQUIRE(queue.size()    == 2UL);
    }
}
