#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        int mod = 1e9+7;
        for (int i = 1; i <= min(k, target); i++) dp[0][i] = 1;
        for (int i = 1; i < n; i++){
            long accumulate = 0;
            for (int j = i+1; j <= target; j++){
                accumulate = (accumulate + dp[i-1][j-1]) % mod;
                if (j - k > 0) accumulate -= dp[i-1][j-k-1];
                if (accumulate < 0) accumulate += mod;
                dp[i][j] = accumulate;
            }
        }

        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        return dp[n-1][target];
    }
};

int main(){
    // int n = 2;
    // int k = 6;
    // int target = 7;
    int n = 30;
    int k = 30;
    int target = 500;
    Solution S;
    cout << S.numRollsToTarget(n, k, target) << endl;
    return 0;
}