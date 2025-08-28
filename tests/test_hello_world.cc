
extern "C" {
    #include "hello_world.h"
}

#include <cstring>

#include <catch2/catch_all.hpp>

TEST_CASE("get_hello_world")
{
    auto cmp = strcmp(get_hello_world(), "Hello, World!");
    REQUIRE(cmp == 0);
}
