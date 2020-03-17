project(String)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC title1.cc main.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(StrChallegeTest ${SRC})

target_link_libraries(StrChallegeTest ${TEST_LIB})
INSTALL(TARGETS StrChallegeTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})