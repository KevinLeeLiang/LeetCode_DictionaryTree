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
    for (auto word : words) {
        map[word]++;
    }
    vector<pair<int, string>> vec;
    for (auto it = map.begin(); it != map.end(); it++) {
        vec.push_back(make_pair(it->second, it->first));
    }
    sort(vec.begin(), vec.end(), [](pair<int, string> &a, pair<int, string> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
    });
    vector<string> result;
    for (int i = 0; i < k; i++) {
        result.push_back(vec[i].second);
    }
    return result;
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