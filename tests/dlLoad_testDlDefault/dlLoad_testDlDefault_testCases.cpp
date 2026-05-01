/*
 * ---------------------------------------------------
 * dlLoad_testDlDefault_testCases.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2025/07/12 21:20:25
 * ---------------------------------------------------
 */

#include <gtest/gtest.h>

#include "dlLoad/dlLoad.h"
#include "testLib5.hpp"

#if (defined(__GNUC__) || defined(__clang__)) && defined(DL_LOAD_TEST_DL_DEFAULT_API_EXPORT)
    #define DL_LOAD_TEST_DL_DEFAULT_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(DL_LOAD_TEST_DL_DEFAULT_API_EXPORT)
    #define DL_LOAD_TEST_DL_DEFAULT_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(DL_LOAD_TEST_DL_DEFAULT_API_IMPORT)
    #define DL_LOAD_TEST_DL_DEFAULT_API __declspec(dllimport)

#else
    #define DL_LOAD_TEST_DL_DEFAULT_API
#endif

extern "C"
{
    DL_LOAD_TEST_DL_DEFAULT_API int function(void)
    {
        return 42;
    }
}

TEST(dlLoadTtestDlDefault, exeLoadFromExe)
{
    using Func = int (*)(void);
    
    Func f = (Func)getSym(DL_DEFAULT, "function");
    ASSERT_NE(f, nullptr);
    ASSERT_EQ(f(), 42);
}

TEST(dlLoadTtestDlDefault, libLoadFromExe)
{
    ASSERT_EQ(dyload_function(), 42);
}

TEST(dlLoadTtestDlDefault, libLoadFromLib)
{
    ASSERT_EQ(dyload_function2(), 42);
}
