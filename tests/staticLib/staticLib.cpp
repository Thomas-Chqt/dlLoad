/*
 * ---------------------------------------------------
 * staticLib.cpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/13 19:03:14
 * ---------------------------------------------------
 */

#include "staticLib.hpp"

StaticLibClass::StaticLibClass(int n)
    : m_value(n)
{
}

StaticLibClass* createInstance(int n)
{
    return new StaticLibClass(n * 2);
}