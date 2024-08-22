#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        string str;
        str += s[0];
        for (int i = 1; i < s.length(); i++) if (s[i] != s[i-1]) str += s[i];
        // cout << str << endl;
        s = str;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int len = 2; len <= n; len++){
            for (int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                int start = (s[i] == s[j])? i + 1 : i;
                for (int mid = start; mid < j; mid++) dp[i][j] = min(dp[i][j], 1 + dp[start][mid] + dp[mid+1][j]);
            }
        }
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