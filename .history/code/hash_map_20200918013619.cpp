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



template <typename T , typename U>
class hash_map
{
private:
    int hashSize = 12;
    vector< list<Hash_Node<T , U>>> vec; // 数组加链表，解决冲突问题
public:
    hash_map(/* args */)
    : vec(hashSize) {    }
    ~hash_map(){    }

    // 除留取余法 构造哈希函数
    int hash(const T& key)
    {   
        return key % (hashSize + 1);
    }
    //
    bool insert_to(const T& key , const U& val)
    {
        Hash_Node<T,U> node;
        node._key = key;
        node._value = val;
        int t = hash(key);
        for(int i = 0 ; i < hashSize ; ++i)
        {
            if(i == t)
            {
                vec.
            }

        }
    }
    // 哈希查找(遍历)
    bool hash_find(const T& key)
    {
        int index = hash(key);
        for(auto it = vec.begin() ; it != vec.end() ; ++it)
            if(key == it->_key)
                return true;
        return false;
    }


};
