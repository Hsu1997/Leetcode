#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
public:
    struct linklist{
        linklist* next = nullptr;
        int key;
        int val;
        linklist(linklist* n, int k, int v) : next(n), key(k), val(v) {}
    };

    vector<linklist*> m;
    int n;
    MyHashMap() {
        n = 107;
        m.resize(n);
    }
    
    void put(int key, int value) {
        int index = (key * 101) % n;
        if (m[index]){
            linklist* temp = m[index];
            while(temp){
                if (temp->key == key){
                    temp->val = value;
                    return;
                }
                temp = temp->next;
            }
        }
        m[index] = new linklist(m[index], key, value);
    }
    
    int get(int key) {
        int index = (key * 101) % n;
        if (!m[index]) return -1;
        linklist* temp = m[index];
        while(temp){
            if (temp->key == key) return temp->val;
            temp = temp->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index =  (key * 101) % n;
        if (!m[index]) return;
        linklist* temp = m[index];
        if (temp->key == key){
            m[index] = temp->next;
            delete temp;
            return;
        }
        linklist* prev = temp;
        temp = temp->next;
        while(temp){
            if (temp->key == key){
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = prev->next;
            temp = temp->next;
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

int main(){
    MyHashMap *myHashMap = new MyHashMap();
    myHashMap->put(1, 1); // The map is now [[1,1]]
    myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
    cout << myHashMap->get(1) << endl;    // return 1, The map is now [[1,1], [2,2]]
    cout << myHashMap->get(3) << endl;    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    cout << myHashMap->get(2) << endl;    // return 1, The map is now [[1,1], [2,1]]
    myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
    cout << myHashMap->get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,1]]
}