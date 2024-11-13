/*
 * ---------------------------------------------------
 * sharedHeader.hpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 21:22:45
 * ---------------------------------------------------
 */

#if defined(DL_LOAD_TEST_DLL_BUILD)
    #if defined(_WIN32)
        #define DL_LOAD_TEST_API __declspec(dllexport)
    #else
        #define DL_LOAD_TEST_API
    #endif

#elif defined(DL_LOAD_TEST_DLL_LINK)
    #if defined(_WIN32)
        #define DL_LOAD_TEST_API __declspec(dllimport)
    #else
        #define DL_LOAD_TEST_API
    #endif

#else
    #define DL_LOAD_TEST_API
#endif

class DL_LOAD_TEST_API TestClass
{
public:
    TestClass(int n);

    inline int getNum() const { return m_num; }

private:
    int m_num;
};

DL_LOAD_TEST_API TestClass* createInstance(int);