//
// Created by garen_lee on 2025/3/12.
/**
  ******************************************************************************
  * @file           : L472_findAllConcatenatedWordsInDict.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/12
  ******************************************************************************
  */
//

#include "L472_findAllConcatenatedWordsInDict.h"

bool L472_findAllConcatenatedWordsInDict::dfs(const string &word, int start, vector<int>& visited) {
    if (word.size() == start) {
        return true;
    }
    if (visited[start]) {
        return false;
    }
    visited[start] = true;
    Trie * node = trie;
    for (int i = start; i < word.size(); i++){
        char ch = word[i];
        int index = ch - 'a';
        node = node->children[index];
        if (node == nullptr) {
            return false;
        }
        if (node->is_end) {
            if (dfs(word, i + 1, visited)) {
                return true;
            }
        }
    }
    return false;
}
void L472_findAllConcatenatedWordsInDict::insert(const string& word) {
    Trie *node = trie;
    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new Trie();
        }
        node = node->children[index];
    }
    node->is_end = true;
    
}

vector<string> L472_findAllConcatenatedWordsInDict::findAllConcatenatedWordsInADict(vector<string> &words) {
    vector<string>ans;
    sort(words.begin(), words.end(), [&](const string&a, const string & b) {
        return a.size() < b.size();
    });
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        if (word.size() == 0) {
            continue;
        }
        vector<int> visited(word.size(), 0);
        if (dfs(word, 0, visited)) {
            ans.emplace_back(word);
        } else {
            insert(word);
        }
    }
    return ans;
}

void L472_findAllConcatenatedWordsInDict::test() {
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> result = findAllConcatenatedWordsInADict(words);
    print_vector(result);
    words = {"cat", "dog", "catdog"};
    result = findAllConcatenatedWordsInADict(words);
    print_vector(result);
}