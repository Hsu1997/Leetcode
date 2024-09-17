#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void split_word(string& s, unordered_map<string, int>& m){
        int i = 0;
        while(i < s.length()){
            int temp = i;
            while(i < s.length() && s[i] != ' ') i++;
            m[s.substr(temp, i - temp)]++;
            i++;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        split_word(s1, m1);
        split_word(s2, m2);
        vector<string> ans;
        for (auto i : m1) if (i.second == 1 && m2.find(i.first) == m2.end()) ans.push_back(i.first);
        for (auto i : m2) if (i.second == 1 && m1.find(i.first) == m1.end()) ans.push_back(i.first);
        return ans;
    }
};

int main(){
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    // string s1 = "apple apple";
    // string s2 = "banana";
    Solution S;
    vector<string> ans = S.uncommonFromSentences(s1, s2);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}