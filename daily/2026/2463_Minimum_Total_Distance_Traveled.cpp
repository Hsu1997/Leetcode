#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MAX / 2));
        for (int f = 0; f < m; f++){
            int pos = factory[f][0];
            int limit = factory[f][1];
            long long cost = 0;
            for (int cap = 0; cap < limit; cap++){
                cost += abs(pos - robot[cap]);
                dp[f][cap] = cost;
                if (f > 0) dp[f][cap] = min(dp[f][cap], dp[f-1][cap]);
            }
            if (f == 0) continue;
            for (int start = 1; start < n; start++){
                cost = 0;
                dp[f][start] = min(dp[f][start], dp[f-1][start]);
                for (int cap = 0; cap < limit; cap++){
                    if (start + cap == n) break;
                    cost += abs(pos - robot[start + cap]);
                    dp[f][start + cap] = min(dp[f][start + cap], dp[f-1][start - 1] + cost);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(){
    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};
    // vector<int> robot = {1,-1};
    // vector<vector<int>> factory = {{-2,1},{2,1}};
    // vector<int> robot = {1,-1};
    // vector<vector<int>> factory = {{-2,1},{2,1},{3,0}};
    // vector<int> robot = {9,11,99,101};
    // vector<vector<int>> factory = {{10,1},{7,1},{14,1},{100,1},{96,1},{103,1}};
    Solution S;
    cout << S.minimumTotalDistance(robot, factory) << endl;
    return 0;
}