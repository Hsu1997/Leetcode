#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s_rev = s;
        reverse(s.begin(), s.end());
        vector<int> dp(n, 0);
        vector<int> temp(n, 0);
        temp[0] = (s_rev[0] == s[0]);
        for (int j = 1; j < n; j++) temp[j] = (s_rev[j] == s[0]) || temp[j-1];
        for (int i = 1; i < n; i++){
            dp[0] = (s[i] == s_rev[0]) || temp[0];
            for (int j = 1; j < n; j++){
                if (s[i] == s_rev[j]) dp[j] = temp[j-1] + 1;
                else dp[j] = max(temp[j], dp[j-1]);
            }
            swap(dp, temp);
        }
        return temp[n-1];
    }
};

int main(){
    string s = "bbbab";
    // string s = "cbbd";
    Solution S;
    cout << S.longestPalindromeSubseq(s) << endl;
    return 0;
}