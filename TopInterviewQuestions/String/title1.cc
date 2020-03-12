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
  void ReverseString(std::vector<char> &s) {
    int length = s.size();
    for (int kI = 0; kI < length / 2; ++kI) {
      s[kI] = std::exchange(s[length - 1 - kI], s[kI]);
    }
  }
  void ReverseString2(std::vector<char> &s) {
    int length = s.size();
    for (int kI = 0; kI < length / 2; ++kI) {
      std::swap(s[kI], s[length-1-kI]);
    }
  }
  void ReverseString3(std::vector<char> &s) {
    int i = 0, j = s.size() - 1;

    while(i < j) {
      char temp = s[i];
      s[i] = s[j];
      s[j] = temp;

      i++; j--;
    }
  }
};

TEST(Title1_test_Test, test) {
  Title1 title_1;
  struct timeval start{}, end{};
  std::vector<char> char_vector = {'h', 'e', 'l', 'l', 'o'};
  std::vector<char> char_vector2 = {'o', 'l', 'l', 'e', 'h'};
  std::vector<char> char_vector3 = {'a', 'b', 'c', 'd', 'e'};

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 101; ++kI) {
    title_1.ReverseString(char_vector);
  }
  gettimeofday(&end, nullptr);
  std::cout << "ReverseString cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ('o', char_vector[0]);
  EXPECT_EQ('l', char_vector[1]);
  EXPECT_EQ('l', char_vector[2]);
  EXPECT_EQ('e', char_vector[3]);
  EXPECT_EQ('h', char_vector[4]);

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 101; ++kI) {
    title_1.ReverseString2(char_vector2);
  }
  gettimeofday(&end, nullptr);
  std::cout << "ReverseString2 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ('h', char_vector2[0]);
  EXPECT_EQ('e', char_vector2[1]);
  EXPECT_EQ('l', char_vector2[2]);
  EXPECT_EQ('l', char_vector2[3]);
  EXPECT_EQ('o', char_vector2[4]);

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 101; ++kI) {
    title_1.ReverseString3(char_vector3);
  }
  gettimeofday(&end, nullptr);
  std::cout << "ReverseString3 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ('e', char_vector3[0]);
  EXPECT_EQ('d', char_vector3[1]);
  EXPECT_EQ('c', char_vector3[2]);
  EXPECT_EQ('b', char_vector3[3]);
  EXPECT_EQ('a', char_vector3[4]);
}