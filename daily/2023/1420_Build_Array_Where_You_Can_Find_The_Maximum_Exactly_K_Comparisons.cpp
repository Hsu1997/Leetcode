#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        for (int j = 1; j <= m; j++) dp[1][j][1] = 1;
        for (int i = 2; i <= n; i++){
            for (int j = 1; j <= m; j++){
                for (int l = 1; l <= min({i, j, k}); l++){
                    long long temp = 0;
                    temp = j * (long long)dp[i-1][j][l] % MOD;
                    for (int x = 1; x < j; x++) temp = (temp + dp[i-1][x][l-1]) % MOD;
                    dp[i][j][l] = temp;
                }
            }
        }
        long long ans = 0;
        for (int j = 1; j <= m; j++) ans = (ans + dp[n][j][k]) % MOD;
        // for (int i = 1; i <= n; i++){
        //     cout << "length = " << i << endl;
        //     for (int j = 1; j <= m; j++){
        //         for (int l = 1; l <= k; l++) cout << dp[i][j][l] << " ";
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};

int main(){
    int n = 2;
    int m = 3;
    int k = 1;
    // int n = 5;
    // int m = 2;
    // int k = 3;
    // int n = 9;
    // int m = 1;
    // int k = 1;
    Solution S;
    cout << S.numOfArrays(n, m, k) << endl;
    return 0;
}