//
// Created by garen-lee on 2025/2/9.
/**
  ******************************************************************************
  * @file           : L14_longestCommonPrefix.h
  * @author         : garen-lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/9
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L14_LONGESTCOMMONPREFIX_H
#define DICTIONARYTREE_L14_LONGESTCOMMONPREFIX_H

#include "util.h"
class L14_longestCommonPrefix : public LeetcodeDictionaryTree{
private:
    bool isCommonPrefix(vector<string>& strs, int len);
    string longestCommonPrefix(vector<string>& strs);
public:
    L14_longestCommonPrefix(){}
    void test();
};


#endif //DICTIONARYTREE_L14_LONGESTCOMMONPREFIX_H
