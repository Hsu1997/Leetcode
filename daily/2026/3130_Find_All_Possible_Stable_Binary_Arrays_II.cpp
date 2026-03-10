#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[1001][1001][2];
        int mod = 1e9 + 7;
        for (int i = 0; i <= zero; i++){
            for (int j = 0; j <= one; j++){
                for (int k = 0; k <= 1; k++){
                    if (i == 0){
                        if (k == 0 || j > limit) dp[i][j][k] = 0;
                        else dp[i][j][k] = 1;
                    }
                    else if (j == 0){
                        if (k == 1 || i > limit) dp[i][j][k] = 0;
                        else dp[i][j][k] = 1;
                    }
                    else if (k == 0){
                        dp[i][j][k] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                        if (i > limit) dp[i][j][k] = (dp[i][j][k] + mod - dp[i-limit-1][j][1]) % mod;
                    }
                    else{
                        // k == 1
                        dp[i][j][k] = (dp[i][j-1][0] + dp[i][j-1][1]) % mod;
                        if (j > limit) dp[i][j][k] = (dp[i][j][k] + mod - dp[i][j-limit-1][0]) % mod;
                    }
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};

// class Solution {
// public:
//     int numberOfStableArrays(int zero, int one, int limit) {
//         // vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
//         // vector<vector<vector<int>>> accRow(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
//         // vector<vector<vector<int>>> accCol(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
//         static int dp[1001][1001][2];
//         static int accRow[1001][1001][2];
//         static int accCol[1001][1001][2];
//         int mod = 1e9 + 7;
//         for (int i = 1; i <= zero; i++){
//             dp[i][0][0] = (i <= limit)? 1 : 0;
//             // dp[i][0][1] = 0;
//             accRow[i][0][0] = (i <= limit)? 1 : 0;
//             // accRow[i][0][1] = 0;
//             accCol[i][0][0] = min(i, limit);
//             // accCol[i][0][1] = 0;
//         }
//         for (int j = 1; j <= one; j++){
//             // dp[0][j][0] = 0;
//             dp[0][j][1] = (j <= limit)? 1 : 0;
//             accRow[0][j][0] = min(j, limit);
//             // accRow[0][j][1] = 0;
//             // accCol[0][j][0] = 0;
//             accCol[0][j][1] = (j <= limit)? 1 : 0;
//         }
//         for (int i = 1; i <= zero; i++){
//             for (int j = 1; j <= one; j++){
//                 dp[i][j][0] = accCol[i-1][j][1];
//                 if (i - limit - 1 >= 0) dp[i][j][0] = (dp[i][j][0] + mod - accCol[i-limit-1][j][1]) % mod;
//                 // dp[i-1][j][1] + dp[i-2][j][1] + ..... + dp[i-(limit-1)][j][1] + dp[i-limit][j][1]
//                 dp[i][j][1] = accRow[i][j-1][0];
//                 if (j - limit - 1 >= 0) dp[i][j][1] = (dp[i][j][1] + mod - accRow[i][j-limit-1][0]) % mod;
//                 // dp[i][j-1][0] + dp[i][j-2][0] + ..... + dp[i][j-(limit-1)][0] + dp[i][j-limit][0]
//                 accRow[i][j][0] = (accRow[i][j-1][0] + dp[i][j][0]) % mod;
//                 accRow[i][j][1] = (accRow[i][j-1][1] + dp[i][j][1]) % mod;
//                 accCol[i][j][0] = (accCol[i-1][j][0] + dp[i][j][0]) % mod;
//                 accCol[i][j][1] = (accCol[i-1][j][1] + dp[i][j][1]) % mod;
//             }
//         }
//         return (dp[zero][one][0] + dp[zero][one][1]) % mod;
//     }
// };

int main(){
    int zero = 1;
    int one = 1;
    int limit = 2;
    // int zero = 1;
    // int one = 2;
    // int limit = 1;
    // int zero = 3;
    // int one = 3;
    // int limit = 2;
    // int zero = 1000;
    // int one = 1000;
    // int limit = 2;
    Solution S;
    cout << S.numberOfStableArrays(zero, one, limit) << endl;
    return 0;
}