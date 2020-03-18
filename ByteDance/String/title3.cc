//
// Created by believe on 2020/3/18.
// Copyright (c) 2020 believe. All rights reserved.
//


#include <iostream>
#include "util.h" // NOLINT


// 题号 2 : 最长公共前缀
//
// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
//
// 换句话说，第一个字符串的排列之一是第二个字符串的子串。
//

/*
示例 1:

输入 : s1 = "ab" s2 = "eidbaooo"
输出 : True
解释 : s2 包含 s1 的排列之一 ("ba").

示例 2:

输入 : s1= "ab" s2 = "eidboaoo"
输出 : False

注意 :

1. 输入的字符串只包含小写字母
2. 两个字符串的长度都在 [1, 10,000] 之间

 * */

class Title3 {

 public:
  static bool CheckInclusion(const std::string& str1, const std::string& str2) {

    return false;
  }

};

TEST(Title3, test) {

  struct timeval start{}, end{};
  bool ret;

  std::string str3_1 = "ab";
  std::string str3_2 = "eidbaooo";

  gettimeofday(&start, nullptr);
  ret = Title3::CheckInclusion(str3_1, str3_2);
  gettimeofday(&end, nullptr);
  std::cout << "LongestCommonPrefix cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(false, ret);

}
