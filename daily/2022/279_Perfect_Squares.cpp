#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        int count = 1;
        for (int i = 1; i <= n; i++){
            if (i == count*count){
                dp[i] = 1;
                count++;
                continue;
            }
            int min_dp = INT_MAX;
            for (int k = 1; k < count; k++){
                min_dp = min(min_dp, dp[i-k*k]);
            }
            dp[i] = min_dp + 1;
        }
        return dp[n];
    }
};

int main(){
    int n = 12;
    Solution S;
    cout << S.numSquares(n) << endl;
    return 0;
}