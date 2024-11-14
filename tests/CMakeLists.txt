# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/11 23:34:16
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.24)

include(FetchContent)
include(GoogleTest)

enable_testing()

enable_language(CXX)

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
    GIT_SHALLOW    1
)
set(BUILD_GMOCK   OFF)
set(INSTALL_GTEST OFF)
if(WIN32)
    set(gtest_disable_pthreads ON)
endif()
FetchContent_MakeAvailable(googletest)
set_target_properties(gtest PROPERTIES FOLDER "dependencies")
set_target_properties(gtest_main PROPERTIES FOLDER "dependencies")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("testLibs")
add_subdirectory("staticLib")

add_subdirectory("dlLoad_tests")
target_link_libraries(testLib3 PRIVATE dlLoad_test)

add_subdirectory("dlLoad_testWithStaticLib")
target_link_libraries(testLib4 PRIVATE dlLoad_testwithstaticlib)
