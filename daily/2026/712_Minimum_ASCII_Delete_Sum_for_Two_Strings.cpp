#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int> dp(n, 0);
        vector<int> temp(n, 0);
        dp[0] = (s1[0] == s2[0])? int(s1[0]) : 0;
        for (int j = 1; j < n; j++) dp[j] = max(dp[j-1], (s1[0] == s2[j])? int(s1[0]) : 0);
        for (int i = 1; i < m; i++){
            temp[0] = max(dp[0], s1[i] == s2[0]? int(s1[i]) : 0);
            for (int j = 1; j < n; j++){
                temp[j] = dp[j-1];
                if (s1[i] == s2[j]) temp[j] += int(s1[i]);
                temp[j] = max({temp[j], temp[j-1], dp[j]});
            }
            swap(temp, dp);
        }
        int ans = 0;
        for (char c : s1) ans += c;
        for (char c : s2) ans += c;
        ans -= dp.back() * 2;
        return ans;
    }
};

int main(){
    string s1 = "sea";
    string s2 = "eat";
    // string s1 = "delete";
    // string s2 = "leet";
    // string s1 = "a";
    // string s2 = "at";
    // string s1 = "cccbcacbbb";
    // string s2 = "babbaacc";
    Solution S;
    cout << S.minimumDeleteSum(s1, s2) << endl;
    return 0;
}