project(Array)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

aux_source_directory(. DIR_SRCS)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(AlgArrayTest ${DIR_SRCS})

target_link_libraries(AlgArrayTest ${TEST_LIB})
INSTALL(TARGETS AlgArrayTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})