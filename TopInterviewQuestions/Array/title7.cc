//
// Created by PC-Saw on 2019/09/23.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

// 题号 7 : Plus One
//
// Given a non-empty array of digits representing a non-negative integer, plus
// one to the integer.
//
// The digits are stored such that the most significant digit is at the head of
// the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the
// number 0 itself.
//

/*
Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

 * */

class Title7 {

public:
  static std::vector<int> PlusOne(std::vector<int> &digits) { // NOLINT
    int carry = 1;
    for (int i = static_cast<int>(digits.size() - 1); i >= 0; i--) {
      int s = digits[i] + carry;
      digits[i] = s % 10;
      carry = s / 10;
    }
    if (carry)
      digits.insert(digits.begin(), carry);
    return digits;
  }

  static std::vector<int> PlusOneBetter(std::vector<int> &digits) { // NOLINT
    int size = digits.size();
    for (int i = size - 1; i >= 0; --i) {
      if (digits[i] + 1 < 10) {
        digits[i]++;
        return digits;
      } else {
        digits[i] = 0;
      }
    }
    digits.insert(digits.end(), digits[size - 1]);
    for (int j = size; j > 0; --j) {
      digits[j] = digits[j - 1];
    }
    digits[0] = 1;
    return digits;
  }
};

TEST(TopArrTitle7, test7) {

  std::vector<int> vector7_1 = {9, 9, 9, 8};
  std::vector<int> vector7_2 = {9, 9, 9, 8};
  std::vector<int> ret = {0};

  {
    ScopedTimer timer("Title7::PlusOne");
    for (int kI = 0; kI < 100; ++kI) {
      ret = Title7::PlusOne(vector7_1);
    }
  }
  EXPECT_EQ(9, ret[3]);

  // SingleNumberBetter
  ret = {0};
  {
    ScopedTimer timer("Title7::PlusOneBetter");
    for (int kJ = 0; kJ < 100; ++kJ) {
      ret = Title7::PlusOneBetter(vector7_2);
    }
  }
  EXPECT_EQ(9, ret[3]);
}
