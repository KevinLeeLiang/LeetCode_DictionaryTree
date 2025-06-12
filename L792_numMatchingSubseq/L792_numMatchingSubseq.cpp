//
// Created by garen_lee on 2025/4/3.
/**
  ******************************************************************************
  * @file           : L792_numMatchingSubseq.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/4/3
  ******************************************************************************
  */
//

#include "L792_numMatchingSubseq.h"

int L792_numMatchingSubseq::numMatchingSubseq(string s, vector<string> &words) {
    vector<queue<pair<int, int>>> queues(26);
    for (int i = 0; i < words.size(); ++i) {
        queues[words[i][0] - 'a'].emplace(i, 0);
    }
    int res = 0;
    for (auto c : s) {
        auto &q = queues[c - 'a'];
        auto size = q.size();
        while (size--) {
            auto [i, j] = q.front();
            q.pop();
            j++;
            if (j == words[i].size()) {
                res++;
            } else {
                queues[words[i][j] - 'a'].emplace(i, j);
            }
        }
    }
    
    return res;
}

void L792_numMatchingSubseq::test() {
    string s = "abcde";
    vector<string>words = {"a", "bb", "acd", "ace"};
    cout << numMatchingSubseq(s, words) << endl;
    s = "dsahjpjauf";
    words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    cout << numMatchingSubseq(s, words) << endl;
}