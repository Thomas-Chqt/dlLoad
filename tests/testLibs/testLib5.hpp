/*
 * ---------------------------------------------------
 * testLib5.hpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2025/07/12 22:03:32
 * ---------------------------------------------------
 */

#if (defined(__GNUC__) || defined(__clang__)) && defined(TESTLIB5_API_EXPORT)
    #define TESTLIB5_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(TESTLIB5_API_EXPORT)
    #define TESTLIB5_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(TESTLIB5_API_IMPORT)
    #define TESTLIB5_API __declspec(dllimport)

#else
    #define TESTLIB5_API
#endif

TESTLIB5_API int dyload_function(); // use dlLoad to load a function called function, call it and return the result
TESTLIB5_API int dyload_function2(); // use dlLoad to load a function called function2, call it and return the result

