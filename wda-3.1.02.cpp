#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

// 写代码：定义顺序存储的二叉树（数组实现，树的结点从数组下标1开始存储）

template<size_t N>
struct BTree {
    int raw[N + 1];
    size_t size = N;

    BTree(const std::initializer_list<int> &list = {}) {
        auto it = list.begin();
        for (int i = 1; i <= list.size() && i <= N; ++i) {
            raw[i] = *(it++);
        }
    }
};

int find_father(int i) {
    return i / 2;
}

int left_child(int i) {
    return i * 2;
}

int right_child(int i) {
    return i * 2 + 1;
}

template<size_t N>
std::string pre_order(const BTree<N> &bt, int i = 1) {
    int left = left_child(i);
    int right = right_child(i);
    if (i > bt.size) {
        return "";
    }
    return std::to_string(bt.raw[i]) + pre_order(bt, left)
           + pre_order(bt, right);
}

TEST_CASE("wda-3.1.02.cpp") {
    CHECK_EQ(find_father(4), 2);
    CHECK_EQ(find_father(5), 2);
    CHECK_EQ(find_father(1), 0);
    CHECK_EQ(find_father(2), 1);

    CHECK_EQ(left_child(1), 2);
    CHECK_EQ(right_child(1), 3);

    BTree<9> bt = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    CHECK_EQ(pre_order(bt), "124895367");
}