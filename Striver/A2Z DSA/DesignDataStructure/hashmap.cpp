#include "bits/stdc++.h"
using namespace std;

class MyHashMap
{
private:
    vector<int> hashmap;

public:
    MyHashMap()
    {
        hashmap.resize(1e6 + 1, -1);
    }

    void put(int key, int value)
    {
        hashmap[key] = value;
    }

    int get(int key)
    {
        return hashmap[key];
    }

    void remove(int key)
    {
        hashmap[key] = -1;
    }
};

class MyHashMap
{
private:
    vector<list<pair<int, int>>> hashmap;
    int size = 1e4;

public:
    MyHashMap()
    {
        hashmap.resize(1e4);
    }

    void put(int key, int value)
    {
        int idx = key % size;
        auto &chain = hashmap[idx];

        for (auto &it : chain)
        {
            if (it.first == key)
            {
                it.second = value;
                return;
            }
        }

        chain.emplace_back(key, value);
    }

    int get(int key)
    {
        int idx = key % size;
        auto &chain = hashmap[idx];

        for (auto &it : chain)
        {
            if (it.first == key)
            {
                return it.second;
            }
        }

        return -1;
    }

    void remove(int key)
    {
        int idx = key % size;
        auto &chain = hashmap[idx];

        for (auto it = chain.begin(); it != chain.end(); it++)
        {
            if (it->first == key)
            {
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{

    return 0;
}