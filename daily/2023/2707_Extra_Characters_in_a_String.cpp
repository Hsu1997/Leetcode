#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct node{
    unordered_map<char,node*> m;
    bool is_word = false;
    node(){};
};

class Trie{
public:
    node* root;

    Trie(){
        root = new node();
    }

    void insert_word(string &s){
        node* temp = root;
        for (auto i : s){
            if (!temp->m.count(i)) temp->m[i] = new node();
            temp = temp->m[i];
        }
        temp->is_word = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        Trie* T = new Trie();
        for (auto s : dictionary) T->insert_word(s);
        vector<int> dp(n+1, 0);

        for (int i = n-1; i >= 0; i--){
            dp[i] = dp[i+1]+1;
            node* temp = T->root;
            for (int j = i; j < n; j++){
                if (!temp->m.count(s[j])) break;
                temp = temp->m[s[j]];
                if (temp->is_word) dp[i] = min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
    }
};

int main(){
    string s = "leetscode";
    vector<string> dictionary = {"leet","code","leetcode"};
    // string s = "sayhelloworld";
    // vector<string> dictionary = {"hello","world"};
    Solution S;
    cout << S.minExtraChar(s, dictionary) << endl;
    return 0;
}