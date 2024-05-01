#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void PrintTable(vector<vector<vector<int>>>& table){
        int is = table.size();
        int js = table[0].size();
        int ks = table[0][0].size();
        for (int k = 0; k < ks; k++){
            for (int i = 0; i < is; i++){
                for (int j = 0; j < js; j++) cout << table[i][j][k] << " ";
                cout << endl;
            }
            cout << endl;
        }
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, -1)));
        if (houses[0] == 0){
            for (int j = 0; j < n; j++){
                dp[0][j][0] = cost[0][j];
            }
        }
        else dp[0][houses[0]-1][0] = 0;

        for(int i = 1; i < m; i++){
            if (houses[i] == 0){
                for (int j = 0; j < n; j++) if(dp[i-1][j][0] != -1) dp[i][j][0] = dp[i-1][j][0] + cost[i][j];

                for (int k = 1; k < target; k++){
                    for (int j = 0; j < n; j++){
                        dp[i][j][k] = (dp[i-1][j][k] == -1)? -1 : dp[i-1][j][k] + cost[i][j];
                        for (int w = 0; w < n; w++){
                            if (w == j || dp[i-1][w][k-1] == -1) continue;
                            dp[i][j][k] = (dp[i][j][k] == -1)? dp[i-1][w][k-1]+cost[i][j] : min(dp[i][j][k], dp[i-1][w][k-1]+cost[i][j]);
                        }
                    }
                }
            }
            else{
                int color = houses[i]-1;
                if(dp[i-1][color][0] != -1) dp[i][color][0] = dp[i-1][color][0];

                for (int k = 1; k < target; k++){
                    dp[i][color][k] = (dp[i-1][color][k] == -1)? -1 : dp[i-1][color][k];
                    for (int w = 0; w < n; w++){
                        if (w == color || dp[i-1][w][k-1] == -1) continue;
                        dp[i][color][k] = (dp[i][color][k] == -1)? dp[i-1][w][k-1] : min(dp[i][color][k], dp[i-1][w][k-1]);
                    }
                }
            }
        }
        
        PrintTable(dp);

        int ans = INT_MAX;
        for (int j = 0; j < n; j++){
            if (dp[m-1][j][target-1] != -1) ans = min(ans, dp[m-1][j][target-1]);
        }
        return (ans == INT_MAX)? -1: ans; 
    }
};

int main(){
    // vector<int> houses = {0,0,0,0,0};
    // vector<vector<int>> cost = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    // int m = 5;
    // int n = 2;
    // int target = 3;

    // vector<int> houses = {0,2,1,2,0};
    // vector<vector<int>> cost = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    // int m = 5;
    // int n = 2;
    // int target = 3;

    // vector<int> houses = {3,1,2,3};
    // vector<vector<int>> cost = {{1,1,1},{1,1,1},{1,1,1},{1,1,1}};
    // int m = 4;
    // int n = 3;
    // int target = 3;

    vector<int> houses = {2,3,0};
    vector<vector<int>> cost = {{5,2,3},{3,4,1},{1,2,1}};
    int m = 3;
    int n = 3;
    int target = 3;

    Solution S;
    cout << S.minCost(houses, cost, m, n, target) << endl;
}