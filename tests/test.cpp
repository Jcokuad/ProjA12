#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <vector>
#include "min_merge_cost.hpp"
#include "sort_sqn.hpp"

TEST_CASE("min_merge_cost handles 1 and less inputs correctly") {
    std::vector<int> files{};
    REQUIRE(min_merge_cost(files) == 0);

    files.push_back(5);
    REQUIRE(min_merge_cost(files) == 0);
}

TEST_CASE("min_merge_cost handles 2 or more files correctly") {
    std::vector<int> files{10, 20, 30, 40, 50};
    REQUIRE(min_merge_cost(files) == 330);
}

TEST_CASE("sort_sqn handles empty input correctly") {
    std::vector<int> v{};
    std::vector<int> expected_res{};
    REQUIRE(top_sqrtN_sorted(v) == expected_res);
}

TEST_CASE("sort_sqn handles 1 input correctly") {
    std::vector<int> v{5};
    std::vector<int> expected_res{5};
    REQUIRE(top_sqrtN_sorted(v) == expected_res);
}

TEST_CASE("sort_sqn handles multiple inputs correctly with negative and duplicate values") {
    std::vector<int> v{8, 12, 49, -3, 2, 5, 6, 8, -4, 9, 2, -2, 2, -5};
    // N = 14, k = ceil(sqrt(N)) = 4
    std::vector<int> expected_res{49, 12, 9, 8};
    REQUIRE(top_sqrtN_sorted(v) == expected_res);
}

TEST_CASE("sort_sqn handles multiple negative inputs correctly") {
    std::vector<int> v{-4, -6, -2, -2, -3, -5};
    // N = 6, k = ceil(sqrt(N)) = 3
    std::vector<int> expected_res{-2, -2, -3};
    REQUIRE(top_sqrtN_sorted(v) == expected_res);
}