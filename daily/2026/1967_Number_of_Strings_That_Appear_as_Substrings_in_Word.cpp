#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> lcp(string& s){
        int m = s.length();
        vector<int> v(m);
        v[0] = 0;
        int ptr = 0;
        for (int i = 1; i < m; i++){
            while(ptr > 0 && s[i] != s[ptr]) ptr = v[ptr - 1];
            if (s[i] == s[ptr]) ptr++;
            v[i] = ptr;
        }
        return v;
    }
    bool isSubstr(string& pattern, string& word){
        int n = pattern.length();
        int m = word.length();
        vector<int> l = lcp(pattern);
        int ptr = 0;
        for (int i = 0; i < m; i++){
            while(ptr > 0 && word[i] != pattern[ptr]) ptr = l[ptr - 1];
            if (word[i] == pattern[ptr]) ptr++;
            if (ptr == n) return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int m = word.length();
        int n = patterns.size();
        int ans = 0;
        for (string& pattern : patterns){
            if (isSubstr(pattern, word)) ans++;
        }
        return ans;
    }
};

int main(){
    vector<string> patterns = {"a","abc","bc","d"};
    string word = "abc";
    // vector<string> patterns = {"a","b","c"};
    // string word = "aaaaabbbbb";
    // vector<string> patterns = {"a","a","a"};
    // string word = "ab";
    // vector<string> patterns = {"ok","alkmfp","ralkm","cw","lk","rusmjlugnm","pbhjybt","fpbh","posscsob","dkbcxzqdh","rrlncoytcnsg"};
    // string word = "vralkmfpbhjybt";
    Solution S;
    cout << S.numOfStrings(patterns, word) << endl;
    return 0;
}