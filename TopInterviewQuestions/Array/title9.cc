//
// Created by PC-Saw on 2019/09/23.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>
#include <unordered_map>

// 题号 9 : Two Sum
//
// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
//

/*
Example 1:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 * */

class Title9 {

public:
  static std::vector<int> TwoSum(const std::vector<int> &nums, int target) {
    // 哈希表和map在这个数量级下性能差异不明显
    std::unordered_map<int, int> unordered_map;
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
      int complement = target - nums[i];
      if (unordered_map.find(complement) != unordered_map.end()) {
        return std::vector<int>{unordered_map.find(complement)->second, i};
      }
      unordered_map[nums[i]] = i;
    }
    return std::vector<int>{-1, -1};
  }
};

TEST(TopArrTitle9, test9) {

  std::vector<int> vector9 = {2, 7, 11, 15};
  std::vector<int> ret = {0};

  {
    ScopedTimer timer("Title9::TwoSum");
    ret = Title9::TwoSum(vector9, 9);
  }

  EXPECT_EQ(0, ret[0]);
  EXPECT_EQ(1, ret[1]);
}
