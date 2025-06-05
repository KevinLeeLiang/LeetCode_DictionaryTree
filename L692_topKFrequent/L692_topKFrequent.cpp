//
// Created by garen_lee on 2025/3/26.
/**
  ******************************************************************************
  * @file           : L692_topKFrequent.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/26
  ******************************************************************************
  */
//

#include "L692_topKFrequent.h"
vector<string> L692_topKFrequent::topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> map;
    for (auto &word: words) {
        map[word]++;
    }
    vector<string> ws;
    for (auto &pair: map) {
        ws.push_back(pair.first);
    }
    sort(ws.begin(), ws.end(), [&map](string &a, string &b) {
        return map[a] == map[b] ? a < b : map[a] > map[b];
    });
    return vector<string>(ws.begin(), ws.begin() + k);
}
void L692_topKFrequent::test() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> result = topKFrequent(words, k);
    print_vector(result);
    words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    k = 4;
    result = topKFrequent(words, k);
    print_vector(result);
}