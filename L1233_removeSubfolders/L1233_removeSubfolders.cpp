//
// Created by garen_lee on 2025/6/26.
/**
  ******************************************************************************
  * @file           : L1233_removeSubfolders.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/6/26
  ******************************************************************************
  */
//

#include "L1233_removeSubfolders.h"

struct Trie {
    Trie(): ref(-1) {}

    unordered_map<string, Trie*> children;
    int ref;
};

vector<string> L1233_removeSubfolders::removeSubfolders(vector<string>& folder) {
    auto split = [](const string& s) -> vector<string> {
        vector<string> ret;
        string cur;
        for (char ch: s) {
            if (ch == '/') {
                ret.push_back(move(cur));
                cur.clear();
            }
            else {
                cur.push_back(ch);
            }
        }
        ret.push_back(move(cur));
        return ret;
    };

    Trie* root = new Trie();
    for (int i = 0; i < folder.size(); ++i) {
        vector<string> path = split(folder[i]);
        Trie* cur = root;
        for (const string& name: path) {
            if (!cur->children.count(name)) {
                cur->children[name] = new Trie();
            }
            cur = cur->children[name];
        }
        cur->ref = i;
    }

    vector<string> ans;

    function<void(Trie*)> dfs = [&](Trie* cur) {
        if (cur->ref != -1) {
            ans.push_back(folder[cur->ref]);
            return;
        }
        for (auto&& [_, child]: cur->children) {
            dfs(child);
        }
    };

    dfs(root);
    return ans;
}

void L1233_removeSubfolders::test() {
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> res = removeSubfolders(folder);
    print_vector(res);
    folder = {"/a","/a/b/c","/a/b/d"};
    res = removeSubfolders(folder);
    print_vector(res);
    folder = {"/a/b/c","/a/b/ca","/a/b/d"};
    res = removeSubfolders(folder);
    print_vector(res);
}