//
// Created by garen-lee on 2025/2/9.
/**
  ******************************************************************************
  * @file           : L139_wordBreak.cpp.cc
  * @author         : garen-lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/9
  ******************************************************************************
  */
//

#include "L139_wordBreak.h"
bool L139_wordBreak::wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            string tmp = s.substr(j, i - j);
            if (dp[j] && wordSet.find(tmp) != wordSet.end()) {
                dp[i]= true;
            }
        }
    }
    return dp[s.size()];
}
void L139_wordBreak::test() {
    string s;
    vector<string> wordDict;
    s = "leetcode";
    wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict) << endl;
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    cout << wordBreak(s, wordDict) << endl;
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak(s, wordDict) << endl;
}