//
// Created by garen_lee on 2025/2/12.
/**
  ******************************************************************************
  * @file           : L140_wordBreak.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/12
  ******************************************************************************
  */
//

#include "L140_wordBreak.h"

void L140_wordBreak::backTrack(const string& s, int index) {
    if (!this->ans_.count(index)) {
        if (index == s.size()) {
            this->ans_[index] = {""};
            return;
        }
        this->ans_[index] = {};
        for (int i = index + 1; i <= s.size(); ++i) {
            string word = s.substr(index, i - index);
            if (this->wordSet_.count(word)) {
                backTrack(s, i);
                for (auto& item : this->ans_[i])
                    this->ans_[index].push_back(item.empty() ? word : word + " " + item);
            }
        }
    }
}

vector<string> L140_wordBreak::wordBreak(string s, vector<string>& wordDict) {
    this->ans_.clear();
    this->wordSet_ = unordered_set<string>(wordDict.begin(), wordDict.end());
    backTrack(s, 0);
    return this->ans_[0];
}

void L140_wordBreak::test(){
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = wordBreak(s, wordDict);
    print_vector(res);
    s = "pineapplepenapple";
    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    res = wordBreak(s, wordDict);
    print_vector(res);
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    res = wordBreak(s, wordDict);
    print_vector(res);
}