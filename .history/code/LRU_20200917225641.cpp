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
    void put(int key , int val)
    {
        auto it = umap.find(key);
        if(it != umap.end())
        {
            cache.erase(it->second);
            umap.erase(key);
        }

        cache.push_front( pair<int , int>(key  ,val));
        umap.emplace(key ,cache.begin()); 
        if(cache.size() > capacity)
        {
            umap.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

