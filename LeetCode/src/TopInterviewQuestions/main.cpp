#include <iostream>
#include <time.h>
#include "Array/Title1.h"
#include "Array/Title2.h"
#include "Array/Title3.h"
#include "Array/Title4.h"
#include "Array/Title5.h"
#include "Array/Title6.h"

// 关闭 IO 同步
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

using namespace std;

timespec diff(timespec start, timespec end)
{
    timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp;
}

int main() {

    struct timespec startTime,endTime;

// 题号 1 测试用例
#if 0
    vector<int> ret = {0,0,1,1,1,2,2,3,3,4};

    Title1 t1;
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    int retTitle1 = t1.removeDuplicates(ret);

    clock_gettime(CLOCK_MONOTONIC, &endTime);

    for (int i = 0; i < retTitle1; ++i) {
        cout << ret.at(i);
        if (i != retTitle1 - 1) cout << " ,";
    }

    cout << endl << "my function time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif

// 题号 2 测试用例
#if 0
    Title2 t2;
    vector<int> vector2 = {7,1,5,3,6,4};

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    int retTitle2 = t2.maxProfit(vector2);

    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << retTitle2 << endl << "my function time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif

    // 题号 3 测试用例
#if 0
    Title3 t3;
    vector<int> vector3 = {1,2,3,4,5,6,7};

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    t3.rotate(vector3,3);
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "my function time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif

    // 题号 4 测试用例
#if 0

    Title4 t4;
    vector<int> vector4 = {1,1,3,4,5,6,7};

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    t4.containsDuplicate(vector4);
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    t4.containsDuplicate2(vector4);
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function2 time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif

    // 题号 5 测试用例
#if 0

    Title5 t5;
    vector<int> vector5 = {1,2,3,1,3,4,2};

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    t5.singleNumber(vector5);
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    t5.singleNumber2(vector5);
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function2 time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif

    // 题号 6 测试用例
#if 0

    Title6 t6;
    vector<int> vector6_1 = {1,2,3,1,3,4,2};
    vector<int> vector6_2 = {2,6,1,4};

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    vector<int> ret = t6.intersect(vector6_1, vector6_2);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    ret = t6.intersect2(vector6_1, vector6_2);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function2 time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif

    // 题号 7 测试用例
#if 1

    Title6 t6;
    vector<int> vector6_1 = {1,1,5,3};
    vector<int> vector6_2 = {1,2,3};

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    vector<int> ret = t6.intersect(vector6_1, vector6_2);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    ret = t6.intersect2(vector6_1, vector6_2);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << endl << "function2 time cost :" << diff(startTime,endTime).tv_sec << "s " << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif


    return 0;
}