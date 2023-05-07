#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        for (int i = 1; i <= n; i++){
            for (int coins = 0; coins <= k; coins++){
                int current_sum = 0;
                for (int current_pile_coins = 0; current_pile_coins <= min((int)piles[i-1].size(), coins); current_pile_coins++){
                    if (current_pile_coins) current_sum += piles[i-1][current_pile_coins-1];
                    dp[i][coins] = max(dp[i][coins], dp[i-1][coins - current_pile_coins] + current_sum);
                }
            }
        }
        return dp[n][k];
    }
};

int main(){
    vector<vector<int>> piles = {{1,100,3},{7,8,9}};
    int k = 2;
    Solution S;
    cout << S.maxValueOfCoins(piles, k) << endl;
    return 0;
}