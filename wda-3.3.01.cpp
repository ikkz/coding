#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

// 双亲表示法

#define MAX_TREE_NODE 100
struct Node {
    int parent = 0;
    int data = 0;
};

struct Tree {
    Node tree[MAX_TREE_NODE];
    int n = 0;
};
