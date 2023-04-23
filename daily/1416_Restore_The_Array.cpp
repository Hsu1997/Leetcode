#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int helper(vector<int> &dp, string &s, int k, int i){
        if (s[i] == '0') return -1;
        int l = s.length();
        int j = i+1;
        long temp = s[i]-'0';
        if (temp > k) return 0;
        while(j < l && dp[j] == -1){
            temp = temp * 10 + (s[j] - '0');
            j++;
            if (temp > k) return 0;
        }
        int mod = 1e9+7;
        int ans = dp[j];
        while(j < l && temp <= k){
            temp = temp * 10 + (s[j]-'0');
            j++;
            if (temp > k) return ans;
            if (dp[j] == -1) continue;
            ans = (ans + dp[j]) % mod;
        }
        return ans;
    }

    int numberOfArrays(string s, int k) {
        int l = s.length();
        vector<int> dp(l+1, 0);
        dp[l] = 1;
        for (int i = l-1; i >= 0; i--){
            dp[i] = helper(dp, s, k, i);
        }
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        return dp[0];
    }
};

int main(){
    // string s = "1000";
    // int k = 10000;
    // int k = 10;
    string s = "1317";
    int k = 2000;
    Solution S;
    cout << S.numberOfArrays(s, k) << endl;
    return 0;
}