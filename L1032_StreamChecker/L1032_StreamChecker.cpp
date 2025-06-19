//
// Created by garen_lee on 2025/6/19.
/**
  ******************************************************************************
  * @file           : L1032_StreamChecker.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/6/19
  ******************************************************************************
  */
//

#include "L1032_StreamChecker.h"
typedef struct TrieNode {
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode *fail;
    TrieNode() {
        this->children = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
        this->fail = nullptr;
    }
};

class StreamChecker {
public:
    TrieNode* root;
    TrieNode* temp;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (string &word : words) {
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if (cur->children[index] == nullptr) {
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->isEnd = true;
        }
        root->fail = root;
        queue<TrieNode*> q;
        for (int i = 0; i < 26; i++) {
            if(root->children[i] != nullptr) {
                root->children[i]->fail = root;
                q.emplace(root->children[i]);
            } else {
                root->children[i] = root;
            }
        }
        while (!q.empty()) {
            TrieNode* node = q.front();
            q.pop();
            node->isEnd = node->isEnd || node->fail->isEnd;
            for (int i = 0; i < 26; i++) {
                if(node->children[i] != nullptr) {
                    node->children[i]->fail = node->fail->children[i];
                    q.emplace(node->children[i]);
                } else {
                    node->children[i] = node->fail->children[i];
                }
            }
        }
        temp = root;
    }

    bool query(char letter) {
        temp = temp->children[letter - 'a'];
        return temp->isEnd;
    }
};

void L1032_StreamChecker::test() {
    vector<string> words = {"cd", "f", "kl"};
    StreamChecker obj(words);
    cout << obj.query('a') << endl;
    cout << obj.query('b') << endl;
    cout << obj.query('c') << endl;
    cout << obj.query('d') << endl;
    cout << obj.query('e') << endl;
    cout << obj.query('f') << endl;
    cout << obj.query('g') << endl;
    cout << obj.query('h') << endl;
    cout << obj.query('i') << endl;
    cout << obj.query('j') << endl;
    cout << obj.query('k') << endl;
    cout << obj.query('l') << endl;
}