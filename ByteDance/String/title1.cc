//
// Created by believe on 2020/3/16.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

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
  static int LengthOfLongestSubstring2(std::string str) {

    int mp[256];
    for (int &i : mp)
      i = -1;
    int max = 0, len = 0, j = -2, size = str.size();
    for (int i = 0; i < size; i++) {
      if (mp[str[i] - '0'] == -1 || mp[str[i] - '0'] <= j) {
        mp[str[i] - '0'] = i;
        len++;
        if (len > max)
          max = len;
      } else {

        len = i - mp[str[i] - '0'];
        j = mp[str[i] - '0'];
        mp[str[i] - '0'] = i;
      }
    }
    return max;
  }
};

TEST(ByteStrTitle1, test) {

  std::string str1_1 = "abcabcbb";
  std::string str1_2 = "bbbbb";
  std::string str1_3 = "pwwkew";
  int ret = -1;

  {
    ScopedTimer timer("Title1::LengthOfLongestSubstring");
    ret = Title1::LengthOfLongestSubstring(str1_1);
  }
  EXPECT_EQ(3, ret);

  {
    ScopedTimer timer("Title1::LengthOfLongestSubstring2");
    ret = Title1::LengthOfLongestSubstring2(str1_2);
  }
  EXPECT_EQ(1, ret);

  {
    ScopedTimer timer("Title1::LengthOfLongestSubstring");
    ret = Title1::LengthOfLongestSubstring(str1_3);
  }
  EXPECT_EQ(3, ret);
}
