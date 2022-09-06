#pragma once

#include <vector>

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

template <typename T>
LinkList<T> build_link_list_from_vec(const std::vector<T> &vec) {
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