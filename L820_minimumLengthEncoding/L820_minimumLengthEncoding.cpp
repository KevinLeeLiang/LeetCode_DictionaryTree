//
// Created by garen_lee on 2025/4/10.
/**
  ******************************************************************************
  * @file           : L820_minimumLengthEncoding.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/4/10
  ******************************************************************************
  */
//

#include "L820_minimumLengthEncoding.h"

int L820_minimumLengthEncoding::minimumLengthEncoding(vector<string> &words) {
    unordered_set<string> good(words.begin(), words.end());
    for (const string &word : words) {
        for (int i = 1; i < word.size(); ++i) {
            good.erase(word.substr(i));
        }
    }
    int ans = 0;
    for (const string& word: good) {
        ans += word.size() + 1;
    }
    return ans;
}

void L820_minimumLengthEncoding::test() {
    vector<string> words = {"time", "me", "bell"};
    cout << minimumLengthEncoding(words) << endl;
    words = {"t"};
    cout << minimumLengthEncoding(words) << endl;
}