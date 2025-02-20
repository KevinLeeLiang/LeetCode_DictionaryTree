//
// Created by garen_lee on 2025/2/20.
/**
  ******************************************************************************
  * @file           : L211_WordDictionary.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/2/20
  ******************************************************************************
  */
//

#include "L211_WordDictionary.h"
void L211_WordDictionary::test(){
    this->wd_->addWord("bad");
    this->wd_->addWord("dad");
    this->wd_->addWord("mad");
    cout << this->wd_->search("pad") << endl;
    cout << this->wd_->search("bad") << endl;
    cout << this->wd_->search(".ad") << endl;
    cout << this->wd_->search("b..") << endl;
}