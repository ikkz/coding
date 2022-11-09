#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <numeric>

#include "utils.hpp"

using Node = linklist::LinkNode<int>;

constexpr size_t MAX_SIZE = 5;

class Stack {
private:
  Node *head = new Node();

public:
  bool empty() { return this->head->next == nullptr; }

  bool full() { return this->size() == MAX_SIZE; }

  int size() {
    auto len = 0;
    auto p = this->head->next;
    while (p != nullptr) {
      len++;
      p = p->next;
    }
    return len;
  }

  bool push(int el) {
    if (this->full()) {
      return false;
    }
    auto node = new Node();
    node->data = el;
    node->next = head->next;
    head->next = node;
    return true;
  }

  bool pop(int &el) {
    if (this->empty()) {
      return false;
    }
    auto node = head->next;
    head->next = node->next;
    el = node->data;
    delete node;
    return true;
  }
};

TEST_CASE("wd-2.1.03") {
  SUBCASE("初始化") {
    auto stack = Stack();

    CHECK_EQ(stack.size(), 0);
    CHECK(stack.empty());
    CHECK_FALSE(stack.full());
  }

  SUBCASE("元素") {
    auto stack = Stack();

    stack.push(1);

    CHECK_EQ(stack.size(), 1);
    CHECK_FALSE(stack.empty());
    CHECK_FALSE(stack.full());

    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    CHECK_EQ(stack.size(), 5);
    CHECK_FALSE(stack.empty());
    CHECK(stack.full());

    CHECK_FALSE(stack.push(6));

    int el;
    stack.pop(el);
    CHECK_EQ(el, 5);
    CHECK_EQ(stack.size(), 4);

    stack.pop(el);
    stack.pop(el);
    stack.pop(el);
    stack.pop(el);
    CHECK_EQ(el, 1);
    CHECK_EQ(stack.size(), 0);

    CHECK_FALSE(stack.pop(el));
    CHECK_EQ(stack.size(), 0);
  }
}
