#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
public:
    struct trie{
        unordered_map<int,trie*> m;
        bool is_word = false;
    };
    
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
            for (int j = i; j < s.length(); j++){
                if (i == 0 || dp[i-1]) dp[j] = dp[j] || T.find_word(s.substr(i, j-i+1));
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