#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <doctest.h>
#include <vector>

template<typename T>
std::vector<T> solve(std::vector<T> array, int p) {
    p = p % array.size();
    auto reverse = [&](int begin, int end) {
        while (begin < end) {
            std::swap(array[begin++], array[end--]);
        }
    };
    reverse(0, p - 1);
    reverse(p, array.size() - 1);
    reverse(0, array.size() - 1);
    return array;
}

TEST_CASE("2_10") {
    using Vec = std::vector<int>;
    SUBCASE("空数组") {
        CHECK_EQ(solve(Vec{}, 1), Vec{});
    }
    SUBCASE("1") {
        CHECK_EQ(solve(Vec{1}, 1), Vec{1});
    }
    SUBCASE("2") {
        CHECK_EQ(solve(Vec{1, 2}, 1), Vec{2, 1});
    }
    SUBCASE("10") {
        CHECK_EQ(solve(Vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2), Vec{3, 4, 5, 6, 7, 8, 9, 10, 1, 2});
    }
}