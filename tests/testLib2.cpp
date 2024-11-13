/*
 * ---------------------------------------------------
 * testLib2.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 21:14:49
 * ---------------------------------------------------
 */

#if defined(TESTLIB2_DLL_BUILD)
    #if defined(_WIN32)
        #define TESTLIB2_API __declspec(dllexport)
    #else
        #define TESTLIB2_API
    #endif

#elif defined(TESTLIB2_DLL_LINK)
    #if defined(_WIN32)
        #define TESTLIB2_API __declspec(dllimport)
    #else
        #define TESTLIB2_API
    #endif

#else
    #define TESTLIB2_API
#endif

#include <string>

extern "C" 
{
    TESTLIB2_API size_t function1(const std::string& str)
    {
        return str.length();
    }
}