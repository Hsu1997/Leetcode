#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    // not need visited because it can't be reuse by two side (path need to be increasment)
    vector<vector<int>> dp;
    vector<int> row_offset = {-1,0,1,0};
    vector<int> col_offset = {0,1,0,-1};

    int dfs(int x, int y, vector<vector<int>>& matrix){
        // cout << "dfs(" << x << ", " << y << ")" << endl;
        if (dp[x][y] > 0) return dp[x][y];

        for (int j = 0; j < 4; j++){
            int nx = x + row_offset[j];
            int ny = y + col_offset[j];
            // cout << "(" << nx << ", " << ny << ")" << " ";
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] < matrix[x][y]){
                // cout << " get ";
                dp[x][y] = max(dp[x][y], dfs(nx, ny, matrix));
            }
        }
        dp[x][y]++;
        // cout << endl << "dp[" << x << "][" << y << "] = " << dp[x][y] << endl;
        return dp[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        if (m == 0) return 0;

        dp = vector<vector<int>>(m, vector<int>(n,0));
        int ans = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return ans;
    }
};

int main(){
    // vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    vector<vector<int>> matrix = {{0,1,2,3,4,5,6,7,8,9},{19,18,17,16,15,14,13,12,11,10},{20,21,22,23,24,25,26,27,28,29},{39,38,37,36,35,34,33,32,31,30},{40,41,42,43,44,45,46,47,48,49},{59,58,57,56,55,54,53,52,51,50},{60,61,62,63,64,65,66,67,68,69},{79,78,77,76,75,74,73,72,71,70},{80,81,82,83,84,85,86,87,88,89},{99,98,97,96,95,94,93,92,91,90},{100,101,102,103,104,105,106,107,108,109},{119,118,117,116,115,114,113,112,111,110},{120,121,122,123,124,125,126,127,128,129},{139,138,137,136,135,134,133,132,131,130},{0,0,0,0,0,0,0,0,0,0}};
    Solution S;
    cout << S.longestIncreasingPath(matrix) << endl;
    return 0;
}

