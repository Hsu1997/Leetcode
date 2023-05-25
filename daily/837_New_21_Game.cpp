#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1;
        vector<double> dp(n+1, 0);
        dp[0] = 1;
        double acc = 0;
        double ans = 0;
        for (int i = 1; i <= n; i++){
            if (i - maxPts - 1 >= 0 && i - maxPts - 1 < k) acc -= dp[i - maxPts - 1];
            if (i - 1 < k) acc += dp[i - 1];
            dp[i] = acc / (double) maxPts;
            if (i >= k) ans += dp[i];
        }
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        return round(ans * 1e5) / 1e5;
    }
};

int main(){
    // int n = 21;
    // int k = 17;
    // int maxPts = 10;
    // int n = 12;
    // int k = 1;
    // int maxPts = 10;
    int n = 7597;
    int k = 4797;
    int maxPts = 5726;
    Solution S;
    cout << S.new21Game(n, k, maxPts) << endl;
    return 0;
}