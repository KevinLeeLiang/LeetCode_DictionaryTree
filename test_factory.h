//
// Created by garen-lee on 2025/2/9.
/**
  ******************************************************************************
  * @file           : test_factory.h
  * @author         : garen-lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/9
  ******************************************************************************
  */
//

#ifndef DICTIONARYTREE_TEST_FACTORY_H
#define DICTIONARYTREE_TEST_FACTORY_H
#include <memory>
#include "L14_longestCommonPrefix/L14_longestCommonPrefix.h"
#include "L139_wordBreak/L139_wordBreak.h"
#include "L140_wordBreak/L140_wordBreak.h"
#include "L208_implementTrie/L208_implememtTrie.h"
class test_factory {
private:
    void buildSolution(string title) {
        if (title == "L14") {
            std::shared_ptr<L14_longestCommonPrefix> tmp= std::make_shared<L14_longestCommonPrefix>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L139") {
            std::shared_ptr<L139_wordBreak> tmp= std::make_shared<L139_wordBreak>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L140") {
            std::shared_ptr<L140_wordBreak> tmp= std::make_shared<L140_wordBreak>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L208") {
            std::shared_ptr<L208_implememtTrie> tmp= std::make_shared<L208_implememtTrie>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        }
    }
public:
    test_factory(string title) {
        cout << "test " << title << endl;
        buildSolution(title);
    }
    void test() {
        solution_->test();
    }
    ~test_factory() {}

private:
    std::shared_ptr<LeetcodeDictionaryTree> solution_;
};
#endif //DICTIONARYTREE_TEST_FACTORY_H
