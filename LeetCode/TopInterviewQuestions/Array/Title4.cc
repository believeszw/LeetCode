//
// Created by PC-Saw on 2019/06/16.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE4_H
#define TOP_INTERVIEW_QUESTIONS_TITLE4_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "Util.h"


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

static const auto io_sync_off = []() {
  // turn off sync
  std::ios::sync_with_stdio(false);
  // untie in/out streams
  std::cin.tie(nullptr);
  return nullptr;
}();

class Title4 {

 public:
  bool ContainsDuplicate(std::vector<int> &nums) {
    return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
  }

  bool ContainsDuplicateBetter(std::vector<int> &nums) {
    int size = nums.size();
    if (size <= 1) return false;

    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < size; ++i) if (nums[i] == nums[i - 1]) return true;

    return false;
  }
};

TEST(Title, test4) {
  Title4 t4;
  std::vector<int> vector4 = {1, 1, 3, 4, 5, 6, 7};
  struct timeval start{}, end{};

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 100; ++kI) {
    t4.ContainsDuplicate(vector4);
  }
  gettimeofday(&end, nullptr);
  std::cout << "ContainsDuplicate cost time : " << diff(start, end) << " us." << std::endl;


  vector4 = {1, 1, 3, 4, 5, 6, 7};
  // ContainsDuplicateBetter
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 100; ++kJ) {
    t4.ContainsDuplicateBetter(vector4);
  }
  gettimeofday(&end, nullptr);
  std::cout << "ContainsDuplicateBetter cost time : " << diff(start, end) << " us." << std::endl;
}

#endif // TOP_INTERVIEW_QUESTIONS_TITLE4_H
