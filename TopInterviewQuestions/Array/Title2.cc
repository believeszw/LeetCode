//
// Created by PC-Saw on 2019/09/23.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE2_H
#define TOP_INTERVIEW_QUESTIONS_TITLE2_H

#include <iostream>
#include "Util.h"


// 题号 2 : Best Time to Buy and Sell Stock II
//
// Best Time to Buy and Sell Stock II
//
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
//
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

/*
Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

 * */

class Title2 {

 public:

  int MaxProfit(std::vector<int> &prices) {

    // 判断是否为空
    int n = prices.size();
    if (n == 0) return 0;

    // 初始化买卖价格
    int left = prices[0];
    int right = prices[0];
    int profit = 0;

    for (int i = 1; i < n; ++i) {
      // 持续增长
      if (prices[i] >= right) {
        right = prices[i];
      } else { // 出现下降
        profit = profit + right - left;
        left = right = prices[i];
      }
    }

    profit = profit + right - left;

    return profit;
  }

  // 更优解
  int MaxProfitBetter(std::vector<int> &prices) {
    // 判断是否为空
    int n = prices.size();
    if (n == 0) return 0;
    int profit = 0;

    // 计算所有增量
    for (int i = 0; i < n - 1; ++i) {
      if (prices[i] < prices[i + 1]) {
        profit += prices[i + 1] - prices[i];
      }
    }

    return profit;
  }
};

TEST(Title, test2) {

  Title2 title_2;
  std::vector<int> vector2 = {7, 1, 5, 3, 6, 4};
  struct timeval start{}, end{};
  int ret = 0;

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 10000; ++kI) {
    ret = title_2.MaxProfit(vector2);
  }
  gettimeofday(&end, nullptr);
  std::cout << "MaxProfit       cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(7, ret);

  // MaxProfitBetter
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 10000; ++kJ) {
    ret = title_2.MaxProfitBetter(vector2);
  }
  gettimeofday(&end, nullptr);
  std::cout << "MaxProfitBetter cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(7, ret);

}

#endif // TOP_INTERVIEW_QUESTIONS_TITLE2_H
