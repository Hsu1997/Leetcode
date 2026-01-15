#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for (int i = 0; i < m; i++){
//             if (matrix[i][0] == '1') dp[i][0] = 1;
//             for (int j = 1; j < n; j++){
//                 if (matrix[i][j] == '1') dp[i][j] = 1 + dp[i][j-1];
//                 else dp[i][j] = 0;
//             }
//         }
//         int ans = 0;
//         for (int i = 0; i < m; i++){
//             for (int j = 0; j < n; j++){
//                 if (matrix[i][j] == '0') continue;
//                 int curr = dp[i][j];
//                 for (int k = i; k >= 0; k--){
//                     curr = min(curr, dp[k][j]);
//                     ans = max(ans, curr * (i - k + 1));
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            stack<int> sta;
            for (int j = 0; j <= n; j++){
                int curr;
                if (j == n) curr = 0;
                else{
                    curr = (matrix[i][j] == '0')? 0 : dp[j] + 1;
                    temp[j] = curr;
                }
                while(!sta.empty() && temp[sta.top()] >= curr){
                    int h = temp[sta.top()];
                    sta.pop();
                    int leftSmaller = (sta.empty())? -1 : sta.top();
                    ans = max(ans, h * (j - leftSmaller - 1));
                }
                sta.push(j);
            }
            swap(dp, temp);
        }
        return ans;
    }
};

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    // vector<vector<char>> matrix = {{'0'}};
    // vector<vector<char>> matrix = {{'1'}};
    Solution S;
    cout << S.maximalRectangle(matrix) << endl;
    return 0;
}