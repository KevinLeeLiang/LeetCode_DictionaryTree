//
// Created by garen_lee on 2025/7/10.
/**
  ******************************************************************************
  * @file           : L1707_maximizeXor.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/10
  ******************************************************************************
  */
//

#include "L1707_maximizeXor.h"
namespace L1707 {
class Trie {
public:
    const int L = 30;

    Trie *children[2] = {};

    void insert(int val) {
        Trie *node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int val) {
        int ans = 0;
        Trie *node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr) {
                ans |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};
}

vector<int> L1707_maximizeXor::maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    sort(nums.begin(), nums.end());
    int numQ = queries.size();
    for (int i = 0; i < numQ; ++i) {
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), [](auto &x, auto &y) { return x[1] < y[1]; });

    vector<int> ans(numQ);
    L1707::Trie* t = new L1707::Trie();
    int idx = 0, n = nums.size();
    for (auto &q : queries) {
        int x = q[0], m = q[1], qid = q[2];
        while (idx < n && nums[idx] <= m) {
            t->insert(nums[idx]);
            ++idx;
        }
        if (idx == 0) { // 字典树为空
            ans[qid] = -1;
        } else {
            ans[qid] = t->getMaxXor(x);
        }
    }
    return ans;

}

void L1707_maximizeXor::test() {
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1},
                                   {1, 3},
                                   {5, 6}};
    vector<int> res = maximizeXor(nums, queries);
    print_vector(res);
    nums = {5, 2, 4, 6, 6, 3};
    queries = {{12, 4},
               {8,  1},
               {6,  3}};
    res = maximizeXor(nums, queries);
    print_vector(res);
}