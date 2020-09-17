/**
 *  create by NLWMODE at 09/17/2020. 
 *  哈希表的简单实现
 *  拉链法
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

template <typename T , typename U>
class hash_map
{
private:
    vector< list<Hash_Node<T , U> >  > vec; // 数组加链表，解决冲突问题
public:
    hash_map(/* args */);
    ~hash_map();
};
