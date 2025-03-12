//
// Created by garen_lee on 2025/3/12.
/**
  ******************************************************************************
  * @file           : L648_replaceWords.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/12
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L648_REPLACEWORDS_H
#define DICTIONARYTREE_L648_REPLACEWORDS_H

#include "util.h"
class L648_replaceWords : public LeetcodeDictionaryTree {
private:
    string replaceWords(vector<string>& dictionary, string sentence);
    vector<string> split(const std::string& str, const std::string& delimiter);
public:
    L648_replaceWords() {}
    void test();
};


#endif //DICTIONARYTREE_L648_REPLACEWORDS_H
