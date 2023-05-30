#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MyHashSet {
public:
    unordered_set<int> s;

    MyHashSet() {}
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(key);
    }
    
    bool contains(int key) {
        return s.count(key);
    }
};

int main(){
    MyHashSet* myHashSet = new MyHashSet();
    myHashSet->add(1);      // set = [1]
    myHashSet->add(2);      // set = [1, 2]
    cout << myHashSet->contains(1) << endl; // return True
    cout << myHashSet->contains(3) << endl; // return False, (not found)
    myHashSet->add(2);      // set = [1, 2]
    cout << myHashSet->contains(2) << endl; // return True
    myHashSet->remove(2);   // set = [1]
    cout << myHashSet->contains(2) << endl; // return False, (already removed)
}