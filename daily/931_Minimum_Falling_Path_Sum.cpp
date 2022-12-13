#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        for (int i = n-2; i >= 0; i--){
            matrix[i][0] += min(matrix[i+1][0],matrix[i+1][1]);
            for (int j = 1; j < n-1; j++) matrix[i][j] += min({matrix[i+1][j-1],matrix[i+1][j],matrix[i+1][j+1]});
            matrix[i][n-1] += min(matrix[i+1][n-2], matrix[i+1][n-1]);
            // for (auto j : matrix[i]) cout << j << " ";
            // cout << endl;
        }

        int ans = numeric_limits<int>::max();
        for (int i : matrix[0]) ans = min(ans, i);
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    // vector<vector<int>> matrix = {{-19,57},{-40,-5}};
    Solution S;
    cout << S.minFallingPathSum(matrix) << endl;
    return 0;
}