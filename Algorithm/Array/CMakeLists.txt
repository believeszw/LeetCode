project(Array)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC title1.cc title2.cc title3.cc main.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(AlgArrayTest ${SRC})

target_link_libraries(AlgArrayTest ${TEST_LIB})
INSTALL(TARGETS AlgArrayTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})