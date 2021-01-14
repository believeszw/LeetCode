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
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    int ans = INT_MAX;
    std::vector<int> sums(n + 1, 0);
    // 为了方便计算，令 size = n + 1
    // sums[0] = 0 意味着前 0 个元素的前缀和为 0
    // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
    // 以此类推
    for (int i = 1; i <= n; i++) {
      sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      int target = s + sums[i - 1];
      auto bound = lower_bound(sums.begin(), sums.end(), target);
      if (bound != sums.end()) {
        ans = std::min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};

TEST(AlgArrayTitleXII, test1) {

  struct timeval start{}, end{};
  std::vector<int> ret = {2, 3, 1, 2, 4, 3};

  gettimeofday(&start, nullptr);
  int ret_value = TitleXII::MinSubArrayLen(7, ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value, 2);

  std::vector<int> ret2 = {2, 3, 1, 2, 4, 3};

  gettimeofday(&start, nullptr);
  int ret_value2 = TitleXII::MinSubArrayLen2(7, ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value2, 2);
}
