#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct node{
    node* prev;
    node* next;
    int key;
    int val;
    node() : prev(nullptr), next(nullptr), key(-1), val(-1) {}
    node(node* p, node* n, int k, int v) : prev(p), next(n), key(k), val(v){}
};

class LRUCache {
public:
    int c;
    int s = 0;
    node* head = new node();
    node* tail = head;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        c = capacity;
    }
    
    void move_to_tail(node* t){
        if (t->prev) t->prev->next = t->next;
        if (t->next) t->next->prev = t->prev;
        tail->next = t;
        t->prev = tail;
        t->next = nullptr;
        tail = t;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        node* temp = m[key];
        if (temp != tail) move_to_tail(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if (m.count(key)){
            node* temp = m[key];
            temp->val = value;
            if (temp != tail) move_to_tail(temp);
        }
        else{
            if (m.size() == c){
                node* d = head->next;
                m.erase(d->key);
                if (d == tail){
                    tail = head;
                    head->next = nullptr;
                }
                else{
                    head->next = d->next;
                    d->next->prev = head;
                }
            }
            node* n = new node(tail, nullptr, key, value);
            tail->next = n;
            tail = n;
            m[key] = tail;
        }
        // for (auto i : m) cout << i.first << " : " << i.second->val << ", ";
        // cout << endl;
    }
};

int main(){
    // LRUCache* lRUCache = new LRUCache(2);
    // lRUCache->put(1, 1); // cache is {1=1}
    // lRUCache->put(2, 2); // cache is {1=1, 2=2}
    // cout << lRUCache->get(1) << endl;    // return 1
    // lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // cout << lRUCache->get(2) << endl;    // returns -1 (not found)
    // lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // cout << lRUCache->get(1) << endl;    // return -1 (not found)
    // cout << lRUCache->get(3) << endl;    // return 3
    // cout << lRUCache->get(4) << endl;    // return 4

    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(2, 1); // cache is {2=1}
    lRUCache->put(2, 2); // cache is {2=2}
    cout << lRUCache->get(2) << endl;    // return 2
    lRUCache->put(1, 1); // LRU key was 2, evicts key 2, cache is {1=1, 2=2}
    lRUCache->put(4, 1); // LRU key was 1, evicts key 1, cache is {1=1, 4=1}
    cout << lRUCache->get(2) << endl;    // returns -1 (not found)

    return 0;
}