//
// Created by garen_lee on 2025/6/19.
/**
  ******************************************************************************
  * @file           : L1023_camelMatch.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/6/19
  ******************************************************************************
  */
//

#include "L1023_camelMatch.h"

vector<bool> L1023_camelMatch::camelMatch(vector<string> &words, string pattern) {
    vector<bool> res;
    for (auto word : words) {
        int i = 0;
        bool flag = true;
        for (auto c : word) {
            if (i < pattern.size() && c == pattern[i]) {
                i++;
            } else if (c >= 'A' && c <= 'Z') {
                flag = false;
                break;
            }
        }
        if (i < pattern.size()) {
            flag = false;
        }
        res.push_back(flag);
    }
    return res;
}

void L1023_camelMatch::test() {
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FB";
    vector<bool> res = camelMatch(queries, pattern);
    for (auto flag : res) {
        cout << flag << " ";
    }
    cout << endl;
    cout << "______" << endl;
    queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    pattern = "FoBa";
    res = camelMatch(queries, pattern);
    for (auto flag : res) {
        cout << flag << " ";
    }
    cout << endl;
    cout << "______" << endl;
    queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    pattern = "FoBaT";
    res = camelMatch(queries, pattern);
    for (auto flag : res) {
        cout << flag << " ";
    }
    cout << endl;
    cout << "______" << endl;
}