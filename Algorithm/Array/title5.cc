//
// Created by PC-Saw on 2021/01/07.
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

// 题号 5 : 颜色分类
//
// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//

/*

进阶：

你可以不使用代码库中的排序函数来解决这道题吗？
你能想出一个仅使用常数空间的一趟扫描算法吗？

示例 1:
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

示例 2:
输入：nums = [2,0,1]
输出：[0,1,2]

示例 3：
输入：nums = [0]
输出：[0]

示例 4：
输入：nums = [1]
输出：[1]

提示：

n == nums.length
1 <= n <= 300
nums[i] 为 0、1 或 2

 * */

class Title5 {

 public:

  static void SortColors(std::vector<int> &nums) {
    int size = nums.size();
    if (size < 2) return;
    int left = 0, right = size - 1;

    for (int kI = 0; kI <= right; ++kI) {
      if (nums[kI] == 0) {
        if (kI == left) {
          left++;
          continue;
        }
        std::swap(nums[kI--], nums[left++]);
      }
      if (nums[kI] == 2) {
        std::swap(nums[kI--], nums[right--]);
      }
    }
  }

  static void SortColors2(std::vector<int> &nums) {
    int size = nums.size();
    if (size < 2) return;
    int red = 0, white = 0, cnt = 0;
    for (int kI = 0; kI < size; ++kI) {
      if (nums[kI] == 0) {
        red++;
      } else if (nums[kI] == 1) {
        white++;
      }
    }

    for (; cnt < red; ++cnt) {
      nums[cnt] = 0;
    }
    for (; cnt < white + red; ++cnt) {
      nums[cnt] = 1;
    }
    for (; cnt < size; ++cnt) {
      nums[cnt] = 2;
    }

  }
};

TEST(AlgArrayTitle5, test1) {

  struct timeval start{}, end{};
  std::vector<int> ret = {2, 0, 2, 1, 1, 0};

  gettimeofday(&start, nullptr);
  Title5::SortColors2(ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  for (int kI = 0; kI < 6; ++kI) {
    std::cout << ret[kI];
    if (kI != 5)
      std::cout << ", ";
  }
  std::cout << std::endl;

  std::vector<int> ret2 = {2, 0, 1};

  gettimeofday(&start, nullptr);
  Title5::SortColors(ret2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  for (int kI = 0; kI < 3; ++kI) {
    std::cout << ret2[kI];
    if (kI != 2)
      std::cout << ", ";
  }

}
