//
// Created by PC-Saw on 2021/01/06.
// Copyright (c) 2020 believe. All rights reserved.
//


#include <iostream>
#include "util.h" // NOLINT


// static const auto io_sync_off = []() {
//  // turn off sync
//  std::ios::sync_with_stdio(false);
//  // untie in/out streams
//  std::cin.tie(nullptr);
//  return nullptr;
//}();

// 题号 1 : 移动零
//
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//

/*
示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:

1. 必须在原数组上操作，不能拷贝额外的数组。
2. 尽量减少操作次数。

 * */

class Title1 {

 public:

  static void moveZeroes(std::vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return;
    int index = 0;
    for (int kI = 0; kI < size; ++kI) {
      if (nums[kI] != 0) nums[index++] = nums[kI];
    }
    if (index != size) {
      for (int kI = index; kI < size; ++kI) {
        nums[kI] = 0;
      }
    }
  }
};

TEST(AlgTitle1, test1) {

  struct timeval start{}, end{};
  std::vector<int> ret = {0, 1, 0, 3, 12};

  gettimeofday(&start, nullptr);
  Title1::moveZeroes(ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  std::vector<int> exp_ret = {1,3,12,0,0};

  EXPECT_TRUE(exp_ret==ret);
}
