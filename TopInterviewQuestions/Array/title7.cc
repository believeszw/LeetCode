//
// Created by PC-Saw on 2019/09/23.
//


#include <iostream>
#include "util.h"

// 题号 7 : Plus One
//
// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
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

  std::vector<int> PlusOne(std::vector<int> &digits) {
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

  std::vector<int> PlusOneBetter(std::vector<int> &digits) {
    int size = static_cast<int>(digits.size());
    for (int i = size - 1; i >= 0; --i) {
      if (digits[i] + 1 < 10) {
        digits[i]++;
        return digits;
      } else {
        digits[i] = 0;
      }

    }
    digits.push_back(digits[size - 1]);
    for (int j = size; j > 0; --j) {
      digits[j] = digits[j - 1];
    }
    digits[0] = 1;
    return digits;
  }
};

TEST(Title_test7_Test, test7) {
  Title7 title_7;
  std::vector<int> vector7_1 = {9, 9, 9, 8};
  std::vector<int> vector7_2 = {9, 9, 9, 8};
  std::vector<int> ret = {0};
  struct timeval start{}, end{};

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 100; ++kI) {
    ret = title_7.PlusOne(vector7_1);
  }
  gettimeofday(&end, nullptr);
  std::cout << "PlusOne       cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(9, ret[3]);

  // SingleNumberBetter
  ret = {0};
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 100; ++kJ) {
    ret = title_7.PlusOneBetter(vector7_2);
  }
  gettimeofday(&end, nullptr);
  std::cout << "PlusOneBetter cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(9, ret[3]);

}
