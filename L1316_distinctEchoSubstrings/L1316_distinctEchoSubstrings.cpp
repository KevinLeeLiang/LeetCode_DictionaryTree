//
// Created by garen_lee on 2025/7/3.
/**
  ******************************************************************************
  * @file           : L1316_distinctEchoSubstrings.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/3
  ******************************************************************************
  */
//

#include "L1316_distinctEchoSubstrings.h"

int L1316_distinctEchoSubstrings::distinctEchoSubstrings(string text) {
    int n = text.size();
    int base = 31;
    vector<int> pre(n + 1), mul(n + 1);
    pre[0] = 0;
    mul[0] = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = ((LL)pre[i - 1] * base + text[i - 1]) % mod;
        mul[i] = (LL)mul[i - 1] * base % mod;
    }
    unordered_set<int> seen[n];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int l = j - i;
            if (j + l <= n) {
                int hash_left = gethash(pre, mul, i, j - 1);
                if (!seen[l - 1].count(hash_left) && hash_left == gethash(pre, mul, j, j + l - 1)) {
                    ++ans;
                    seen[l - 1].insert(hash_left);
                }
            }
        }
    }
    return ans;
}

void L1316_distinctEchoSubstrings::test() {
    string s = "abcabcabc";
    cout << distinctEchoSubstrings(s) << endl;
    s = "leetcodeleetcode";
    cout << distinctEchoSubstrings(s) << endl;
}