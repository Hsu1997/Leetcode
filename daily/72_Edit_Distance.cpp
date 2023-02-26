#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (n == 0 || m == 0) return max(n,m);
        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        for (int j = 1; j < m+1; j++) dp[1][j] = j;
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        for (int i = 0; i < n; i++){
            dp[i%2][0] = i+1;
            // cout << dp[i%2][0] << " ";
            for (int j = 1; j < m+1; j++){
                if (word1[i] == word2[j-1]) dp[i%2][j] = dp[(i+1)%2][j-1];
                else dp[i%2][j] = min({dp[(i+1)%2][j-1], dp[i%2][j-1], dp[(i+1)%2][j]})+1;
                // cout << dp[(i)%2][j] << " ";
            }
            // cout << endl;
        }
        return dp[(n-1)%2][m];
    }
};

int main(){
    // string word1 = "horse";
    // string word2 = "ros";
    string word1 = "intention";
    string word2 = "execution";
    Solution S;
    cout << S.minDistance(word1, word2) << endl;
    return 0;
}