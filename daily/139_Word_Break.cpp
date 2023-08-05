#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct trie{
    unordered_map<int,trie*> m;
    bool is_word = false;
};

class Trie {
public:
    
    trie* root = new trie();

    void insert_word(string s){
        trie* temp = root;
        for (auto i : s){
            if (!temp->m.count(i-'a')) temp->m[i-'a'] = new trie();
            temp = temp->m[i-'a'];
        }
        temp->is_word = true;
    }

    bool find_word(string s){
        trie* temp = root;
        for (auto i : s){
            if (!temp->m.count(i-'a')) return false;
            temp = temp->m[i-'a'];
        }
        return temp->is_word;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie T;
        for (string s : wordDict) T.insert_word(s);
        vector<bool> dp(s.length(), false);
        for (int i = 0; i < s.length(); i++){
            if (i == 0 || dp[i-1]){
                trie* temp = T.root;
                for (int j = i; j < s.length(); j++){
                    if (!temp->m.count(s[j]-'a')) break;
                    temp = temp->m[s[j]-'a'];
                    if (temp->is_word) dp[j] = true;
                }

            }
        }
        return dp[s.length()-1];
    }
};

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    Solution S;
    cout << S.wordBreak(s, wordDict) << endl;
    return 0;
}