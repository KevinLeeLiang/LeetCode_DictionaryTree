//
// Created by garen_lee on 2025/3/5.
/**
  ******************************************************************************
  * @file           : L421_findMaximumXOR.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/5
  ******************************************************************************
  */
//

#include "L421_findMaximumXOR.h"

void L421_findMaximumXOR::add(int num) {
    Trie* cur = root;
    for (int k = HIGH_BIT; k >= 0; --k) {
        int bit = (num >> k) & 1;
        if (bit == 0) {
            if (!cur->left) {
                cur->left = new Trie();
            }
            cur = cur->left;
        } else {
            if (!cur->right) {
                cur->right = new Trie();
            }
            cur = cur->right;
        }
    }
}

int L421_findMaximumXOR::check(int num) {
    Trie* cur = root;
    int x = 0;
    for (int k = HIGH_BIT; k >= 0; --k) {
        int bit = (num >> k) & 1;
        if (bit == 0) {
            if (cur->right) {
                cur = cur->right;
                x = x * 2 + 1;
            } else {
                cur = cur->left;
                x = x * 2;
            }
        } else {
            if (cur->left) {
                cur = cur->left;
                x = x * 2 + 1;
            } else {
                cur = cur->right;
                x = x * 2;
            }
        }
    }
    return x;
}

int L421_findMaximumXOR::findMaximumXOR(vector<int> &nums) {
    int n = nums.size();
    int x = 0;
    for (int i = 1; i < n; ++i) {
        add(nums[i - 1]);
        x = max(x, check(nums[i]));
    }
    return x;
}

void L421_findMaximumXOR::test() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << findMaximumXOR(nums) << endl;
    nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << findMaximumXOR(nums) << endl;
}