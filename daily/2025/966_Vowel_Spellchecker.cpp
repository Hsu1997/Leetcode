#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string to_lower(string& s){
        string ans = s;
        for (int i = 0; i < ans.length(); i++){
            if (ans[i] >= 'A' && ans[i] <= 'Z') ans[i] = 'a' + ans[i] - 'A';
        }
        return ans;
    }
    string maskVowel(string& s){
        string ans = to_lower(s);
        for (int i = 0; i < ans.length(); i++){
            if (is_vowel(ans[i])) ans[i] = '*';
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> equal;
        unordered_map<string, int> cap;
        unordered_map<string, int> v;
        for (int i = 0; i < wordlist.size(); i++){
            string s = wordlist[i];
            if (equal.find(s) == equal.end()) equal[s] = i;
            string l = to_lower(s);
            if (cap.find(l) == cap.end()) cap[l] = i;
            string m = maskVowel(s);
            if (v.find(m) == v.end()) v[m] = i;
        }
        vector<string> ans;
        for (string query : queries){
            if (equal.find(query) != equal.end()) ans.push_back(wordlist[equal[query]]);
            else if (cap.find(to_lower(query)) != cap.end()) ans.push_back(wordlist[cap[to_lower(query)]]);
            else if (v.find(maskVowel(query)) != v.end()) ans.push_back(wordlist[v[maskVowel(query)]]);
            else ans.push_back("");
        }
        return ans;
    }
};

int main(){
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    // vector<string> wordlist = {"yellow"};
    // vector<string> queries = {"YellOw"};
    Solution S;
    vector<string> ans = S.spellchecker(wordlist, queries);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}