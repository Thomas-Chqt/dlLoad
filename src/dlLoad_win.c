/*
 * ---------------------------------------------------
 * dlLoad_win.c
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/11 21:18:31
 * ---------------------------------------------------
 */

#include "dlLoad/dlLoad.h"
#include "Windows.h"

DlHandle dlLoad(const char* path)
{
    return LoadLibraryExA((LPCSTR)path, (HANDLE)NULL, (DWORD)0);
}

void* getSym(DlHandle handle, const char* name)
{
    return GetProcAddress((HMODULE)handle, (LPCSTR)name);
}

int dlFree(DlHandle handle)
{
    return FreeLibrary((HMODULE)handle) == 0;
}