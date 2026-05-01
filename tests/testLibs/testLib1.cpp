/*
 * ---------------------------------------------------
 * testLib1.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 19:03:31
 * ---------------------------------------------------
 */

#include "testLib1.hpp"

extern "C" 
{
    void function1()
    {
    }

    int function2()
    {
        return 42;
    }

    int function3(int arg)
    {
        return arg * 2;
    }
}
