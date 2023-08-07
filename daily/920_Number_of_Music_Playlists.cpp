#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int numMusicPlaylists(int n, int goal, int k) {
//         int m = 1e9+7;
//         vector<vector<long>> dp(goal+1, vector<long>(n+1));
//         dp[0][0] = 1;
//         for (int g = 1; g <= goal; g++){
//             for (int s = 1; s <= min(n,g); s++){
//                 dp[g][s] = dp[g-1][s-1] * (n-s+1) % m;
//                 if (s > k) dp[g][s] = (dp[g][s] + dp[g-1][s] * (s-k) % m) % m;
//             }
//             for (auto i : dp[g]) cout << i << " ";
//             cout << endl;
//         }
//         return dp[goal][n];
//     }
// };

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int m = 1e9+7;
        vector<long> dp(n+1);
        vector<long> temp(n+1);
        dp[0] = 1;
        for (int g = 1; g <= goal; g++){
            for (int s = 1; s <= min(n,g); s++){
                temp[s] = dp[s-1] * (n-s+1) % m;
                if (s > k) temp[s] = (temp[s] + dp[s] * (s-k) % m) % m;
            }
            // Only dp[0][0] = 1, else row first element is 0
            dp[0] = 0;
            swap(dp, temp);
            // for (auto i : dp) cout << i << " ";
            // cout << endl;
        }
        return dp[n];
    }
};

int main(){
    // int n = 3;
    // int goal = 3;
    // int k = 1;
    int n = 16;
    int goal = 19;
    int k = 5;
    Solution S;
    cout << S.numMusicPlaylists(n, goal, k) << endl;
    return 0;
}