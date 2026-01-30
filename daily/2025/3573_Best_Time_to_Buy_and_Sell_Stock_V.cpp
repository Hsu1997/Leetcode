#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // [idx][transaction][empty: 0, short: 1, long: 2]
        // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(3, -1e9)));
        // dp[0][0][0] = 0;
        // dp[0][0][1] = prices[0];
        // dp[0][0][2] = -prices[0];
        // for (int i = 1; i < n; i++){
            //     for (int j = 0; j <= k; j++){
                //         dp[i][j][0] = dp[i-1][j][0];
                //         if (j > 0) dp[i][j][0] = max({dp[i][j][0], dp[i-1][j-1][1] - prices[i], dp[i-1][j-1][2] + prices[i]});
                //         dp[i][j][1] = max(dp[i-1][j][0] + prices[i], dp[i-1][j][1]);
                //         dp[i][j][2] = max(dp[i-1][j][0] - prices[i], dp[i-1][j][2]);
                //     }
                // }
                // long long ans = 0;
                // for (int j = 0; j <= k; j++) ans = max(ans, dp[n-1][j][0]);
            // return ans;

        // [idx][transaction][empty: 0, short: 1, long: 2]
        vector<vector<long long>> dp(k + 1, vector<long long>(3, 0));
        for (int j = 0; j <= k; j++){
            dp[j][1] = prices[0];
            dp[j][2] = -prices[0];
        }
        for (int i = 1; i < n; i++){
            for (int j = k; j > 0; j--){
                dp[j][2] = max(dp[j][2], dp[j][0] - prices[i]);
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
                dp[j][0] = max({dp[j][0], dp[j-1][1] - prices[i], dp[j-1][2] + prices[i]});
            }
            dp[0][2] = max(dp[0][2], 1LL * -prices[i]);
            dp[0][1] = max(dp[0][1], 1LL * prices[i]);
        }
        return dp[k][0];
    }
};

int main(){
    vector<int> prices = {1,7,9,8,2};
    int k = 2;
    // vector<int> prices = {12,16,19,19,8,1,19,13,9};
    // int k = 3;
    // vector<int> prices = {14,6,10,19};
    // int k = 1;
    Solution S;
    cout << S.maximumProfit(prices, k) << endl;
    return 0;
}