#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string s1;
    string s2;
    vector<vector<vector<bool>>> dp;

    bool isScramble(string _s1, string _s2) {
        s1 = _s1;
        s2 = _s2;
        int n = s1.length();
        dp = vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n+1,false)));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (s1[i] == s2[j]) dp[i][j][1] = true;
            }
        }
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++){
        //         cout << dp[i][j][1] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for (int l = 2; l <= n; l++){
            for (int i = 0; i < n + 1 - l; i++){
                for (int j = 0; j < n + 1 - l; j++){
                    for (int b = 1; b < l; b++){
                        dp[i][j][l] = dp[i][j][l] || (dp[i][j][b] && dp[i+b][j+b][l-b]);
                        dp[i][j][l] = dp[i][j][l] || (dp[i][j+b][l-b] && dp[i+l-b][j][b]);
                        if (dp[i][j][l]) break;
                    }
                    // cout << dp[i][j][1] << " ";
                }
                // cout << endl;
            }
            // cout << endl;
        }

        return dp[0][0][n];
    }
};

int main(){
    string s1 = "great";
    string s2 = "rgeat";
    // string s1 = "abcde";
    // string s2 = "caebd";
    // string s1 = "a";
    // string s2 = "a";
    // string s1 = "abcdbdacbdac";
    // string s2 = "bdacabcdbdac";
    // string s1 = "abc";
    // string s2 = "cba";
    Solution S;
    cout << S.isScramble(s1, s2) << endl;
    return 0;
}