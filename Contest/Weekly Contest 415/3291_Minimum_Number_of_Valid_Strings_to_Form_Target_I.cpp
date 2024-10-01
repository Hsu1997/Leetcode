#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node{
    vector<Node*> child;
    bool is_word;
    Node() : is_word(false), child(vector<Node*>(26)) {};
};

class Trie{
public:
    Node* root;
    Trie() : root(new Node()) {};
    void add_word(string& s){
        Node* temp = root;
        for (char c : s){
            if (!temp->child[c-'a'])
                temp->child[c-'a'] = new Node();
            temp = temp->child[c-'a'];
        }
        temp->is_word = true;
    }
    bool find_word(string& s){
        Node* temp = root;
        for (char c : s){
            if (!temp->child[c-'a']) 
                return false;
            temp = temp->child[c-'a'];
        }
        return true;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie prefix_T;
        for (string& word : words){
            prefix_T.add_word(word);
        }
        vector<int> dp(target.length() + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < target.length(); i++){
            if (dp[i] == INT_MAX) continue;
            Node* temp = prefix_T.root;
            for (int j = i; j < target.length(); j++){
                if (!temp->child[target[j] - 'a']) break;
                temp = temp->child[target[j] - 'a'];
                dp[j+1] = min(dp[j+1], dp[i] + 1);
            }
        }
        return (dp.back() == INT_MAX)? -1 : dp.back();
    }
};

int main(){
    vector<string> words = {"abc","aaaaa","bcdef"};
    string target = "aabcdabc";
    // vector<string> words = {"abababab","ab"};
    // string target = "ababaababa";
    // vector<string> words = {"abcdef"};
    // string target = "xyz";
    Solution S;
    cout << S.minValidStrings(words, target) << endl;
    return 0;
}