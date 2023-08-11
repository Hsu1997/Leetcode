#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (auto c : coins){
            for (int i = c; i <= amount; i++){
                dp[i] += dp[i-c];
            }
        }
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        return dp[amount];
    }
};

int main(){
    int amount = 5;
    vector<int> coins = {1,2,5};
    Solution S;
    cout << S.change(amount, coins) << endl;
    return 0;
}