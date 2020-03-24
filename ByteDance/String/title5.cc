//
// Created by believe on 2020/3/23.
// Copyright (c) 2020 believe. All rights reserved.
//

#include <iostream>
#include <stack>
#include "util.h" // NOLINT

// 给定一个字符串，逐个翻转字符串中的每个单词。

/*
示例 1:

输入 : "the sky is blue"
输出 : "blue is sky the"

示例 2:

输入 : "  hello world!  "
输出 : "world! hello"
解释 : 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括.

示例 3:

输入 : "a good   example"
输出 : "example good a"
解释 : 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

说明 :

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

进阶 :

请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。

 */

class Title5 {
 public:
  static std::string ReverseWords(const std::string &str) {
    uint64_t size = str.size();

    std::vector<std::string> vector;
    int len = 1;
    std::string ret_str;

    for (uint64_t kI = 0; kI < size; ++kI) {
      if (str[kI] == ' ') {
        continue;
      }

      while (str[++kI] != ' ' && ++len) {
        if (kI + 1 == size) {
          vector.insert(vector.end(), str.substr(kI - len + 1, len));
          return GetStrFromVector(vector);
        }
      }
      vector.insert(vector.end(), str.substr(kI - len, len));
      len = 1;
    }

    return GetStrFromVector(vector);
  }

  static std::string GetStrFromVector(const std::vector<std::string> &vector) {
    std::string ret_str;
    auto vector_size = vector.size();
    for (uint64_t kJ = 0; kJ < vector_size; ++kJ) {
      ret_str += vector[vector_size - kJ - 1];
      if (kJ != vector_size - 1)
        ret_str += ' ';
    }
    return ret_str;
  }

};

TEST(Title5, test) {
  struct timeval start{}, end{};
  std::string ret;
  std::string str5_1 = "the sky is blue";
  std::string str5_2 = "blue is sky the";

  gettimeofday(&start, nullptr);
  ret = Title5::ReverseWords(str5_1);
  gettimeofday(&end, nullptr);
  std::cout << "ReverseWords cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(str5_2, ret);

  str5_1 = "  hello world!  ";
  str5_2 = "world! hello";

  gettimeofday(&start, nullptr);
  ret = Title5::ReverseWords(str5_1);
  gettimeofday(&end, nullptr);
  std::cout << "ReverseWords cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(str5_2, ret);

  str5_1 = "a good   example";
  str5_2 = "example good a";

  gettimeofday(&start, nullptr);
  ret = Title5::ReverseWords(str5_1);
  gettimeofday(&end, nullptr);
  std::cout << "ReverseWords cost time : " << diff(start, end) << " us." << std::endl;

  str5_1 = "   a   ";
  str5_2 = "a";

  gettimeofday(&start, nullptr);
  ret = Title5::ReverseWords(str5_1);
  gettimeofday(&end, nullptr);
  std::cout << "ReverseWords cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(str5_2, ret);
}
