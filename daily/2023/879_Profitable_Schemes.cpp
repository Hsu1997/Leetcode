#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9+7;
        int ans = 0;
        vector<vector<int>> dp(minProfit+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < group.size(); i++){
            int rev = profit[i];
            int cost = group[i];
            // for (auto k : dp){
            //     for (auto j : k) cout << j << " ";
            //     cout << endl;
            // }
            // cout << "round : " << i << ", profit = " << rev << ", cost = " << cost << endl;
            for (int acc_pro = minProfit; acc_pro >= 0; acc_pro--){
                for (int acc_cost = n - cost; acc_cost >= 0; acc_cost--){
                    if (acc_pro + rev >= minProfit) dp[minProfit][acc_cost + cost] = (dp[minProfit][acc_cost + cost] + dp[acc_pro][acc_cost]) % mod;
                    else dp[acc_pro + rev][acc_cost + cost] = (dp[acc_pro + rev][acc_cost + cost] + dp[acc_pro][acc_cost]) % mod;
                }
            }
        }
        // for (auto k : dp){
        //     for (auto j : k) cout << j << " ";
        //     cout << endl;
        // }
        for (auto i : dp[minProfit]) ans = (ans + i) % mod;
        return ans;
    }
};

int main(){
    // int n = 5;
    // int minProfit = 3;
    // vector<int> group = {2,2};
    // vector<int> profit = {2,3};
    int n = 10;
    int minProfit = 5;
    vector<int> group = {2,3,5};
    vector<int> profit = {6,7,8};
    Solution S;
    cout << S.profitableSchemes(n, minProfit, group, profit) << endl;
    return 0;
}