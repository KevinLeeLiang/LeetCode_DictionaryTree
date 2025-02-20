//
// Created by garen_lee on 2025/2/20.
/**
  ******************************************************************************
  * @file           : L212_findWords.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/20
  ******************************************************************************
  */
//

#include "L212_findWords.h"
void L212_findWords::insertTrie(TrieNode *root, const string &word) {
    TrieNode *node = root;
    for (auto c : word){
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

bool L212_findWords::dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, set<string>& res) {
    char ch = board[i][j];
    if (!node->children.count(ch)) {
        return false;
    }
    node = node->children[ch];
    if (node->word.size() > 0) {
        res.insert(node->word);
    }

    board[i][j] = '#';
    for (int k = 0; k < 4; ++k) {
        int nx = i + dirs[k][0];
        int ny = j + dirs[k][1];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
            if (board[nx][ny] != '#') {
                dfs(board, nx, ny, node,res);
            }
        }
    }
    board[i][j] = ch;

    return true;
}

vector<string> L212_findWords::findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode*  root = new TrieNode();
    for (auto& word : words) {
        insertTrie(root, word);
    }
    set<string>res;
    vector<string> ans;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dfs(board, i, j, root, res);
        }
    }
    for (auto &word : res) {
        ans.emplace_back(word);
    }
    return ans;
}

void L212_findWords::test() {
    vector<vector<char>> board = {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> res = findWords(board,words);
    print_vector(res);
    board = {
            {'a','b'},
            {'c','d'}
    };
    words = {"abcb"};
    res = findWords(board,words);
    print_vector(res);
}