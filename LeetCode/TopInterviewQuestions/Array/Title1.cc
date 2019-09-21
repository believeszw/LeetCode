//
// Created by PC-Saw on 2018/12/25.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE1_H
#define TOP_INTERVIEW_QUESTIONS_TITLE1_H

#include <iostream>
#include <vector>
#include "Util.h"
#include "gtest/gtest.h"
#include <sys/time.h>

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

static const auto io_sync_off = []()
{
  // turn off sync
  std::ios::sync_with_stdio(false);
  // untie in/out streams
  std::cin.tie(nullptr);
  return nullptr;
}();

class Title1 {

public:
    int removeDuplicates(std::vector<int>& nums) {

        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] != nums[i]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};

TEST(Title, test) {

  struct timeval start{}, end{};
  gettimeofday( &start, nullptr );

  std::vector<int> ret = {0,0,1,1,1,2,2,3,3,4};

  Title1 t1;
  int retTitle1 = t1.removeDuplicates(ret);

  gettimeofday( &end, nullptr );
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;


  std::cout << "[";
  for (int i = 0; i < retTitle1; ++i) {
      std::cout << ret.at(i);
      if (i != retTitle1 - 1) std::cout << ", ";
  }
  std::cout << "]";
}

#endif // TOP_INTERVIEW_QUESTIONS_TITLE1_H