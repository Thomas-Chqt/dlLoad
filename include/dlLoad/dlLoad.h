/*
 * ---------------------------------------------------
 * dlLoad.h
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/11 20:18:44
 * ---------------------------------------------------
 */

#ifndef DLLOAD_H
#define DLLOAD_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef void* DlHandle;

DlHandle dlLoad(const char* path);
void* getSym(DlHandle handle, const char* name);
int dlFree(DlHandle handle);

#ifdef __cplusplus
}
#endif

#endif // DLLOAD_H