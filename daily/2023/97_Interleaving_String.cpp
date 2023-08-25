#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s2.length() > s1.length()) swap(s1,s2);
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if (l3 != l1 + l2) return false;
        if (l1 == 0 || l2 == 0) return s1 == s3 || s2 == s3;
        vector<bool> dp(l2+1, false);
        dp[0] = 1;
        for (int j = 1; j < l2+1; j++) dp[j] = dp[j-1] && (s2[j-1] == s3[j-1]);
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        for (int i = 1; i < l1+1; i++){
            dp[0] = dp[0] && (s1[i-1] == s3[i-1]);
            for (int j = 1; j < l2+1; j++){
                dp[j] = ((s3[i+j-1] == s1[i-1]) && dp[j]) || ((s3[i+j-1] == s2[j-1]) && dp[j-1]);
            }
            // for (auto i : dp) cout << i << " ";
            // cout << endl;
        }
        return dp.back();
    }
};

int main(){
    string s1 = "aabaac";
    string s2 = "aadaaeaaf";
    string s3 = "aadaaeaabaafaac";
    Solution S;
    cout << S.isInterleave(s1,s2,s3) << endl;
    return 0;
}