//
// Created by garen_lee on 2025/7/3.
/**
  ******************************************************************************
  * @file           : L1316_distinctEchoSubstrings.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/3
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1316_DISTINCTECHOSUBSTRINGS_H
#define DICTIONARYTREE_L1316_DISTINCTECHOSUBSTRINGS_H

#include "util.h"
using LL = long long;

class L1316_distinctEchoSubstrings : public LeetcodeDictionaryTree {
private:
    constexpr  static int mod = (int)1e9 + 7;
    int gethash(const vector<int>& pre, const vector<int>& mul, int l, int r) {
        return (pre[r + 1] - (LL)pre[l] * mul[r - l + 1] % mod + mod) % mod;
    }
    int distinctEchoSubstrings(string text);
public:
    L1316_distinctEchoSubstrings() {}
    void test();
};


#endif //DICTIONARYTREE_L1316_DISTINCTECHOSUBSTRINGS_H
