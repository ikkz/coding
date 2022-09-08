#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <vector>

using Vec = std::vector<int>;
using namespace linklist;

int solve(LinkList<int> list, int k) {
  auto slow = list;
  auto quick = list;
  while (k--) {
    quick = quick->next;
  }
  while (quick) {
    slow = slow->next;
    quick = quick->next;
  }
  return slow->data;
}

TEST_CASE("09") {
  CHECK_EQ(13, solve(build_link_list<int>({11, 13, 15, 17, 19}), 4));
  CHECK_EQ(11, solve(build_link_list<int>({11, 13, 15, 17, 19}), 5));
  CHECK_EQ(19, solve(build_link_list<int>({11, 13, 15, 17, 19}), 1));
}