#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int len = 2; len <= n; len++){
            for (int left = 0; left <= n - len; left++){
                int right = left + len - 1;
                int start = -1;
                for (int i = left; i < right; i++){
                    if (start == -1 && s[i] != s[right]) start = i;
                    if (start != -1) dp[left][right] = min(dp[left][right], 1 + dp[start][i] + dp[i+1][right]);
                }
                if (start == -1) dp[left][right] = 0;
            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp[0][n-1] + 1;
    }
};

int main(){
    string s = "aaabbb";
    // string s = "aba";
    Solution S;
    cout << S.strangePrinter(s) << endl;
    return 0;
}