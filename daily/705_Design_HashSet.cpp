#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
public:
    static const int index_size = 10;
    vector<vector<int>> hashset;
    // vector<int> hashset[index_size];
    
    MyHashSet() {
        hashset.reserve(index_size);
    }
    
    void add(int key) {
        int index = key % index_size;
        if (!contains(key)) hashset[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key % index_size;
        for (vector<int>::iterator ptr = hashset[index].begin(); ptr != hashset[index].end(); ptr++){
            if (*ptr == key){
                hashset[index].erase(ptr);
                return;
            }
        }
        return;
    }
    
    bool contains(int key) {
        int index = key % index_size;
        for (int i : hashset[index]){
            if (i == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(){
    MyHashSet* myHashSet = new MyHashSet();
    myHashSet->add(1);      // set = [1]
    myHashSet->add(2);      // set = [1, 2]
    myHashSet->contains(1); // return True
    myHashSet->contains(3); // return False, (not found)
    myHashSet->add(2);      // set = [1, 2]
    myHashSet->contains(2); // return True
    myHashSet->remove(2);   // set = [1]
    myHashSet->contains(2); // return False, (already removed)
    return 0;
}