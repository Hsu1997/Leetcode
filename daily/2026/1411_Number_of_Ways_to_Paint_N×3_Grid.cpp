#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        long long ans = 0;
        vector<long long> dp(12, 1);
        for (int i = 2; i <= n; i++){
            vector<long long> temp(12, 0);
            temp[0] = (dp[4] + dp[5] + dp[7] + dp[8] + dp[9]) % mod;
            temp[1] = (dp[4] + dp[6] + dp[7] + dp[8]) % mod;
            temp[2] = (dp[4] + dp[5] + dp[8] + dp[9] + dp[11]) % mod;
            temp[3] = (dp[5] + dp[9] + dp[10] + dp[11]) % mod;
            temp[4] = (dp[0] + dp[1] + dp[2] + dp[10] + dp[11]) % mod;
            temp[5] = (dp[0] + dp[2] + dp[3] + dp[10]) % mod;
            temp[6] = (dp[1] + dp[8] + dp[9] + dp[11]) % mod;
            temp[7] = (dp[0] + dp[1] + dp[9] + dp[10] + dp[11]) % mod;
            temp[8] = (dp[0] + dp[1] + dp[2] + dp[6]) % mod;
            temp[9] = (dp[0] + dp[2] + dp[3] + dp[6] + dp[7]) % mod;
            temp[10] = (dp[3] + dp[4] + dp[5] + dp[7]) % mod;
            temp[11] =  (dp[2] + dp[3] + dp[4] + dp[6] + dp[7]) % mod;
            dp = temp;
        }
        for (long long i : dp) ans = (ans + i) % mod;
        return ans;
    }
};

int main(){
    int n = 1;
    // int n = 2;
    // int n = 10;
    // int n = 1000;
    // int n = 5000;
    Solution S;
    cout << S.numOfWays(n) << endl;
    return 0;
}