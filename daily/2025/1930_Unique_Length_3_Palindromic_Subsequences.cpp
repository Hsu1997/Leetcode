#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char,int> m;
        for (char c : s) m[c]++;
        for (char c = 'a'; c <= 'z'; c++){
            unordered_map<char,int> count = m;
            int l = 0;
            int r = n-1;
            while(l < n && s[l] != c){
                count[s[l]]--;
                l++;
            }
            while(r > l && s[r] != c){
                count[s[r]]--;
                r--;
            }
            if (r == l) continue;
            int temp = 0;
            count[c] -= 2;
            for (auto i : count) if (i.second > 0) temp ++;
            ans += temp;
        }
        return ans;
    }
};

int main(){
    string s = "aabca";
    // string s = "adc";
    // string s = "bbcbaba";
    Solution S;
    cout << S.countPalindromicSubsequence(s) << endl;
    return 0;
}