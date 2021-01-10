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

// 题号 7 : 合并两个有序数组
//
// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//

/*

 说明：

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例 1:

输入：
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出：[1,2,2,3,5,6]

提示：

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n

 * */

class Title7 {

 public:

  static void Merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int index1 = m - 1, index2 = n - 1;
    int i = m + n - 1;
    while (i != index1) {
      if (index1 >= 0 && nums1[index1] >= nums2[index2]) nums1[i--] = nums1[index1--];
      else nums1[i--] = nums2[index2--];
    }
  }
};

TEST(AlgTitle7, test1) {

  struct timeval start{}, end{};
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m_1 = 3;
  std::vector<int> nums2 = {4, 5, 6};
  int m_2 = 3;

  gettimeofday(&start, nullptr);
  Title7::Merge(nums1, m_1, nums2, m_2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  int size = nums1.size();
  for (int kI = 0; kI < size; ++kI) {
    std::cout << nums1[kI];
    if (kI != size - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;
}
