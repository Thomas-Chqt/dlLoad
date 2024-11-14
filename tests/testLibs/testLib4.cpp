/*
 * ---------------------------------------------------
 * testLib4.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/13 21:15:33
 * ---------------------------------------------------
 */

#if (defined(__GNUC__) || defined(__clang__)) && defined(TESTLIB4_API_EXPORT)
    #define TESTLIB4_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(TESTLIB4_API_EXPORT)
    #define TESTLIB4_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(TESTLIB4_API_IMPORT)
    #define TESTLIB4_API __declspec(dllimport)

#else
    #define TESTLIB4_API
#endif

#include "staticLib.hpp"

extern "C" 
{
    TESTLIB4_API StaticLibClass* function1(int n)
    {
        return new StaticLibClass(n);
    }

    TESTLIB4_API StaticLibClass* function2(int n)
    {
        return createInstance(n);
    }
}