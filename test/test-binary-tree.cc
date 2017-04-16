#include <catch.hpp>
#include <binary-tree.h>


TEST_CASE( "Iterator Increment Behavior" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    tree.insert(std::pair<int, int>(5UL, 0UL));
    tree.insert(std::pair<int, int>(2UL, 0UL));
    tree.insert(std::pair<int, int>(4UL, 0UL));
    tree.insert(std::pair<int, int>(3UL, 0UL));
    tree.insert(std::pair<int, int>(0UL, 0UL));
    tree.insert(std::pair<int, int>(1UL, 0UL));
    tree.insert(std::pair<int, int>(9UL, 0UL));
    tree.insert(std::pair<int, int>(8UL, 0UL));
    tree.insert(std::pair<int, int>(7UL, 0UL));
    tree.insert(std::pair<int, int>(6UL, 0UL));

    auto prev = tree.front();
    for(auto it = ++tree.front(); it != tree.end(); it++)
    {
        std::cout << (*it).first << " " << (*prev).first << std::endl;
        REQUIRE((*it).first > (*prev).first);
        prev++;
    }
}


TEST_CASE( "Iterator Decrement Behavior" )
{
    /*
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    tree.insert(std::pair<int, int>(5UL, 0UL));
    tree.insert(std::pair<int, int>(2UL, 0UL));
    tree.insert(std::pair<int, int>(4UL, 0UL));
    tree.insert(std::pair<int, int>(3UL, 0UL));
    tree.insert(std::pair<int, int>(0UL, 0UL));
    tree.insert(std::pair<int, int>(1UL, 0UL));
    tree.insert(std::pair<int, int>(9UL, 0UL));
    tree.insert(std::pair<int, int>(8UL, 0UL));
    tree.insert(std::pair<int, int>(7UL, 0UL));
    tree.insert(std::pair<int, int>(6UL, 0UL));*/
}

TEST_CASE( "Empty Tree Behavior" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    REQUIRE(tree.empty() == true);
    REQUIRE(tree.size()  == 0UL);
    REQUIRE(tree.front() == null_iterator);
    REQUIRE(tree.end()   == null_iterator);

    SECTION("Test Tree::insert")
    {
        //auto pair = tree.insert(std::pair<int, int>(0UL, 0UL));
        //REQUIRE(pair.first  == tree.front());
        //REQUIRE(pair.second == true);
    }

    SECTION("Test Tree::clear")
    {
        tree.clear();

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }

    SECTION("Test Tree::erase")
    {

    }

    SECTION("Test Tree::find")
    {

    }

    SECTION("Test Tree::at")
    {

    }

    SECTION("Test Tree::balance")
    {

    }
}

TEST_CASE( "Test the list with one element" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    REQUIRE(tree.empty() == true);
    REQUIRE(tree.size()  == 0UL);
    REQUIRE(tree.front() == null_iterator);
    REQUIRE(tree.end()   == null_iterator);


    SECTION("Test Tree::insert")
    {

    }

    SECTION("Test Tree::clear")
    {

    }

    SECTION("Test Tree::erase")
    {

    }

    SECTION("Test Tree::find")
    {

    }

    SECTION("Test Tree::at")
    {

    }

    SECTION("Test Tree::balance")
    {

    }
}

TEST_CASE( "Test the list with many elements" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    REQUIRE(tree.empty() == true);
    REQUIRE(tree.size()  == 0UL);
    REQUIRE(tree.front() == null_iterator);
    REQUIRE(tree.end()   == null_iterator);

    SECTION("Test Tree::insert")
    {

    }

    SECTION("Test Tree::clear")
    {

    }

    SECTION("Test Tree::erase")
    {

    }

    SECTION("Test Tree::find")
    {

    }

    SECTION("Test Tree::at")
    {

    }

    SECTION("Test Tree::balance")
    {

    }
}