project(AllQuestions)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${COMPILE_PLAT})

SET(SRC title1.cc title4.cc main.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(AllQuestions ${SRC})

target_link_libraries(AllQuestions ${TEST_LIB})
INSTALL(TARGETS AllQuestions DESTINATION ${EXECUTABLE_OUTPUT_PATH})