#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
public:
    // frequency => [{key, value},{key, value},{key, value},....]
    unordered_map<int,list<pair<int,int>>> frequencies;
    // key => {frequency, pointer}
    unordered_map<int,pair<int, list<pair<int,int>>::iterator>> pointer;
    int capacity;
    int min_freq;

    LFUCache(int _capacity) {
        capacity = _capacity;
    }

    void insert(int key, int value, int frequency){
        frequencies[frequency].push_back({key, value});
        pointer[key] = {frequency, prev(frequencies[frequency].end())};
    }
    
    int get(int key) {
        if (pointer.find(key) == pointer.end()) return -1;
        int frequency = pointer[key].first;
        list<pair<int,int>>::iterator it = pointer[key].second;
        int value = (*it).second;
        frequencies[frequency].erase(it);
        if (frequencies[frequency].empty()){
            frequencies.erase(frequency);
            if (frequency == min_freq) min_freq++;
        }
        insert(key, value, frequency + 1);
        return value;
    }
    
    void put(int key, int value) {
        if (pointer.find(key) != pointer.end()){
            (*pointer[key].second).second = value;
            get(key);
        }
        else{
            if (pointer.size() == capacity){
                pointer.erase(frequencies[min_freq].front().first);
                frequencies[min_freq].pop_front();
                if (frequencies[min_freq].empty()) frequencies.erase(min_freq);
            }
            min_freq = 1;
            insert(key, value, 1);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LFUCache* lfu = new LFUCache(2);
    lfu->put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu->get(1) << endl;      // return 1 cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu->put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2. cache=[3,1], cnt(3)=1, cnt(1)=2 return -1 (not found)
    cout << lfu->get(3) << endl;      // return 3 cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu->put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1. cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu->get(1) << endl;      // return -1 (not found)
    cout << lfu->get(3) << endl;      // return 3 cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu->get(4) << endl;      // return 4 cache=[4,3], cnt(4)=2, cnt(3)=3
    return 0;
}