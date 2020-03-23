//
// Created by believe on 2019/9/21.
// Copyright (c) 2020 believe. All rights reserved.
//

#pragma once

#ifndef INCLUDE_UTIL_H_
#define INCLUDE_UTIL_H_

#include <sys/time.h> // NOLINT
#include "gtest/gtest.h"

inline int64_t diff(timeval start, timeval end) {
  return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

#endif  // INCLUDE_UTIL_H_
