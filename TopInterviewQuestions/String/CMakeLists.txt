project(String)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC title1.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(StringTest ${SRC})

target_link_libraries(StringTest ${TEST_LIB})
INSTALL(TARGETS StringTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})