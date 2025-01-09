#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Node{
    array<Node*, 26> child;
    int count;
    Node(): count(0){
        child.fill(nullptr);
    }
};

class Trie{
public:
    Node* root;
    Trie(){root = new Node();}

    void insert(string& s){
        Node* curr = root;
        for (char c : s){
            if (!curr->child[c-'a']) curr->child[c-'a'] = new Node();
            curr = curr->child[c-'a'];
            curr->count++;
        }
    }
    int query(string& s){
        Node* curr = root;
        for (char c : s){
            if (!curr->child[c-'a']) return 0;
            curr = curr->child[c-'a'];
        }
        return curr->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie T;
        for (string& s : words) T.insert(s);
        return T.query(pref);
    }
};

int main(){
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";
    // vector<string> words = {"leetcode","win","loops","success"};
    // string pref = "code";
    Solution S;
    cout << S.prefixCount(words, pref) << endl;
    return 0;
}