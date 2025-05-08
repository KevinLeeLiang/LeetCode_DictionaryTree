//
// Created by garen_lee on 2025/2/26.
/**
  ******************************************************************************
  * @file           : L386_lexicalOrder.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/26
  ******************************************************************************
  */
//

#include "L386_lexicalOrder.h"

void L386_lexicalOrder::dfs(int cur, int n, vector<int> &res) {
    if (cur > n)
        return;
    res.push_back(cur);
    for (int i = 0; i < 10; ++i) {
        dfs(cur * 10 + i, n, res);
    }
}

vector<int> L386_lexicalOrder::lexicalOrder(int n) {
    if (n == 0)
        return {};
    vector<int> res;
    for (int i = 1; i < 10; ++i) {
        dfs(i, n, res);
    }
    return res;
}

void L386_lexicalOrder::test() {
    int n = 13;
    vector<int> res = lexicalOrder(n);
    print_vector(res);
    n = 2;
    res = lexicalOrder(n);
    print_vector(res);
}