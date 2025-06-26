//
// Created by garen_lee on 2025/6/26.
/**
  ******************************************************************************
  * @file           : L1233_removeSubfolders.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/6/26
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L1233_REMOVESUBFOLDERS_H
#define DICTIONARYTREE_L1233_REMOVESUBFOLDERS_H

#include "util.h"
class L1233_removeSubfolders : public LeetcodeDictionaryTree {
private:
    vector<string> removeSubfolders(vector<string> &folder);
public:
    L1233_removeSubfolders() {}
    void test();
};


#endif //DICTIONARYTREE_L1233_REMOVESUBFOLDERS_H
