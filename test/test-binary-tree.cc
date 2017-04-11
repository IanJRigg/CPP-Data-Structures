#include <catch.hpp>
#include <binary-tree.h>

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
        auto it = tree.insert(std::pair<int, int>(0UL, 0UL));
    }

    SECTION("Test Tree::clear")
    {
        tree.clear();
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