#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ans = 0;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;

        int mod = 1e9+7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] += 1, dp[i][n-1] += 1;
        for (int j = 0; j < n; j++) dp[0][j] += 1, dp[m-1][j] += 1;
        
        ans += dp[startRow][startColumn];
        
        vector<int> x_move = {-1,0,1,0};
        vector<int> y_move = {0,1,0,-1};
        
        for(int move = 2; move <= maxMove; move++){
            vector<vector<int>> dp_temp(m, vector<int>(n, 0));
            
            // for (auto i : dp){
            //     for (auto j : i) cout << j << " ";
            //     cout << endl;
            // }
            // cout << endl;
            
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    for (int d = 0; d < 4; d++){
                        int new_x = i + x_move[d];
                        int new_y = j + y_move[d];
                        if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) dp_temp[i][j] += dp[new_x][new_y];
                        dp_temp[i][j] %= mod;
                    }
                }
            }
            ans += dp_temp[startRow][startColumn];
            ans %= mod;
            swap(dp, dp_temp);
        }

        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        // cout << endl;

        return ans;
    }
};

int main(){
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0;
    int startColumn = 0;
    // int m = 8;
    // int n = 7;
    // int maxMove = 16;
    // int startRow = 1;
    // int startColumn = 5;
    Solution S;
    cout << S.findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}