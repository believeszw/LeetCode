//
// Created by PC-Saw on 2018/12/25.
//

#ifndef UNTITLED_TITLE1_H
#define UNTITLED_TITLE1_H

#include <vector>
#include <unordered_map>
#include "util.h"

// 题号 1 : Two Sum
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//

/*
Example 1:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 * */

class Title1 {

 public:
  std::vector<int> TwoSum(std::vector<int> &nums, int target) {
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

TEST(Title, test) {
  Title1 title_1;
  std::vector<int> vector = {2, 7, 11, 15};
  std::vector<int> ret = {0};
  struct timeval start{}, end{};

  gettimeofday(&start, nullptr);
  ret = title_1.TwoSum(vector, 9);
  gettimeofday(&end, nullptr);
  std::cout << "TwoSum cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(0, ret[0]);
  EXPECT_EQ(1, ret[1]);

}

#endif //UNTITLED_TITLE1_H
