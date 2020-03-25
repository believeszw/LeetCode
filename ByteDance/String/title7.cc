//
// Created by believe on 2020/3/26.
// Copyright (c) 2020 believe. All rights reserved.
//

#include <iostream>
#include "util.h" // NOLINT

// 题号 7 : 复原IP地址
//
// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//

/*
示例 1:

输入 : "25525511135"
输出 : ["255.255.11.135", "255.255.111.35"]

 */

static std::vector<std::string> res;

class Title7 {
 public:
  static std::vector<std::string> RestoreIpAddresses(std::string str) {
    std::string ip;
    Helper(str, 0, ip);
    return res;
  }
  static void Helper(std::string str, int index, std::string ip) {
    int size = str.size();
    if (index == 4) {
      if (str.empty()) res.push_back(ip);
    } else {
      for (int k = 1; k < 4; ++k) {
        if (size < k) break;
        int val = stoi(str.substr(0, k));
        int size_val = std::to_string(val).size();
        if (val > 255 || k != size_val) continue;  //剪枝
        Helper(str.substr(k), index + 1, ip + str.substr(0, k) + (index == 3 ? "" : "."));
      }
    }
    return;
  }
};

TEST(Title7, test) {
  std::string str7_1 = "25525511135";
  std::vector<std::string> ret;
  ret = Title7::RestoreIpAddresses(str7_1);

  EXPECT_EQ("255.255.11.135", ret[0]);
  EXPECT_EQ("255.255.111.35", ret[1]);
}
