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

// 题号 12 : 长度最小的子数组
//
// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
//

/*

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

进阶：

如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

 * */

class TitleXII {

 public:

  static int MinSubArrayLen(int s, std::vector<int> &nums) {
    int size = nums.size();
    int min = size, sum = 0, left = 0;
    for (int kI = 0; kI < size; ++kI) {
      sum += nums[kI];
      while (sum >= s) {
        min = min > kI - left + 1 ? kI - left + 1 : min;
        sum -= nums[left++];
      }
    }
    if (left == 0)
      return 0;
    return min;
  }

  // todo O(nlogn)
  static int MinSubArrayLen2(int s, std::vector<int> &nums) {
    int size = nums.size();
    int min = size, sum = 0, left = 0;
    (void) s;
    (void) sum;
    (void) left;
    return min;
  }
};

TEST(AlgTitleXII, test1) {

  struct timeval start{}, end{};
  std::vector<int> ret = {2, 3, 1, 2, 4, 3};

  gettimeofday(&start, nullptr);
  int ret_value = TitleXII::MinSubArrayLen(7, ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value, 2);

}
