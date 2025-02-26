//
// Created by garen_lee on 2025/2/26.
/**
  ******************************************************************************
  * @file           : L386_lexicalOrder.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/26
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L386_LEXICALORDER_H
#define DICTIONARYTREE_L386_LEXICALORDER_H

#include "util.h"
class L386_lexicalOrder : public LeetcodeDictionaryTree{
private:
    vector<int> lexicalOrder(int n);
    void dfs(int cur, int n, vector<int> &res);
public:
    L386_lexicalOrder(){}
    void test();
};


#endif //DICTIONARYTREE_L386_LEXICALORDER_H
