/*
 * ---------------------------------------------------
 * testLib2.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 21:14:49
 * ---------------------------------------------------
 */

#if (defined(__GNUC__) || defined(__clang__)) && defined(TESTLIB2_API_EXPORT)
    #define TESTLIB2_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(TESTLIB2_API_EXPORT)
    #define TESTLIB2_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(TESTLIB2_API_IMPORT)
    #define TESTLIB2_API __declspec(dllimport)

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