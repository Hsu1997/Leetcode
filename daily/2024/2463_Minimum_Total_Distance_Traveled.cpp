#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        while(!factory.empty() && factory[0][1] == 0) factory.erase(factory.begin());
        int r = robot.size();
        int f = factory.size();
        vector<vector<long long>> dp(f, vector<long long>(r, 1e12));
        dp[0][0] = abs(factory[0][0] - robot[0]);
        for (int l = 1; l < min(r, factory[0][1]); l++){
            dp[0][l] = dp[0][l-1] + abs(factory[0][0] - robot[l]);
        }
        for (int i = 1; i < f; i++){
            for (int j = 0; j < r; j++){
                dp[i][j] = dp[i-1][j];
                int limit = factory[i][1];
                long long acc = 0;
                for (int r = 0; r < limit && j - r >= 0; r++){
                    acc += abs(factory[i][0] - robot[j-r]);
                    if (j - r - 1 < 0){
                        dp[i][j] = min(dp[i][j], acc);
                    }
                    else{
                        if (dp[i-1][j-r-1] == 1e12) continue;
                        dp[i][j] = min(dp[i][j], dp[i-1][j-r-1] + acc);
                    }
                }
                if (dp[i][j] == 1e12) break;
            }
        }
        return dp[f-1][r-1];
    }
};

int main(){
    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};
    // vector<int> robot = {1,-1};
    // vector<vector<int>> factory = {{-2,1},{2,1}};
    // vector<int> robot = {1,-1};
    // vector<vector<int>> factory = {{-2,1},{2,1},{3,0}};
    Solution S;
    cout << S.minimumTotalDistance(robot, factory) << endl;
    return 0;
}