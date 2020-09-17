/**
 *  create by NLWMODE at 09/17/2020. 
 *  LRU 淘汰算法简单实现
 */
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LRU
{
private:
    int capacity;
    list < pair<int , int> > cache; //用于保存当前缓存窗口
    unordered_map<int , list< pair<int , int> >::iterator > umap; // 编号以及在list中的下标，方便删除
public:
    LRU(int cap): capacity(cap)
    {}
    // 往缓存中插入新的访问记录
    void put(int key , int val)
    {
        auto it = umap.find(key);
        if(it != umap.end())
        {
            cache.erase(it->second);
            umap.erase(key);
        }
        // 先插入在判断是否超过缓存大小，会省很多判断
        cache.push_front( pair<int , int>(key  ,val));
        umap.emplace(key ,cache.begin()); 
        if(cache.size() > capacity) 
        {
            umap.erase(cache.back().first);
            cache.pop_back();
        }
    }
    // 通过key,查找值，相当于一次访问，需要把访问的对象放在最前面，如果有，删除原来的
    int get(int key)
    {
        auto it = umap.find(key);
        if(it != umap.end())
        {
            return -1;
        }
        auto target_it = it->second;
        pair<int , int> tmp{target_it->first , target_it->second};
        cache.push_front( tmp );
        cache.erase(target_it);
        umap.erase(key);
        umap.emplace(key , cache.begin());
        return tmp.second;
    }
};

int main()
{
    cout << "hello World!" << endl;
    return 0;
}