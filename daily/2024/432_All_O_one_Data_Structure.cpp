#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Node{
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;
    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
    Node(int freq, Node* prev, Node* next) : freq(freq), prev(prev), next(next) {}
};


class AllOne {
public:
    Node* min;
    Node* max;
    unordered_map<string, Node*> m;

    AllOne() {
        min = new Node(0);
        max = new Node(0);
        min->next = max;
        max->prev = min;
    }
    
    void inc(string key) {
        // key already exist
        if (m.find(key) != m.end()){
            Node* curr = m[key];
            int frequency = curr->freq;
            curr->keys.erase(key);
            // add new node
            Node* added_one;
            if (min->next == max || curr->next->freq != frequency + 1){
                added_one = new Node(frequency + 1, curr, curr->next);
                curr->next->prev = added_one;
                curr->next = added_one;
            }
            else{
                added_one = curr->next;
            }
            added_one->keys.insert(key);
            m[key] = added_one;

            // delete node if no key remain
            if (curr->keys.empty()){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }
        // key is new
        else{
            // count 1 is already exist
            Node* count_one;
            if (min->next == max || min->next->freq != 1){
                count_one = new Node(1, min, min->next);
                min->next->prev = count_one;
                min->next = count_one;
            }
            else{
                count_one = min->next;
            }
            count_one->keys.insert(key);
            m[key] = count_one;
        }
    }
    
    void dec(string key) {
        if (m.find(key) == m.end()) return;
        // key already exist
        Node* curr = m[key];
        int frequency = curr->freq;
        curr->keys.erase(key);
        // just delete key
        if (frequency  == 1) m.erase(key); 
        // add new node
        else{
            Node* dec_one;
            if (curr->prev == min || curr->prev->freq != frequency - 1){
                dec_one = new Node(frequency - 1, curr->prev, curr);
                curr->prev->next = dec_one;
                curr->prev = dec_one;
            }
            else{
                dec_one = curr->prev;
            }
            dec_one->keys.insert(key);
            m[key] = dec_one;
        }

        // delete node if no key remain
        if (curr->keys.empty()){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }
    
    string getMaxKey() {
        if (max->prev == min) return "";
        return *(max->prev->keys.begin());
    }
    
    string getMinKey() {
        if (min->next == max) return "";
        return *(min->next->keys.begin());
    }
};

int main(){
    // AllOne* allOne = new AllOne();
    // allOne->inc("hello");
    // allOne->inc("hello");
    // cout << allOne->getMaxKey() << " ";
    // cout << allOne->getMinKey() << " ";
    // allOne->inc("leet");
    // cout << allOne->getMaxKey() << " ";
    // cout << allOne->getMinKey() << " ";
    // cout << endl;

    // AllOne* allOne = new AllOne();
    // cout << allOne->getMaxKey() << " ";
    // cout << allOne->getMinKey() << " ";
    // cout << endl;

    AllOne* allOne = new AllOne();
    allOne->inc("a");
    allOne->inc("b");
    allOne->inc("b");
    allOne->inc("c");
    allOne->inc("c");
    allOne->inc("c");
    allOne->dec("b");
    allOne->dec("b");
    cout << allOne->getMinKey() << " ";
    allOne->dec("a");
    cout << allOne->getMaxKey() << " ";
    cout << allOne->getMinKey() << " ";
    cout << endl;
    return 0;
}