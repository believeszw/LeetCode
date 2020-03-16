//
// Created by PC-Saw on 2019/09/23.
//


#include <iostream>
#include "util.h"

// 题号 X : Valid Sudoku
//
// https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/769/
//

class TitleX {

 public:
  static bool IsValidSudoku(std::vector<std::vector<char>> &board) {
    std::vector<std::vector<int>> row_vector(9, std::vector<int>(9, 0));
    std::vector<std::vector<int>> col_vector(9, std::vector<int>(9, 0));

    // 判断每一个单元
    int index_x = 0;
    int index_y = 0;

    while (index_x != 9) {

      std::vector<int> vector(9, 0);
      for (int kI = 0; kI < 9; ++kI) {

        // 先排除 ‘.’
        if (board[index_x][index_y] == '.') {
          if (++index_y % 3 == 0) { // 列前进
            index_x++;              // 换行
            if (index_x % 3 != 0)
              index_y -= 3;        // 列重置
          }
          continue;
        }

        int value = board[index_x][index_y] - '1';
        vector[value]++;
        row_vector[index_x][value]++;
        col_vector[index_y][value]++;

        // 判断行
        if (row_vector[index_x][value] > 1)
          return false;
        // 判断列
        if (col_vector[index_y][value] > 1)
          return false;
        // 判断九宫格
        if (vector[value] > 1)
          return false;

        if (++index_y % 3 == 0) { // 列前进
          index_x++;              // 换行
          if (index_x % 3 != 0)
            index_y -= 3;        // 列重置
        }
      }

      if (index_y != 9)
        index_x -= 3; // 行重置
      else
        index_y = 0;  // 列重置
    }

    return true;
  }

  static bool IsValidSudoku2(std::vector<std::vector<char>> &board) {
    int r[9][10] = {{0}};
    int c[9][10] = {{0}};
    int b[3][3][10] = {{{0}}};

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int x = board[i][j] - '0';
          r[i][x] += 1;
          c[j][x] += 1;
          b[i / 3][j / 3][x] += 1;
          if (r[i][x] > 1 || c[j][x] > 1 || b[i / 3][j / 3][x] > 1)
            return false;
        }
      }
    }
    return true;
  }

  static bool IsValidSudoku3(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {

          for (int k = 0; k < 9; k++) {
            if ((board[i][j] == board[i][k] && j != k) ||
                (board[i][j] == board[k][j] && i != k)) {
              return false;
            }
          }
          int x = j / 3;
          int y = i / 3;

          int min_x = x * 3;
          int max_x = ((x + 1) * 3) - 1;
          int min_y = y * 3;
          int max_y = ((y + 1) * 3) - 1;

          for (int m = min_y; m <= max_y; m++) {
            for (int n = min_x; n <= max_x; n++) {
              if (board[i][j] == board[m][n] && (i != m || j != n)) {
                return false;
              }
            }
          }
        }
      }
    }
    return true;
  }

};

TEST(Titlex_testX_Test, testX) {

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
  ret = TitleX::IsValidSudoku(vectorX);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_TRUE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku2(vectorX);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku2 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_TRUE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku3(vectorX);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku3 cost time : " << diff(start, end) << " us." << std::endl;

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
  ret = TitleX::IsValidSudoku(vectorX2);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku2(vectorX2);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku2 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku3(vectorX2);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku3 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  std::vector<std::vector<char>> vectorX3 = {
      {'9', '3', '.', '.', '7', '.', '.', '.', '.'},
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
  ret = TitleX::IsValidSudoku(vectorX3);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku2(vectorX3);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku2 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku3(vectorX3);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku3 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  std::vector<std::vector<char>> vectorX4 = {
      {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
      {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
      {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
      {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
  };
  ret = true;

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku(vectorX4);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku2(vectorX4);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku2 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

  gettimeofday(&start, nullptr);
  ret = TitleX::IsValidSudoku3(vectorX4);
  gettimeofday(&end, nullptr);
  std::cout << "IsValidSudoku3 cost time : " << diff(start, end) << " us." << std::endl;

  EXPECT_FALSE(ret);

}
