#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n,0));
        int ans = INT_MIN;
        for (int i = 1; i <= m; i++){
            for (int j = 0; j < n; j++) dp[i][j] = dp[i-1][j] + matrix[i-1][j];
        }

        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        // row : i ~ p
        // col : j ~ l
        for (int i = 1; i <= m; i++){
            for (int p = i; p <= m; p++){
                for (int j = 0; j < n; j++){
                    int val = 0;
                    for (int l = j; l < n; l++){
                        val += dp[p][l] - dp[i-1][l];
                        if (val < k) ans = max(ans, val);
                        if (val == k) return k;
                        // cout << val << " ";
                    }
                    // cout << endl;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{1, 0,1},
                                  {0,-2,3}};
    int k = 2;
    Solution S;
    cout << S.maxSumSubmatrix(matrix, k) << endl;
    return 0;
}