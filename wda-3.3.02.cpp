#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

// 孩子表示法

struct Child {
    int id = 0;
    Child *next;
};

struct Node {
    int data = 0;
    Child *first_child = nullptr;
};

Node tree[30];
