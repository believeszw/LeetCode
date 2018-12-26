#include <iostream>
#include "src/Title4.h"
#include <time.h>

using namespace std;

int main() {

    struct timespec startTime,endTime;
// 题号 1 测试用例
#if 0
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(17);

    Title1 t1;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    vector<int> ret = t1.twoSum(nums,9);
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret.at(i) << endl;
    }

    cout << "my function time cost :" << endTime.tv_nsec - startTime.tv_nsec << "ns" << endl;
#endif

// 题号 4 测试用例
#if 0
    Title4 t4;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    vector<int> vector1;
    vector<int> vector2;
    vector1.push_back(1);
    vector1.push_back(2);
    vector2.push_back(4);
    vector2.push_back(6);
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    cout << "pushIn vector time cost :" << endTime.tv_nsec - startTime.tv_nsec << " ns" << endl;

    // my method
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    for (int i = 0; i < 10; ++i)
        t4.findMedianSortedArrays(vector1,vector2);
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    cout << "my   function time cost :" << endTime.tv_nsec - startTime.tv_nsec << " ns" << endl;

    // 最佳方法
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    for (int i = 0; i < 10; ++i)
        t4.findMedianSortedArrays2(vector1,vector2);
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    cout << "best function time cost :" << endTime.tv_nsec - startTime.tv_nsec << " ns" << endl;
#endif
//    clock_gettime(CLOCK_MONOTONIC, &startTime);
//
//    clock_gettime(CLOCK_MONOTONIC, &endTime);
//    cout << "best function time cost :" << endTime.tv_nsec - startTime.tv_nsec << " ns" << endl;
    return 0;
}