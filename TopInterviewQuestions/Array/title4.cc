//
// Created by PC-Saw on 2019/09/23.
//


#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "util.h"


// 题号 4 : Contains Duplicate
//
// Given an array of integers, find if the array contains any duplicates.
//
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

/*
Example 1:

Input: [1,2,3,1]
Output: true

Example 2:

Input: [1,2,3,4]
Output: false

Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

 * */

class Title4 {

 public:
  static bool ContainsDuplicate(std::vector<int> &nums) {
    return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
  }

  static bool ContainsDuplicateBetter(std::vector<int> &nums) {
    int size = nums.size();
    if (size <= 1) return false;

    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < size; ++i) if (nums[i] == nums[i - 1]) return true;

    return false;
  }
};

TEST(Title4_test4_Test, test4) {

  std::vector<int> vector4 = {1, 1, 3, 4, 5, 6, 7};
  bool ret = false;
  struct timeval start{}, end{};

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 100; ++kI) {
    ret = Title4::ContainsDuplicate(vector4);
  }
  gettimeofday(&end, nullptr);
  std::cout << "ContainsDuplicate       cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_TRUE(ret);

  ret = false;
  vector4 = {1, 1, 3, 4, 5, 6, 7};
  // ContainsDuplicateBetter
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 100; ++kJ) {
    ret = Title4::ContainsDuplicateBetter(vector4);
  }
  gettimeofday(&end, nullptr);
  std::cout << "ContainsDuplicateBetter cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_TRUE(ret);
}
