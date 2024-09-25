#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n+1);
        // dp[n] = 0;
        for (int i = n-1; i >= 0; i--){
            dp[i] = dp[i+1] + 1;
            for (string candidate : dictionary){
                int l = candidate.length();
                if (i + l - 1 >= n) continue;
                if (s.substr(i, l) == candidate) dp[i] = min(dp[i], dp[i+l]);
            }
        }
        return dp[0];
    }
};

int main(){
    string s = "leetscode";
    vector<string> dictionary = {"leet","code","leetcode"};
    // string s = "sayhelloworld";
    // vector<string> dictionary = {"hello","world"};
    Solution S;
    cout << S.minExtraChar(s, dictionary) << endl;
    return 0;
}