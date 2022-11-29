#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> v;

    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)) return false;
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) return false;
        v[m[val]] = v.back();
        m[v.back()] = m[val];
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    RandomizedSet* randomizedSet = new RandomizedSet();
    cout << randomizedSet->insert(1) << endl;
    cout << randomizedSet->remove(2) << endl;
    cout << randomizedSet->insert(2) << endl;
    cout << randomizedSet->getRandom() << endl;
    cout << randomizedSet->remove(1) << endl;
    cout << randomizedSet->insert(2) << endl;
    cout << randomizedSet->getRandom() << endl;
    return 0;
}