//
// Created by believe on 2021/1/26.
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

// 题号 6 : 对角线遍历
//
// 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
//

/*
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

[
 [ 1, 2, 3, 4 ],
 [ 5, 6, 7, 8 ],
 [ 9, 10,11,12]
]

说明:
给定矩阵中的元素总数不会超过 100000 。

 * */

class Title6 {
 public:
  static std::vector<int> FindDiagonalOrder(std::vector<std::vector<int>> &matrix) {
    std::vector<int> nums;
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0;    // i 是 x + y 的和
    while (i < m + n) {
      // 第 1 3 5 ... 趟
      int x1 = (i < m) ? i : m - 1;    // 确定 x y 的初始值
      int y1 = i - x1;
      while (x1 >= 0 && y1 < n) {
        nums.push_back(matrix[x1][y1]);
        x1--;
        y1++;
      }
      i++;

      if (i >= m + n) break;
      // 第 2 4 6 ... 趟
      int y2 = (i < n) ? i : n - 1;    // 确定 x y 的初始值
      int x2 = i - y2;
      while (y2 >= 0 && x2 < m) {
        nums.push_back(matrix[x2][y2]);
        x2++;
        y2--;
      }
      i++;
    }
    return nums;
  }
  static std::vector<int> FindDiagonalOrder2(std::vector<std::vector<int>> &matrix) {
    std::vector<int> nums;
    int m = matrix.size();
    if (m == 0) return nums;
    int n = matrix[0].size();
    if (n == 0) return nums;

    bool bXFlag = true;
    for (int i = 0; i < m + n; i++) {
      int pm = bXFlag ? m : n;
      int pn = bXFlag ? n : m;

      int x = (i < pm) ? i : pm - 1;
      int y = i - x;

      while (x >= 0 && y < pn) {
        nums.push_back(bXFlag ? matrix[x][y] : matrix[y][x]);
        x--;
        y++;
      }

      bXFlag = !bXFlag;
    }
    return nums;
  }
};

TEST(AlgStrTitle6, test1) {
  struct timeval start{}, end{};
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };
  std::vector<int> expect_ret = {1, 2, 4, 7, 5, 3, 6, 8, 9};
  gettimeofday(&start, nullptr);
  std::vector<int> ret = Title6::FindDiagonalOrder2(matrix);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(ret, expect_ret);

}
