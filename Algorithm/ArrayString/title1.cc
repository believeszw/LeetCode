//
// Created by believe on 2021/01/14.
// Copyright (c) 2021 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

// static const auto io_sync_off = []() {
//  // turn off sync
//  std::ios::sync_with_stdio(false);
//  // untie in/out streams
//  std::cin.tie(nullptr);
//  return nullptr;
//}();

// 题号 1 : 寻找数组的中心索引
//
// 给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。
//
// 我们是这样定义数组 中心索引
// 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
//
// 如果数组不存在中心索引，那么我们应该返回
// -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
//

/*
示例 1：

输入：
nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11)
相等。 同时, 3 也是第一个符合要求的中心索引。

示例 2：

输入：
nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心索引。

说明：

nums 的长度范围为 [0, 10000]。
任何一个 nums[i] 将会是一个范围在 [-1000, 1000] 的整数。

 * */

class Title1 {
public:
  static int PivotIndex(std::vector<int> &nums) {
    int size = nums.size();
    if (size == 0) {
      return -1;
    }
    // sum[i] 代表前 i 个元素的和
    std::vector<int> sum(size + 1, 0);
    for (int kI = 1; kI <= size; ++kI) {
      sum[kI] = sum[kI - 1] + nums[kI - 1];
    }
    for (int kI = 0; kI < size; ++kI) {
      if (sum[kI] == sum[size] - sum[kI + 1]) {
        return kI;
      }
    }
    return -1;
  }
};

TEST(AlgStrTitle1, test1) {

  std::vector<int> ret = {-1, -1, 0, 1, 1, 0};
  int ret_value{0};
  {
    ScopedTimer timer("Title1::PivotIndex");
    ret_value = Title1::PivotIndex(ret);
  }

  EXPECT_EQ(ret_value, 5);
}
