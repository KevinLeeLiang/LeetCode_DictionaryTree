//
// Created by garen_lee on 2025/3/19.
/**
  ******************************************************************************
  * @file           : L677_MapSum.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/19
  ******************************************************************************
  */
//

#include "L677_MapSum.h"

using namespace L677;

MapSum::MapSum() {

}

void MapSum::insert(string key, int val) {
    int delta = val;
    if (map.find(key) != map.end()) {
        delta -= map[key];
    }
    map[key] = val;
    for (int i = 0; i <=key.size(); ++i) {
        prefix_map[key.substr(0, i)] +=delta;
    }
}

int MapSum::sum(string prefix) {
    return  prefix_map[prefix];
}

void L677_MapSum::test(){
    MapSum ms;
    ms.insert("apple", 3);
    cout << ms.sum("ap") << endl;
    ms.insert("app", 2);
    cout << ms.sum("ap") << endl;
}