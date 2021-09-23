//
// Created by believe on 2019/9/21.
// Copyright (c) 2020 believe. All rights reserved.
//

#pragma once

#ifndef INCLUDE_UTIL_H_
#define INCLUDE_UTIL_H_

#include "gtest/gtest.h"
#include <sys/time.h> // NOLINT

inline int64_t diff(timeval start, timeval end) {
  return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

class ScopedTimer {
public:
  ScopedTimer(const char *name)
      : m_name(name), m_beg(std::chrono::high_resolution_clock::now()) {}
  ~ScopedTimer() {
    auto end = std::chrono::high_resolution_clock::now();
    auto dur =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_beg);
    std::cout << m_name << " : " << dur.count() << " ns\n";
  }

private:
  const char *m_name;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_beg;
};
#endif // INCLUDE_UTIL_H_
