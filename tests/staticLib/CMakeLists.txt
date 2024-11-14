# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/13 19:49:53
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.24)

add_library(staticLib STATIC)
set_target_properties(staticLib PROPERTIES FOLDER "tests/staticLib")
target_sources(staticLib PRIVATE "staticLib.cpp" "staticLib.hpp")
target_include_directories(staticLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_definitions(staticLib PRIVATE "STATIC_LIB_API_EXPORT")
