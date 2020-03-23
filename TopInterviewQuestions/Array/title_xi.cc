//
// Created by PC-Saw on 2019/09/24.
// Copyright (c) 2020 believe. All rights reserved.
//


#include <iostream>
#include "util.h" // NOLINT


// 题号 9 : Rotate Image
//
// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Note:
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
//

/*
Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

 * */

class TitleXI {

 public:
  static void Rotate(std::vector<std::vector<int>> &matrix) { // NOLINT
    int size = matrix.size();

    for (int kI = 0; kI < size / 2; ++kI) {
      for (int kJ = kI; kJ < size - 1 - kI; ++kJ) {
        int tmp = matrix[size - 1 - kJ][kI];
        tmp = std::exchange(matrix[kI][kJ], tmp);
        tmp = std::exchange(matrix[kJ][size - 1 - kI], tmp);
        tmp = std::exchange(matrix[size - 1 - kI][size - 1 - kJ], tmp);
        tmp = std::exchange(matrix[size - 1 - kJ][kI], tmp);
      }
    }
  }

};

TEST(TitleXI, testXI) {

  struct timeval start{}, end{};
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };

  gettimeofday(&start, nullptr);
  TitleXI::Rotate(matrix);
  gettimeofday(&end, nullptr);
  std::cout << "3 * 3 Rotate cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(7, matrix[0][0]);
  EXPECT_EQ(4, matrix[0][1]);
  EXPECT_EQ(1, matrix[0][2]);
  EXPECT_EQ(8, matrix[1][0]);
  EXPECT_EQ(5, matrix[1][1]);
  EXPECT_EQ(2, matrix[1][2]);
  EXPECT_EQ(9, matrix[2][0]);
  EXPECT_EQ(6, matrix[2][1]);
  EXPECT_EQ(3, matrix[2][2]);

  std::vector<std::vector<int>> matrix2 = {
      {5, 1, 9, 11},
      {2, 4, 8, 10},
      {13, 3, 6, 7},
      {15, 14, 12, 16}
  };

  gettimeofday(&start, nullptr);
  TitleXI::Rotate(matrix2);
  gettimeofday(&end, nullptr);
  std::cout << "4 * 4 Rotate cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_EQ(15, matrix2[0][0]);
  EXPECT_EQ(13, matrix2[0][1]);
  EXPECT_EQ(2, matrix2[0][2]);
  EXPECT_EQ(5, matrix2[0][3]);
  EXPECT_EQ(14, matrix2[1][0]);
  EXPECT_EQ(3, matrix2[1][1]);
  EXPECT_EQ(4, matrix2[1][2]);
  EXPECT_EQ(1, matrix2[1][3]);
  EXPECT_EQ(12, matrix2[2][0]);
  EXPECT_EQ(6, matrix2[2][1]);
  EXPECT_EQ(8, matrix2[2][2]);
  EXPECT_EQ(9, matrix2[2][3]);
  EXPECT_EQ(16, matrix2[3][0]);
  EXPECT_EQ(7, matrix2[3][1]);
  EXPECT_EQ(10, matrix2[3][2]);
  EXPECT_EQ(11, matrix2[3][3]);
}
