#include <iostream>
#include <vector>

using namespace std;

// dp with O(n*k) space

// class Solution {
// public:
//     int kInversePairs(int n, int k) {
//         if (k > (n-1)*n/2) return 0;
//         if (k == 0) return 1;
//         int mod = 1e9+7;
//         vector<vector<int>> dp(n, vector<int>(k+1, 0));
//         for (int i = 0; i < n; i++) dp[i][0] = 1;

//         for (int i = 1; i < n; i++){
//             int temp = 1;
//             for (int j = 1; j <= k && j <= i*(i+1)/2; j++){
//                 temp = (temp + dp[i-1][j]) % mod;
//                 if (j > i) temp = (temp - dp[i-1][j-i-1]) % mod;
//                 if (temp < 0) temp += mod;
//                 dp[i][j] = temp;
//             }
//         }

//         // for (auto i : dp){
//         //     for (auto j : i) cout << j << " ";
//         //     cout << endl;
//         // }

//         return dp[n-1][k];
//     }
// };

// dp with O(n) space
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k > (n-1)*n/2) return 0;
        if (k == 0) return 1;

        int mod = 1e9+7;
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        vector<int> dp_temp = dp;
        // vector<vector<int>> dp(n, vector<int>(k+1, 0));
        // for (int i = 0; i < n; i++) dp[i][0] = 1;

        for (int i = 1; i < n; i++){
            int temp = 1;
            for (int j = 1; j <= k && j <= i*(i+1)/2; j++){
                temp = (temp + dp[j]) % mod;
                if (j > i) temp = (temp - dp[j-i-1]) % mod;
                if (temp < 0) temp += mod;
                dp_temp[j] = temp;
            }
            swap(dp, dp_temp);
        }

        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        return dp[k];
    }
};

int main(){
    int n = 3;
    int k = 1;
    Solution S;
    cout << S.kInversePairs(n, k) << endl;
    return 0;
}