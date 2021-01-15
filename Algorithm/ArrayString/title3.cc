//
// Created by believe on 2021/1/15.
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

// 题号 3 : 合并区间
//
// 给出一个区间的集合，请合并所有重叠的区间。
//

/*
示例 1:
输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。

提示：
intervals[i][0] <= intervals[i][1]

 * */

class Title3 {
 public:
  static std::vector<std::vector<int>> Merge(std::vector<std::vector<int>>& intervals) {
    (void)intervals;
    return std::vector<std::vector<int>>{0};
  }
};

TEST(AlgStrTitle3, test1) {
  struct timeval start{}, end{};
  std::vector<std::vector<int>> ret = {{1,3},{2,6},{8,10},{15,18}};
  std::vector<std::vector<int>> expect_ret = {{1,6},{8,10},{15,18}};
  gettimeofday(&start, nullptr);
  std::vector<std::vector<int>> ret_value = Title3::Merge(ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(ret_value, expect_ret);

  std::vector<std::vector<int>> ret2 = {{1,4},{4,5}};
  std::vector<std::vector<int>> expect_ret2 = {{1,5}};
  gettimeofday(&start, nullptr);
  std::vector<std::vector<int>> ret_value2 = Title3::Merge(ret2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(ret_value2, expect_ret2);
}
