#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <string>
#include <vector>

using namespace tree;

using Node = BinaryTreeNode<std::string>;

std::string dfs(Node *node) {
  // 存在只有一个操作数的情况
  if (!node) {
    return "";
  }
  // 没有左右操作数即不是操作符，返回该操作数
  if (!node->left && !node->right) {
    return node->data;
  }
  return "(" + dfs(node->left) + node->data + dfs(node->right) + ")";
}

std::string solve(Node *node) {
  if (!node) {
    return "";
  }
  // 顶层不需要括号
  std::string result = "";
  if (node->left) {
    result += dfs(node->left);
  }
  result += node->data;
  if (node->right) {
    result += dfs(node->right);
  }
  return result;
}

TEST_CASE("17") {
  SUBCASE("1") {
    // 1层
    auto root = new Node("*");

    // 2 层
    auto left = new Node("+");
    auto right = new Node("*");
    root->left = left;
    root->right = right;

    // 3 层
    left->left = new Node("a");
    left->right = new Node("b");
    right->left = new Node("c");
    right->right = new Node("-", nullptr, new Node("d"));

    CHECK_EQ(solve(root), std::string("(a+b)*(c*(-d))"));
  }

  SUBCASE("1") {
    // 1层
    auto root = new Node("+");

    // 2 层
    auto left = new Node("*");
    auto right = new Node("-");
    root->left = left;
    root->right = right;

    // 3 层
    left->left = new Node("a");
    left->right = new Node("b");
    right->right = new Node("-", new Node("c"), new Node("d"));

    CHECK_EQ(solve(root), std::string("(a*b)+(-(c-d))"));
  }
}