#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(5,0));
        dp[0] = {1,1,1,1,1};

        for (int i = 1; i < n; i++){
            dp[i][0] = ((dp[i-1][1] + dp[i-1][2]) % mod + dp[i-1][4] % mod) % mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % mod;
            dp[i][3] = dp[i-1][2] % mod;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % mod;
        }

        int ans = 0;
        for (int i = 0; i < 5; i++) ans = (ans + dp[n-1][i]) % mod;
        return ans;
    }
};

int main(){
    int n = 20000;
    Solution S;
    cout << S.countVowelPermutation(n) << endl;
    return 0;
}