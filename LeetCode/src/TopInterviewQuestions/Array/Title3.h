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
    // 还有一个思路，三次翻转，第一次全部翻转，还有2次以k为分界线进行翻转
    void rotate(std::vector<int>& nums, int k) {

        int  n = nums.size();

        if (n == 0) return;
        if (k == 0) return;
        if (k >= n) k = k % n;

        int cur = 0;
        int start = 0;

        for (int i = 0; i < n - 1; ++i) {

            // 起始位置移动位置即本身时，起始位置向前进 1
            if ((cur + k) % n == start) {
                start++;
                cur = start;
                continue;
            }

            // 起始位置与移动后位置元素互换
            swap(nums[start], nums[(cur + k) % n]);

            // 当前位置记录被换元素需要移动到的位置
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
