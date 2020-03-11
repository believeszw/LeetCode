//
// Created by PC-Saw on 2019/09/23.
//


#include <iostream>
#include "util.h"


// 题号 3 : Rotate Array
//
// Given an array, rotate the array to the right by k steps, where k is non-negative.

/*
Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

 * */

class Title3 {
 public:

  // 较优解
  void RotateBetter(std::vector<int> &nums, int k) {

    int n = nums.size();

    if (n == 0 || k == 0) return;
    if (k >= n) k = k % n;

    int cur = 0;
    int start = 0;

    for (int i = 0; i < n - 1; ++i) {

      // 起始位置移动位置即本身时，起始位置向前进 1
      if ((cur + k) % n == start) {
        start++;
        cur = start;
        continue;
      }

      // 起始位置与移动后位置元素互换
      nums[(cur + k) % n] = std::exchange(nums[start], nums[(cur + k) % n]);

      // 当前位置记录被换元素需要移动到的位置
      cur = (cur + k) % n;
    }
  }

  // 还有一个思路，三次翻转，前2次以k为分界线进行翻转，最后全部翻转
  void Rotate(std::vector<int> &nums, int k) {
    int i, j;
    int len = nums.size();
    k = k % len;
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
  }

};

TEST(Title, test3) {

  Title3 title_3;
  std::vector<int> vector3 = {1, 2, 3, 4, 5, 6, 7, 8};
  struct timeval start{}, end{};

  title_3.Rotate(vector3, 3);
  EXPECT_EQ(6, vector3[0]);
  EXPECT_EQ(7, vector3[1]);
  EXPECT_EQ(8, vector3[2]);
  EXPECT_EQ(1, vector3[3]);
  EXPECT_EQ(2, vector3[4]);
  EXPECT_EQ(3, vector3[5]);

  vector3 = {1, 2, 3, 4, 5, 6, 7, 8};
  title_3.RotateBetter(vector3, 3);
  EXPECT_EQ(6, vector3[0]);
  EXPECT_EQ(7, vector3[1]);
  EXPECT_EQ(8, vector3[2]);
  EXPECT_EQ(1, vector3[3]);
  EXPECT_EQ(2, vector3[4]);
  EXPECT_EQ(3, vector3[5]);

  // 性能测试
  vector3 = {1, 2, 3, 4, 5, 6, 7, 8};
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 100; ++kJ) {
    title_3.Rotate(vector3, 3);
  }
  gettimeofday(&end, nullptr);
  std::cout << "Rotate       cost time : " << diff(start, end) << " us." << std::endl;

  vector3 = {1, 2, 3, 4, 5, 6, 7, 8};
  gettimeofday(&start, nullptr);
  for (int kJ = 0; kJ < 100; ++kJ) {
    title_3.RotateBetter(vector3, 3);
  }
  gettimeofday(&end, nullptr);
  std::cout << "RotateBetter cost time : " << diff(start, end) << " us." << std::endl;

  // 为了测试性能这里就不打印了，已经乱序了
//  std::cout << "[";
//  for (int kI = 0; kI < vector3.size(); ++kI) {
//    std::cout << vector3[kI];
//    if (kI != vector3.size() - 1) std::cout << ", ";
//  }
//  std::cout << "]";

}
