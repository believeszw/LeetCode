#include <iostream>
#include "Array/Title1.h"
#include <time.h>

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
#if 1
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

// 题号 4 测试用例
#if 0
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    clock_gettime(CLOCK_MONOTONIC, &endTime);
    cout << "best function time cost :" << endTime.tv_nsec - startTime.tv_nsec << " ns" << endl;
#endif
//    clock_gettime(CLOCK_MONOTONIC, &startTime);
//
//    clock_gettime(CLOCK_MONOTONIC, &endTime);
//    cout << "best function time cost :" << endTime.tv_nsec - startTime.tv_nsec << " ns" << endl;
    return 0;
}