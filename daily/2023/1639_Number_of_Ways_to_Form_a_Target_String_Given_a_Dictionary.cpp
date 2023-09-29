#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numWays(vector<string> &words, string target) {
        int n = words.size();
        int s = words[0].length();
        int k = target.length();
        int mod = 1e9+7;
        vector<vector<int>> cnt(26, vector<int>(s, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < s; j++){
                cnt[words[i][j] - 'a'][j]++;
            }
        }
        // for (auto i : cnt){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        vector<vector<long>> dp(s, vector<long>(k, 0));
        dp[0][0] = cnt[target[0]-'a'][0];
        // for (int j = 1; j < k; j++) dp[0][j] = (cnt[target[0]-'a'][j] * dp[0][j-1]) % mod;
        for (int i = 1; i < s; i++){
            // cout << "i = " << i << " ";
            dp[i][0] = (dp[i-1][0] + cnt[target[0]-'a'][i]) % mod;
            for (int j = 1; j < k && j <= i; j++){
                // cout << "j = " << j << ", ";
                dp[i][j] = (dp[i-1][j] + (cnt[target[j]-'a'][i] * dp[i-1][j-1]) % mod) % mod;
            }
            // cout << endl;
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp[s-1][k-1];
    }
};

int main()
{
    vector<string> words = {"acca", "bbbb", "caca"};
    string target = "aba";
    // vector<string> words = {"abba","baab"};
    // string target = "bab";
    Solution S;
    cout << S.numWays(words, target) << endl;
    return 0;
}