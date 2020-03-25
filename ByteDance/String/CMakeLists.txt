project(String)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC title1.cc title2.cc main.cc title3.cc title4.cc title5.cc title6.cc title7.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(StrChallengeTest ${SRC})

target_link_libraries(StrChallengeTest ${TEST_LIB})
INSTALL(TARGETS StrChallengeTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})