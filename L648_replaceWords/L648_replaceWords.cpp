//
// Created by garen_lee on 2025/3/12.
/**
  ******************************************************************************
  * @file           : L648_replaceWords.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/12
  ******************************************************************************
  */
//

#include "L648_replaceWords.h"

vector<string> L648_replaceWords::split(const std::string& str, const std::string& delimiter) {
    std::regex re(delimiter);
    std::sregex_token_iterator it(str.begin(), str.end(), re, -1);
    std::sregex_token_iterator reg_end;

    std::vector<std::string> result(it, reg_end);
    return result;
}

string L648_replaceWords::replaceWords(vector<string> &dictionary, string sentence) {
    string ans;
    unordered_set<string> set;
    for (auto s:dictionary){
        set.insert(s);
    }
    vector<string>tokens;
    tokens = split(sentence, "\\s+");
    for (int j = 0; j < tokens.size(); ++j) {
        auto t = tokens[j];
        bool flag = false;
        for (int i = 0; i < t.size(); ++i) {
            string tmp;
            tmp.assign(t.begin(), t.begin() + i);
            if (set.find(tmp) != set.end()){
                ans += tmp;
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans += t;
        }
        if (j < tokens.size()- 1)
            ans+= " ";

    }

    return ans;
}

void L648_replaceWords::test() {
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << replaceWords(dictionary, sentence) << endl;
    dictionary = {"a", "b", "c"};
    sentence = "aadsfasf absbs bbab cadsfafs";
    cout << replaceWords(dictionary, sentence) << endl;
}