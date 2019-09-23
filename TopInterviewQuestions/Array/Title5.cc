//
// Created by PC-Saw on 2019/06/17.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE5_H
#define TOP_INTERVIEW_QUESTIONS_TITLE5_H

#include <iostream>
#include "Util.h"


// 题号 5 : Single Number
//
// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

/*
Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4

 * */

class Title5 {

 public:

  // 先从小到大排序，去掉尾巴进行比较，单个的总是出现在两个数字中的前一个
  int SingleNumber(std::vector<int> &nums) {
    unsigned long long int size = nums.size();
    if (size == 1) return nums[0];

    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < size - 1; i = i + 2) if (nums[i - 1] != nums[i]) return nums[i - 1];
    return nums[size - 1];
  }

  // 利用异或最终结果就是单独的元素
  int SingleNumberBetter(std::vector<int> &nums) {
    int tmp = 0;

    for (int i = 0; i < nums.size(); ++i) {
      tmp = tmp ^ nums[i];
    }
    return tmp;
  }

};

TEST(Title, test5) {
  Title5 title_5;
  std::vector<int> vector5 = {1, 2, 3, 1, 3, 4, 2};
  int ret = -1;
  struct timeval start{}, end{};

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 100; ++kI) {
    ret = title_5.SingleNumber(vector5);
  }
  gettimeofday(&end, nullptr);
  std::cout << "SingleNumber       cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(4, ret);


  // SingleNumberBetter
  ret = -1;
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 100; ++kJ) {
    ret = title_5.SingleNumberBetter(vector5);
  }
  gettimeofday(&end, nullptr);
  std::cout << "SingleNumberBetter cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(4, ret);

}

#endif // TOP_INTERVIEW_QUESTIONS_TITLE5_H
