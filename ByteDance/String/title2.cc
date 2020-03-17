//
// Created by believe on 2020/3/16.
//


#include <iostream>
#include "util.h"


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
  static std::string LongestCommonPrefix(std::vector<std::string>& strs) {

    return "";
  }


};

TEST(Title2, test) {

  struct timeval start{}, end{};
  std::vector<std::string> str2_1 = {"flower", "flow", "flight"};
  std::vector<std::string> str2_2 = {"dog", "racecar", "car"};
  std::string ret;

  gettimeofday(&start, nullptr);
  ret = Title2::LongestCommonPrefix(str2_1);
  gettimeofday(&end, nullptr);
  std::cout << "LongestCommonPrefix cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ("fl", ret);

  gettimeofday(&start, nullptr);
  ret = Title2::LongestCommonPrefix(str2_2);
  gettimeofday(&end, nullptr);
  std::cout << "LongestCommonPrefix cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ("", ret);


}