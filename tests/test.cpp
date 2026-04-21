#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <vector>
#include "min_merge_cost.hpp"
#include "sort_sqn.hpp"

using namespace dsac::priority;

TEST_CASE("min_merge_cost handles empty input correctly") {
    std::vector<int> files{};
    REQUIRE(min_merge_cost(files) == 0);
}