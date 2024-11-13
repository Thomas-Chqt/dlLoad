# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/11 23:34:16
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.16)

include(FetchContent)
include(GoogleTest)

enable_testing()

enable_language(CXX)

add_library(testLib1 SHARED "testLib1.cpp")
set_target_properties(testLib1
    PROPERTIES CXX_STANDARD 14
    CXX_STANDARD_REQUIRED   ON
    FOLDER                  "tests"
)
target_compile_definitions(testLib1 PRIVATE "TESTLIB1_DLL_BUILD" INTERFACE "TESTLIB1_DLL_LINK")
set(TEST_LIB_1_FILE $<TARGET_FILE:testLib1>)

add_library(testLib2 SHARED "testLib2.cpp")
set_target_properties(testLib2
    PROPERTIES CXX_STANDARD 14
    CXX_STANDARD_REQUIRED   ON
    FOLDER                  "tests"
)
target_compile_definitions(testLib2 PRIVATE "TESTLIB2_DLL_BUILD" INTERFACE "TESTLIB2_DLL_LINK")
set(TEST_LIB_2_FILE $<TARGET_FILE:testLib2>)

add_library(testLib3 SHARED "testLib3.cpp")
set_target_properties(testLib3
    PROPERTIES CXX_STANDARD 14
    CXX_STANDARD_REQUIRED   ON
    FOLDER                  "tests"
)
target_compile_definitions(testLib3 PRIVATE "TESTLIB3_DLL_BUILD" INTERFACE "TESTLIB3_DLL_LINK")
target_compile_definitions(testLib3 PRIVATE "DL_LOAD_TEST_DLL_LINK")
set(TEST_LIB_3_FILE $<TARGET_FILE:testLib3>)

add_executable(dlLoad_test)

set_target_properties(dlLoad_test
    PROPERTIES CXX_STANDARD 14
    CXX_STANDARD_REQUIRED   ON
    FOLDER                  "tests"
    ENABLE_EXPORTS          ON
)

target_sources(dlLoad_test PRIVATE "dlLoad_testCases.cpp")

target_include_directories(dlLoad_test PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_compile_definitions(dlLoad_test PRIVATE "DL_LOAD_TEST_DLL_BUILD" INTERFACE "DL_LOAD_TEST_DLL_LINK")
target_compile_definitions(dlLoad_test PRIVATE "TEST_LIB_1_FILE=\"${TEST_LIB_1_FILE}\"")
target_compile_definitions(dlLoad_test PRIVATE "TEST_LIB_2_FILE=\"${TEST_LIB_2_FILE}\"")
target_compile_definitions(dlLoad_test PRIVATE "TEST_LIB_3_FILE=\"${TEST_LIB_3_FILE}\"")

set(BUILD_SHARED_LIBS_BACK ${BUILD_SHARED_LIBS})
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build using shared libraries" FORCE)
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
set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS_BACK} CACHE BOOL "Build using shared libraries" FORCE)

target_link_libraries(dlLoad_test PRIVATE dlLoad GTest::gtest_main)
target_link_libraries(testLib3 PRIVATE dlLoad_test)
if(APPLE)
    target_link_options(testLib3 PRIVATE "-undefined" "dynamic_lookup")
endif()

gtest_discover_tests(dlLoad_test)
