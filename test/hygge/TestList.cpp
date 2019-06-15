#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <hygge/List.h>

using namespace hygge;

TEST_CASE("Insert")
{
    List list;
    SECTION("Insert 1 element")
    {
        list.add(236.16, 0);
        REQUIRE(list.size() == 1);
        REQUIRE(list.get(0) == list.front());
        REQUIRE(list.get(0) == list.back());
        REQUIRE(list.get(0)->value == 236.16);

        SECTION("Remove 1 element")
        {
            list.remove(0);
            REQUIRE(list.size() == 0);
            REQUIRE(list.front() == nullptr);
            REQUIRE(list.back() == nullptr);
        }
    }
    SECTION("Insert 2 elements in sequence")
    {
        list.add(236.16, 0);
        REQUIRE(list.size() == 1);
        REQUIRE(list.get(0) == list.front());
        REQUIRE(list.get(0) == list.back());
        REQUIRE(list.get(0)->value == 236.16);

        list.add(18.23, 1);
        REQUIRE(list.size() == 2);
        REQUIRE(list.get(0) == list.front());
        REQUIRE(list.get(1) == list.back());
        REQUIRE(list.get(0)->value == 236.16);
        REQUIRE(list.get(1)->value == 18.23);

        SECTION("Remove 2 elements")
        {
            list.remove(0);
            REQUIRE(list.size() == 1);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(0) == list.back());
            REQUIRE(list.get(0)->value == 18.23);

            list.remove(0);
            REQUIRE(list.size() == 0);
            REQUIRE(list.front() == nullptr);
            REQUIRE(list.back() == nullptr);
        }

        SECTION("Remove 2 elements in reverse order")
        {
            list.remove(1);
            REQUIRE(list.size() == 1);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(0) == list.back());
            REQUIRE(list.get(0)->value == 236.16);

            list.remove(0);
            REQUIRE(list.size() == 0);
            REQUIRE(list.front() == nullptr);
            REQUIRE(list.back() == nullptr);
        }
    }

    SECTION("Insert several elements in different order")
    {
        list.add(236.16, 0);
        REQUIRE(list.size() == 1);
        REQUIRE(list.get(0) == list.front());
        REQUIRE(list.get(0) == list.back());
        REQUIRE(list.get(0)->value == 236.16);

        list.add(18.23, 0);
        REQUIRE(list.size() == 2);
        REQUIRE(list.get(0) == list.front());
        REQUIRE(list.get(1) == list.back());
        REQUIRE(list.get(0)->value == 18.23);
        REQUIRE(list.get(1)->value == 236.16);

        list.add(1.6, 1);
        REQUIRE(list.size() == 3);
        REQUIRE(list.get(0) == list.front());
        REQUIRE(list.get(2) == list.back());
        REQUIRE(list.get(0)->value == 18.23);
        REQUIRE(list.get(1)->value == 1.6);
        REQUIRE(list.get(2)->value == 236.16);

        list.add(268.333, 1);
        REQUIRE(list.size() == 4);
        REQUIRE(list.get(0) == list.front());
        REQUIRE(list.get(3) == list.back());
        REQUIRE(list.get(0)->value == 18.23);
        REQUIRE(list.get(1)->value == 268.333);
        REQUIRE(list.get(2)->value == 1.6);
        REQUIRE(list.get(3)->value == 236.16);

        SECTION("Remove elements")
        {
            list.remove(0);
            REQUIRE(list.size() == 3);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(2) == list.back());
            REQUIRE(list.get(0)->value == 268.333);
            REQUIRE(list.get(1)->value == 1.6);
            REQUIRE(list.get(2)->value == 236.16);

            list.remove(0);
            REQUIRE(list.size() == 2);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(1) == list.back());
            REQUIRE(list.get(0)->value == 1.6);
            REQUIRE(list.get(1)->value == 236.16);

            list.remove(0);
            REQUIRE(list.size() == 1);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(0) == list.back());
            REQUIRE(list.get(0)->value == 236.16);

            list.remove(0);
            REQUIRE(list.size() == 0);
            REQUIRE(list.front() == nullptr);
            REQUIRE(list.back() == nullptr);
        }

        SECTION("Remove elements in reverse order")
        {
            list.remove(3);
            REQUIRE(list.size() == 3);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(2) == list.back());
            REQUIRE(list.get(0)->value == 18.23);
            REQUIRE(list.get(1)->value == 268.333);
            REQUIRE(list.get(2)->value == 1.6);

            list.remove(2);
            REQUIRE(list.size() == 2);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(1) == list.back());
            REQUIRE(list.get(0)->value == 18.23);
            REQUIRE(list.get(1)->value == 268.333);

            list.remove(1);
            REQUIRE(list.size() == 1);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(0) == list.back());
            REQUIRE(list.get(0)->value == 18.23);

            list.remove(0);
            REQUIRE(list.size() == 0);
            REQUIRE(list.front() == nullptr);
            REQUIRE(list.back() == nullptr);
        }

        SECTION("Remove elements in different order")
        {
            list.remove(2);
            REQUIRE(list.size() == 3);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(2) == list.back());
            REQUIRE(list.get(0)->value == 18.23);
            REQUIRE(list.get(1)->value == 268.333);
            REQUIRE(list.get(2)->value == 236.16);

            list.remove(0);
            REQUIRE(list.size() == 2);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(1) == list.back());
            REQUIRE(list.get(0)->value == 268.333);
            REQUIRE(list.get(1)->value == 236.16);

            list.remove(1);
            REQUIRE(list.size() == 1);
            REQUIRE(list.get(0) == list.front());
            REQUIRE(list.get(0) == list.back());
            REQUIRE(list.get(0)->value == 268.333);

            list.remove(0);
            REQUIRE(list.size() == 0);
            REQUIRE(list.front() == nullptr);
            REQUIRE(list.back() == nullptr);
        }
    }
}