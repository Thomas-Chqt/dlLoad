/*
 * ---------------------------------------------------
 * testLib3.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 21:22:34
 * ---------------------------------------------------
 */

#if (defined(__GNUC__) || defined(__clang__)) && defined(TESTLIB3_API_EXPORT)
    #define TESTLIB3_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(TESTLIB3_API_EXPORT)
    #define TESTLIB3_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(TESTLIB3_API_IMPORT)
    #define TESTLIB3_API __declspec(dllimport)

#else
    #define TESTLIB3_API
#endif

#include "sharedHeader.hpp"

extern "C" 
{
    TESTLIB3_API TestClass* function1(int n)
    {
        return new TestClass(n);
    }

    TESTLIB3_API TestClass* function2(int n)
    {
        return createInstance(n);
    }
}