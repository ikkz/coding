#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <numeric>

constexpr size_t MAX_SIZE = 5;

class Stack {
private:
  int raw[MAX_SIZE] = {0};
  int top = -1; // 指向当前栈顶元素的位置

public:
  bool empty() { return this->size() == 0; }

  bool full() { return this->size() == MAX_SIZE; }

  int size() { return this->top + 1; }

  bool push(int el) {
    if (this->full()) {
      return false;
    }
    this->raw[++this->top] = el;
    return true;
  }

  bool pop(int &el) {
    if (this->empty()) {
      return false;
    }
    el = this->raw[this->top--];
    return true;
  }
};

TEST_CASE("wd-2.1.01") {
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
