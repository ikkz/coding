#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <vector>

using namespace linklist;
using Node = LinkNode<char>;
using List = LinkList<char>;

void forward(Node *&node) { node = node->next; }

int length(List list) {
  int len = -1;
  for (; list; len++, forward(list))
    ;
  return len;
}

char solve(List str1, List str2) {
  int len1 = length(str1);
  int len2 = length(str2);
  int diff = std::abs(len1 - len2);
  while (diff--) {
    forward(len1 < len2 ? str2 : str1);
  }
  while (str1 != str2) {
    forward(str1);
    forward(str2);
  }
  return str1->data;
}

TEST_CASE("12") {
  auto str1 = build_link_list_from_vec<char>({'l', 'o', 'a', 'd'});
  auto str2 = build_link_list_from_vec<char>({'b', 'e'});
  auto tail = build_link_list_from_vec<char>({'i', 'n', 'g'})->next;

  auto p = str1;
  for (; p->next; p = p->next)
    ;
  p->next = tail;

  p = str2;
  for (; p->next; p = p->next)
    ;
  p->next = tail;

  CHECK_EQ(solve(str1, str2), 'i');
}