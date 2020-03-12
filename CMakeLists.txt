cmake_minimum_required(VERSION 3.14)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

# googletest
set(GOOGLETEST_VERSION 1.10.0)
add_subdirectory(
        googletest/googletest
)
include_directories(
        googletest/googletest/include
)
# end

include_directories(${PROJECT_SOURCE_DIR}/include)

# -g 调试信息
# -Wall 开启所有警告
# -Werror 警告视为错误
# -fsanitize=address
# Out-of-bounds accesses to heap, stack and globals
# Use-after-free
# Use-after-return (runtime flag ASAN_OPTIONS=detect_stack_use_after_return=1)
# Use-after-scope (clang flag -fsanitize-address-use-after-scope)
# Double-free, invalid free
# Memory leaks (experimental)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -O0 -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize=address")

# --coverage 用于统计测试覆盖率
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

#set(CMAKE_CXX_FLAGS_DEBUG   "-O0" )             # 调试包不优化
#set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG " )   # release包优化

add_subdirectory(AllQuestions)
add_subdirectory(TopInterviewQuestions)

#IF (WIN32)
#    MESSAGE(STATUS "Now is windows")
#ELSEIF (APPLE)
#    MESSAGE(STATUS "Now is Apple systens.")
#ELSEIF (UNIX)
#        MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")
#ENDIF ()

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

#IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
#    MESSAGE(STATUS "current platform: Linux ")
#ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
#    MESSAGE(STATUS "current platform: Windows")
#ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
#    MESSAGE(STATUS "current platform: FreeBSD")
#ELSE ()
#    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
#ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
