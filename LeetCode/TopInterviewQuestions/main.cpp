#include <iostream>
#include <time.h>
#include <sysinfoapi.h>
#include <profileapi.h>
#include "Array/Title1.cc"
#include "Array/Title2.cc"
#include "Array/Title3.cc"
#include "Array/Title4.cc"
#include "Array/Title5.cc"
#include "Array/Title6.h"
#include "Array/Title7.h"
#include "Array/Title8.h"
#include "Array/Title9.h"

//// 关闭 IO 同步
//static const auto io_sync_off = []()
//{
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

using namespace std;


int main() {

    LARGE_INTEGER timeStart,timeEnd,tc;


    // 题号 5 测试用例
#if 0





    QueryPerformanceCounter(&timeEnd);
    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;

    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);



    QueryPerformanceCounter(&timeEnd);
    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;
#endif

    // 题号 6 测试用例
#if 0
    Title6 t6;
    vector<int> vector6_1 = {1,2,3,1,3,4,2};
    vector<int> vector6_2 = {2,6,1,4};

    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);

    vector<int> ret = t6.intersect(vector6_1, vector6_2);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    QueryPerformanceCounter(&timeEnd);
    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;

    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);

    ret = t6.intersect2(vector6_1, vector6_2);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    QueryPerformanceCounter(&timeEnd);
    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;
#endif

    // 题号 7 测试用例
#if 0
    Title7 t7;
    vector<int> vector7_1 = {9,9,9,8};
    vector<int> vector7_2 = {9,9,9,8};

    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);

    vector<int> ret = t7.plusOne(vector7_1);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    QueryPerformanceCounter(&timeEnd);

    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;

    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);

    ret = t7.plusOne2(vector7_2);
    for (int i = 0; i < ret.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << ret[i];
    }

    QueryPerformanceCounter(&timeEnd);

    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;
#endif

    // 题号 8 测试用例
#if 0
    Title8 t8;
    vector<int> vector8 = {9,0,11,9,0,2,0};

    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);

    t8.moveZeroes(vector8);
    for (int i = 0; i < vector8.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << vector8[i];
    }
    QueryPerformanceCounter(&timeEnd);

    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;

    vector8 = {9,1,0,9,0,2,0};
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);

    t8.moveZeroes(vector8);
    for (int i = 0; i < vector8.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << vector8[i];
    }

    QueryPerformanceCounter(&timeEnd);

    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;
#endif

    // 题号 9 测试用例
#if 1
    Title9 t9;
    vector<int> vector8 = {9,0,11,9,0,2,0};

    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&timeStart);

    t9.twoSum(vector8,1);
    for (int i = 0; i < vector8.size(); ++i) {
        if (i != 0)
            cout << ",";
        cout << vector8[i];
    }
    QueryPerformanceCounter(&timeEnd);

    cout << endl << "function time cost :" << (timeEnd.QuadPart - timeStart.QuadPart)*1.0/tc.QuadPart << "s " << endl;


#endif

    return 0;
}
