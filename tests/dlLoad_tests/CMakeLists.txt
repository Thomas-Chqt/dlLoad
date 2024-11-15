# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/13 19:56:42
# ---------------------------------------------------


add_executable(dlLoad_test)

set_target_properties(dlLoad_test PROPERTIES
    FOLDER         "tests"
    ENABLE_EXPORTS ON
)

target_sources(dlLoad_test PRIVATE "dlLoad_testCases.cpp" "sharedHeader.hpp")

target_include_directories(dlLoad_test PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_compile_definitions(dlLoad_test
    PRIVATE   "DL_LOAD_TEST_API_EXPORT"
    INTERFACE "DL_LOAD_TEST_API_IMPORT"
)

target_compile_definitions(dlLoad_test PRIVATE TEST_LIB_1_FILE=\"$<TARGET_FILE:testLib1>\")
target_compile_definitions(dlLoad_test PRIVATE TEST_LIB_2_FILE=\"$<TARGET_FILE:testLib2>\")
target_compile_definitions(dlLoad_test PRIVATE TEST_LIB_3_FILE=\"$<TARGET_FILE:testLib3>\")

target_link_libraries(dlLoad_test PRIVATE dlLoad GTest::gtest_main)
gtest_discover_tests(dlLoad_test)
