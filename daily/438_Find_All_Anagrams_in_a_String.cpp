#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> goal(26,0);
        vector<int> count(26,0);
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        int acc = 0;
        for (auto i : p) goal[i-'a']++;
        for (int i = 0; i < n; i++){
            count[s[i]-'a']++;
            if (count[s[i]-'a'] <= goal[s[i]-'a']) acc++;
            
            // cout << i << " : ";
            // for (auto i : count) cout << i << " ";
            // cout << " => " << acc << endl;
            
            if (acc == m) ans.push_back(i-m+1);
            if (i-m+1 >= 0){
                count[s[i-m+1]-'a']--;
                if (count[s[i-m+1]-'a'] < goal[s[i-m+1]-'a']) acc--; 
            }
        }
        return ans;
    }
};

int main(){
    string s = "cbaebabacd";
    string p = "abc";
    // string s = "abab";
    // string p = "ab";
    Solution S;
    vector<int> ans = S.findAnagrams(s,p);
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}