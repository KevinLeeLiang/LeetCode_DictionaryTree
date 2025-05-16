//
// Created by garen_lee on 2025/3/5.
/**
  ******************************************************************************
  * @file           : L440_findKthNumber.cpp.cc
  * @author         : garen_lee
  * @brief          : None
  * @attention      : None
  * @date           : 2025/3/5
  ******************************************************************************
  */
//

#include "L440_findKthNumber.h"

int L440_findKthNumber::calculateSteps(int n, long long curr, long long next) {
    int steps = 0;
    while (curr <= n) {
        steps += min((long long)n + 1, next) - curr;
        curr *= 10;
        next *= 10;
    }
    return steps;
}

int L440_findKthNumber::findKthNumber(int n, int k) {
    int curr = 1;
    k -- ;
    while (k > 0) {
        int step = calculateSteps(n, curr, curr + 1);
        if (step <= k) {
            k -= step;
            curr ++ ;
        } else {
            curr *= 10;
            k -- ;
        }
    }
    return curr;
}

void L440_findKthNumber::test() {
    int n = 13;
    int k = 3;
    cout << findKthNumber(n, k) << endl;
    n = 1;
    k = 1;
    cout << findKthNumber(n, k) << endl;
    n = 2;
    k = 2;
    cout << findKthNumber(n, k) << endl;
}