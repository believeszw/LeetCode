//
// Created by believe on 2020/3/28.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <algorithm>
#include <iostream>

// 题号 1 : 三数之和
//
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得
// a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
//
// 注意：答案中不可以包含重复的三元组。
//

/*
示例 :

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

 * */

class Title1 {
public:
  static std::vector<std::vector<int>>
  ThreeSum(std::vector<int> &nums) { // NOLINT
    uint64_t size = nums.size();
    std::vector<std::vector<int>> ret;
    if (size < 3)
      return ret;
    sort(nums.begin(), nums.end());

    for (uint64_t kI = 0; kI < size - 2; ++kI) {
      if (nums.at(kI) > 0)
        break;
      if (kI > 0 && nums.at(kI) == nums.at(kI - 1))
        continue;
      uint64_t left = kI + 1;
      uint64_t right = size - 1;
      while (left < right) {
        int sum = nums[kI] + nums[left] + nums[right];
        if (sum < 0) {
          ++left;
        } else if (sum > 0) {
          --right;
        } else {
          ret.push_back({nums.at(kI), nums.at(left++), nums.at(right--)});
          while (nums[left] == nums[left - 1] && left++ < right) {
          }
          while (nums[right] == nums[right + 1] && left < right--) {
          }
        }
      }
    }
    return ret;
  }
};

TEST(Title1, test) {

  std::vector<int> vector1_1{-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> ret;
  std::vector<int> vector1_2{-1, -1, 2};
  std::vector<int> vector1_3{-1, 0, 1};
  {
    ScopedTimer timer("Title1::ThreeSum");
    ret = Title1::ThreeSum(vector1_1);
  }

  EXPECT_EQ(vector1_2, ret[0]);
  EXPECT_EQ(vector1_3, ret[1]);
}
