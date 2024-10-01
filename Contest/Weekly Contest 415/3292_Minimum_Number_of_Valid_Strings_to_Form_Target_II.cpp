#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> KMP(const string& s){
        vector<int> lps(s.length());
        int len = 0;
        for (int i = 1; i < s.length(); i++){
            while(len > 0 && s[i] != s[len]){
                len = lps[len-1];
            }
            if (s[i] == s[len]) len++;
            lps[i] = len;
        }
        return lps;
    }

    int minValidStrings(vector<string>& words, string target) {
        // calculate each position the longest prefix length, from back to front, we can make sure match longer than we can is better.
        // Because we match longer prefix, doesn't influence previous prefix valid or invalid, at most substract previous prefix length.
        int t = target.length();
        vector<int> dp(t, 0);
        for (string& word : words){
            int w = word.length();
            vector<int> temp = KMP(word + "#" + target);
            for (int i = 0; i < t; i++){
                dp[i] = max(dp[i], temp[w + 1 + i]);
            }
        }
        t--;
        int ans = 0;
        while(t >= 0 && dp[t]){
            t -= dp[t];
            ans++;
        }
        return (t == -1)? ans : -1;
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