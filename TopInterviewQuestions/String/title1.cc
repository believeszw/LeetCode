//
// Created by believe on 2020/3/11.
//


#include <iostream>
#include "util.h"


// 题号 1 : Reverse String
//
// Write a function that reverses a string. The input string is given as an array of characters char[].
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// You may assume all the characters consist of printable ascii characters.

/*
Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

 * */

class Title1 {

 public:
  void ReverseString(std::vector<char>& s) {
    int length = s.size();
    for (int kI = 0; kI < length / 2; ++kI) {
      s[kI] = std::exchange(s[length - 1 - kI], s[kI]);
    }
  }
};

TEST(Title1, test) {
  Title1 title_1;
  struct timeval start{}, end{};
  std::vector<char> char_vector = {'h', 'e', 'l', 'l', 'o'};

  gettimeofday(&start, nullptr);
  title_1.ReverseString(char_vector);
  gettimeofday(&end, nullptr);
  std::cout << "ReverseString cost time : " << diff(start, end) << " us." << std::endl;


  EXPECT_EQ('o', char_vector[0]);
  EXPECT_EQ('l', char_vector[1]);
  EXPECT_EQ('l', char_vector[2]);
  EXPECT_EQ('e', char_vector[3]);
  EXPECT_EQ('h', char_vector[4]);
}