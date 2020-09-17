/**
 *  create by NLWMODE at 09/17/2020. 
 *  哈希表的简单实现
 */
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
using namespace std;

template <typename T , typename U>
struct Hash_Node
{
    T _key;
    U _value;
};

const int hashSize = 12;
