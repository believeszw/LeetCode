//
// Created by believe on 2020/3/28.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "util.h" // NOLINT
#include <iostream>

// 题号 2 : 岛屿的最大面积
//
// 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
//
// 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1
// 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
// 0（代表水）包围着。
//
// 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

/*
示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

对于上面这个给定矩阵应返回 6。注意答案不应该是 11
，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:

[[0,0,0,0,0,0,0,0]]

 对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

 * */

class Title2 {
public:
};

// TEST(Title1, test) {
//
//   struct timeval start{}, end{};
//   std::vector<int> vector1_1{-1, 0, 1, 2, -1, -4};
//   std::vector<std::vector<int>> ret;
//   std::vector<int> vector1_2{-1, -1, 2};
//   std::vector<int> vector1_3{-1, 0, 1};
//
//   gettimeofday(&start, nullptr);
////  ret = Title2::ThreeSum(vector1_1);
//  gettimeofday(&end, nullptr);
//  std::cout << "ThreeSum cost time : " << diff(start, end) << " us." <<
//  std::endl;
//
//  EXPECT_EQ(vector1_2, ret[0]);
//  EXPECT_EQ(vector1_3, ret[1]);
//}
