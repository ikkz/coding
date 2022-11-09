#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

// 孩子兄弟表示法

struct Node {
    char data;
    Node *child = nullptr;
    Node *sibling = nullptr;
};