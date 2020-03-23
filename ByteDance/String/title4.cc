//
// Created by believe on 2020/3/20.
// Copyright (c) 2020 believe. All rights reserved.
//

#include <iostream>
#include "util.h" // NOLINT

// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

/*
示例 1:

输入 : num1 = "2", num2 = "3"
输出 : "6"

示例 2:

输入 : num1 = "123", num2 = "456"
输出 : "56088"

说明 ：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

 */

class Title4 {
 public:
  static std::string Multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int size1 = num1.size(), size2 = num2.size();

    std::vector<int> vector(size1 + size2, 0);
    for (int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
        vector[i + j] += (num1[i] - '0') * (num2[j] - '0');
      }
    }

    for (int i = 0; i < size1 + size2; i++) {
      if (vector[i] > 9) {
        int t = vector[i];
        vector[i] = t % 10;
        vector[i + 1] += (t / 10);
      }
    }

    int pos = (vector[size1 + size2 - 1] == 0 ? size1 + size2 - 2 : size1 + size2 - 1);

    std::string ret_str = "";
    for (; pos >= 0; --pos) {
      ret_str += (vector[pos] + '0');
    }
    return ret_str;
  }

  static std::string Multiply2(std::string num1, std::string num2) {
    int len1 = num1.size(), len2 = num2.size();

    //前两个判断排除空串且保证后两个判断的下标访问不越界(短路特性)
    //后两个判断排除乘数为0的情况(num1 和 num2 均不以零开头，除非是数字 0 本身)
    if (len1 == 0 || len2 == 0 || num1[0] == '0' || num2[0] == '0') return "0";
    int product;
    std::string res(len1 + len2, '0');
    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = len2 - 1; j >= 0; j--) {
        product = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
        res[i + j] += product / 10;
        //当前位是重写，不是+=！
        //res[i+j+1]+=product%10;
        res[i + j + 1] = product % 10 + '0';
      }
    }
    //不用循环排除高位的'0'，因为若乘数中没有0，则只有最高位可能是'0'
    // for(int i=0;i<len1+len2;i++)
    //     if(res[i]!='0') return res.substr(i);
    // return "0";
    return res[0] == '0' ? res.substr(1) : res;
  }
};

TEST(Title4, base) {
  std::string ret;
  std::string str1 = "1";
  std::string str2 = "1";
  ret = Title4::Multiply(str1, str2);
  EXPECT_EQ("1", ret);

  str1 = "99";
  ret = Title4::Multiply(str1, str2);
  EXPECT_EQ("99", ret);

  str1 = "0";
  ret = Title4::Multiply(str1, str2);
  EXPECT_EQ("0", ret);

  str1 = "99";
  str2 = "2";
  ret = Title4::Multiply(str1, str2);
  EXPECT_EQ("198", ret);

  str1 = "11";
  str2 = "11";
  ret = Title4::Multiply(str1, str2);
  EXPECT_EQ("121", ret);

  str1 = "1999";
  str2 = "1999";
  ret = Title4::Multiply(str1, str2);
  EXPECT_EQ("3996001", ret);
}

TEST(Title4, test) {
  struct timeval start{}, end{};
  std::string ret;
  std::string str4_1 = "123456789";
  std::string str4_2 = "987654321";

  gettimeofday(&start, nullptr);
  ret = Title4::Multiply(str4_1, str4_2);
  gettimeofday(&end, nullptr);
  std::cout << "Multiply cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ("121932631112635269", ret);

  gettimeofday(&start, nullptr);
  ret = Title4::Multiply2(str4_1, str4_2);
  gettimeofday(&end, nullptr);
  std::cout << "Multiply2 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ("121932631112635269", ret);
}
