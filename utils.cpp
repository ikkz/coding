#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <exception>
#include <vector>

TEST_CASE("build_link_list") {
  using namespace linklist;

  SUBCASE("空链表") {
    auto list = build_link_list<int>({});
    CHECK(list != nullptr);
    CHECK_EQ(list->next, nullptr);
  }

  SUBCASE("1个数据") {
    auto list = build_link_list<int>({1});
    CHECK_NE(list, nullptr);
    CHECK_NE(list->next, nullptr);

    CHECK_EQ(list->next->data, 1);
    CHECK_EQ(list->next->next, nullptr);
  }

  SUBCASE("多个数据") {
    auto list = build_link_list<int>({1, 2, 3, 4, 5});
    auto p = list->next;
    auto i = 0;
    while (p) {
      CHECK_EQ(p->data, ++i);
      p = p->next;
    }
  }
}