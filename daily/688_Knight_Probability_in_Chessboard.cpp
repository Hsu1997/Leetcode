#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool in_board(int i, int j, int n){
        return (i >= 0) && (i < n) && (j >= 0) && (j < n);
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<int> x_d = {-2,-1,1,2,2,1,-1,-2};
        vector<int> y_d = {1,2,2,1,-1,-2,-2,-1};
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1;
        for (int t = 0; t < k; t++){
            vector<vector<double>> temp(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    for (int d = 0; d < 8; d++){
                        int new_x = i + x_d[d];
                        int new_y = j + y_d[d];
                        if (in_board(new_x, new_y, n)) temp[new_x][new_y] += dp[i][j]/8;
                    }
                }
            }
            swap(dp, temp);
        }
        double ans = 0;
        for (auto i : dp){
            for (auto j : i) ans += j;
        }
        return ans;
    }
};

int main(){
    // int n = 3;
    // int k = 2;
    // int row = 0;
    // int column = 0;
    int n = 1;
    int k = 0;
    int row = 0;
    int column = 0;
    Solution S;
    cout << S.knightProbability(n, k, row, column) << endl;
    return 0;
}