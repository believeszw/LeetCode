//
// Created by PC-Saw on 2019/06/18.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE8_H
#define TOP_INTERVIEW_QUESTIONS_TITLE8_H

#include <iostream>
#include <unordered_map>
#include "Util.h"

// 题号 X : Valid Sudoku
//
// https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/769/
//

class TitleX {

 public:
  bool IsValidSudoku(std::vector<std::vector<char>> &board) {

  }

};

TEST(Title, testX) {
  TitleX title_x;
  std::vector<std::vector<char>> vectorX = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  bool ret = false;
  struct timeval start{}, end{};

  gettimeofday(&start, nullptr);

  gettimeofday(&end, nullptr);
  std::cout << 'IsValidSudoku cost time : ' << diff(start, end) << ' us.' << std::endl;

  EXPECT_TRUE(ret);

  std::vector<std::vector<char>> vectorX2 = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  ret = true;

  gettimeofday(&start, nullptr);

  gettimeofday(&end, nullptr);
  std::cout << 'IsValidSudoku cost time : ' << diff(start, end) << ' us.' << std::endl;

  EXPECT_FALSE(ret);

}
#endif // TOP_INTERVIEW_QUESTIONS_TITLE8_H
