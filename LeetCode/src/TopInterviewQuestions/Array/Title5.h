//
// Created by PC-Saw on 2019/06/16.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE5_H
#define TOP_INTERVIEW_QUESTIONS_TITLE5_H

#include <iostream>
#include <vector>
#include <algorithm>

// 题号 5 : Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

/*
Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4

 * */

class Title5 {

public:
    int singleNumber(std::vector<int>& nums) {
        unsigned long long int size = nums.size();
        if (size == 1) return nums[0];

        std::sort(nums.begin(), nums.end());
            for (int i = 1; i < size - 1; i = i+2) if (nums[i - 1] != nums[i]) return nums[i - 1];
            return nums[size - 1];
    }

};


#endif // TOP_INTERVIEW_QUESTIONS_TITLE5_H
