#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        int ans = 0;
        int mod = 1e9+7;
        dp[zero] += 1;
        dp[one] += 1;
        for (int i = 1; i <= high; i++){
            if (i - zero > 0) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i - one > 0) dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= low) ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};

int main(){
    // int low = 3;
    // int high = 3;
    // int zero = 1;
    // int one = 1;
    // int low = 2;
    // int high = 3;
    // int zero = 1;
    // int one = 2;
    int low = 200;
    int high = 200;
    int zero = 10;
    int one = 1;
    Solution S;
    cout << S.countGoodStrings(low, high, zero, one) << endl;
    return 0;
}