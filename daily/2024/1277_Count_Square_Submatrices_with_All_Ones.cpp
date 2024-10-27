#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            int cont = 0;
            for (int j = n-1; j >= 0; j--){
                if (matrix[i][j] == 1){
                    cont++;
                    dp[i][j] = cont;
                }
                else cont = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dp[i][j]){
                    int k = 0;
                    int min_amount = dp[i][j];
                    while(i + k < m){
                        min_amount = min(min_amount, dp[i+k][j]);
                        if (min_amount > k) ans++;
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    // vector<vector<int>> matrix = {{1,0,1},{1,1,0},{1,1,0}};
    Solution S;
    cout << S.countSquares(matrix) << endl;
    return 0;
}