#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, INT_MAX);
        int dp[amount+1]; // array is faster than vector
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++){
            dp[i] = INT_MAX;
            for (int coin : coins){
                if (i - coin < 0) break;
                if (dp[i-coin] != INT_MAX) dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return (dp[amount] == INT_MAX)? -1 : dp[amount];
    }
};

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    Solution S;
    cout << S.coinChange(coins, amount) << endl;
    return 0;
}