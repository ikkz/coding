// https://leetcode.cn/problems/binary-tree-inorder-traversal/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "utils.hpp"
#include "doctest.h"
#include <stack>

using TreeNode = tree::BinaryTreeNode<int>;

class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode *p) {
    auto stack = std::stack<TreeNode *>();
    auto result = std::vector<int>();
    while (p || !stack.empty()) {
      if (p) {
        stack.push(p);
        p = p->left;
      } else {
        p = stack.top();
        stack.pop();
        result.push_back(p->data);
        p = p->right;
      }
    }
    return result;
  }
};