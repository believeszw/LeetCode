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

// 题号 6 : 数组中的第K个最大元素
//
// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//

/*

示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

 * */

class Title6 {

 public:
  static void AdjustHeap(std::vector<int> &nums, int index, int len) {

    //先取出当前元素i
    int temp = nums[index];

    //从i结点的左子结点开始，也就是2i+1处开始
    for (int k = index * 2 + 1; k < len; k = k * 2 + 1) {
      //如果左子结点小于右子结点，k指向右子结点
      if (k + 1 < len && nums[k] < nums[k + 1]) {
        k++;
      }
      //如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
      if (nums[k] > temp) {
        nums[index] = nums[k];
        index = k;
      } else {
        break;
      }
    }
    //将temp值放到最终的位置
    nums[index] = temp;
  }

  static int FindKthLargest(std::vector<int> &nums, int k) {
    int size = nums.size();
    if (size < 1) return 0;
    for (int kI = size / 2 - 1; kI >= 0; --kI) {
      AdjustHeap(nums, kI, size);
    }
    for (int kI = size - 1; kI > 0; --kI) {
      std::swap(nums[0], nums[kI]);
      AdjustHeap(nums, 0, kI);
    }

    return nums[size - k];
  }

};

TEST(AlgArrayTitle6, test1) {

  struct timeval start{}, end{};
  std::vector<int> ret = {3, 2, 1, 5, 6, 4};

  gettimeofday(&start, nullptr);
  int ret_value = Title6::FindKthLargest(ret, 2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(5, ret_value);
  for (int kI = 0; kI < 6; ++kI) {
    std::cout << ret[kI];
    if (kI != 5)
      std::cout << ", ";
  }
  std::cout << std::endl;

  std::vector<int> ret2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

  gettimeofday(&start, nullptr);
  ret_value = Title6::FindKthLargest(ret2, 4);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(4, ret_value);
  for (int kI = 0; kI < 9; ++kI) {
    std::cout << ret2[kI];
    if (kI != 8)
      std::cout << ", ";
  }
  std::cout << std::endl;
}
