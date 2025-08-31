
extern "C" {
    #include "deque.h"
}

#include <catch2/catch_all.hpp>

TEST_CASE("deque")
{
    auto deque = deque_create();
    REQUIRE(deque);

    SECTION("after creation has no elements")
    {
        auto num_elems = deque_size(deque);
        REQUIRE(num_elems == 0);
    }

    SECTION("after push_back one element")
    {
        deque_push_back(deque, (void*)(intptr_t)0x1 );

        SECTION("has one element")
        {
            auto num_elems = deque_size(deque);
            REQUIRE(num_elems == 1);
        }

        SECTION("has expected element")
        {
            auto elem = (int)(intptr_t)deque_peek_back(deque);
            REQUIRE(elem == 0x1);
        }

        SECTION("pop_back removes one element")
        {
            deque_pop_back(deque);

            auto num_elems = deque_size(deque);
            REQUIRE(num_elems == 0);
        }
    }

    SECTION("after push_front one element")
    {
        deque_push_front(deque, (void*)(intptr_t)0x1 );

        SECTION("has one element")
        {
            auto num_elems = deque_size(deque);
            REQUIRE(num_elems == 1);
        }

        SECTION("has expected element")
        {
            auto elem = (int)(intptr_t)deque_peek_front(deque);
            REQUIRE(elem == 0x1);
        }

        SECTION("pop_front removes one element")
        {
            deque_pop_front(deque);

            auto num_elems = deque_size(deque);
            REQUIRE(num_elems == 0);
        }
    }

    SECTION("after push_back three elements")
    {
        deque_push_back(deque, (void*)(intptr_t)0x1 );
        deque_push_back(deque, (void*)(intptr_t)0x2 );
        deque_push_back(deque, (void*)(intptr_t)0x3 );

        SECTION("peek_back behaves like a stack")
        {
            int num_elems, elem;

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 3);

            elem = (int)(intptr_t)deque_peek_back(deque);
            REQUIRE(elem == 0x3);

            deque_pop_back(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 2);

            elem = (int)(intptr_t)deque_peek_back(deque);
            REQUIRE(elem == 0x2);

            deque_pop_back(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 1);

            elem = (int)(intptr_t)deque_peek_back(deque);
            REQUIRE(elem == 0x1);
        }

        SECTION("peek_front behaves like a queue")
        {
            int num_elems, elem;

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 3);

            elem = (int)(intptr_t)deque_peek_front(deque);
            REQUIRE(elem == 0x1);

            deque_pop_front(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 2);

            elem = (int)(intptr_t)deque_peek_front(deque);
            REQUIRE(elem == 0x2);

            deque_pop_front(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 1);

            elem = (int)(intptr_t)deque_peek_front(deque);
            REQUIRE(elem == 0x3);
        }
    }

    SECTION("after push_front three elements")
    {
        deque_push_front(deque, (void*)(intptr_t)0x1 );
        deque_push_front(deque, (void*)(intptr_t)0x2 );
        deque_push_front(deque, (void*)(intptr_t)0x3 );

        SECTION("peek_front behaves like a stack")
        {
            int num_elems, elem;

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 3);

            elem = (int)(intptr_t)deque_peek_front(deque);
            REQUIRE(elem == 0x3);

            deque_pop_front(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 2);

            elem = (int)(intptr_t)deque_peek_front(deque);
            REQUIRE(elem == 0x2);

            deque_pop_front(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 1);

            elem = (int)(intptr_t)deque_peek_front(deque);
            REQUIRE(elem == 0x1);
        }

        SECTION("peek_back behaves like a queue")
        {
            int num_elems, elem;

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 3);

            elem = (int)(intptr_t)deque_peek_back(deque);
            REQUIRE(elem == 0x1);

            deque_pop_back(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 2);

            elem = (int)(intptr_t)deque_peek_back(deque);
            REQUIRE(elem == 0x2);

            deque_pop_back(deque);

            num_elems = deque_size(deque);
            REQUIRE(num_elems == 1);

            elem = (int)(intptr_t)deque_peek_back(deque);
            REQUIRE(elem == 0x3);
        }
    }
}
