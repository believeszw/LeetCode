//
// Created by believe on 2021/1/10.
// Copyright (c) 2021 believe. All rights reserved.
//


#include <iostream>
#include "util.h" // NOLINT


// static const auto io_sync_off = []() {
//  // turn off sync
//  std::ios::sync_with_stdio(false);
//  // untie in/out streams
//  std::cin.tie(nullptr);
//  return nullptr;
//}();

// 题号 4 : 删除排序数组中的重复项 II
//
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//

/*

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

 * */

class Title9 {

 public:

  static bool IsPalindrome(std::string s) {
    (void)s;
    std::cout << "A" - "a" << std::endl;
    return true;
  }
};

TEST(AlgTitle9, test1) {

  struct timeval start{}, end{};
  std::string str = "A man, a plan, a canal: Panama";

  gettimeofday(&start, nullptr);
  bool ret_value = Title9::IsPalindrome(str);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_TRUE(ret_value);
}
