/*
 * ---------------------------------------------------
 * dlLoad_withStaticLib_testCases.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/13 19:08:19
 * ---------------------------------------------------
 */

#include <dlLoad/dlLoad.h>
#include <gtest/gtest.h>
#include "staticLib.hpp"

// void func()
// {
//     StaticLibClass c(3);
//     StaticLibClass* p = createInstance(3);
//     delete p;
// }

TEST(dlLoadTestWithStaticLib, mainExeClassConstructor)
{
    using Func = StaticLibClass* (*)(int);

    DlHandle handle = dlLoad(TEST_LIB_4_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function1");
    ASSERT_NE(f, nullptr);

    int arg = 42;
    StaticLibClass* instance = f(arg);
    ASSERT_NE(instance, nullptr);
    ASSERT_EQ(instance->getValue(), arg);
    delete instance;

    ASSERT_EQ(dlFree(handle), 0);
}

TEST(dlLoadTestWithStaticLib, mainExeFunc)
{
    using Func = StaticLibClass* (*)(int);

    DlHandle handle = dlLoad(TEST_LIB_4_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function2");
    ASSERT_NE(f, nullptr);

    int arg = 42;
    StaticLibClass* instance = f(arg);
    ASSERT_NE(instance, nullptr);
    ASSERT_EQ(instance->getValue(), arg * 2);
    delete instance;

    ASSERT_EQ(dlFree(handle), 0);
}