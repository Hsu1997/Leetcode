#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + maxPts + 1, 0);
        dp[0] = 1;
        if (k > 0) for (int i = 1; i <= maxPts; i++) dp[i] += (double)1 / maxPts;
        double acc = 0;
        for (int i = 1; i < k + maxPts; i++){
            if (i - maxPts - 1 > 0) acc -= dp[i - maxPts - 1];
            dp[i] += acc / maxPts;
            if (i < k) acc += dp[i];
        }
        double ans = 0;
        for (int i = k; i <= n; i++) ans += dp[i];
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        return ans;
    }
};

int main(){
    int n = 10;
    int k = 1;
    int maxPts = 10;
    // int n = 6;
    // int k = 1;
    // int maxPts = 10;
    // int n = 21;
    // int k = 17;
    // int maxPts = 10;
    // int n = 1;
    // int k = 0;
    // int maxPts = 1;
    // int n = 0;
    // int k = 0;
    // int maxPts = 1;
    Solution S;
    cout << S.new21Game(n, k, maxPts) << endl;
    return 0;
}