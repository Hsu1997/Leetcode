#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool vaild(string s){
        int x = stoi(s);
        return (x > 0 && x <= 26);
    }

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.length()+1, 0);
        dp[s.length()] = 1;
        dp[s.length()-1] = vaild({s[s.length()-1]});

        for (int i = s.length()-2; i >= 0; i--){
            if (s[i] == '0') dp[i] = 0;
            else{
                if (vaild({s[i]})) dp[i] += dp[i+1];
                if (vaild({s[i], s[i+1]})) dp[i] += dp[i+2]; 
            }
        }

        // for (auto i : dp) cout << i << " ";
        // cout << endl;

        return dp[0];
    }
};

int main(){
    string s = "2101";
    Solution S;
    cout << S.numDecodings(s) << endl;
    return 0;
}