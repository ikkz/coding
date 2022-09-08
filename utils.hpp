#pragma once

#include <algorithm>
#include <vector>
namespace linklist {

template <typename T> struct LinkNode {
  T data;
  LinkNode<T> *next;
};

template <typename T> struct DoubleLinkNode {
  T data;
  DoubleLinkNode<T> *prev, *next;
};

template <typename T> using LinkList = LinkNode<T> *;

template <typename T> using DoubleLinkList = DoubleLinkNode<T> *;

// 尾插法
template <typename T>
LinkList<T> build_link_list(const std::vector<T> &vec) {
  auto head = new LinkNode<T>();
  auto p = head;
  for (auto &i : vec) {
    auto node = new LinkNode<T>();
    node->data = i;
    node->next = nullptr;
    p->next = node;
    p = p->next;
  }
  return head;
}

template <typename T>
bool is_link_list_equal(LinkList<T> list1, LinkList<T> list2) {
  list1 = list1->next;
  list2 = list2->next;
  while (list1 && list2 && list1->data == list2->data) {
    list1 = list1->next;
    list2 = list2->next;
  }
  return list1 == nullptr && list2 == nullptr;
}

// 复制链表
template <typename T> LinkList<T> copy(LinkList<T> list) {
  auto head = new LinkNode<T>();
  auto p = head;
  for (auto it = list->next; it; it = it->next) {
    auto node = new LinkNode<T>();
    node->data = it->data;
    node->next = nullptr;
    p->next = node;
    p = p->next;
  }
  return head;
}

} // namespace linklist

namespace tree {
template <typename T> struct BinaryTreeNode {
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;
};
} // namespace tree