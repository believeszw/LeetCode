//
// Created by believe on 2021/1/11.
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

// 题号 11 : 盛最多水的容器
//
// 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//

/*

说明：你不能倾斜容器。

示例 1：

输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：
输入：height = [1,1]
输出：1

示例 3：
输入：height = [4,3,2,1,4]
输出：16

示例 4：
输入：height = [1,2,1]
输出：2

提示：

n = height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104

 * */

class TitleXI {

 public:

  static int MaxArea(std::vector<int> &height) {
    int size = height.size();
    int left = 0, right = size - 1, ret = 0;
    while (left < right) {
      int tmp = std::min(height[left], height[right]) * (right - left);
      ret = tmp > ret ? tmp : ret;
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return ret;
  }
};

TEST(AlgArrayTitleXI, test1) {

  struct timeval start{}, end{};
  std::vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  gettimeofday(&start, nullptr);
  int ret_value = TitleXI::MaxArea(vec);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value, 49);

  std::vector<int> vec2 = {4, 3, 2, 1, 4};

  gettimeofday(&start, nullptr);
  int ret_value2 = TitleXI::MaxArea(vec2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value2, 16);

  std::vector<int> vec3 = {1, 3, 2, 5, 25, 24, 5};

  gettimeofday(&start, nullptr);
  int ret_value3 = TitleXI::MaxArea(vec3);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value3, 24);
}
