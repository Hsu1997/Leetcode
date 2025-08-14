#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n-1] = fruits[0][n-1];
        for (int i = 1; i < n; i++){
            dp[i][n-1] = fruits[i][n-1] + max(dp[i-1][n-1], dp[i-1][n-2]);
            for (int j = n - 2; j >= max(i, n - 1 - i); j--){
                dp[i][j] = fruits[i][j] + max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        ans += dp[n-1][n-1];
        // dp = vector<vector<int>>(n, vector<int>(n, 0));
        dp[n-1][0] = fruits[n-1][0];
        for (int j = 1; j < n; j++){
            dp[n-1][j] = fruits[n-1][j] + max(dp[n-1][j-1], dp[n-2][j-1]);
            for (int i = n-2; i >= max(j, n-1-j); i--){
                dp[i][j] = fruits[i][j] + max({dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]});
            }
        }
        ans += dp[n-1][n-1];
        return ans;
    }
};

int main(){
    vector<vector<int>> fruits = {{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}};
    // vector<vector<int>> fruits = {{1,1},{1,1}};
    Solution S;
    cout << S.maxCollectedFruits(fruits) << endl;
    return 0;
}