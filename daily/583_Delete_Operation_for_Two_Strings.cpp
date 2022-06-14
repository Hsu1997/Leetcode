#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(2, vector<int>(word2.size() + 1, 0));

        for (int i = 1; i <= word2.size(); i++) dp[0][i] = i;
        // for (auto i : dp[0]) cout << i << " ";
        // cout << endl;

        int round = 1;
        for (char i : word1){
            dp[round % 2][0] = round;
            int k = 1;
            for (char j : word2){
                if (i == j) dp[round % 2][k] = dp[(round+1) % 2][k-1];
                else dp[round % 2][k] = min(dp[round % 2][k-1], dp[(round+1) % 2][k]) + 1;
                k++;
            }
            // for (auto i : dp[round%2]) cout << i << " ";
            // cout << endl;
            round++;

        }
        return dp[(round+1)%2][word2.size()];
    }
};

int main(){
    string word1 = "leetcode";
    string word2 = "etco";
    Solution S;
    cout << S.minDistance(word1, word2) << endl;
    return 0;
}