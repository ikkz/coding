#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <vector>

using Vec = std::vector<int>;

int partition(Vec &vec, int begin, int end) {
  int pivot = vec[end];
  int next = begin, it = begin;
  while (it < end) {
    if (vec[it] < pivot) {
      std::swap(vec[it], vec[next++]);
    }
    it++;
  }
  std::swap(vec[next], vec[end]);
  return next;
}
// 0 1 2 3 4
//     |
//    5/2

// 0 1 2 3
//     |
//    4/2
void quick_sort(Vec &vec, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pivot = partition(vec, begin, end);
  int mid = vec.size() / 2; // 后面集合的起始元素
  if (pivot < mid) {
    quick_sort(vec, pivot + 1, end);
  }
  if (pivot > mid) {
    quick_sort(vec, begin, pivot - 1);
  }
}

std::tuple<int, int> solve(Vec &vec) {
  quick_sort(vec, 0, vec.size() - 1);
  int delta_n = vec.size() % 2;

  int mid = vec.size() / 2;
  int s1 = 0, s2 = 0;
  for (int i = 0; i < vec.size(); i++) {
    (i < mid ? s1 : s2) += vec[i];
  }
  int delta_s = std::abs(s1 - s2);

  return std::make_tuple(delta_n, delta_s);
}

TEST_CASE("16") {
  SUBCASE("边界") {
    auto vec = Vec{1, 9};
    CHECK_EQ(solve(vec), std::make_tuple(0, 8));
  }
  SUBCASE("奇数个") {
    auto vec = Vec{1, 4, 2, 3, 5};
    CHECK_EQ(solve(vec), std::make_tuple(1, 9));
  }
  SUBCASE("偶数个") {
    auto vec = Vec{1, 4, 2, 3};
    CHECK_EQ(solve(vec), std::make_tuple(0, 4));
  }
}
