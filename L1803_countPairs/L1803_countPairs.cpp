//
// Created by garen_lee on 2025/7/17.
/**
  ******************************************************************************
  * @file           : L1803_countPairs.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/17
  ******************************************************************************
  */
//

#include "L1803_countPairs.h"

void L1803_countPairs::add(int num) {
    Trie* cur = root;
    for (int k = HIGH_BIT; k >= 0; k--) {
        int bit = (num >> k) & 1;
        if (cur->son[bit] == nullptr) {
            cur->son[bit] = new Trie();
        }
        cur = cur->son[bit];
        cur->sum++;
    }
}

int L1803_countPairs::get(int num, int x) {
    Trie* cur = root;
    int sum = 0;
    for (int k = HIGH_BIT; k >= 0; k--) {
        int r = (num >> k) & 1;
        if ((x >> k) & 1) {
            if (cur->son[r] != nullptr) {
                sum += cur->son[r]->sum;
            }
            if (cur->son[r ^ 1] == nullptr) {
                return sum;
            }
            cur = cur->son[r ^ 1];
        } else {
            if (cur->son[r] == nullptr) {
                return sum;
            }
            cur = cur->son[r];
        }
    }
    sum += cur->sum;
    return sum;
}

int L1803_countPairs::f(vector<int> &nums, int x) {
    root = new Trie();
    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
        add(nums[i - 1]);
        res += get(nums[i], x);
    }
    return res;
}
int L1803_countPairs::countPairs(vector<int> &nums, int low, int high) {
    return f(nums, high) - f(nums, low - 1);
}

void L1803_countPairs::test() {
    vector<int> nums = {1, 4, 2, 7};
    int low = 2, high = 6;
    cout << countPairs(nums, low, high) << endl;
    nums = {9, 8, 4, 2, 1};
    low = 5, high = 14;
    cout << countPairs(nums, low, high) << endl;
}