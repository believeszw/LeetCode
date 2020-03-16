//
// Created by believe on 2020/3/16.
//


#include <iostream>
#include "util.h"


// 题号 1 : 无重复字符的最长子串
//
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//

/*
Example 1:

Input: "abcabcbb"
Output: 3
explain: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

Example 2:

Input: "bbbbb"
Output: 1
explain: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

Example 3:

Input: "pwwkew"
Output: 3
explain: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

 * */

class Title1 {

 public:
  int LengthOfLongestSubstring(std::string str) {
    int left = 0, right = 0, ret = 0;
    int len = str.length();
    while (right < len) {
      for (int kI = 0; kI < right; ++kI) {
        if (str.at(kI) == str.at(right)) {
          ret = right - left;
          left = kI + 1;
        }
      }

      right++;
    }

    return ret;
  }
};

TEST(Title1_test_Test, test) {
  Title1 title_1;
  struct timeval start{}, end{};
  std::string str1_1 = "abcabcbb";
  std::string str1_2 = "bbbbb";
  std::string str1_3 = "pwwkew";
  int ret = -1;

  gettimeofday(&start, nullptr);
//  for (int kI = 0; kI < 101; ++kI) {
  ret = title_1.LengthOfLongestSubstring(str1_1);
//  }
  gettimeofday(&end, nullptr);
  std::cout << "ReverseString cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(3, ret);



}