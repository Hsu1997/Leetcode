#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for (int index = 0; index < n; index++){
            for (int remain = n; remain >= 0; remain--){
                int paint = cost[index] + dp[max(0,remain - 1 - time[index])];
                dp[remain] = min(dp[remain], paint);
            }
            // for (auto i : dp) cout << i << " ";
            // cout << endl;
        }
        return dp[n];
    }
};

int main(){
    vector<int> cost = {1,2,3,2};
    vector<int> time = {1,2,3,2};
    // vector<int> cost = {2,3,4,2};
    // vector<int> time = {1,1,1,1};
    Solution S;
    cout << S.paintWalls(cost, time) << endl;
    return 0;
}