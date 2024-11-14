# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/13 20:17:30
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.24)

add_executable(dlLoad_testwithstaticlib)

set_target_properties(dlLoad_testwithstaticlib PROPERTIES
    FOLDER         "tests"
    ENABLE_EXPORTS ON
)

target_sources(dlLoad_testwithstaticlib PRIVATE "dlLoad_withStaticLib_testCases.cpp")

target_include_directories(dlLoad_testwithstaticlib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_compile_definitions(dlLoad_testwithstaticlib
    PRIVATE   "DL_LOAD_TEST_WITH_STATIC_LIB_API_EXPORT"
    INTERFACE "DL_LOAD_TEST_WITH_STATIC_LIB_API_IMPORT"
)

target_compile_definitions(dlLoad_testwithstaticlib
    PRIVATE   "STATIC_LIB_API_EXPORT"
    INTERFACE "STATIC_LIB_API_IMPORT"
)

target_compile_definitions(dlLoad_testwithstaticlib PRIVATE TEST_LIB_4_FILE=\"$<TARGET_FILE:testLib4>\")

target_link_libraries(dlLoad_testwithstaticlib PRIVATE $<LINK_LIBRARY:WHOLE_ARCHIVE,staticLib>)
target_include_directories(dlLoad_testwithstaticlib INTERFACE $<TARGET_PROPERTY:staticLib,INTERFACE_INCLUDE_DIRECTORIES>)


target_link_libraries(dlLoad_testwithstaticlib PRIVATE dlLoad GTest::gtest_main)
gtest_discover_tests(dlLoad_testwithstaticlib)

