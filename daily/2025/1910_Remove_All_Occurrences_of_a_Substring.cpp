#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> computeLPSArray(string& pattern){
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;
        for (int i = 1; i < m; i++){
            while(len > 0 && pattern[i] != pattern[len]) len = lps[len - 1];
            len += (pattern[i] == pattern[len]);
            lps[i] = len;
        }
        return lps;
    }
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();
        vector<int> lps = computeLPSArray(part);
        stack<pair<int,int>> sta;
        int len = 0;
        for (int i = 0; i < n; i++){
            while(len > 0 && s[i] != part[len]) len = lps[len - 1];
            len += (s[i] == part[len]);
            sta.push({i, len});
            if (len == m){
                for (int k = 0; k < m; k++) sta.pop();
                len = (sta.empty())? 0 : sta.top().second;
            }
        }
        string ans;
        while(!sta.empty()){
            ans += s[sta.top().first];
            sta.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    // string s = "axxxxyyyyb";
    // string part = "xy";
    Solution S;
    cout << S.removeOccurrences(s, part) << endl;
    return 0;
}