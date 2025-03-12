//
// Created by garen-lee on 2025/2/9.
/**
  ******************************************************************************
  * @file           : util.h
  * @author         : garen-lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/9
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_UTIL_H
#define DICTIONARYTREE_UTIL_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <cstdint>
#include <cstdarg>
#include <set>
#include <regex>

using namespace std;

class LeetcodeDictionaryTree {
public:
    LeetcodeDictionaryTree() {}

    ~LeetcodeDictionaryTree() {}

    virtual void test() = 0;
};

template<typename T>
void print_vector(vector<T> &vec) {
    for (auto &item : vec) {
        cout << item << " ";
    }
    cout << endl;
    cout << "__________" << endl;
}

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


inline TreeNode *createTree(vector<int> tree_vals) {
    if (tree_vals.size() == 0)
        return nullptr;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(tree_vals[0]);
    int index = 0;
    q.push(root);
    index++;
    while (!q.empty()) {
        if (index >= tree_vals.size())
            break;
        auto p = q.front();
        q.pop();
        if (index < tree_vals.size() && tree_vals[index] != 0) {
            p->left = new TreeNode(tree_vals[index]);
            q.push(p->left);
        }
        index++;
        if (index < tree_vals.size() && tree_vals[index] != 0) {

            p->right = new TreeNode(tree_vals[index]);
            q.push(p->right);
        }
        index++;
    }
    return root;
}

inline TreeNode *createTree2(vector<int> tree_vals) {
    if (tree_vals.size() == 0)
        return nullptr;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(tree_vals[0]);
    int index = 0;
    q.push(root);
    index++;
    while (!q.empty()) {
        if (index >= tree_vals.size())
            break;
        auto p = q.front();
        q.pop();
        if (index < tree_vals.size() && tree_vals[index] >= 0) {
            p->left = new TreeNode(tree_vals[index]);
            q.push(p->left);
        }
        index++;
        if (index < tree_vals.size() && tree_vals[index] >= 0) {

            p->right = new TreeNode(tree_vals[index]);
            q.push(p->right);
        }
        index++;
    }
    return root;
}

inline TreeNode *create_treenode(vector<int> tree_vals, bool is_include_zero) {
    if (is_include_zero) {
        auto *tree = createTree2(tree_vals);
        return tree;
    } else {
        auto *tree = createTree(tree_vals);
        //	cout << tree->val << endl;
        return tree;
    }
}

inline string print_tree(TreeNode *root) {
    string s;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        auto size = q.size();
        for (int i = 0; i < size; ++i) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                s += "0";
            } else {
                s += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            s.pop_back();
        } else {
            break;
        }
    }
    return s;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *create_list(vector<int> list_vals) {
    if (list_vals.size() == 0)
        return nullptr;
    ListNode *head = new ListNode(list_vals[0]);
    ListNode *p = head;
    for (int i = 1; i < list_vals.size(); ++i) {
        p->next = new ListNode(list_vals[i]);
        p = p->next;
        if (i == list_vals.size() - 1) {
            p->next = nullptr;
        }
    }
    return head;
}
inline void print_list(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    cout << "__________" << endl;
}

template<typename T>
void print_vector_vector(vector<vector<T>> &vec) {
    for (auto &item : vec) {
        for (auto &item2 : item) {
            cout << item2 << " ";
        }
        cout << endl;
    }
    cout <<  "__________" << endl;
}

#endif //DICTIONARYTREE_UTIL_H
