/*
 * ---------------------------------------------------
 * testLib5.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2025/07/12 22:01:45
 * ---------------------------------------------------
 */

#include "testLib5.hpp"

#include "dlLoad/dlLoad.h"

int dyload_function()
{
    using Func = int (*)(void);
    
    Func f = (Func)getSym(DL_DEFAULT, "function");
    if (f == nullptr)
        return -1;

    return f();
}

int dyload_function2()
{
    using Func = int (*)(void);

    DlHandle handle = dlLoad(TEST_LIB_1_FILE, DL_NOW | DL_LOCAL);
    if (handle == nullptr)
        return -1;

    Func f = (Func)getSym(handle, "function2");
    int result = (f != nullptr) ? f() : -1;
    dlFree(handle);
    return result;
}
