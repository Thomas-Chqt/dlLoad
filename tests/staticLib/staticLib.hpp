/*
 * ---------------------------------------------------
 * staticLib.hpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/13 19:03:22
 * ---------------------------------------------------
 */

#ifndef STATICLIB_HPP
#define STATICLIB_HPP

#if (defined(__GNUC__) || defined(__clang__)) && defined(STATIC_LIB_API_EXPORT)
    #define STATIC_LIB_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(STATIC_LIB_API_EXPORT)
    #define STATIC_LIB_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(STATIC_LIB_API_IMPORT)
    #define STATIC_LIB_API __declspec(dllimport)

#else
    #define STATIC_LIB_API
#endif

class STATIC_LIB_API StaticLibClass
{
public:
    StaticLibClass(int);

    inline int getValue() const { return m_value; }

private:
    int m_value;
};

STATIC_LIB_API StaticLibClass* createInstance(int);

#endif // STATICLIB_HPP