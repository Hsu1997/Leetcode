#include <iostream>
#include <vector>
#include <string>

using namespace std;

class trie{
public:

    struct node{
        vector<node*> ch = vector<node*>(26,NULL);
    };

    node* root;
    int words = 0;
    int total_length = 0;

    trie(){
        root = new node;
    }

    void insert(string s){
        // cout << "insert " << s << " : ";
        node* now = root;
        bool new_word = false;
        for (char i : s){
            if (now->ch[i-'a'] == NULL){
                now->ch[i-'a'] = new node();
                new_word = true;
            }
            now = now->ch[i-'a'];
        }
        if (new_word){
            words++;
            total_length += s.length();
        }
        // cout << total_length << " " << words << endl;
    } 
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        trie T;

        for (int i = 7; i > 0; i--){
            // cout << "i = " << i << endl;
            for (string s : words){
                // cout << "now looking at " << s << endl;
                if (s.length() == i){
                    string temp = s;
                    reverse(temp.begin(), temp.end());
                    // cout << "temp = " << temp << endl;
                    T.insert(temp);
                }
            }
        }
        // cout << T.total_length << " " << T.words << endl;
        return T.total_length + T.words;   
    }
};

int main(){
    vector<string> words = {"time", "me", "bell"};
    // vector<string> words = {"t"};
    Solution S;
    cout << S.minimumLengthEncoding(words) << endl;
}