//
// Created by PC-Saw on 2018/12/25.
// Copyright (c) 2020 believe. All rights reserved.
//

#include <iostream>
#include <vector>

// 关闭 IO 同步
// static const auto io_sync_off = []() {
//  // turn off sync
//  std::ios::sync_with_stdio(false);
//  // untie in/out streams
//  std::cin.tie(nullptr);
//  return nullptr;
//}();

class Title4 {
public:
  // 题号 4 : 寻找两个有序数组的中位数
  /*
  给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

  请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

  你可以假设 nums1 和 nums2 不会同时为空。

  示例 1:
  nums1 = [1, 3]
  nums2 = [2]

  则中位数是 2.0
   */
  // 我的方法
  static double FindMedianSortedArrays(const std::vector<int> &nums1,
                                       const std::vector<int> &nums2) {
    int64_t size = 0;
    if (!nums1.empty() || !nums2.empty()) {
      size = nums1.size() + nums2.size();
    } else {
      return false;
    }

    int64_t m = 0, n = 0;
    // 判断中位数是两数平均值还是单个值
    if (size % 2 == 1) { // 总个数为基数则为中间值
      n = size / 2;
      m = n;
    } else { // 偶数则为中间俩个数的平均值
      n = size / 2;
      m = n - 1;
    }

    double midData = 0;
    int leftPoint = 0;
    int rightPoint = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();

    // 获取中位数
    for (int64_t i = 0; i <= n; ++i) {
      // 对数组进行判断是否越界
      if (leftPoint >= size1) { // 即将进行的操作下标将越界
        if (midData == 0)
          midData = (static_cast<double>(nums2[m - leftPoint] +
                                         nums2[n - leftPoint])) /
                    2;
        else
          midData = (midData + nums2[n - leftPoint]) / 2;
        return midData;
      }
      if (rightPoint >= size2) { // 即将进行的操作下标将越界
        if (midData == 0)
          midData = (static_cast<double>(nums1[m - rightPoint] +
                                         nums1[n - rightPoint])) /
                    2;
        else
          midData = (midData + nums1[n - rightPoint]) / 2;
        return midData;
      }

      // 向后推进
      if (nums1[leftPoint] <= nums2[rightPoint]) {
        if (i == m)
          midData = static_cast<double>(nums1[leftPoint]);
        if (i == n) {
          midData = (midData + nums1[leftPoint]) / 2;
          return midData;
        }

        leftPoint++;
      } else {
        if (i == m)
          midData = static_cast<double>(nums2[rightPoint]);

        if (i == n) {
          midData = (midData + nums2[rightPoint]) / 2;
          return midData;
        }
        rightPoint++;
      }
    }
    return midData;
  }

  // 性能最优解法
  static int FindKth(const std::vector<int> &nums1,
                     const std::vector<int> &nums2, int k) {
    if (nums1.empty())
      return nums2[k - 1];
    if (nums2.empty())
      return nums1[k - 1];
    if (k == 1)
      return std::min(nums1[0], nums2[0]);
    int i = std::min(static_cast<int>(nums1.size()), k / 2),
        j = std::min(static_cast<int>(nums2.size()), k / 2);
    if (nums1[i - 1] > nums2[j - 1]) {
      return FindKth(nums1, std::vector<int>(nums2.begin() + j, nums2.end()),
                     k - j);
    } else {
      return FindKth(std::vector<int>(nums1.begin() + i, nums1.end()), nums2,
                     k - i);
    }
    return 0;
  }

  static double FindMedianSortedArrays2(const std::vector<int> &nums1,
                                        const std::vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    return (FindKth(nums1, nums2, (m + n + 1) / 2) +
            FindKth(nums1, nums2, (m + n + 2) / 2)) /
           2.0;
  }
};
