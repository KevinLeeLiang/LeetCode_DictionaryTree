//
// Created by garen_lee on 2025/7/17.
/**
  ******************************************************************************
  * @file           : L1803_countPairs.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/17
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1803_COUNTPAIRS_H
#define DICTIONARYTREE_L1803_COUNTPAIRS_H

#include "util.h"
struct Trie {
    // son[0] 表示左子树，son[1] 表示右子树
    array<Trie*, 2> son{nullptr, nullptr};
    int sum;
    Trie():sum(0) {}
};

class L1803_countPairs : public LeetcodeDictionaryTree {
private:
    // 字典树的根节点
    Trie* root = nullptr;
    // 最高位的二进制位编号为 14
    static constexpr int HIGH_BIT = 13;
    void add(int num);
    int get(int num, int x);
    int f(vector<int>& nums, int x);
    int countPairs(vector<int>& nums, int low, int high);
public:
    L1803_countPairs() {}
    void test();
};


#endif //DICTIONARYTREE_L1803_COUNTPAIRS_H
