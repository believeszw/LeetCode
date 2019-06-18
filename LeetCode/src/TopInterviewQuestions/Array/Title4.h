//
// Created by PC-Saw on 2019/06/16.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE4_H
#define TOP_INTERVIEW_QUESTIONS_TITLE4_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// 题号 4 : Contains Duplicate
//
// Given an array of integers, find if the array contains any duplicates.
//
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

/*
Example 1:

Input: [1,2,3,1]
Output: true

Example 2:

Input: [1,2,3,4]
Output: false

Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

 * */

class Title4 {

public:
    bool containsDuplicate(std::vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return false;

        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < size; ++ i) if (nums[i] == nums[i - 1]) return true;

        return false;
    }

    bool containsDuplicate2(std::vector<int>& nums) {
        return nums.size()>std::unordered_set<int>(nums.begin(),nums.end()).size();
    }
};


#endif // TOP_INTERVIEW_QUESTIONS_TITLE4_H
