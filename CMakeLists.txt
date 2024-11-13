# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/11/11 21:21:04
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.16)

include(CheckSourceCompiles)
enable_testing()

option(DL_BUILD_TESTS "Build ldLoad tests"            OFF)
option(DL_INSTALL     "Enable ldLoad install command" OFF)

project(dlLoad)
enable_language(C)

add_library(dlLoad STATIC)

if(UNIX)
    message(FATAL_ERROR "Unix not yet implemented")
elseif(WIN32)
    message(STATUS "Windows detected")
    set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
    check_source_compiles(C 
        "#include \"Windows.h\"
        int main() {
            void* handle = LoadLibraryExA((LPCSTR)\"\", (HANDLE)NULL, (DWORD)0);
            void* func = GetProcAddress((HMODULE)handle, (LPCSTR)\"\");
            (void)FreeLibrary((HMODULE)handle);
        }"
        can_use_LoadLibrary)

    if(NOT can_use_LoadLibrary)
        message(FATAL_ERROR "cannot use LoadLibrary")
    endif()
    target_sources(dlLoad PRIVATE "src/dlLoad_win.c")
else()
    message(FATAL_ERROR "Unknown platform")
endif()

target_include_directories(dlLoad PRIVATE "src" PUBLIC "include")

if (DL_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(DL_INSTALL)
    install(TARGETS dlLoad
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
    )
    install(DIRECTORY "include/" DESTINATION "include")
endif()