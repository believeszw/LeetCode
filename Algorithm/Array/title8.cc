//
// Created by believe on 2021/1/10.
// Copyright (c) 2021 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>
#include <unordered_map>

// static const auto io_sync_off = []() {
//  // turn off sync
//  std::ios::sync_with_stdio(false);
//  // untie in/out streams
//  std::cin.tie(nullptr);
//  return nullptr;
//}();

// 题号 8 : 两数之和 II - 输入有序数组
//
// 给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。
//
// 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
//

/*

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

示例:
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

 * */

class Title8 {

public:
  static std::vector<int> TwoSum(std::vector<int> &numbers, int target) {
    int size = numbers.size();
    std::vector<int> tmp_vec{0, 0};
    if (size < 2) {
      return tmp_vec;
    }
    std::unordered_map<int, int> unordered_map;
    for (int kI = 0; kI < size; ++kI) {
      int tmp = target - numbers[kI];
      if (unordered_map.find(tmp) != unordered_map.end()) {
        return std::vector<int>{unordered_map.find(tmp)->second, kI + 1};
      }
      unordered_map[numbers[kI]] = kI + 1;
    }
    return tmp_vec;
  }

  static std::vector<int> TwoSum2(std::vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1, sum = 0;
    while (l < r) {
      sum = numbers[l] + numbers[r];
      if (sum == target)
        break;
      if (sum < target)
        ++l;
      else
        --r;
    }
    return std::vector<int>{l + 1, r + 1};
  }
};

TEST(AlgArrayTitle8, test1) {

  std::vector<int> nums = {2, 7, 11, 15};
  std::vector<int> ret{0, 0};
  {
    ScopedTimer timer("Title8::TwoSum2");
    ret = Title8::TwoSum2(nums, 9);
  }

  EXPECT_EQ(ret[0], 1);
  EXPECT_EQ(ret[1], 2);

  std::vector<int> nums2 = {2, 7, 11, 15};
  std::vector<int> ret2{0, 0};
  {
    ScopedTimer timer("Title8::TwoSum");
    ret2 = Title8::TwoSum(nums2, 9);
  }

  EXPECT_EQ(ret2[0], 1);
  EXPECT_EQ(ret2[1], 2);
}
