//
// Created by PC-Saw on 2019/09/23.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE6_H
#define TOP_INTERVIEW_QUESTIONS_TITLE6_H

#include <iostream>
#include <unordered_map>
#include "Util.h"


// 题号 6 : Intersection of Two Arrays II
//
// Given two arrays, write a function to compute their intersection.
//

/*
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]


Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

 * */

class Title6 {

 public:

  std::vector<int> IntersectBetter(std::vector<int> &nums1, std::vector<int> &nums2) {

    unsigned long long int size1 = nums1.size();
    unsigned long long int size2 = nums2.size();

    // 定义新数组
    std::vector<int> ret;

    if (size1 <= 0 || size2 <= 0) {
      return ret;
    }

    // 先将两数组排序
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    // 将重复元素放入返回的容器中
    for (int i = 0; i < size1;) {
      for (int j = 0; j < size2;) {
        if (nums1[i] < nums2[j]) {
          i++;
        } else if (nums1[i] == nums2[j]) {
          ret.push_back(nums1[i++]);
          j++;
        } else {
          j++;
        }

        // 如果有下标超出返回容器
        if (i == size1 || j == size2)
          return ret;
      }
    }
    return ret;
  }

  std::vector<int> Intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::unordered_map<int, int> hashMap;
    std::vector<int> result;
    for (int num1 : nums1) {
      hashMap[num1]++;
    }
    for (int num2 : nums2) {
      if (hashMap[num2] > 0) {
        result.push_back(num2);
        hashMap[num2]--;
      }
    }
    return result;
  }
};

TEST(Title, test6) {
  Title6 title_6;
  std::vector<int> vector6_1 = {1, 2, 3, 1, 3, 4, 2};
  std::vector<int> vector6_2 = {2, 6, 1, 4};
  std::vector<int> ret;
  struct timeval start{}, end{};

  gettimeofday(&start, nullptr);
  for (int kI = 0; kI < 100; ++kI) {
    ret = title_6.IntersectBetter(vector6_1, vector6_2);
  }
  gettimeofday(&end, nullptr);
  std::cout << "IntersectBetter cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(1, ret[0]);
  EXPECT_EQ(2, ret[1]);
  EXPECT_EQ(4, ret[2]);

  // SingleNumberBetter
  ret = {0};
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 100; ++kJ) {
    ret = title_6.Intersect(vector6_1, vector6_2);
  }
  gettimeofday(&end, nullptr);
  std::cout << "Intersect       cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(1, ret[0]);
  EXPECT_EQ(2, ret[1]);
  EXPECT_EQ(4, ret[2]);

//  for (int i = 0; i < ret.size(); ++i) {
//    if (i != 0)
//      std::cout << ",";
//    std::cout << ret[i];
//  }

}

#endif // TOP_INTERVIEW_QUESTIONS_TITLE6_H
