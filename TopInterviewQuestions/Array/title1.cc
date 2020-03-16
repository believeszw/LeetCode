//
// Created by PC-Saw on 2019/09/23.
//


#include <iostream>
#include "util.h"


//static const auto io_sync_off = []() {
//  // turn off sync
//  std::ios::sync_with_stdio(false);
//  // untie in/out streams
//  std::cin.tie(nullptr);
//  return nullptr;
//}();

// 题号 1 : Remove Duplicates from Sorted Array
//
// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

/*
Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.

Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],


Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

 * */

class Title1 {

 public:

  // 两个游标向后移动，一个遍历，一个将不重复元素向前移动
  static int RemoveDuplicates(std::vector<int> &nums) {

    int n = nums.size();
    if (n <= 1) {
      return n;
    }

    int count = 1;
    for (int i = 1; i < n; ++i) {
      if (nums[i - 1] != nums[i]) {
        nums[count++] = nums[i];
      }
    }
    return count;
  }
};

TEST(Title1_test1_Test, test1) {

  struct timeval start{}, end{};
  std::vector<int> ret = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  gettimeofday(&start, nullptr);
  int retTitle1 = Title1::RemoveDuplicates(ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;

  std::cout << "[";
  for (int i = 0; i < retTitle1; ++i) {
    EXPECT_EQ(i, ret.at(i));
    std::cout << ret.at(i);
    if (i != retTitle1 - 1) std::cout << ", ";
  }
  std::cout << "]";

}
