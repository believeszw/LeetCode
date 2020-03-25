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

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    MESSAGE("This is Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0") # 调试包不优化
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    MESSAGE("This is Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2") # release包优化
endif()

# -g 调试信息
# -Wall 开启所有警告
# -Werror 警告视为错误
# -Wextra 打印一些额外的警告信息
# -fsanitize=address
# Out-of-bounds accesses to heap, stack and globals
# Use-after-free
# Use-after-return (runtime flag ASAN_OPTIONS=detect_stack_use_after_return=1)
# Use-after-scope (clang flag -fsanitize-address-use-after-scope)
# Double-free, invalid free
# Memory leaks (experimental)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wextra -fno-omit-frame-pointer -fno-optimize-sibling-calls \
-fsanitize=undefined -fPIE") # -pie # -S .o 文件显示汇编

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread") # 检查数据竞争
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak") # address 已包含，可单独开启
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory -fsanitize-memory-track-origins") # access uninited

# -fno-optimize-sibling-calls 尾递归消除
# -fno-omit-frame-pointer : 保留函数调用的帧信息，以便分析函数调用关系
# -fsanitize=undefined : 未定义行为检测
# -fsanitize=leak 开启后，可以出界更详细的错误信息

# --coverage 用于统计测试覆盖率
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

add_subdirectory(AllQuestions)
add_subdirectory(ByteDance)
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

if (0)
# GoogleTest begin
# Download and unpack googletest at configure time
configure_file(ImportGtest.cmake googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
        )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build"
        )

# The gtest/gmock targets carry header search path dependencies
# automatically when using CMake 2.8.11 or later. Otherwise we
# have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include"
            )
endif ()
# GoogleTest end
endif ()
