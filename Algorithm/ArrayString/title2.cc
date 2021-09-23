//
// Created by believe on 2021/1/15.
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

// 题号 2 : 搜索插入位置
//
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
// 你可以假设数组中无重复元素。
//

/*
示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1

示例 3:
输入: [1,3,5,6], 7
输出: 4

示例 4:
输入: [1,3,5,6], 0
输出: 0

 * */

class Title2 {
public:
  static int SearchInsert(std::vector<int> &nums, int target) {
    int size = nums.size();
    if (size <= 0) {
      return 0;
    }
    for (int kI = 0; kI < size; ++kI) {
      if (nums[kI] >= target) {
        return kI;
      }
    }
    return size;
  }
  static int SearchInsert2(std::vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1, ans = n;
    while (left <= right) {
      int middle = left + ((right - left) >> 1); // NOLINT
      if (target > nums[middle]) {
        left = middle + 1;
      } else {
        ans = middle;
        right = middle - 1;
      }
    }
    return ans;
  }
};

TEST(AlgStrTitle2, test1) {

  std::vector<int> ret = {1, 3, 5, 6};
  int ret_value{0};
  {
    ScopedTimer timer("Title2::SearchInsert");
    ret_value = Title2::SearchInsert(ret, 5);
  }
  EXPECT_EQ(ret_value, 2);

  std::vector<int> ret2 = {1, 3, 5, 6};
  int ret_value2{0};
  {
    ScopedTimer timer("Title2::SearchInsert2");
    ret_value2 = Title2::SearchInsert2(ret, 5);
  }
  EXPECT_EQ(ret_value2, 2);
}
