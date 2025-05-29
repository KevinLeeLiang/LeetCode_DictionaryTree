//
// Created by garen_lee on 2025/3/19.
/**
  ******************************************************************************
  * @file           : L677_MapSum.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/19
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L677_MAPSUM_H
#define DICTIONARYTREE_L677_MAPSUM_H

#include "util.h"
namespace L677 {
    class MapSum {
    public:
        MapSum();
        void insert(string key, int val);
        int sum(string prefix);
    private:
        unordered_map<string, int> map;
        unordered_map<string, int> prefixmap;
    };
}
class L677_MapSum : public LeetcodeDictionaryTree {
public:
    L677_MapSum() {}
    void test();
};


#endif //DICTIONARYTREE_L677_MAPSUM_H
