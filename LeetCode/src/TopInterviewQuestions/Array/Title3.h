//
// Created by believe on 2019/6/2.
//

#ifndef TOPINTERVIEWQUESTIONS_TITLE3_H
#define TOPINTERVIEWQUESTIONS_TITLE3_H

#include <iostream>
#include <vector>

// 题号 3 : Rotate Array
//
// Given an array, rotate the array to the right by k steps, where k is non-negative.

/*
Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

 * */

class Title3 {
public:
    void rotate(std::vector<int>& nums, int k) {
        int  n = nums.size();
        if (n == 0) return;
        if (k == 0) return;
        int cur = 0;
        int start = 0;
        for (int i = 0; i < n - 1; ++i) {
            if ((cur + k) % n == start) {
                start++;
                cur = start;
                continue;
            }
            swap(nums[start], nums[(cur + k) % n]);
            cur = (cur + k) % n;
        }
    }

    void swap(int &a, int &b){
        a = a + b;
        b = a - b;
        a = a - b;
    }
};


#endif //TOPINTERVIEWQUESTIONS_TITLE3_H
