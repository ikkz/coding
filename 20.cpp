#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <numeric>
#include <vector>

using Vec = std::vector<int>;

int distance(int a, int b, int c) {
  return std::abs(a - b) + std::abs(b - c) + std::abs(c - a);
}

int solve(Vec s1, Vec s2, Vec s3) {
  int min = INT_MAX;
  int i = 0, j = 0, k = 0;
  // 存在还没到末尾的下标
  while (i != s1.size() - 1 || j != s2.size() - 1 || k != s3.size() - 1) {
    // 分别试着移动三个下标，计算距离
    // 如果在最后一个了则不能移动，距离设置为 INT_MAX
    int distance1 =
        i != s1.size() - 1 ? distance(s1[i + 1], s2[j], s3[k]) : INT_MAX;
    int distance2 =
        j != s2.size() - 1 ? distance(s1[i], s2[j + 1], s3[k]) : INT_MAX;
    int distance3 =
        k != s3.size() - 1 ? distance(s1[i], s2[j], s3[k + 1]) : INT_MAX;

    // 比较得最小的移动
    if (distance1 < distance2 && distance1 < distance3) {
      i++;
      min = std::min(distance1, min);
    } else if (distance2 < distance1 && distance2 < distance3) {
      j++;
      min = std::min(distance2, min);
    } else {
      k++;
      min = std::min(distance3, min);
    }
  }
  return min;
}

TEST_CASE("20") {
  CHECK_EQ(solve(Vec{-1, 0, 9}, Vec{-25, -10, 10, 11}, Vec{2, 9, 17, 30, 41}),
           2);

  CHECK_EQ(
      solve(Vec{-1, 0, 9}, Vec{-25, -10, 0, 10, 11}, Vec{0, 2, 9, 17, 30, 41}),
      0);
}