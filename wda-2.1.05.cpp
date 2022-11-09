#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <numeric>

#include "utils.hpp"

using Node = linklist::DoubleLinkNode<int>;

constexpr size_t MAX_SIZE = 5;

class Stack {
private:
    Node *tail = nullptr;

public:
    bool empty() { return this->tail == nullptr; }

    bool full() { return this->size() == MAX_SIZE; }

    int size() {
        if (empty()) {
            return 0;
        }
        auto len = 1;
        auto p = this->tail->next;
        while (p != this->tail) {
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
        if (this->empty()) {
            this->tail = node;
            node->next = node;
            node->prev = node;
            return true;
        }
        node->next = tail->next;
        node->prev = tail;
        tail->next = node;
        node->next->prev = node;
        tail = node;
        return true;
    }

    bool pop(int &el) {
        if (this->empty()) {
            return false;
        }
        el = tail->data;
        if (this->size() == 1) {
            delete tail;
            tail = nullptr;
            return true;
        }
        auto node = tail;
        tail->prev->next = node->next;
        node->next->prev = tail->prev;
        tail = tail->prev;
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

        stack.push(3);
        stack.pop(el);
        CHECK_EQ(el, 3);

        stack.pop(el);
        stack.pop(el);
        CHECK_EQ(el, 1);
        CHECK_EQ(stack.size(), 0);

        CHECK_FALSE(stack.pop(el));
        CHECK_EQ(stack.size(), 0);
    }
}
