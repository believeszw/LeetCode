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

// 题号 10 : 反转字符串中的元音字母
//
// 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//

/*

示例 1：
输入："hello"
输出："holle"

示例 2：
输入："leetcode"
输出："leotcede"

提示：

元音字母不包含字母 "y" 。

 * */

class TitleX {

 public:

  static std::string ReverseVowels2(std::string str) {
    std::set<char> vec{'a', 'e', 'i', 'o', 'u'};
    int size = str.size();
    int left = 0, right = size - 1;
    while (left < right) {
      while (vec.find(tolower(str[left])) == vec.end() && left < right) {
        ++left;
      }
      while (vec.find(tolower(str[right])) == vec.end() && left < right) {
        --right;
      }
      std::swap(str[left++], str[right--]);
    }
    return str;
  }

  static std::string ReverseVowels(std::string str) {
    int size = str.size();
    int left = 0, right = size - 1;
    while (left < right) {
      while (!IsVowel(str[left]) && left < right) {
        ++left;
      }
      while (!IsVowel(str[right]) && left < right) {
        --right;
      }
      std::swap(str[left++], str[right--]);
    }
    return str;
  }
  static bool IsVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      return true;
    } else
      return false;
  }

};

TEST(AlgTitleX, test1) {

  struct timeval start{}, end{};
  std::string str = "leetcode";

  gettimeofday(&start, nullptr);
  std::string ret_value = TitleX::ReverseVowels(str);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value, "leotcede");

  std::string str2 = "hello";

  gettimeofday(&start, nullptr);
  std::string ret_value2 = TitleX::ReverseVowels2(str2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value2, "holle");
}
