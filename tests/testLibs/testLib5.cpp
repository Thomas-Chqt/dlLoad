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
    return f();
}

int dyload_function2()
{
    using Func = int (*)(void);
    
    Func f = (Func)getSym(DL_DEFAULT, "function2");
    return f();
}
