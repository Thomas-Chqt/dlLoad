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
typedef unsigned int DlLoadFlags;

#define DL_DEFAULT (DlHandle)0

#define DL_LAZY   ((DlLoadFlags)1u << 0)
#define DL_NOW    ((DlLoadFlags)1u << 1)
#define DL_GLOBAL ((DlLoadFlags)1u << 2)
#define DL_LOCAL  ((DlLoadFlags)1u << 3)

DlHandle dlLoad(const char* path, DlLoadFlags flags);
void* getSym(DlHandle handle, const char* name);
int dlFree(DlHandle handle);

#ifdef __cplusplus
}
#endif

#endif // DLLOAD_H
