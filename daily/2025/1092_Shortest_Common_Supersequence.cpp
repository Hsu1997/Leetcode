#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = (str1[0] == str2[0]);
        for (int j = 1; j < n; j++) dp[0][j] = (str1[0] == str2[j]) || dp[0][j-1];
        for (int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] || (str1[i] == str2[0]);
            for (int j = 1; j < n; j++){
                if (str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string LCS;
        int i = m - 1;
        int j = n - 1;
        while(i > 0 && j > 0){
            if (dp[i][j] == dp[i-1][j]) i--;
            else if (dp[i][j] == dp[i][j-1]) j--;
            else{
                LCS.push_back(str1[i]);
                i--, j--;
            }
        }
        if (dp[i][j] == 1){
            while(i > 0 && dp[i-1][j] == 1) i--;
            while(j > 0 && dp[i][j-1] == 1) j--;
            LCS.push_back(str1[i]);
        }
        reverse(LCS.begin(), LCS.end());
        // cout << LCS << endl;
        i = 0;
        j = 0;
        int idx = 0;
        int l = LCS.length();
        string ans;
        ans.reserve(m + n - l);
        while(idx < l){
            while(str1[i] != LCS[idx]) ans.push_back(str1[i++]);
            while(str2[j] != LCS[idx]) ans.push_back(str2[j++]);
            ans.push_back(str1[i]);
            idx++, i++, j++;
        }
        while(i < m) ans.push_back(str1[i++]);
        while(j < n) ans.push_back(str2[j++]);
        return ans;
    }
};

int main(){
    // string str1 = "abac";
    // string str2 = "cab";
    string str1 = "aaaaaaaa";
    string str2 = "aaaaaaaa";
    Solution S;
    cout << S.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}