//
// Created by garen_lee on 2025/4/10.
/**
  ******************************************************************************
  * @file           : L820_minimumLengthEncoding.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/4/10
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L820_MINIMUMLENGTHENCODING_H
#define DICTIONARYTREE_L820_MINIMUMLENGTHENCODING_H

#include "util.h"
class L820_minimumLengthEncoding : public LeetcodeDictionaryTree {
private:
    int minimumLengthEncoding(vector<string> &words);
public:
    L820_minimumLengthEncoding() {}
    void test();
};


#endif //DICTIONARYTREE_L820_MINIMUMLENGTHENCODING_H
