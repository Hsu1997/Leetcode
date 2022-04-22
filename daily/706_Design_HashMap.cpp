#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
public:
    const static int index_size = 10;
    vector< pair<int, int> > hashset[index_size];

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = key % index_size;
        for (vector< pair<int, int>>::iterator i = hashset[index].begin(); i != hashset[index].end(); i++){
            if (i->first == key){
                i->second = value;
                return;
            }
        }
        hashset[index].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int index = key % index_size;
        for (auto i : hashset[index]){
            if (i.first == key) return i.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % index_size;
        for (vector< pair<int, int>>::iterator i = hashset[index].begin(); i != hashset[index].end(); i++){
            if (i->first == key){
                hashset[index].erase(i);
                return;
            }
        }
    }

    void printall(){
        for (auto i : hashset){
            for (auto j : i){
                cout << "(" << j.first << "," << j.second << "), ";
            }
        }
        cout << endl;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(){
    MyHashMap* myHashMap = new MyHashMap();
    myHashMap->put(1, 1); // The map is now [[1,1]]
    // myHashMap->printall();
    myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
    // myHashMap->printall();
    cout << myHashMap->get(1) << endl;;    // return 1, The map is now [[1,1], [2,2]]
    cout << myHashMap->get(3) << endl;    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    // myHashMap->printall();
    cout << myHashMap->get(2) << endl;    // return 1, The map is now [[1,1], [2,1]]
    myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
    cout << myHashMap->get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,1]]
    return 0;
}