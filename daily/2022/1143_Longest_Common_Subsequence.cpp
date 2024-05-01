#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.length(), 0);
        vector<int> temp(text1.length(), 0);
        int s = 0;
        for (int i = 0; i < text1.length(); i++){
            if (text1[i] == text2[0]) s = 1;
            temp[i] = s;
        }
        // for (auto k : temp) cout << k << " ";
        // cout << endl;

        for (int i = 1; i < text2.length(); i++){
            dp[0] = (text1[0] == text2[i])? 1 : temp[0];
            for (int j = 1; j < text1.length(); j++){
                if (text2[i] == text1[j]) dp[j] = max({temp[j-1]+1, temp[j], dp[j-1]});
                else dp[j] = max({temp[j-1], temp[j], dp[j-1]});
            }
            // for (auto k : dp) cout << k << " ";
            // cout << endl;
            swap(dp, temp);
        }
        return temp.back();
    }
};

int main(){
    string text1 = "abcde";
    string text2 = "ace";
    // string text1 = "abc";
    // string text2 = "abc";
    // string text1 = "abc";
    // string text2 = "def";
    Solution S;
    cout << S.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}