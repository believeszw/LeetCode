project(Array)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/../../include)
link_directories(${PROJECT_SOURCE_DIR}/../../gtest)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/${COMPILE_PLAT})

SET(SRC Title1.cc Title2.cc Title3.cc Title4.cc Title5.cc Title6.cc Title7.cc Title8.cc Title9.cc TitleX.cc)

SET(TEST_LIB gtest gtest_main -lpthread)

add_executable(ArrayTest ${SRC})

target_link_libraries(ArrayTest ${TEST_LIB})
INSTALL(TARGETS ArrayTest DESTINATION ${EXECUTABLE_OUTPUT_PATH})