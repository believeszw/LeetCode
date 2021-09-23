//
// Created by PC-Saw on 2021/01/06.
// Copyright (c) 2021 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

// static const auto io_sync_off = []() {
//  // turn off sync
//  std::ios::sync_with_stdio(false);
//  // untie in/out streams
//  std::cin.tie(nullptr);
//  return nullptr;
//}();

// 题号 3 : 删除排序数组中的重复项
//
// 给定一个排序数组，你需要在 原地
// 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1)
// 额外空间的条件下完成。
//
//

/*
示例 1:

给定数组 nums = [1,1,2],

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

你不需要考虑数组中超出新长度后面的元素。

示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
  print(nums[i]);
}

 * */

class Title3 {

public:
  static int RemoveDuplicates(std::vector<int> &nums) {
    int size = nums.size();
    if (size < 1)
      return 0;
    int index = 0;

    for (int kI = 0; kI < size; ++kI) {
      if (nums[index] != nums[kI]) {
        nums[++index] = nums[kI];
      }
    }
    return index + 1;
  }
};

TEST(AlgArrayTitle3, test1) {

  std::vector<int> ret = {1, 1, 2};
  int ret_value{0};
  {
    ScopedTimer timer("Title3::RemoveDuplicates");
    ret_value = Title3::RemoveDuplicates(ret);
  }

  EXPECT_EQ(ret_value, 2);
  for (int kI = 0; kI < ret_value; ++kI) {
    std::cout << ret[kI];
    if (kI != ret_value - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;

  std::vector<int> ret2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int ret_value2{0};
  {
    ScopedTimer timer("Title3::RemoveDuplicates");
    ret_value2 = Title3::RemoveDuplicates(ret2);
  }

  EXPECT_EQ(ret_value2, 5);
  for (int kI = 0; kI < ret_value2; ++kI) {
    std::cout << ret2[kI];
    if (kI != ret_value2 - 1)
      std::cout << ", ";
  }
}
