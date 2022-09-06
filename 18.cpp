#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <exception>
#include <vector>

using Vec = std::vector<int>;

int solve(const Vec &vec) {
  Vec map(vec.size() + 2);
  for (auto i : vec) {
    if (i >= 0 && i <= vec.size() + 1) {
      map[i]++;
    }
  }
  for (size_t i = 1; i < map.size(); i++) {
    if (!map[i]) {
      return i;
    }
  }
  throw std::logic_error("不会到这");
}

TEST_CASE("18") {
  {
    Vec vec = {-5, 3, 2, 3};
    CHECK_EQ(1, solve(vec));
  }
  {
    Vec vec = {1, 2, 3};
    CHECK_EQ(4, solve(vec));
  }
}