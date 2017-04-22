#include <catch.hpp>
#include <binary-tree.h>

#include <unistd.h>
#include <stdexcept>


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
        REQUIRE((*it).first > (*prev).first);
        prev++;
    }
}


TEST_CASE( "Iterator Decrement Behavior" )
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
    for(auto it = ++tree.back(); it != tree.rend(); it--)
    {
        REQUIRE((*it).first < (*prev).first);
        prev--;
    }
}

TEST_CASE( "Empty Tree Behavior" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    REQUIRE(tree.empty() == true);
    REQUIRE(tree.size()  == 0UL);
    REQUIRE(tree.front() == null_iterator);
    REQUIRE(tree.back()  == null_iterator);
    REQUIRE(tree.end()   == null_iterator);
    REQUIRE(tree.rend()  == null_iterator);

    SECTION("Test Tree::insert")
    {
        auto pair = tree.insert(std::pair<int, int>(0UL, 0UL));

        REQUIRE(pair.first  == tree.back());
        REQUIRE(pair.first  == tree.front());
        REQUIRE(pair.second == true);

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 1UL);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
    }

    SECTION("Test Tree::clear")
    {
        tree.clear();

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
    }

    SECTION("Test Tree::erase")
    {
        tree.erase(null_iterator);

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
    }

    SECTION("Test Tree::find")
    {
        auto it = tree.find(0);

        REQUIRE(it == null_iterator);

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
    }

    SECTION("Test Tree::at")
    {
        bool success = false;
        try
        {
            auto retval = tree.at(0);
        }
        catch(std::out_of_range ex)
        {
            std::string err = std::string(ex.what());
            REQUIRE(err.compare("Key is out of range") == 0UL);
            success = true;
        }
        REQUIRE(success      == true);

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
    }
}

TEST_CASE( "Test the list with one element" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    const auto pair_0 = tree.insert(std::pair<int, int>(0UL, 0UL));

    REQUIRE(tree.empty() == false);
    REQUIRE(tree.size()  == 1UL);
    REQUIRE(tree.front() == pair_0.first);
    REQUIRE(tree.back()  == pair_0.first);
    REQUIRE(tree.end()   == null_iterator);
    REQUIRE(tree.rend()  == null_iterator);


    SECTION("Test Tree::insert")
    {
        auto pair_1 = tree.insert(std::pair<int, int>(1UL, 0UL));

        REQUIRE(pair_1.first  == (++tree.front()));
        REQUIRE(pair_1.first  == tree.back());
        REQUIRE(pair_1.second == true);

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 2UL);
        REQUIRE(tree.front() == pair_0.first);
        REQUIRE(tree.back()  == pair_1.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }

    SECTION("Test Tree::clear")
    {
        tree.clear();

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }

    SECTION("Test Tree::erase")
    {
        tree.erase(tree.front());

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }

    SECTION("Test Tree::find")
    {
        auto it = tree.find(0UL);

        REQUIRE(it == tree.front());

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 1UL);
        REQUIRE(tree.front() == pair_0.first);
        REQUIRE(tree.back()  == pair_0.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }

    SECTION("Test Tree::at")
    {
        int value = tree.at(0UL);

        REQUIRE(value == 0UL);

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 1UL);
        REQUIRE(tree.front() == pair_0.first);
        REQUIRE(tree.back()  == pair_0.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }
}

TEST_CASE( "Test the list with many elements" )
{
    const auto null_iterator = Binary::Iterator<int, int>(nullptr);
    Binary::Tree<int, int> tree;

    const auto pair_1 = tree.insert(std::pair<int, int>(1UL, 0UL));
    const auto pair_2 = tree.insert(std::pair<int, int>(2UL, 0UL));
    const auto pair_3 = tree.insert(std::pair<int, int>(3UL, 0UL));

    REQUIRE(tree.empty() == false);
    REQUIRE(tree.size()  == 3UL);
    REQUIRE(tree.front() == pair_1.first);
    REQUIRE(tree.back()  == pair_3.first);
    REQUIRE(tree.end()   == null_iterator);
    REQUIRE(tree.rend()  == null_iterator);

    SECTION("Test Tree::insert")
    {
        auto pair_0 = tree.insert(std::pair<int, int>(0UL, 0UL));

        REQUIRE(pair_0.first  == tree.front());
        REQUIRE(pair_0.second == true);

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 4UL);
        REQUIRE(tree.front() == pair_0.first);
        REQUIRE(tree.back()  == pair_3.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
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
}