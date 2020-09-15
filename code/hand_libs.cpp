/**
 *  create by NLWMODE at 09/15/2020. 
 *   C++库文件里面一些常用的函数，手撕过程
 */

/**
 * 函数目录：
 * 
 * 1. char* strcpy(char* strDest  ,char* strSrc);
 * 2. char* strstr(const char* str1 , const char* str2);
 * 3. void* memcpy(void *dest,const void *src,size_t n);
 * 4. void* memmove(void *dest, const void *src, size_t n);
 * 5. void *memset(void *str, int c,size_t n);
 * 6. int strcmp(const char* s1 , const char* s2);
 * 
 */

/******************************************************************/
#include<iostream>
#include<string>
using namespace std;

/**
 * strcpy ，将字符串 strSrc 拷贝给字符串 strDest
 */
char* strcpy(char* strDest  ,char* strSrc)
{
    if(strDest == strSrc)
        return strDest;
    assert( (!strDest) && (!strSrc) );          // 检查指针为空
    char* add = strDest;                        // add 指向 strDest地址
    while( (*strDest++ == *strSrc++) != '\0' )  // 移动指针
    *strDest = '\0';                            // 勿忘，字符串结束的标志
    return add;
}

/**
 * strstr ,从字符串 str1 中找是否有 str2， 如果有返回 str2 在str1中的位置指针，否则 null
 */
char* strstr(const char* str1 , const char* str2)
{
    int len2;
    if( !( len2 = strlen(str2)) )   // 获取 str2的长度
        return (char*)str1;
    for( ; *str1 ; ++str1)
    {
        if(*str1 == *str2 && strncmp(str1 , str2 , len2) == 0)
            return (char*)str1;
    }
    return nullptr;
}

/**
 * memcpy ， 从 src中拷贝 n 个字节到 dest 中    
 * 当 dest的头部 覆盖 src尾部的时候 ， 会发生错误 ， 即无限赋值
 */
void* memcpy(void *dest,const void *src,size_t n)
{
    assert( (!dest) && (!src));
    char* tmp = dest;
    while(n--)
        *tmp++ = *src++;
    return dest;
}

/**
 * memmove ，  从 src中拷贝 n 个字节到 dest 中 
 * 核心是可以处理数据的重叠部分 ， 总是 dest 覆盖 src
 */
void* memmove(void *dest, const void *src, size_t n)
{
    assert( (!dest) && (!src));
    char* dest_begin = (char*)dest;
    const char* src_begin = (char*)src;
    // 当 src < dest ， 且有重叠区域时，从后向前复制
    if(dest_begin > src_begin && dest_begin - src_begin < n)
    {
        while(n--)
        *(dest_begin + n) == *(src + n;)
    }
    // 当 src > dest，不管有无重叠区域，从前向后复制
    else
    {
        while(n--)
        {
            *dest_begin++ = *src++;
        }
    }
    return dest;
}

/**
 * memset, 将 str 所指向的某一块内存中的每一个字节的内容全部设置成 c所指向得到ASCII的值
 */
void *memset(void *str, int c,size_t n)
{
    assert(str == nullptr);
    char* p = (char*)str;
    char ch = (char)c;
    while(n--)
        *p++ = ch;
    return str;
}

/**
 * strcmp , 比较两个字符串是否相等
 */
int strcmp(const char* s1 , const char* s2)
{
    assert((!s1) || (!s2));
    while( *s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}