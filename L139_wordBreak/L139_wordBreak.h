//
// Created by garen-lee on 2025/2/9.
/**
  ******************************************************************************
  * @file           : L139_wordBreak.h
  * @author         : garen-lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/9
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L139_WORDBREAK_H
#define DICTIONARYTREE_L139_WORDBREAK_H

#include "util.h"
class L139_wordBreak : public LeetcodeDictionaryTree{
private:
    bool wordBreak(string s, vector<string>& wordDict);
public:
    L139_wordBreak(){}
    void test();
};


#endif //DICTIONARYTREE_L139_WORDBREAK_H
