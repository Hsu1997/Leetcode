#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        int mod = 1e9 + 7;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            int curr = pow(i, x);
            if (curr > n) return dp[n];
            for (int j = n; j >= curr; j--){
                dp[j] = (dp[j] + dp[j - curr]) % mod;
            }
        }
        return dp[n];
    }
};

int main(){
    int n = 10;
    int x = 2;
    // int n = 4;
    // int x = 1;
    // int n = 300;
    // int x = 2;
    Solution S;
    cout << S.numberOfWays(n, x) << endl;
    return 0;
}