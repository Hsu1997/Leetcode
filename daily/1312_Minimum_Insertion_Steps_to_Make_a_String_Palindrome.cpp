#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int helper(string &s, vector<vector<int>>& dp, int i, int j){
        if (i >= j) return 0;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        if (s[i] == s[j]) dp[i][j] = helper(s,dp,i+1,j-1);
        else dp[i][j] = min(helper(s,dp,i+1,j), helper(s,dp,i,j-1)) + 1;
        return dp[i][j];
    }

    int minInsertions(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, INT_MAX));
        return helper(s, dp, 0, l-1);
    }
};

int main(){
    // string s = "zzazz";
    // string s = "mbadm";
    string s = "leetcode";
    Solution S;
    cout << S.minInsertions(s) << endl;
    return 0;
}