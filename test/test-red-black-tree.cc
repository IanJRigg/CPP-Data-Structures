//#include <catch.hpp>
//#include <red-black-tree.h>
//
//#include <unistd.h>
//#include <stdexcept>
//
//const auto null_iterator = Binary::Iterator<int, int>(nullptr);
/*
TEST_CASE( "Red Black Iterator Increment Behavior" )
{
    Binary::Red_Black_Tree<int, int> tree;

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


TEST_CASE( "Red Black Iterator Decrement Behavior" )
{
    Binary::Red_Black_Tree<int, int> tree;

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

TEST_CASE( "Red Black Empty Tree Behavior" )
{
    Binary::Red_Black_Tree<int, int> tree;

    REQUIRE(tree.empty() == true);
    REQUIRE(tree.size()  == 0UL);
    REQUIRE(tree.front() == null_iterator);
    REQUIRE(tree.back()  == null_iterator);
    REQUIRE(tree.end()   == null_iterator);
    REQUIRE(tree.rend()  == null_iterator);

    SECTION("Test Red_Black_Tree::insert")
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

    SECTION("Test Red_Black_Tree::clear")
    {
        tree.clear();

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
    }

    SECTION("Test Red_Black_Tree::erase")
    {
        tree.erase(null_iterator);

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);
    }

    SECTION("Test Red_Black_Tree::find")
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

    SECTION("Test Red_Black_Tree::at")
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

TEST_CASE( "Red Black Test the list with one element" )
{
    Binary::Red_Black_Tree<int, int> tree;

    const auto pair_0 = tree.insert(std::pair<int, int>(0UL, 0UL));

    REQUIRE(tree.empty() == false);
    REQUIRE(tree.size()  == 1UL);
    REQUIRE(tree.front() == pair_0.first);
    REQUIRE(tree.back()  == pair_0.first);
    REQUIRE(tree.end()   == null_iterator);
    REQUIRE(tree.rend()  == null_iterator);


    SECTION("Test Red_Black_Tree::insert")
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

    SECTION("Test Red_Black_Tree::clear")
    {
        tree.clear();

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }

    SECTION("Test Red_Black_Tree::erase")
    {
        tree.erase(tree.front());

        REQUIRE(tree.empty() == true);
        REQUIRE(tree.size()  == 0UL);
        REQUIRE(tree.front() == null_iterator);
        REQUIRE(tree.back()  == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.end()   == null_iterator);
    }

    SECTION("Test Red_Black_Tree::find")
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

    SECTION("Test Red_Black_Tree::at")
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

TEST_CASE( "Red Black Test the list with many elements" )
{
    SECTION("Red Black Test on node with no children")
    {
        Binary::Red_Black_Tree<int, int> tree;

        const auto pair_2 = tree.insert(std::pair<int, int>(2UL, 0UL));
        const auto pair_1 = tree.insert(std::pair<int, int>(1UL, 0UL));
        const auto pair_3 = tree.insert(std::pair<int, int>(3UL, 0UL));

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 3UL);
        REQUIRE(tree.front() == pair_1.first);
        REQUIRE(tree.back()  == pair_3.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);

        SECTION("Test Red_Black_Tree::insert")
        {
            auto pair_4 = tree.insert(std::pair<int, int>(4UL, 0UL));

            // Redundant, but leaving it for consistency
            REQUIRE(pair_4.first  == tree.back());
            REQUIRE(pair_4.second == true);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 4UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::clear")
        {
            tree.clear();

            REQUIRE(tree.empty() == true);
            REQUIRE(tree.size()  == 0UL);
            REQUIRE(tree.front() == null_iterator);
            REQUIRE(tree.back()  == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::erase")
        {
            tree.erase(tree.back());

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 2UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_2.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::find")
        {
            auto it = tree.find(3UL);

            REQUIRE(it == tree.back());

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_3.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }

        SECTION("Test Red_Black_Tree::at")
        {
            int value = tree.at(3UL);

            REQUIRE(value == 0UL);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_3.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }
    }

    SECTION("Red Black Test on node with a left child")
    {
        Binary::Red_Black_Tree<int, int> tree;

        const auto pair_1 = tree.insert(std::pair<int, int>(1UL, 0UL));
        const auto pair_4 = tree.insert(std::pair<int, int>(4UL, 0UL));
        const auto pair_2 = tree.insert(std::pair<int, int>(2UL, 0UL));

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 3UL);
        REQUIRE(tree.front() == pair_1.first);
        REQUIRE(tree.back()  == pair_4.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);

        SECTION("Test Red_Black_Tree::insert")
        {
            auto pair_5 = tree.insert(std::pair<int, int>(5UL, 0UL));

            REQUIRE(pair_5.first  == tree.back());
            REQUIRE(pair_5.second == true);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 4UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_5.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::clear")
        {
            tree.clear();

            REQUIRE(tree.empty() == true);
            REQUIRE(tree.size()  == 0UL);
            REQUIRE(tree.front() == null_iterator);
            REQUIRE(tree.back()  == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::erase")
        {
            tree.erase(pair_4.first);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 2UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_2.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::find")
        {
            auto it = tree.find(4UL);

            REQUIRE(it == tree.back());

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }

        SECTION("Test Red_Black_Tree::at")
        {
            int value = tree.at(4UL);

            REQUIRE(value == 0UL);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }

    }

    SECTION("Red Black Test on a node with a right child")
    {
        Binary::Red_Black_Tree<int, int> tree;

        const auto pair_1 = tree.insert(std::pair<int, int>(1UL, 0UL));
        const auto pair_2 = tree.insert(std::pair<int, int>(2UL, 0UL));
        const auto pair_4 = tree.insert(std::pair<int, int>(4UL, 0UL));

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 3UL);
        REQUIRE(tree.front() == pair_1.first);
        REQUIRE(tree.back()  == pair_4.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);

        SECTION("Test Red_Black_Tree::insert")
        {
            auto pair_3 = tree.insert(std::pair<int, int>(3UL, 0UL));

            REQUIRE(pair_3.first  == --(tree.back()));
            REQUIRE(pair_3.second == true);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 4UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::clear")
        {
            tree.clear();

            REQUIRE(tree.empty() == true);
            REQUIRE(tree.size()  == 0UL);
            REQUIRE(tree.front() == null_iterator);
            REQUIRE(tree.back()  == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::erase")
        {
            tree.erase(pair_2.first);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 2UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::find")
        {
            auto it = tree.find(2UL);

            REQUIRE(it == pair_2.first);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }

        SECTION("Test Red_Black_Tree::at")
        {
            int value = tree.at(2UL);

            REQUIRE(value == 0UL);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }

    }

    SECTION("Red Black Test on a node with both chilren")
    {
        Binary::Red_Black_Tree<int, int> tree;

        const auto pair_2 = tree.insert(std::pair<int, int>(2UL, 0UL));
        const auto pair_1 = tree.insert(std::pair<int, int>(1UL, 0UL));
        const auto pair_3 = tree.insert(std::pair<int, int>(3UL, 0UL));

        REQUIRE(tree.empty() == false);
        REQUIRE(tree.size()  == 3UL);
        REQUIRE(tree.front() == pair_1.first);
        REQUIRE(tree.back()  == pair_3.first);
        REQUIRE(tree.end()   == null_iterator);
        REQUIRE(tree.rend()  == null_iterator);

        SECTION("Test Red_Black_Tree::insert")
        {
            auto pair_4 = tree.insert(std::pair<int, int>(4UL, 0UL));

            REQUIRE(pair_4.first  == tree.back());
            REQUIRE(pair_4.second == true);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 4UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_4.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::clear")
        {
            tree.clear();

            REQUIRE(tree.empty() == true);
            REQUIRE(tree.size()  == 0UL);
            REQUIRE(tree.front() == null_iterator);
            REQUIRE(tree.back()  == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::erase")
        {
            tree.erase(pair_2.first);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 2UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_3.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.rend()  == null_iterator);
        }

        SECTION("Test Red_Black_Tree::find")
        {
            auto it = tree.find(2UL);

            REQUIRE(it == pair_2.first);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_3.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }

        SECTION("Test Red_Black_Tree::at")
        {
            int value = tree.at(2UL);

            REQUIRE(value == 0UL);

            REQUIRE(tree.empty() == false);
            REQUIRE(tree.size()  == 3UL);
            REQUIRE(tree.front() == pair_1.first);
            REQUIRE(tree.back()  == pair_3.first);
            REQUIRE(tree.end()   == null_iterator);
            REQUIRE(tree.end()   == null_iterator);
        }
    }
}
*/