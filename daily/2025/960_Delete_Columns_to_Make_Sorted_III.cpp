#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool all_greater(int j, int k, vector<string>& strs){
        int n = strs.size();
        for (int i = 0; i < n; i++){
            if (strs[i][j] > strs[i][k]) return false;
        }
        return true;
    }
    
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int l = strs[0].length();
        vector<int> dp(l);
        dp[l-1] = 0;
        for (int j = l - 2; j >= 0; j--){
            int temp = l - j - 1;
            for (int k = j + 1; k < l; k++){
                if (all_greater(j, k, strs)) temp = min(temp, k - j - 1 + dp[k]);
            }
            dp[j] = temp;
        }
        int ans = l - 1;
        for (int k = 0; k < l; k++){
            ans = min(ans, dp[k] + k);
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"babca","bbazb"};
    // vector<string> strs = {"edcba"};
    // vector<string> strs = {"ghi","def","abc"};
    Solution S;
    cout << S.minDeletionSize(strs) << endl;
    return 0;
}