//
// Created by garen_lee on 2025/3/5.
/**
  ******************************************************************************
  * @file           : L421_findMaximumXOR.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/5
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L421_FINDMAXIMUMXOR_H
#define DICTIONARYTREE_L421_FINDMAXIMUMXOR_H

#include "util.h"
class L421_findMaximumXOR : public LeetcodeDictionaryTree {
private:
    struct Trie {
        Trie *left;
        Trie *right;
        Trie() {
            left = nullptr;
            right = nullptr;
        }
    };
    // 字典树的根节点
    Trie* root = new Trie();
    // 最高位的二进制位编号为 30
    static constexpr int HIGH_BIT = 30;
private:
    int findMaximumXOR(vector<int>& nums);
    void add(int num);
    int check(int num);
public:
    L421_findMaximumXOR() {}
    void test();
};


#endif //DICTIONARYTREE_L421_FINDMAXIMUMXOR_H
