#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        for (int i = 2; i <= cost.size(); i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[cost.size()];
    }
};

int main(){
    // vector<int> cost = {10,15,20};
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    Solution S;
    cout << S.minCostClimbingStairs(cost) << endl;
    return 0;
}