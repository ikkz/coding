#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <exception>
#include <numeric>
#include <vector>

using namespace linklist;

using List = LinkList<int>;
using Node = LinkNode<int>;

int length(List list) {
  int len = -1;
  for (; list; len++, list = list->next)
    ;
  return len;
}
// 从链表头部取下一个节点
Node *pick_first(List list) {
  auto node = list->next;
  if (node) {
    list->next = node->next;
    node->next = nullptr;
  }
  return node;
}

List solve(List list) {
  auto forward = new Node();
  auto tail = forward;

  auto backward = new Node();

  int len = (length(list) + 1) / 2;

  // 前半部分全部尾插法进正向链表
  while (len--) {
    auto node = pick_first(list);
    tail->next = node;
    tail = tail->next;
  }

  // 剩下的全部头插法进反向链表
  while (true) {
    auto node = pick_first(list);
    if (!node) {
      break;
    }
    node->next = backward->next;
    backward->next = node;
  }

  // 尾插法合并
  tail = list;
  while (forward->next || backward->next) {
    auto forward_node = pick_first(forward);
    auto backward_node = pick_first(backward);

    if (forward_node) {
      tail->next = forward_node;
      tail = forward_node;
    }
    if (backward_node) {
      tail->next = backward_node;
      tail = backward_node;
    }
  }
  return list;
}

TEST_CASE("19") {
  SUBCASE("偶数个") {
    std::vector<int> numbers;
    numbers.resize(10);
    std::iota(numbers.begin(), numbers.end(), 1);
    auto list = build_link_list<int>(numbers);

    CHECK(is_link_list_equal(
        solve(list), build_link_list<int>({1, 10, 2, 9, 3, 8, 4, 7, 5, 6})));
  }

  SUBCASE("奇数个") {
    std::vector<int> numbers;
    numbers.resize(9);
    std::iota(numbers.begin(), numbers.end(), 1);
    auto list = build_link_list<int>(numbers);

    CHECK(is_link_list_equal(
        solve(list), build_link_list<int>({1, 9, 2, 8, 3, 7, 4, 6, 5})));
  }
}
