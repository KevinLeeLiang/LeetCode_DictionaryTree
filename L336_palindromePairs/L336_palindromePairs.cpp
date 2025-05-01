//
// Created by garen_lee on 2025/2/26.
/**
  ******************************************************************************
  * @file           : L336_palindromePairs.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/26
  ******************************************************************************
  */
//

#include "L336_palindromePairs.h"
bool L336_palindromePairs::f(string s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--])return false;
    }
    return true;
}
vector<vector<int>> L336_palindromePairs::palindromePairs(vector<string> &words) {
    unordered_map<string, int>map;
    set<int>word_size_set;
    int n = words.size();
    for(int i=0;i<n;i++){
        map[words[i]]=i;
        word_size_set.insert(words[i].size());
    }
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); ++i) {
        string word_re = words[i];
        reverse(word_re.begin(), word_re.end());
        if (map.count(word_re) && map[word_re] != i) {
            res.push_back({map[word_re], i});
        }
        int length = word_re.size();
        for (auto it = word_size_set.begin(); *it != length; ++it) {
            int d = *it;
            if (f(word_re, 0, length - d - 1) && map.count(word_re.substr(length-d))){
                res.push_back({i, map[word_re.substr(length-d)]});
            }
            if (f(word_re, d, length - 1) && map.count(word_re.substr(0, d))) {
                res.push_back({map[word_re.substr(0, d)], i});
            }
        }
    }
    return res;
}

void L336_palindromePairs::test() {

    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> result = palindromePairs(words);
    print_vector_vector(result);
    words = {"bat", "tab", "cat"};
    result = palindromePairs(words);
    print_vector_vector(result);
    words = {"a", ""};
    result = palindromePairs(words);
    print_vector_vector(result);
}
