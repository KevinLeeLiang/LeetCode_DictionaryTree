//
// Created by garen_lee on 2025/3/19.
/**
  ******************************************************************************
  * @file           : L676_MagicDictionary.h
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/19
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_L676_MAGICDICTIONARY_H
#define DICTIONARYTREE_L676_MAGICDICTIONARY_H

#include "util.h"
namespace L676 {
    struct Trie {
        bool is_finished;
        Trie* child[26];
        Trie() {
            is_finished = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    class MagicDictionary {
    public:
        MagicDictionary();

        void buildDict(vector<string> dict);

        bool search(string word);
    private:
        Trie* root;
    };
}

class L676_MagicDictionary : public LeetcodeDictionaryTree {
public:
    L676_MagicDictionary() {}
    void test();
};


#endif //DICTIONARYTREE_L676_MAGICDICTIONARY_H
