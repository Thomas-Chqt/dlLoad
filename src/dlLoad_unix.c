/*
 * ---------------------------------------------------
 * dlLoad_unix.c
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/11 21:18:47
 * ---------------------------------------------------
 */

#include "dlLoad/dlLoad.h"
#include <dlfcn.h>

DlHandle dlLoad(const char* path)
{
    return dlopen(path, RTLD_NOW | RTLD_GLOBAL);
}

void* getSym(DlHandle handle, const char* name)
{
    if (handle == DL_DEFAULT)
        return dlsym(RTLD_DEFAULT, name);
    else
        return dlsym(handle, name);
}

int dlFree(DlHandle handle)
{
    return dlclose(handle);
}
