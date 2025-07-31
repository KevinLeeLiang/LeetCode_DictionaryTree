//
// Created by garen_lee on 2025/7/31.
/**
  ******************************************************************************
  * @file           : L1938_maxGeneticDifference.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/7/31
  ******************************************************************************
  */
//

#include "L1938_maxGeneticDifference.h"
struct Trie {
    Trie* left;
    Trie* right;
    // 由于我们的字典树需要支持删除数的操作
    // 因此这里使用 cnt 变量进行记录该节点对应的数的个数
    int cnt;

    Trie(): left(nullptr), right(nullptr), cnt(0) {}
};

vector<int> L1938_maxGeneticDifference::maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
    int n = parents.size();

    // 将 parents 存储为树的形式，方便进行深度优先遍历
    vector<vector<int>> edges(n);
    // 找出根节点
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (parents[i] == -1) {
            root = i;
        }
        else {
            edges[parents[i]].push_back(i);
        }
    }

    int q = queries.size();
    // 使用离线的思想，stored[i] 存储了所有节点 i 对应的询问
    vector<vector<pair<int, int>>> stored(n);
    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        stored[queries[i][0]].emplace_back(i, queries[i][1]);
    }

    Trie* r = new Trie();

    // 向字典树添加一个数
    auto trie_insert = [&](int x) {
        Trie* cur = r;
        for (int i = MAXD; i >= 0; --i) {
            if (x & (1 << i)) {
                if (!cur->right) {
                    cur->right = new Trie();
                }
                cur = cur->right;
            }
            else {
                if (!cur->left) {
                    cur->left = new Trie();
                }
                cur = cur->left;
            }
            ++cur->cnt;
        }
    };

    // 对于给定的 x，返回字典树中包含的数与 x 进行异或运算可以达到的最大值
    auto trie_query = [&](int x) -> int {
        int ret = 0;
        Trie* cur = r;
        for (int i = MAXD; i >= 0; --i) {
            if (x & (1 << i)) {
                if (cur->left && cur->left->cnt) {
                    ret |= (1 << i);
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                }
            }
            else {
                if (cur->right && cur->right->cnt) {
                    ret |= (1 << i);
                    cur = cur->right;
                }
                else {
                    cur = cur->left;
                }
            }
        }
        return ret;
    };

    // 从字典树中删除一个数
    auto trie_erase = [&](int x) {
        Trie* cur = r;
        for (int i = MAXD; i >= 0; --i) {
            if (x & (1 << i)) {
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
            --cur->cnt;
        }
    };

    // 深度优先遍历
    function<void(int)> dfs = [&](int u) {
        trie_insert(u);
        for (auto [idx, num]: stored[u]) {
            ans[idx] = trie_query(num);
        }
        for (int v: edges[u]) {
            dfs(v);
        }
        trie_erase(u);
    };

    dfs(root);
    return ans;
}

void L1938_maxGeneticDifference::test() {
    vector<int> parents = {-1, 0, 1, 1};
    vector<vector<int>> queries = {{0, 2}, {3, 2}, {2, 5}};
    vector<int> res = maxGeneticDifference(parents, queries);
    print_vector(res);
    parents = {3, 7, -1, 2, 0, 7, 0, 2};
    queries = {{4, 6}, {1, 15}, {0, 5}};
    res = maxGeneticDifference(parents, queries);
    print_vector(res);
}