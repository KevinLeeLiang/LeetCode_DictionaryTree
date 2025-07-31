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
#include "L211_WordDictionary/L211_WordDictionary.h"
#include "L212_findWords/L212_findWords.h"
#include "L336_palindromePairs/L336_palindromePairs.h"
#include "L386_lexicalOrder/L386_lexicalOrder.h"
#include "L421_findMaximumXOR/L421_findMaximumXOR.h"
#include "L440_findKthNumber/L440_findKthNumber.h"
#include "L472_findAllConcatenatedWordsInADict/L472_findAllConcatenatedWordsInDict.h"
#include "L648_replaceWords/L648_replaceWords.h"
#include "L676_MagicDictionary/L676_MagicDictionary.h"
#include "L677_MapSum/L677_MapSum.h"
#include "L692_topKFrequent/L692_topKFrequent.h"
#include "L720_longestWord/L720_longestWord.h"
#include "L745_WordFilter/L745_WordFilter.h"
#include "L792_numMatchingSubseq/L792_numMatchingSubseq.h"
#include "L820_minimumLengthEncoding/L820_minimumLengthEncoding.h"
#include "L1023_camelMatch/L1023_camelMatch.h"
#include "L1032_StreamChecker/L1032_StreamChecker.h"
#include "L1178_findNumOfValidWords/L1178_findNumOfValidWords.h"
#include "L1233_removeSubfolders/L1233_removeSubfolders.h"
#include "L1268_suggestedProducts/L1268_suggestedProducts.h"
#include "L1316_distinctEchoSubstrings/L1316_distinctEchoSubstrings.h"
#include "L1707_maximizeXor/L1707_maximizeXor.h"
#include "L1803_countPairs/L1803_countPairs.h"
#include "L1938_maxGeneticDifference/L1938_maxGeneticDifference.h"

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
        } else if (title == "L211") {
            std::shared_ptr<L211_WordDictionary> tmp= std::make_shared<L211_WordDictionary>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L212") {
            std::shared_ptr<L212_findWords> tmp= std::make_shared<L212_findWords>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L336") {
            std::shared_ptr<L336_palindromePairs> tmp= std::make_shared<L336_palindromePairs>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L386") {
            std::shared_ptr<L386_lexicalOrder> tmp= std::make_shared<L386_lexicalOrder>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L421") {
            std::shared_ptr<L421_findMaximumXOR> tmp= std::make_shared<L421_findMaximumXOR>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L440") {
            std::shared_ptr<L440_findKthNumber> tmp= std::make_shared<L440_findKthNumber>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L472") {
            std::shared_ptr<L472_findAllConcatenatedWordsInDict> tmp= std::make_shared<L472_findAllConcatenatedWordsInDict>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L648") {
            std::shared_ptr<L648_replaceWords> tmp= std::make_shared<L648_replaceWords>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L676") {
            std::shared_ptr<L676_MagicDictionary> tmp= std::make_shared<L676_MagicDictionary>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L677") {
            std::shared_ptr<L677_MapSum> tmp= std::make_shared<L677_MapSum>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L692") {
            std::shared_ptr<L692_topKFrequent> tmp= std::make_shared<L692_topKFrequent>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L720") {
            std::shared_ptr<L720_longestWord> tmp= std::make_shared<L720_longestWord>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L745") {
            std::shared_ptr<L745_WordFilter> tmp= std::make_shared<L745_WordFilter>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L792") {
            std::shared_ptr<L792_numMatchingSubseq> tmp= std::make_shared<L792_numMatchingSubseq>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L820") {
            std::shared_ptr<L820_minimumLengthEncoding> tmp= std::make_shared<L820_minimumLengthEncoding>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1023") {
            std::shared_ptr<L1023_camelMatch> tmp= std::make_shared<L1023_camelMatch>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1032") {
            std::shared_ptr<L1032_StreamChecker> tmp= std::make_shared<L1032_StreamChecker>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1178") {
            std::shared_ptr<L1178_findNumOfValidWords> tmp= std::make_shared<L1178_findNumOfValidWords>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1233") {
            std::shared_ptr<L1233_removeSubfolders> tmp= std::make_shared<L1233_removeSubfolders>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1268") {
            std::shared_ptr<L1268_suggestedProducts> tmp= std::make_shared<L1268_suggestedProducts>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1316") {
            std::shared_ptr<L1316_distinctEchoSubstrings> tmp= std::make_shared<L1316_distinctEchoSubstrings>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1707") {
            std::shared_ptr<L1707_maximizeXor> tmp= std::make_shared<L1707_maximizeXor>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1803") {
            std::shared_ptr<L1803_countPairs> tmp= std::make_shared<L1803_countPairs>();
            solution_ = std::dynamic_pointer_cast<LeetcodeDictionaryTree>(tmp);
        } else if (title == "L1938") {
            std::shared_ptr<L1938_maxGeneticDifference> tmp= std::make_shared<L1938_maxGeneticDifference>();
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
