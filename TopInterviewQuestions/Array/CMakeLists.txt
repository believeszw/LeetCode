project(Array)

set(CMAKE_CXX_STANDARD 14)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC title1.cc title2.cc title3.cc title4.cc title5.cc title6.cc title7.cc title8.cc title9.cc title_x.cc title_xi.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(ArrayTest ${SRC})

target_link_libraries(ArrayTest ${TEST_LIB})
INSTALL(TARGETS ArrayTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})