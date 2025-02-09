//
// Created by garen-lee on 2025/2/9.
/**
  ******************************************************************************
  * @file           : L14_longestCommonPrefix.cpp.cc
  * @author         : garen-lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/9
  ******************************************************************************
  */
//

#include "L14_longestCommonPrefix.h"

bool L14_longestCommonPrefix::isCommonPrefix(vector<string>& strs, int len) {
    string str0 = strs[0].substr(0, len);
    int count = strs.size();
    for (int i = 1; i < count; ++i) {
        string str = strs[i];
        for (int j = 0; j < len; ++j) {
            if (str0[j] != str[j]) {
                return false;
            }
        }
    }
    return true;

}
string L14_longestCommonPrefix::longestCommonPrefix(vector<string>& strs) {
    if (!strs.size()) {
        return "";
    }
    int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size();})->size();
    int low = 0, high = minLength;
    while (low < high) {
        int mid = (high - low + 1) / 2 + low;
        if (isCommonPrefix(strs, mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return strs[0].substr(0, low);
}
void L14_longestCommonPrefix::test(){
    vector<string >strs;
    strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;
    strs = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs) << endl;
}