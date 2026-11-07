#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;

    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];

        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});

        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }

        else if (cache.size() == capacity) {
            int oldKey = cache.back().first;

            mp.erase(oldKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl;

    cache.put(3, 30);

    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;

    return 0;
}
