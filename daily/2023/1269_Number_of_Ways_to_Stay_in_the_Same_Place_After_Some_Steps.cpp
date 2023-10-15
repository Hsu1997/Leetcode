#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9 + 7;
        arrLen = min(steps, arrLen);
        vector<vector<int>> dp(2, vector<int>(arrLen, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++){
            for (int j = 0; j < arrLen; j++){
                dp[i%2][j] = dp[(i-1)%2][j];
                if (j > 0) dp[i%2][j] = (dp[i%2][j] + dp[(i-1)%2][j-1]) % mod;
                if (j < arrLen - 1) dp[i%2][j] = (dp[i%2][j] + dp[(i-1)%2][j+1]) % mod;
            }
        }
        return dp[steps%2][0];
    }
};

int main(){
    int steps = 3;
    int arrLen = 2;
    // int steps = 2;
    // int arrLen = 4;
    // int steps = 4;
    // int arrLen = 2;
    Solution S;
    cout << S.numWays(steps, arrLen) << endl;
    return 0;
}