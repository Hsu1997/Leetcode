#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Trie {
public:
    struct node{
        vector<node*> next;
        bool is_word = false;
        
        node(){
            next = vector<node*>(26,nullptr);
        }
    };

    node* root;

    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* temp = root;
        for (auto i : word){
            if (temp->next[i-'a'] == nullptr) temp->next[i-'a'] = new node();
            temp = temp->next[i-'a'];
        }
        temp->is_word = true;
    }
    
    bool search(string word) {
        node* temp = root;
        for (auto i : word){
            if (temp->next[i-'a'] == nullptr) return false;
            temp = temp->next[i-'a'];
        }
        return temp->is_word;
    }
    
    bool startsWith(string prefix) {
        node* temp = root;
        for (auto i : prefix){
            if (temp->next[i-'a'] == nullptr) return false;
            temp = temp->next[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << " "; // return True
    cout << trie->search("app") << " "; // return False
    cout << trie->startsWith("app") << " "; // return True
    trie->insert("app");
    cout << trie->search("app") << " "; // return True
    cout << endl;
    return 0;
}