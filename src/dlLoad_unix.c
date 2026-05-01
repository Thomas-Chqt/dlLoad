/*
 * ---------------------------------------------------
 * dlLoad_unix.c
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/11 21:18:47
 * ---------------------------------------------------
 */

#include "dlLoad/dlLoad.h"
#include <stddef.h>
#include <dlfcn.h>

static int getNativeFlags(DlLoadFlags flags)
{
    int nativeFlags = 0;
    DlLoadFlags knownFlags[] = {
        DL_LAZY,
        DL_NOW,
        DL_GLOBAL,
        DL_LOCAL
    };
    size_t i = 0;

    for (i = 0; i < sizeof(knownFlags) / sizeof(knownFlags[0]); i++)
    {
        DlLoadFlags knownFlag = knownFlags[i];

        if ((flags & knownFlag) == 0)
            continue;

        switch (knownFlag)
        {
        case DL_LAZY:
            nativeFlags |= RTLD_LAZY;
            break;
        case DL_NOW:
            nativeFlags |= RTLD_NOW;
            break;
        case DL_GLOBAL:
            nativeFlags |= RTLD_GLOBAL;
            break;
        case DL_LOCAL:
            nativeFlags |= RTLD_LOCAL;
            break;
        default:
            break;
        }
    }

    return nativeFlags;
}

DlHandle dlLoad(const char* path, DlLoadFlags flags)
{
    return dlopen(path, getNativeFlags(flags));
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
