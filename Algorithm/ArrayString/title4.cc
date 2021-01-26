//
// Created by believe on 2021/1/21.
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

// 题号 4 : 旋转矩阵
//
// 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
//
// 不占用额外内存空间能否做到？
//

/*
示例 1:
给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

 * */

class Title4 {
 public:
  static void Rotate(std::vector<std::vector<int>> &matrix) {
    int size = matrix.size();
    if (size == 0) { return; }
    int row = (size >> 1) - 1; // 左上角区域的最大行下标，
    int col = (size - 1) >> 1; // 左上角区域的最大列下标，行列下标从 0 开始。
    for (int i = row; i >= 0; --i) {
      for (int j = col; j >= 0; --j) {
        std::swap(matrix[i][j], matrix[j][size - i - 1]);
        std::swap(matrix[i][j], matrix[size - i - 1][size - j - 1]);
        std::swap(matrix[i][j], matrix[size - j - 1][i]);
      }
    }
  }
};

TEST(AlgStrTitle4, test1) {
  struct timeval start{}, end{};
  std::vector<std::vector<int>> ret = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };
  std::vector<std::vector<int>> expect_ret = {
      {7, 4, 1},
      {8, 5, 2},
      {9, 6, 3}
  };
  gettimeofday(&start, nullptr);
  Title4::Rotate(ret);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(ret, expect_ret);

  std::vector<std::vector<int>> ret2 = {
      {5, 1, 9, 11},
      {2, 4, 8, 10},
      {13, 3, 6, 7},
      {15, 14, 12, 16}
  };
  std::vector<std::vector<int>> expect_ret2 = {
      {15, 13, 2, 5},
      {14, 3, 4, 1},
      {12, 6, 8, 9},
      {16, 7, 10, 11}
  };
  gettimeofday(&start, nullptr);
  Title4::Rotate(ret2);
  gettimeofday(&end, nullptr);
  std::cout << "function cost time : " << diff(start, end) << " us." << std::endl;
  EXPECT_EQ(ret2, expect_ret2);
}
