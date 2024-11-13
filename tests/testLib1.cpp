/*
 * ---------------------------------------------------
 * testLib1.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 19:03:31
 * ---------------------------------------------------
 */

#if defined(TESTLIB1_DLL_BUILD)
    #if defined(_WIN32)
        #define TESTLIB1_API __declspec(dllexport)
    #else
        #define TESTLIB1_API
    #endif

#elif defined(TESTLIB1_DLL_LINK)
    #if defined(_WIN32)
        #define TESTLIB1_API __declspec(dllimport)
    #else
        #define TESTLIB1_API
    #endif

#else
    #define TESTLIB1_API
#endif

extern "C" 
{
    TESTLIB1_API void function1()
    {
    }

    TESTLIB1_API int function2()
    {
        return 42;
    }

    TESTLIB1_API int function3(int arg)
    {
        return arg * 2;
    }
}