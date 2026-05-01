dlLoad
======

dlLoad is a mix between `dlopen` and `LoadLibrary`. It is a small library that allows to load shared libraries at runtime with the same code on Windows, Linux, and macOS.

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
    DlHandle handle = dlLoad("path/to/myLib.dll", DL_NOW | DL_LOCAL);

    // retrive a function pointer to the desired function in the library
    Func f = (Func)getSym(handle, "myFunction");

    // use the function
    f(42);

    // release the handle
    dlFree(handle);
}
````

Load flags
----------

`dlLoad()` takes a bitmask of flags:

```cpp
DlHandle handle = dlLoad("path/to/myLib.dll", DL_NOW | DL_LOCAL);
```

| dlLoad flags | Unix equivalent | Windows equivalent |
|--------------|-----------------|--------------------|
| `DL_LAZY`    | `RTLD_LAZY`     | `0`                |
| `DL_NOW`     | `RTLD_NOW`      | `0`                |
| `DL_GLOBAL`  | `RTLD_GLOBAL`   | `0`                |
| `DL_LOCAL`   | `RTLD_LOCAL`    | `0`                |
