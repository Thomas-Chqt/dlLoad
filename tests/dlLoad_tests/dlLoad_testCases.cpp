/*
 * ---------------------------------------------------
 * dlLoad_testCases.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/11 23:34:40
 * ---------------------------------------------------
 */

#include <dlLoad/dlLoad.h>
#include <gtest/gtest.h>
#include <string>
#include "sharedHeader.hpp"

TEST(dlLoadTest, voidFuncNoArg)
{
    using Func = void (*)();

    DlHandle handle = dlLoad(TEST_LIB_1_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function1");
    ASSERT_NE(f, nullptr);

    f();

    ASSERT_EQ(dlFree(handle), 0);
}

TEST(dlLoadTest, intFuncNoArg)
{
    using Func = int (*)();

    DlHandle handle = dlLoad(TEST_LIB_1_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function2");
    ASSERT_NE(f, nullptr);

    ASSERT_EQ(f(), 42);

    ASSERT_EQ(dlFree(handle), 0);
}

TEST(dlLoadTest, intFuncIntArg)
{
    using Func = int (*)(int);

    DlHandle handle = dlLoad(TEST_LIB_1_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function3");
    ASSERT_NE(f, nullptr);

    int arg = 42;
    ASSERT_EQ(f(arg), arg * 2);

    ASSERT_EQ(dlFree(handle), 0);
}

TEST(dlLoadTest, sizetFuncStrArg)
{
    using Func = size_t (*)(const std::string&);

    DlHandle handle = dlLoad(TEST_LIB_2_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function1");
    ASSERT_NE(f, nullptr);

    std::string arg = "42";
    ASSERT_EQ(f(arg), arg.length());

    ASSERT_EQ(dlFree(handle), 0);
}

TestClass::TestClass(int n)
    : m_num(n)
{
}

TestClass* createInstance(int n)
{
    return new TestClass(n * 2);
}

TEST(dlLoadTest, mainExeClassConstructor)
{
    using Func = TestClass* (*)(int);

    DlHandle handle = dlLoad(TEST_LIB_3_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function1");
    ASSERT_NE(f, nullptr);

    int arg = 42;
    TestClass* instance = f(arg);
    ASSERT_NE(instance, nullptr);
    ASSERT_EQ(instance->getNum(), arg);
    delete instance;

    ASSERT_EQ(dlFree(handle), 0);
}

TEST(dlLoadTest, mainExeFunc)
{
    using Func = TestClass* (*)(int);

    DlHandle handle = dlLoad(TEST_LIB_3_FILE);
    ASSERT_NE(handle, nullptr);

    Func f = (Func)getSym(handle, "function2");
    ASSERT_NE(f, nullptr);

    int arg = 42;
    TestClass* instance = f(arg);
    ASSERT_NE(instance, nullptr);
    ASSERT_EQ(instance->getNum(), arg * 2);
    delete instance;

    ASSERT_EQ(dlFree(handle), 0);
}

extern "C" int function1(void)
{
    return 42;
}

TEST(dlLoadTest, dlDefault)
{
    using Func = int (*)(void);
    
    Func f = (Func)getSym(DL_DEFAULT, "function1");
    ASSERT_NE(f, nullptr);
    ASSERT_EQ(f(), 42);
}

TEST(dlLoadTest, dlDefaultFromLinkedDll)
{
    using Func = int (*)(const char*);
    
    Func f = (Func)getSym(DL_DEFAULT, "atoi");
    ASSERT_NE(f, nullptr);
    ASSERT_EQ(f("42"), 42);
}
