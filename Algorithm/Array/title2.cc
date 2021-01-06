//
// Created by PC-Saw on 2021/01/06.
// Copyright (c) 2020 believe. All rights reserved.
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

// 题号 2 : 移除元素
//
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//

/*
示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。

示例 2:

 给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。

 说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
  print(nums[i]);
}

 * */

class Title1 {

 public:

  static int RemoveElement(std::vector<int>& nums, int val) {
    int size = nums.size();
    if (size < 1) return 0;
    int index = 0;
    int ret = 0;

    for (int kI = 0; kI < size; ++kI) {
      if (nums[kI] != val) {
        nums[index++] = nums[kI];
        ret++;
      }
    }
    return ret;
  }
};

TEST(AlgTitle2, test1) {

  struct timeval start{}, end{};
  std::vector<int> ret = {3,2,2,3};

  gettimeofday(&start, nullptr);
  int ret_value = Title1::RemoveElement(ret, 3);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value, 2);
  for (int kI = 0; kI < ret_value; ++kI) {
    std::cout << ret[kI];
    if (kI != ret_value-1)
      std::cout << ", ";
  }
  std::cout << std::endl;

  std::vector<int> ret2 = {0,1,2,2,3,0,4,2};

  gettimeofday(&start, nullptr);
  int ret_value2 = Title1::RemoveElement(ret2, 2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(ret_value2, 5);
  for (int kI = 0; kI < ret_value2; ++kI) {
    std::cout << ret2[kI];
    if (kI != ret_value2-1)
      std::cout << ", ";
  }


}
