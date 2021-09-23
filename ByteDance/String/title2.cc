//
// Created by believe on 2020/3/16.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

// 题号 2 : 最长公共前缀
//
// 编写一个函数来查找字符串数组中的最长公共前缀。
//
// 如果不存在公共前缀，返回空字符串 ""。
//

/*
示例 1:

输入 : ["flower","flow","flight"]
输出 : "fl"

示例 2:

输入 : ["dog","racecar","car"]
输出 : ""
解释 : 输入不存在公共前缀。

说明 :

所有输入只包含小写字母 a-z 。

 * */

class Title2 {

public:
  static std::string LongestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.empty())
      return "";

    std::string first = strs[0];
    if (first.empty())
      return "";

    unsigned int size = strs.size(), index = 0;
    if (size == 1)
      return first;

    std::string ret;
    bool flag = true;
    while (flag) {
      char tmp = first[index];

      for (unsigned int kI = 1; kI < size; ++kI) {
        if (tmp != strs[kI][index])
          return ret;
        if (index == strs[kI].size() - 1)
          flag = false;
      }

      ++index;
      ret += tmp;
    }

    return ret;
  }

  static std::string LongestCommonPrefix2(std::vector<std::string> &strs) {
    std::string ret = !strs.empty() ? strs[0] : "";
    for (const auto &str : strs) {
      while (str.substr(0, ret.size()) != ret) {
        ret = ret.substr(0, ret.size() - 1);
        if (ret.empty())
          return ret;
      }
    }
    return ret;
  }
};

TEST(ByteStrTitle2, test) {

  std::string ret;

  std::vector<std::string> str2_1;
  str2_1.insert(str2_1.end(), "flower");
  str2_1.insert(str2_1.end(), "flow");
  str2_1.insert(str2_1.end(), "flight");

  std::vector<std::string> str2_2;
  str2_2.insert(str2_2.end(), "dog");
  str2_2.insert(str2_2.end(), "racecar");
  str2_2.insert(str2_2.end(), "car");
  {
    ScopedTimer timer("Title2::LongestCommonPrefix");
    ret = Title2::LongestCommonPrefix(str2_1);
  }

  EXPECT_EQ("fl", ret);

  {
    ScopedTimer timer("Title2::LongestCommonPrefix2");
    ret = Title2::LongestCommonPrefix2(str2_1);
  }

  EXPECT_EQ("fl", ret);

  {
    ScopedTimer timer("Title2::LongestCommonPrefix2");
    ret = Title2::LongestCommonPrefix2(str2_2);
  }
  EXPECT_EQ("", ret);
}
