#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int d = 1; d < max(m, n); d++){
            if (d < n){
                for (int i = 1; i < min(m, d); i++){
                    if (matrix[i][d] == 1){
                        matrix[i][d] = min({matrix[i-1][d-1], matrix[i-1][d], matrix[i][d-1]}) + 1;
                    }
                }
            }
            if (d < m){
                for (int j = 1; j < min(n, d); j++){
                    if (matrix[d][j] == 1){
                        matrix[d][j] = min({matrix[d-1][j-1], matrix[d-1][j], matrix[d][j-1]}) + 1;
                    }
                }
            }
            if (d < min(m, n) && matrix[d][d] == 1) matrix[d][d] = min({matrix[d-1][d-1], matrix[d-1][d], matrix[d][d-1]}) + 1;
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans += matrix[i][j];
                // cout << matrix[i][j] << " ";
            }
            // cout << endl;
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