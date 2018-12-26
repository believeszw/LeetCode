//
// Created by PC-Saw on 2018/12/25.
//

#ifndef UNTITLED_TITLE1_H
#define UNTITLED_TITLE1_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <unordered_map>


using namespace std;

// 关闭 IO 同步
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Title1 {
    // 题号 1 :两数之和
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例：
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]
 */
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // 哈希表和map在这个数量级下性能差异不明显
        unordered_map<int, int> hm1;

        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if(hm1.find(complement) != hm1.end())
            {
                return vector<int>{hm1.find(complement)->second, i};
            }
            hm1[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};


#endif //UNTITLED_TITLE1_H
