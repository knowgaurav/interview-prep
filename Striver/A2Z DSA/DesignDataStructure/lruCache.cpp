#include "bits/stdc++.h"
using namespace std;

class LRUCache
{
private:
    list<int> dll;                               // doubly linked list
    map<int, pair<list<int>::iterator, int>> mp; // key, <address, value>
    int capacity;

    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        makeRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            capacity--;
        }

        if (capacity < 0)
        {
            mp.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{

    return 0;
}