dlLoad
======

dlLoad is a mix between `dlopen` and `LoadLibrary`. It is a small library that allows dynamically loading shared libraries on Windows, Linux, and macOS with the same code.

Support
-------

| Platform | Supported | Underlying API |
|----------|-----------|----------------|
| Windows  | YES       | LoadLibrary    |
| Linux    | YES       | dlopen         |
| macOS    | YES       | dlopen         |

Build
-----

CMake is used as the build system. The easiest way to use the library is within another CMake project using `add_subdirectory`, but the library can also be built separately.

```sh
mkdir build
cmake -S . -B build
cmake --build build
```

CMake Options
-------------

| Option           | Default Value | Description                       |
|----------------- |---------------|-----------------------------------|
| `DL_BUILD_TESTS` | `OFF`         | Build unit tests                  |
| `DL_INSTALL`     | `OFF`         | Add dlLoad to the install command |


Usage example
-------------

```cpp
#include "dlLoad/dlLoad.h"

// define the type of the function you want to extract from the dll
using Func = int (*)(int) 

int main()
{
    // create a handle to the shared library
    // equivalent to :
    // Windows : LoadLibraryExA((LPCSTR)"path/to/myLib.dll", (HANDLE)NULL, (DWORD)0);
    // Unix : dlopen("path/to/myLib.dll", RTLD_NOW | RTLD_GLOBAL);
    DlHandle handle = dlLoad("path/to/myLib.dll");

    // retrive a function pointer to the desired function in the library
    Func f = (Func)getSym(handle, "myFunction");

    // use the function
    f(42);

    // release the handle
    dlFree(handle);
}
````