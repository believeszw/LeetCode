//
// Created by PC-Saw on 2019/09/23.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

// 题号 8 : Move Zeroes
//
// Given an array nums, write a function to move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.
//

/*
Example 1:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

 * */

class Title8 {

public:
  static void MoveZeroesBetter(std::vector<int> &nums) { // NOLINT

    int size = static_cast<int>(nums.size());
    if (size <= 0) {
      return;
    }

    int zeroIndex = 0;
    for (int i = 0; i < size; ++i) {
      // 如果是非零的则赋值
      if (nums[i] != 0) {
        nums[zeroIndex] = nums[i];
        if (zeroIndex++ != i) {
          nums[i] = 0;
        }
      }
    }
  }

  static void MoveZeroes(std::vector<int> &nums) { // NOLINT

    int size = static_cast<int>(nums.size());
    if (size <= 0) {
      return;
    }

    int zeroIndex = 0;
    for (int i = 0; i < size; ++i) {
      // 如果是非零的则赋值
      if (nums[i] != 0) {
        nums[zeroIndex++] = nums[i];
      }
    }
    for (int j = zeroIndex; j < size; ++j) {
      nums[j] = 0;
    }
  }
};

TEST(TopArrTitle8, test8) {

  std::vector<int> vector8 = {9, 0, 11, 9, 0, 2, 0};

  {
    ScopedTimer timer("Title8::MoveZeroesBetter");
    for (int kI = 0; kI < 1000; ++kI) {
      Title8::MoveZeroesBetter(vector8);
    }
  }
  EXPECT_EQ(0, vector8[4]);
  EXPECT_EQ(0, vector8[5]);
  EXPECT_EQ(0, vector8[6]);

  vector8 = {9, 1, 0, 9, 0, 2, 0};
  {
    ScopedTimer timer("Title8::MoveZeroes");
    for (int kJ = 0; kJ < 1000; ++kJ) {
      Title8::MoveZeroes(vector8);
    }
  }
  EXPECT_EQ(0, vector8[4]);
  EXPECT_EQ(0, vector8[5]);
  EXPECT_EQ(0, vector8[6]);
}
