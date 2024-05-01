#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();

        if (l1 + l2 != l3) return false;
        if (s1 == "") return !s2.compare(s3);
        if (s2 == "") return !s1.compare(s3);

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        dp[0][0] = 1;


        for (int i = 1; i < l1+1; i++) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for (int j = 1; j < l2+1; j++) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];


        for (int i = 1; i < l1+1; i++){
            for (int j = 1; j < l2+1; j++){
                // cout << "(" << i << "," << j << ") => " << s3[i+j-1] << s1[i-1] << s2[j-1] << endl;
                if ((s3[i+j-1] == s1[i-1] && dp[i-1][j]) || (s3[i+j-1] == s2[j-1] && dp[i][j-1])) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }

        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        return dp[l1][l2];
    }
};

int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbcbbcac";
    // string s3 = "aadbbbaccc";
    // string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    // string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    // string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    Solution S;
    cout << S.isInterleave(s1, s2, s3) << endl;
    return 0;
}