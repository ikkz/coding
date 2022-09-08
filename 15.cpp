#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <vector>

using namespace linklist;

using List = LinkList<int>;

List solve(List list, int n) {
  std::vector<bool> exists(n + 1, false);
  // 快慢指针
  auto previous = list;
  auto current = list->next;
  while (current) {
    int abs = std::abs(current->data);
    if (exists[abs]) {
      // 存在则删除当前节点
      previous->next = current->next;
      delete current;
      current = previous->next;
    } else {
      // 否则跳过
      exists[abs] = true;
      previous = current;
      current = current->next;
    }
  }
  return list;
}

TEST_CASE("18") {
  auto list = build_link_list<int>({21, -15, -15, -7, 15});

  CHECK(is_link_list_equal(solve(copy(list), 21),
                           build_link_list<int>({21, -15, -7})));
}