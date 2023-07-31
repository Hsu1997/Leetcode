#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> dp(n1+1);
        vector<int> temp(n1+1);
        for (int j = 0; j < n1; j++) dp[j+1] = dp[j] + s1[j];
        for (int i = 0; i < n2; i++){
            // for (auto k : dp) cout << k << " ";
            // cout << endl;
            temp[0] = dp[0] + s2[i];
            for (int j = 0; j < n1; j++){
                if (s1[j] == s2[i]) temp[j+1] = dp[j];
                else temp[j+1] = min(temp[j] + s1[j], dp[j+1] + s2[i]);
            }
            swap(temp, dp);
        }
        // for (auto k : dp) cout << k << " ";
        //     cout << endl;
        return dp.back();
    }
};

int main(){
    string s1 = "sea";
    string s2 = "eat";
    // string s1 = "delete";
    // string s2 = "leet";
    // for (int i = 'a'; i <= 'z'; i++) cout << (char)i << " : " << i << endl;
    Solution S;
    cout << S.minimumDeleteSum(s1, s2) << endl;
    return 0;
}