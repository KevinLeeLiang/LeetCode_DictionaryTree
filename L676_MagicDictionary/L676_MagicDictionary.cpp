//
// Created by garen_lee on 2025/3/19.
/**
  ******************************************************************************
  * @file           : L676_MagicDictionary.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/19
  ******************************************************************************
  */
//

#include "L676_MagicDictionary.h"

using namespace L676;

MagicDictionary::MagicDictionary() {
    root = new Trie();
}

void MagicDictionary::buildDict(vector<string> dict) {
    for (auto &&word : dict) {
        Trie* cur = root;
        for (auto &&c : word) {
            if (!cur->child[c - 'a']) {
                cur->child[c - 'a'] = new Trie();
            }
            cur = cur->child[c - 'a'];
        }
        cur->is_finished = true;
    }
}

bool MagicDictionary::search(string word) {
    function<bool(Trie*, int, int)> dfs = [&](Trie* node, int pos, int modified) {
        if (pos == word.size()) {
            return modified == 1 && node->is_finished;
        }
        int idx = word[pos] - 'a';
        if (node->child[idx]) {
            if (dfs(node->child[idx], pos + 1, modified)) {
                return true;
            }
        }
        if (!modified) {
            for (int i = 0; i < 26; ++i) {
                if (i != idx && node->child[i] && dfs(node->child[i], pos + 1, modified + 1)) {
                    return true;
                }
            }
        }
        return false;
    };
    return dfs(root, 0, false);
}

void L676_MagicDictionary::test() {
    MagicDictionary md;
    md.buildDict({"hello", "leetcode"});
    cout << md.search("hello") << endl;
    cout << md.search("hhllo") << endl;
    cout << md.search("hell") << endl;
    cout << md.search("leetcoded") << endl;
}