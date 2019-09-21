project(AllQuestions)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/../include)
link_directories(${PROJECT_SOURCE_DIR}/../gtest)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC main.cpp)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(AllQuestions ${SRC})

target_link_libraries(AllQuestions ${TEST_LIB})
INSTALL(TARGETS AllQuestions DESTINATION ${EXECUTABLE_OUTPUT_PATH})