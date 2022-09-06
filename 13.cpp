#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <vector>

using Vec = std::vector<int>;

int solve(Vec vec) {
  Vec map(vec.size(), 0);
  std::for_each(vec.begin(), vec.end(), [&](int i) { map[i]++; });
  for (int i = 0; i < map.size(); ++i) {
    if (map[i] > vec.size() / 2) {
      return i;
    }
  }
  return -1;
}

TEST_CASE("13") {
  SUBCASE("有主元素") {
    Vec vec = {0, 5, 5, 3, 5, 7, 5, 5};
    CHECK_EQ(5, solve(vec));
  }

  SUBCASE("无主元素") {
    Vec vec = {0, 5, 5, 3, 5, 1, 5, 7};
    CHECK_EQ(-1, solve(vec));
  }

  SUBCASE("空数组") {
    Vec vec = {};
    CHECK_EQ(-1, solve(vec));
  }

  SUBCASE("1个元素") {
    Vec vec = {0};
    CHECK_EQ(0, solve(vec));
  }

  SUBCASE("2个元素") {
    Vec vec = {1, 2};
    CHECK_EQ(-1, solve(vec));
  }
}