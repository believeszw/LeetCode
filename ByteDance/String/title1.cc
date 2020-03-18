//
// Created by believe on 2020/3/16.
// Copyright (c) 2020 believe. All rights reserved.
//


#include <iostream>
#include "util.h" // NOLINT


// 题号 1 : 无重复字符的最长子串
//
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//

/*
示例 1:

输入 : "abcabcbb"
输出 : 3
解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入 : "bbbbb"
输出 : 1
解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入 : "pwwkew"
输出 : 3
解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

 * */

class Title1 {

 public:
  static int LengthOfLongestSubstring(std::string str) {
    int left{0}, right{0}, ret{0}, length{0};
    int len = str.size();

    while (right < len) {
      char tmpChar = str.at(right);
      for (int index = left; index < right; ++index) {
        if (str.at(index) == tmpChar) {
          left = index + 1;
          length = right - left;
          break;
        }
      }
      ++right;
      ret = std::max(++length, ret);
    }
    return ret;
  }

  // LeetCode 上采用映射的一种思路
  static int LengthOfLongestSubstring2(std::string s) {

    int mp[256];
    for (int &i : mp) i = -1;
    int max = 0, len = 0, j = -2, size = s.size();
    for (int i = 0; i < size; i++) {
      if (mp[(int) s[i]] == -1 || mp[(int) s[i]] <= j) {
        mp[(int) s[i]] = i;
        len++;
        if (len > max) max = len;
      } else {

        len = i - mp[(int) s[i]];
        j = mp[(int) s[i]];
        mp[(int) s[i]] = i;
      }
    }
    return max;
  }
};

TEST(Title1, test) {

  struct timeval start{}, end{};
  std::string str1_1 = "abcabcbb";
  std::string str1_2 = "bbbbb";
  std::string str1_3 = "pwwkew";
  int ret = -1;

  gettimeofday(&start, nullptr);
  ret = Title1::LengthOfLongestSubstring(str1_1);
  gettimeofday(&end, nullptr);
  std::cout << "LengthOfLongestSubstring cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(3, ret);

  gettimeofday(&start, nullptr);
  ret = Title1::LengthOfLongestSubstring2(str1_2);
  gettimeofday(&end, nullptr);
  std::cout << "LengthOfLongestSubstring2 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(1, ret);

  gettimeofday(&start, nullptr);
  ret = Title1::LengthOfLongestSubstring(str1_1);
  gettimeofday(&end, nullptr);
  std::cout << "LengthOfLongestSubstring cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(3, ret);
}
