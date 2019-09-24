//
// Created by PC-Saw on 2019/09/24.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLEXI_H
#define TOP_INTERVIEW_QUESTIONS_TITLEXI_H

#include <iostream>
#include "Util.h"



// 题号 9 : Rotate Image
//
// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Note:
//
//You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
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
  void Rotate(std::vector<std::vector<int>> &matrix) {

  }
};

TEST(Title, testXI) {
  TitleXI title_xi;
  struct timeval start{}, end{};
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };

  gettimeofday(&start, nullptr);
  title_xi.Rotate(matrix);
  gettimeofday(&end, nullptr);
  std::cout << "TwoSum cost time : " << diff(start, end) << " us." << std::endl;

//  EXPECT_EQ(0, ret[0]);
//  EXPECT_EQ(1, ret[1]);

  std::vector<std::vector<int>> matrix2 = {
      { 5, 1, 9,11},
      { 2, 4, 8,10},
      {13, 3, 6, 7},
      {15,14,12,16}
  };

  gettimeofday(&start, nullptr);
  title_xi.Rotate(matrix2);
  gettimeofday(&end, nullptr);
  std::cout << "TwoSum cost time : " << diff(start, end) << " us." << std::endl;

}

#endif // TOP_INTERVIEW_QUESTIONS_TITLEXI_H

