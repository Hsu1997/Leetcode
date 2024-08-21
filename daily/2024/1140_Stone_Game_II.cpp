#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    int n;
    int helper(vector<int>& piles, vector<vector<vector<int>>>& dp, int who, int start, int m){
        if (start == n) return 0;
        if (dp[who][start][m] != -1) return dp[who][start][m];
        int ans = INT_MIN;
        int acc = 0;
        for (int s = start + 1; s <= min(n, start + 2 * m); s++){
            acc += piles[s - 1];
            ans = max(ans, acc - helper(piles, dp, (who + 1) % 2, s, max(m, (s - start))));
        }
        return dp[who][start][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        helper(piles, dp, 0, 0, 1);
        // for (auto i : dp[0]){
        //     for (auto j : i) cout << setw(2) <<  j <<  " ";
        //     cout << endl;
        // }
        // cout << endl;
        // for (auto i : dp[1]){
        //     for (auto j : i) cout << setw(2) << j <<  " ";
        //     cout << endl;
        // }
        int total = 0;
        for (int i : piles) total += i;
        return (total + dp[0][0][1]) / 2;
    }
};

int main(){
    vector<int> piles = {2,7,9,4,4};
    // vector<int> piles = {1,2,3,4,5,100};
    // vector<int> piles = {1,1,1};
    Solution S;
    cout << S.stoneGameII(piles) << endl;
    return 0;
}