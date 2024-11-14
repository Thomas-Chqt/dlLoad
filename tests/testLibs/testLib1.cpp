/*
 * ---------------------------------------------------
 * testLib1.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 19:03:31
 * ---------------------------------------------------
 */

#if (defined(__GNUC__) || defined(__clang__)) && defined(TESTLIB1_API_EXPORT)
    #define TESTLIB1_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(TESTLIB1_API_EXPORT)
    #define TESTLIB1_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(TESTLIB1_API_IMPORT)
    #define TESTLIB1_API __declspec(dllimport)

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