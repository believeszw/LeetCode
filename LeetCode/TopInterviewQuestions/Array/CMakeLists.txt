project(Array)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/../../include)
link_directories(${PROJECT_SOURCE_DIR}/../../gtest)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC Title1.cc Title2.cc Title3.cc Title4.h Title5.h Title6.h Title7.h Title8.h)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(ArrayTest ${SRC})

target_link_libraries(ArrayTest ${TEST_LIB})
INSTALL(TARGETS ArrayTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})