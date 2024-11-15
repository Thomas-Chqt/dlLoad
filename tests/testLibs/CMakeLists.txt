# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/13 19:48:32
# ---------------------------------------------------

add_library(testLib1 SHARED)
set_target_properties(testLib1 PROPERTIES FOLDER "tests/testLibs")
target_sources(testLib1 PRIVATE "testLib1.cpp")
target_compile_definitions(testLib1 PRIVATE "TESTLIB1_API_EXPORT" INTERFACE "TESTLIB1_API_IMPORT")

add_library(testLib2 SHARED)
set_target_properties(testLib2 PROPERTIES FOLDER "tests/testLibs")
target_sources(testLib2 PRIVATE "testLib2.cpp")
target_compile_definitions(testLib2 PRIVATE "TESTLIB2_API_EXPORT" INTERFACE "TESTLIB2_API_IMPORT")

add_library(testLib3 SHARED)
set_target_properties(testLib3 PROPERTIES FOLDER "tests/testLibs")
target_sources(testLib3 PRIVATE "testLib3.cpp")
target_compile_definitions(testLib3 PRIVATE "TESTLIB3_API_EXPORT" INTERFACE "TESTLIB3_API_IMPORT")
if(APPLE)
    target_link_options(testLib3 PRIVATE "-undefined" "dynamic_lookup")
endif()

add_library(testLib4 SHARED)
set_target_properties(testLib4 PROPERTIES FOLDER "tests/testLibs")
target_sources(testLib4 PRIVATE "testLib4.cpp")
target_compile_definitions(testLib4 PRIVATE "TESTLIB4_API_EXPORT" INTERFACE "TESTLIB4_API_IMPORT")
if(APPLE)
    target_link_options(testLib4 PRIVATE "-undefined" "dynamic_lookup")
endif()
