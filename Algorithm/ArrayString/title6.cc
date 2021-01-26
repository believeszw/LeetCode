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

解释:

 * */

class Title5 {
 public:
  static void SetColRowZeros(std::vector<std::vector<int>> &matrix, int row, int col) {
    int row_size = matrix[col].size();
    int col_size = matrix.size();
    for (int kI = 0; kI < row_size; ++kI) { // row
      matrix[col][kI] = 0;
    }
    for (int kI = 0; kI < col_size; ++kI) { // col
      matrix[kI][row] = 0;
    }
  }

  static void SetZeroes(std::vector<std::vector<int>> &matrix) {
    std::vector<std::vector<int>> zero_index;
    int row_size = matrix[0].size();
    int col_size = matrix.size();
    for (int kI = 0; kI < col_size; ++kI) {
      for (int kJ = 0; kJ < row_size; ++kJ) {
        if (matrix[kI][kJ] == 0) {
          zero_index.push_back({kJ, kI});
        }
      }
    }
    int size = zero_index.size();
    for (int kI = 0; kI < size; ++kI) {
      SetColRowZeros(matrix, zero_index[kI][0], zero_index[kI][1]);
    }
  }
};

TEST(AlgStrTitle5, test1) {
  struct timeval start{}, end{};
  std::vector<std::vector<int>> ret = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}
  };
  std::vector<std::vector<int>> expect_ret = {
      {1, 0, 1},
      {0, 0, 0},
      {1, 0, 1}
  };
  gettimeofday(&start, nullptr);
  Title5::SetZeroes(ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(ret, expect_ret);

  std::vector<std::vector<int>> ret2 = {
      {0, 1, 2, 0},
      {3, 4, 5, 2},
      {1, 3, 1, 5}
  };
  std::vector<std::vector<int>> expect_ret2 = {
      {0, 0, 0, 0},
      {0, 4, 5, 0},
      {0, 3, 1, 0}
  };
  gettimeofday(&start, nullptr);
  Title5::SetZeroes(ret2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(ret2, expect_ret2);
}
