#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <vector>

using Vec = std::vector<int>;

int partition(Vec &vec, int begin, int end) {
    int pivot = vec[end];
    int next = begin;
    for (int it = begin; it < end; ++it) {
        if (vec[it] < pivot) {
            std::swap(vec[it], vec[next++]);
        }
    }
    std::swap(vec[next], vec[end]);
    return next;
}

void quick_sort_impl(Vec &vec, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int pivot = partition(vec, begin, end);
    quick_sort_impl(vec, begin, pivot - 1);
    quick_sort_impl(vec, pivot + 1, end);
}

void quick_sort(Vec &vec) {
    quick_sort_impl(vec, 0, static_cast<int>(vec.size() - 1));
}

int solve_quick_sort(Vec vec1, Vec vec2) {
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    quick_sort(vec1);
    return vec1[static_cast<size_t>(std::ceil(static_cast<double>(vec1.size()) / 2) - 1)];
}

TEST_CASE("11") {
    SUBCASE("快速排序") {
        {
            Vec s1 = {11, 13, 15, 17, 19};
            Vec s2 = {2, 4, 6, 8, 20};
            CHECK_EQ(11, solve_quick_sort(s1, s2));
        }
        {
            Vec s1 = {1};
            Vec s2 = {2};
            CHECK_EQ(1, solve_quick_sort(s1, s2));
        }
        {
            Vec s1 = {1};
            Vec s2 = {3, 2};
            CHECK_EQ(2, solve_quick_sort(s1, s2));
        }
    }
    SUBCASE("序号计数") {
        // TODO
    }
}