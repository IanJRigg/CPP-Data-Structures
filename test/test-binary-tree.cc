#include <catch.hpp>
#include <binary-tree.h>

TEST_CASE( "Test the Binary Tree with 0, 1, and many elements" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    SECTION("Empty Tree")
    {
        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }
}