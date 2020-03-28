project(Array)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC main.cc title1.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(ArrayChallengeTest ${SRC})

target_link_libraries(ArrayChallengeTest ${TEST_LIB})
INSTALL(TARGETS ArrayChallengeTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})