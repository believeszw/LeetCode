//
// Created by believe on 2020/3/17.
// Copyright (c) 2020 believe. All rights reserved.
//

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  std::cout << "Running main() from gtest_main.cc\n";
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
