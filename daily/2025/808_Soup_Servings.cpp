#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n > 5000) return 1;
        int m = (n / 25) + (n % 25 > 0);
        vector<vector<double>> dp(m + 1, vector<double>(m + 1, 0));
        dp[0][0] = 0.5;
        for (int i = 1; i <= m; i++){
            dp[i][0] = 0;
            dp[0][i] = 1;
            for (int j = 1; j <= i; j++){
                dp[i][j] = (dp[max(0, i-4)][j] + dp[max(0, i-3)][j-1] + dp[max(0, i-2)][max(0, j-2)] + dp[i-1][max(0, j-3)]) / 4;
                dp[j][i] = (dp[max(0, j-4)][i] + dp[max(0, j-3)][i-1] + dp[max(0, j-2)][max(0, i-2)] + dp[j-1][max(0, i-3)]) / 4;
            }
            if (dp[i][i] > 1 - 1e-5) return 1;
        }
        return dp[m][m];
    }
};

int main(){
    int n = 50;
    // int n = 100;
    // int n = 660295675;
    Solution S;
    cout << S.soupServings(n) << endl;
    return 0;
}