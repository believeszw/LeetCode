//
// Created by believe on 2019/9/21.
//

#pragma once

#ifndef LEETCODE_SRC_INCLUDE_UTIL_H_
#define LEETCODE_SRC_INCLUDE_UTIL_H_

#include "gtest/gtest.h"
#include <sys/time.h>

inline long diff(timeval start, timeval end)
{
  return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

#endif //LEETCODE_SRC_INCLUDE_UTIL_H_
