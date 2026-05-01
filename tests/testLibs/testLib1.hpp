/*
 * ---------------------------------------------------
 * testLib1.hpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2025/07/13 00:10:23
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
    TESTLIB1_API void function1();
    TESTLIB1_API int function2();
    TESTLIB1_API int function3(int arg);
}
