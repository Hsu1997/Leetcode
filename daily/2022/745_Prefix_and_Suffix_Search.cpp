#include <iostream>
#include <vector>

using namespace std;

class trie{
    struct node{
        vector<node*> ch = vector<node*>(27,0);
        int index = -1;
    };

public:
    node* root;

    trie() {
        root = new node();
    }

    void insert(string s, int index){
        node* temp = root;

        for (auto i : s){
            if (!temp->ch[i - 'a']) temp->ch[i-'a'] = new node();
            temp = temp->ch[i-'a'];
            temp->index = index;
        }
    }

    int search(string s){
        node* temp = root;
        for (auto i : s){
            if (!temp->ch[i-'a']) return -1;
            temp = temp->ch[i-'a'];
        }
        return temp->index;
    }

};

class WordFilter {
public:
    trie* T;
    WordFilter(vector<string>& words) {
        T = new trie();
        int index = 0;
        for (string word : words){
            string temp = '{' + word;
            T->insert(temp, index);
            int l = word.length();
            for (int i = l-1; i >= 0; i--){
                temp = word[i] + temp;
                T->insert(temp, index);
            }
            index++;
        }
    }
    
    int f(string prefix, string suffix) {
        return T->search(suffix + '{' + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main(){
    vector<string> words = {"apple"};
    string prefix = "a";
    string suffix = "e";

    WordFilter* obj = new WordFilter(words);
    int param_1 = obj->f(prefix,suffix);
    cout << param_1 << endl;

    return 0;
}