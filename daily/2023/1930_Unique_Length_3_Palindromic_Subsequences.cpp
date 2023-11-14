#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (int i = 0; i < 26; i++){
            char temp = 'a' + i;
            int l = 0;
            int r = s.length()-1;
            while(l < r && s[l] != temp) l++;
            if (l > r) continue;
            while(r >= 0 && s[r] != temp) r--;
            if (r < 0 || l == r) continue;
            int count = 0;
            for (int k = l+1; k < r; k++) count |= 1 << (s[k]-'a');
            ans += (int)__builtin_popcount(count);
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