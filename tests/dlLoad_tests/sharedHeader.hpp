/*
 * ---------------------------------------------------
 * sharedHeader.hpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/11/12 21:22:45
 * ---------------------------------------------------
 */

#if (defined(__GNUC__) || defined(__clang__)) && defined(DL_LOAD_TEST_API_EXPORT)
    #define DL_LOAD_TEST_API __attribute__((visibility("default")))

#elif defined(_MSC_VER) && defined(DL_LOAD_TEST_API_EXPORT)
    #define DL_LOAD_TEST_API __declspec(dllexport)

#elif defined(_MSC_VER) && defined(DL_LOAD_TEST_API_IMPORT)
    #define DL_LOAD_TEST_API __declspec(dllimport)

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