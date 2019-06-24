//
// Created by PC-Saw on 2019/06/18.
//

#ifndef TOP_INTERVIEW_QUESTIONS_TITLE7_H
#define TOP_INTERVIEW_QUESTIONS_TITLE7_H

#include <iostream>
#include <vector>
#include <algorithm>

// 题号 7 : Plus One
//
//Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
//You may assume the integer does not contain any leading zero, except the number 0 itself.
//

/*
Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

 * */

class Title7 {

public:

    std::vector<int> plusOne(std::vector<int>& digits) {
        int size = static_cast<int>(digits.size());
        for (int i = size -  1; i >= 0; --i) {
            if (digits[i] + 1 < 10){
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }

        }
        digits.push_back(digits[size - 1]);
        for (int j = size; j > 0; --j) {
            digits[j] = digits[j - 1];
        }
        digits[0] = 1;
        return digits;
    }

    std::vector<int> plusOne2(std::vector<int>& digits) {
        int carry = 1;
        for(int i = static_cast<int>(digits.size() - 1); i >= 0; i--)
        {
            int s = digits[i] + carry;
            digits[i] = s % 10;
            carry = s/10;
        }
        if(carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};


#endif // TOP_INTERVIEW_QUESTIONS_TITLE7_H
