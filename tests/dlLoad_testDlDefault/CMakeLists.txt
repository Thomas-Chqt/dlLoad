# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/13 19:56:42
# ---------------------------------------------------

add_executable(dlLoad_testDlDefault)

set_target_properties(dlLoad_testDlDefault PROPERTIES
    FOLDER         "tests"
    ENABLE_EXPORTS ON
)

if(WIN32)
    target_sources(dlLoad_testDlDefault PRIVATE "dlLoad_testDlDefault_testCases.cpp" "dlLoad_testDlDefault.def")
else()
    target_sources(dlLoad_testDlDefault PRIVATE "dlLoad_testDlDefault_testCases.cpp")
endif()

target_include_directories(dlLoad_testDlDefault PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_compile_definitions(dlLoad_testDlDefault
    PRIVATE   "DL_LOAD_TEST_DL_DEFAULT_API_EXPORT"
    INTERFACE "DL_LOAD_TEST_DL_DEFAULT_API_IMPORT"
)

target_link_libraries(dlLoad_testDlDefault PRIVATE testLib1 testLib5 dlLoad GTest::gtest_main)
gtest_discover_tests(dlLoad_testDlDefault)

