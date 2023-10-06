#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 3; i <= n; i++){
            dp[i] = i-1;
            for (int j = i-1; j >= 2; j--) dp[i] = max({dp[i], (i-j) * dp[j], (i-j)*(j)});
        }
        // for (auto i : dp) cout << i << " ";
        return dp.back();
    }
};

int main(){
    int n = 10;
    Solution S;
    cout << S.integerBreak(n) << endl;
    return 0;
}