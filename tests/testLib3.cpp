/*
 * ---------------------------------------------------
 * testLib3.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 21:22:34
 * ---------------------------------------------------
 */

#if defined(TESTLIB3_DLL_BUILD)
    #if defined(_WIN32)
        #define TESTLIB3_API __declspec(dllexport)
    #else
        #define TESTLIB3_API
    #endif

#elif defined(TESTLIB3_DLL_LINK)
    #if defined(_WIN32)
        #define TESTLIB3_API __declspec(dllimport)
    #else
        #define TESTLIB3_API
    #endif

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