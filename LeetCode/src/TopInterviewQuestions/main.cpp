#include <iostream>
#include "Array/Title1.h"
#include "Array/Title2.h"
#include <time.h>

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

    cout << endl << "my function time cost :" << diff(startTime,endTime).tv_sec << ":" << diff(startTime,endTime).tv_nsec << "ns" << endl;

#endif

// 题号 2 测试用例
#if 1

    Title2 t2;
    vector<int> vector2 = {7,6,4,3,1};

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    int retTitle2 = t2.maxProfit(vector2);

    clock_gettime(CLOCK_MONOTONIC, &endTime);

    cout << retTitle2 << endl << "my function time cost :" << diff(startTime,endTime).tv_sec << ":" << diff(startTime,endTime).tv_nsec << "ns" << endl;
#endif

    return 0;
}