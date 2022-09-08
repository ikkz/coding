#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <vector>

using namespace tree;

using Node = BinaryTreeNode<int>;

int dfs(Node *node, int depth /* 当前深度即路径长度 */) {
  if (!node) {
    return 0;
  }
  if (node->left == nullptr && node->right == nullptr) {
    // 叶子结点，返回权值
    return (depth * (node->data));
  }
  // 非叶子结点返回子树权值之和
  return dfs(node->left, depth + 1) + dfs(node->right, depth + 1);
}

int solve(Node *tree) { return dfs(tree, 0); }

TEST_CASE("14") {
  SUBCASE("空树") { CHECK_EQ(solve(nullptr), 0); }

  SUBCASE("一个节点") { CHECK_EQ(solve(new Node(5)), 0); }

  SUBCASE("二层节点") {
    CHECK_EQ(solve(new Node(-1, new Node(2), new Node(3))), 5);
  }

  SUBCASE("三层节点") {
    // 1层
    auto root = new Node(-1);

    // 2 层
    auto left = new Node(-1);
    auto right = new Node(8);
    root->left = left;
    root->right = right;

    // 3 层
    left->left = new Node(4);
    left->right = new Node(7);

    auto wpl = 8 + 4 * 2 + 7 * 2;
    CHECK_EQ(solve(root), wpl);
  }
}