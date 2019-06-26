//
// Created by PC-Saw on 2019/06/18.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE8_H
#define TOP_INTERVIEW_QUESTIONS_TITLE8_H

#include <iostream>
#include <vector>
#include <algorithm>

// 题号 8 : Move Zeroes
//
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//

/*
Example 1:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

 * */

class Title8 {

public:

    void moveZeroes(std::vector<int>& nums) {

        int size = static_cast<int>(nums.size());
        if (size <= 0){
            return;
        }

        int zeroIndex = 0;
        for (int i = 0; i < size; ++i) {
            // 如果是非零的则赋值
            if (nums[i] != 0) {
                nums[zeroIndex] = nums[i];
                if (zeroIndex++ != i){
                    nums[i] = 0;
                }
            }
        }
    }

    void moveZeroes2(std::vector<int>& nums) {

        int size = static_cast<int>(nums.size());
        if (size <= 0){
            return;
        }

        int zeroIndex = 0;
        for (int i = 0; i < size; ++i) {
            // 如果是非零的则赋值
            if (nums[i] != 0) {
                nums[zeroIndex++] = nums[i];
            }
        }
        for (int j = zeroIndex; j < size; ++j){
            nums[j] = 0;
        }
    }
};


#endif // TOP_INTERVIEW_QUESTIONS_TITLE8_H
